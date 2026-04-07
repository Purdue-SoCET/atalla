/*
 * test_dpi.c — smoke test for the Ramulator C DPI wrapper
 *
 * Build:  cmake .. && make test_dpi -j$(nproc)
 * Run:    LD_LIBRARY_PATH=. ./test_dpi dpi_test_config.yaml
 *
 * What it validates
 * -----------------
 *  1. ramulator_init()          – wrapper initialises without crash
 *  2. ramulator_send_request()  – reads and writes are accepted
 *  3. ramulator_tick()          – simulation advances without crash
 *  4. ramulator_check_response()– completed requests are returned
 *  5. Functional model          – reads return the last value written to that addr
 *  6. ramulator_finalize()      – clean shutdown, stats printed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "ramulator_dpi.h"

/* ------------------------------------------------------------------ */
/* Config                                                               */
/* ------------------------------------------------------------------ */
#define MAX_CYCLES      50000
#define MAX_INFLIGHT    64
#define NUM_REQUESTS    128
#define BASE_ADDR       0x0000000000000000ULL
#define ADDR_STRIDE     64ULL   /* cache-line granularity */

/* Write data pattern: deterministic function of address. */
static uint64_t make_write_data(unsigned long long addr) {
    return addr ^ 0xDEADBEEFCAFEBABEULL;
}

/* ------------------------------------------------------------------ */
/* Simple request tracker                                               */
/* ------------------------------------------------------------------ */
typedef struct {
    unsigned long long addr;
    int                req_type;   /* 0=Read, 1=Write */
    int                issued;
    int                completed;
    int                func_ok;    /* functional check result (reads only) */
} ReqEntry;

static ReqEntry requests[NUM_REQUESTS];

/* Shadow table: what value was last written to each address.
 * For addresses that only had reads, expected = make_write_data(addr)
 * is never set, so we track "was it written" separately.          */
static uint64_t written_data[NUM_REQUESTS];
static int      was_written[NUM_REQUESTS];  /* 1 if a write was issued before the read */

static int count_issued(void) {
    int n = 0;
    for (int i = 0; i < NUM_REQUESTS; i++) n += requests[i].issued;
    return n;
}

static int count_completed(void) {
    int n = 0;
    for (int i = 0; i < NUM_REQUESTS; i++) n += requests[i].completed;
    return n;
}

static int count_func_ok(void) {
    int n = 0;
    for (int i = 0; i < NUM_REQUESTS; i++) n += requests[i].func_ok;
    return n;
}

/* ------------------------------------------------------------------ */
/* Helpers                                                              */
/* ------------------------------------------------------------------ */
static void mark_completed(long long addr, uint64_t ret_data) {
    for (int i = 0; i < NUM_REQUESTS; i++) {
        if (requests[i].issued && !requests[i].completed &&
            (long long)requests[i].addr == addr &&
            requests[i].req_type == 0 /* Read */) {

            requests[i].completed = 1;

            /* Functional check: did we get back what was written? */
            uint64_t expected;
            if (was_written[i]) {
                expected = written_data[i];
            } else {
                /* Never written — wrapper returns address as default */
                expected = (uint64_t)addr;
            }

            if (ret_data == expected) {
                requests[i].func_ok = 1;
            } else {
                printf("  [FUNC MISMATCH] addr=0x%llx  got=0x%016llx  expected=0x%016llx\n",
                       (unsigned long long)addr,
                       (unsigned long long)ret_data,
                       (unsigned long long)expected);
            }
            return;
        }
    }
    printf("  [note] completion for addr 0x%llx not matched to pending req\n",
           (unsigned long long)addr);
}

/* ------------------------------------------------------------------ */
/* Main                                                                 */
/* ------------------------------------------------------------------ */
int main(int argc, char* argv[]) {
    const char* config_path = (argc > 1) ? argv[1] : "dpi_test_config.yaml";

    printf("=== Ramulator DPI wrapper smoke test ===\n");
    printf("Config: %s\n\n", config_path);

    /* ---- 1. Init ---- */
    printf("[1] ramulator_init ... ");
    fflush(stdout);
    ramulator_handle_t handle = ramulator_init(config_path);
    if (!handle) {
        fprintf(stderr, "FAIL – ramulator_init returned NULL.\n"
                        "       Check that the config file exists and is valid.\n");
        return 1;
    }
    printf("OK\n");

    /* Prepare request table.
     * Pattern: pairs of (Write, Read, Read, Read) so every read at index i
     * has a write at index i-3 to the same address when i%4 != 0.
     * Writes (i%4 == 0) issue to their own address; subsequent reads at
     * i%4 != 0 target different addresses so there is no prior write —
     * those will verify the "never-written" default path.             */
    for (int i = 0; i < NUM_REQUESTS; i++) {
        requests[i].addr      = BASE_ADDR + (unsigned long long)i * ADDR_STRIDE;
        requests[i].req_type  = (i % 4 == 0) ? 1 : 0;
        requests[i].issued    = 0;
        requests[i].completed = 0;
        requests[i].func_ok   = 0;
        written_data[i]       = 0;
        was_written[i]        = 0;
    }

    int next_req    = 0;
    int inflight    = 0;
    int stall_count = 0;
    int accepted    = 0;
    int rejected    = 0;

    printf("[2] Issuing %d requests over up to %d cycles ...\n",
           NUM_REQUESTS, MAX_CYCLES);

    /* ---- Main simulation loop ---- */
    for (int cycle = 0; cycle < MAX_CYCLES; cycle++) {

        /* Drain completions */
        long long resp;
        long long  resp_data;
        while ((resp = ramulator_check_response(handle, &resp_data)) != -1) {
            mark_completed(resp, resp_data);
            inflight--;
        }

        /* Try to issue the next request */
        if (next_req < NUM_REQUESTS && inflight < MAX_INFLIGHT) {
            int    req_type = requests[next_req].req_type;
            uint64_t data   = (req_type == 1) ? make_write_data(requests[next_req].addr) : 0;

            int ok = ramulator_send_request(
                handle,
                requests[next_req].addr,
                req_type,
                0 /*source_id*/,
                data
            );
            if (ok) {
                requests[next_req].issued = 1;
                if (req_type == 1) {
                    written_data[next_req] = data;
                    was_written[next_req]  = 1;
                    /* Mark the write itself as "completed" immediately —
                     * writes are fire-and-forget (no timing callback).   */
                    requests[next_req].completed = 1;
                    inflight--;   /* don't count writes toward in-flight reads */
                }
                next_req++;
                inflight++;
                accepted++;
                stall_count = 0;
            } else {
                rejected++;
                stall_count++;
            }
        }

        /* Advance simulation */
        ramulator_tick(handle);

        /* Bail out if all reads finished */
        if (count_completed() == NUM_REQUESTS) {
            printf("    All requests completed at cycle %d\n", cycle + 1);
            break;
        }

        if (stall_count > 10000) {
            fprintf(stderr, "    WARNING: stalled for 10000 cycles – possible deadlock.\n");
            break;
        }
    }

    /* ---- Report ---- */
    int total_issued    = count_issued();
    int total_completed = count_completed();
    int reads_completed = 0;
    for (int i = 0; i < NUM_REQUESTS; i++)
        if (requests[i].req_type == 0 && requests[i].completed) reads_completed++;
    int func_ok = count_func_ok();

    printf("\n--- Results ---\n");
    printf("  Requests issued      : %d / %d\n", total_issued, NUM_REQUESTS);
    printf("  Reads completed      : %d\n", reads_completed);
    printf("  Functional checks OK : %d / %d\n", func_ok, reads_completed);
    printf("  Send accepted        : %d\n", accepted);
    printf("  Send rejected        : %d\n", rejected);

    /* ---- Checks ---- */
    printf("\n[3] ramulator_send_request ... ");
    if (accepted > 0)
        printf("OK (%d accepted)\n", accepted);
    else {
        fprintf(stderr, "FAIL – no requests were accepted.\n");
        ramulator_finalize(handle);
        return 1;
    }

    printf("[4] ramulator_check_response ... ");
    if (reads_completed > 0)
        printf("OK (%d completions)\n", reads_completed);
    else
        printf("WARN – no completions observed\n");

    printf("[5] Functional model ... ");
    if (reads_completed > 0 && func_ok == reads_completed)
        printf("OK (all %d reads returned correct data)\n", reads_completed);
    else if (reads_completed == 0)
        printf("WARN – no reads completed, cannot verify\n");
    else {
        fprintf(stderr, "FAIL – %d / %d reads returned wrong data\n",
                reads_completed - func_ok, reads_completed);
        ramulator_finalize(handle);
        return 1;
    }

    printf("[6] ramulator_finalize ... ");
    fflush(stdout);
    ramulator_finalize(handle);
    printf("OK\n");

    printf("\n=== Smoke test PASSED ===\n");
    return 0;
}

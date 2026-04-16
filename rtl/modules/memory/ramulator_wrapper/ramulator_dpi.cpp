#include "ramulator_dpi.h"
#include "base/config.h"
#include "frontend/frontend.h"
#include "memory_system/memory_system.h"
#include <queue>
#include <memory>
#include <unordered_map>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace Ramulator;

enum class MemMode {
    DDR4_64,
    HBM3_PC32
};


struct CompletedReq {
    Addr_t   addr;
    uint64_t data;
    int      source_id;
};

struct RamulatorWrapper {
    std::unique_ptr<IFrontEnd>     frontend;
    std::unique_ptr<IMemorySystem> memory_system;

    std::queue<CompletedReq> completed_requests;

    // tracks the last value written to each address; reads return 0 for
    // anything that hasn't been written yet
    std::unordered_map<Addr_t, uint64_t> functional_mem;

    MemMode  mode = MemMode::DDR4_64;
    uint64_t data_mask = 0xFFFF'FFFF'FFFF'FFFFULL;
    int      data_bytes = 8;

    int      mem_tick_ratio;
    int      frontend_tick_ratio;
    uint64_t cycle_count;

    // Read-request coalescing: multiple sub-block requests (e.g. two consecutive
    // 32-byte AXI beats) that fall inside the same DRAM transaction granule
    // (coalesce_unit bytes) share a single Ramulator CAS.  Each entry holds the
    // list of (original_byte_addr, source_id) pairs waiting on that granule.
    // The map is keyed on granule-aligned address.
    Addr_t coalesce_unit = 64;   // bytes per DRAM transaction (DDR4 default)
    std::unordered_map<Addr_t, std::vector<std::pair<Addr_t,int>>> coalesce_pending;
};

static inline uint64_t normalize_data(const RamulatorWrapper* wrapper, uint64_t v) {
    return v & wrapper->data_mask;
}

extern "C" {

ramulator_handle_t ramulator_init(const char* config_file) {
    try {
        YAML::Node config = Config::parse_config_file(config_file, {});

        auto* wrapper = new RamulatorWrapper();

        std::string cfg = config_file ? config_file : "";
        if (cfg.find("hbm3") != std::string::npos || cfg.find("HBM3") != std::string::npos) {
            wrapper->mode          = MemMode::HBM3_PC32;
            wrapper->data_mask     = 0x0000'0000'FFFF'FFFFULL;
            wrapper->data_bytes    = 4;
            wrapper->coalesce_unit = 32;  // HBM3 PC32: 8-beat × 32-bit bus = 32 bytes
        } else {
            wrapper->mode          = MemMode::DDR4_64;
            wrapper->data_mask     = 0xFFFF'FFFF'FFFF'FFFFULL;
            wrapper->data_bytes    = 8;
            wrapper->coalesce_unit = 64;  // DDR4 x64: 8-beat × 64-bit bus = 64 bytes
        }

        wrapper->frontend.reset(Factory::create_frontend(config));
        wrapper->memory_system.reset(Factory::create_memory_system(config));

        wrapper->frontend->connect_memory_system(wrapper->memory_system.get());
        wrapper->memory_system->connect_frontend(wrapper->frontend.get());

        wrapper->frontend_tick_ratio = wrapper->frontend->get_clock_ratio();
        wrapper->mem_tick_ratio      = wrapper->memory_system->get_clock_ratio();
        wrapper->cycle_count         = 0;

        // Ramulator2's Factory registry destructor segfaults on exit. We register
        // an atexit that calls _Exit() so it fires before the Factory's own
        // cxa_atexit entry (LIFO order) and bails out cleanly.
        std::atexit([]() { std::_Exit(0); });

        return static_cast<ramulator_handle_t>(wrapper);
    } catch (const std::exception& e) {
        fprintf(stderr, "[ramulator_init] ERROR: %s\n", e.what());
        return nullptr;
    } catch (...) {
        fprintf(stderr, "[ramulator_init] ERROR: unknown exception\n");
        return nullptr;
    }
}

int ramulator_send_request(ramulator_handle_t handle,
                           unsigned long long addr,
                           int req_type,
                           int source_id,
                           uint64_t data) {
    try {
        auto* wrapper = static_cast<RamulatorWrapper*>(handle);
        if (!wrapper) return 0;

        Addr_t original_addr = static_cast<Addr_t>(addr);

        // Writes: update functional memory and pass through directly.
        if (req_type == 1) {
            wrapper->functional_mem[original_addr] = normalize_data(wrapper, data);

            auto callback = [](Request& req) {};   // writes need no read-back
            bool accepted = wrapper->frontend->receive_external_requests(
                req_type, addr, source_id, callback
            );
            return accepted ? 1 : 0;
        }

        // Reads: coalesce sub-block requests that fall in the same DRAM granule.
        // Two consecutive 32-byte AXI beats (e.g. 0x000 and 0x020) both address
        // the same 64-byte DRAM transaction; without coalescing we would issue
        // two CAS commands for the same row/bank and waste half the bus bandwidth.
        Addr_t granule = original_addr & ~static_cast<Addr_t>(wrapper->coalesce_unit - 1);

        auto map_it = wrapper->coalesce_pending.find(granule);
        if (map_it != wrapper->coalesce_pending.end()) {
            // A Ramulator request for this granule is already outstanding.
            // Just register this beat's completion; no second CAS needed.
            map_it->second.push_back({original_addr, source_id});
            return 1;
        }

        // First request for this granule: insert into the coalesce map BEFORE
        // calling into Ramulator so the callback (which fires synchronously in
        // some implementations) can always find the entry.
        wrapper->coalesce_pending[granule] = {{original_addr, source_id}};

        auto callback = [wrapper, granule](Request& req) {
            auto it = wrapper->coalesce_pending.find(granule);
            if (it == wrapper->coalesce_pending.end()) return;

            for (auto& [orig_addr, src_id] : it->second) {
                wrapper->completed_requests.push({orig_addr, 0, src_id});
            }
            wrapper->coalesce_pending.erase(it);
        };

        bool accepted = wrapper->frontend->receive_external_requests(
            0, granule, source_id, callback
        );

        if (!accepted) {
            // Ramulator rejected the request (queue full). Roll back the map
            // entry so the SV wrapper can retry next cycle.
            wrapper->coalesce_pending.erase(granule);
            return 0;
        }
        return 1;
    } catch (const std::exception& e) {
        fprintf(stderr, "[ramulator_send_request] ERROR: %s\n", e.what());
        return 0;
    } catch (...) {
        fprintf(stderr, "[ramulator_send_request] ERROR: unknown exception\n");
        return 0;
    }
}

void ramulator_tick(ramulator_handle_t handle) {
    auto* wrapper = static_cast<RamulatorWrapper*>(handle);
    if (!wrapper) return;

    wrapper->cycle_count++;

    if ((wrapper->cycle_count % wrapper->frontend_tick_ratio) == 0) {
        wrapper->frontend->tick();
    }
    if ((wrapper->cycle_count % wrapper->mem_tick_ratio) == 0) {
        wrapper->memory_system->tick();
    }
}

long long ramulator_check_response(ramulator_handle_t handle,
                                   uint64_t* data_out0, uint64_t* data_out1,
                                   uint64_t* data_out2, uint64_t* data_out3,
                                   int* source_id_out) {
    auto* wrapper = static_cast<RamulatorWrapper*>(handle);
    if (!wrapper || wrapper->completed_requests.empty()) {
        return -1;
    }

    CompletedReq cr = wrapper->completed_requests.front();
    wrapper->completed_requests.pop();

    // Align down to the 32-byte (4 × 8-byte) beat boundary.
    Addr_t base = cr.addr & ~(Addr_t)0x1F;

    uint64_t* outs[4] = {data_out0, data_out1, data_out2, data_out3};
    for (int i = 0; i < 4; i++) {
        if (outs[i]) {
            Addr_t a = base + static_cast<Addr_t>(i * 8);
            auto it = wrapper->functional_mem.find(a);
            *outs[i] = (it != wrapper->functional_mem.end())
                       ? normalize_data(wrapper, it->second)
                       : normalize_data(wrapper, static_cast<uint64_t>(a));
        }
    }
    if (source_id_out) *source_id_out = cr.source_id;

    return static_cast<long long>(base);
}

uint64_t ramulator_read_mem(ramulator_handle_t handle, unsigned long long addr) {
    auto* wrapper = static_cast<RamulatorWrapper*>(handle);
    auto it = wrapper->functional_mem.find(static_cast<Addr_t>(addr));
    if (it != wrapper->functional_mem.end())
        return it->second;
    return 0;
}

long long ramulator_load_mem_bin(
    ramulator_handle_t handle,
    const char*        path,
    unsigned long long base_addr
) {
    auto* wrapper = static_cast<RamulatorWrapper*>(handle);

    FILE* f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "[ramulator_load_mem_bin] Cannot open '%s'\n", path);
        return -1;
    }

    uint8_t  buf[8];
    long long beats = 0;
    size_t   n;
    while ((n = fread(buf, 1, 8, f)) > 0) {
        if (n < 8) memset(buf + n, 0, 8 - n);   // zero-pad last beat
        uint64_t val;
        memcpy(&val, buf, 8);                    // little-endian host order
        Addr_t addr = static_cast<Addr_t>(base_addr + static_cast<unsigned long long>(beats) * 8);
        wrapper->functional_mem[addr] = val;
        beats++;
    }
    fclose(f);
    return beats;
}

long long ramulator_load_mem_hex(
    ramulator_handle_t handle,
    const char*        path
) {
    auto* wrapper = static_cast<RamulatorWrapper*>(handle);

    FILE* f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "[ramulator_load_mem_hex] Cannot open '%s'\n", path);
        return -1;
    }

    char      line[256];
    long long entries = 0;
    long long lineno  = 0;
    while (fgets(line, sizeof(line), f)) {
        lineno++;
        // Skip blank lines and comments (# or //)
        char* p = line;
        while (*p == ' ' || *p == '\t') p++;
        if (*p == '\0' || *p == '\n' || *p == '#' ||
            (p[0] == '/' && p[1] == '/'))
            continue;

        unsigned long long addr, data;
        if (sscanf(p, "%llx %llx", &addr, &data) != 2) {
            fprintf(stderr, "[ramulator_load_mem_hex] Parse error at %s:%lld: '%s'\n",
                    path, lineno, line);
            fclose(f);
            return -1;
        }
        wrapper->functional_mem[static_cast<Addr_t>(addr)] =
            static_cast<uint64_t>(data);
        entries++;
    }
    fclose(f);
    return entries;
}

void ramulator_finalize(ramulator_handle_t handle) {
    // Intentionally empty. Ramulator2 crashes in finalize() (print_stats
    // recursion), in destructors, and in the Factory registry at exit.
    // The atexit handler in ramulator_init calls _Exit() to skip all of it.
    (void)handle;
}

// Use this instead of $finish. QuestaSim's post-sim teardown walks into
// the heap corruption that Ramulator2 leaves behind, so we just call
// _Exit() and skip destructors entirely. Flush stdout/stderr first so
// $display output is not lost.
void ramulator_exit(int code) {
    fflush(stdout);
    fflush(stderr);
    std::_Exit(code);
}

} // extern "C"

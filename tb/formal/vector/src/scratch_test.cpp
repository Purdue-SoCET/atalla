#include <scratchpad.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// -----------------------------------------------------------------------------
// Helper: write a 32-element uint16 array to a file as a single line
// -----------------------------------------------------------------------------
void write_vector_line(std::ofstream &file, const std::array<uint16_t, 32> &vec) {
    for (int i = 0; i < 32; i++) {
        file << std::setw(10) << vec[i];
        if (i < 31) file << " ";
    }
    file << "\n";
}

// Helper: compare two arrays for equality
bool vec_equal(const std::array<uint16_t, 32>& a, const std::array<uint16_t, 32>& b) {
    for (int i = 0; i < 32; ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// ============================================================================
// Test 1: Write 32 rows, read 32 rows back with 13-cycle latency
// - capture valid_out while issuing reads
// - drain the pipeline after issuing
// ============================================================================
void test_write_read_rows(scratchpad& sp) {
    std::cout << "Running: Row Read/Write (Vector Dump)...\n";

    std::ofstream out("rows_out.txt");
    if (!out.is_open()) {
        std::cerr << "Error: could not open rows_out.txt\n";
        return;
    }

    // Create test matrix (unique values starting at 0)
    std::array<std::array<uint16_t, 32>, 32> test;
    for (int r = 0; r < 32; r++)
        for (int c = 0; c < 32; c++)
            test[r][c] = r * 32 + c;

    // --------------------------
    // WRITE ALL 32 ROWS (atomic per-row)
    // --------------------------
    for (int row = 0; row < 32; row++) {
        sp.sp_input_if[0].valid_in = 1;
        sp.sp_input_if[0].wen = 1;
        sp.sp_input_if[0].addr = 0;
        sp.sp_input_if[0].row_id = row;
        sp.sp_input_if[0].num_cols = 32;
        sp.sp_input_if[0].row_or_col = 0; // row mode
        sp.sp_input_if[0].wdata = test[row];

        sp.clk = 1; sp.tick();
        sp.clk = 0; sp.tick();
    }
    // De-assert write signals
    sp.sp_input_if[0].valid_in = 0;
    sp.sp_input_if[0].wen = 0;

    // --------------------------
    // ISSUE READS WHILE CAPTURING COMPLETIONS
    // --------------------------
    const int expected = 32;
    int issued = 0;
    int received = 0;
    int safety = 5000; // large safety to prevent infinite loop

    // We will issue one read per cycle, and also sample valid_out each cycle.
    while ((issued < expected || received < expected) && safety-- > 0) {
        // Issue a read if still need to
        if (issued < expected) {
            sp.sp_input_if[0].valid_in = 1;
            sp.sp_input_if[0].wen = 0;
            sp.sp_input_if[0].addr = 0;
            sp.sp_input_if[0].row_id = issued;
            sp.sp_input_if[0].num_cols = 32;
            sp.sp_input_if[0].row_or_col = 0;
            issued++;
        } else {
            sp.sp_input_if[0].valid_in = 0;
        }

        // Rising edge: let module process; capture output if available
        sp.clk = 1; sp.tick();

        if (sp.sp_output_if[0].valid) {
            write_vector_line(out, sp.sp_output_if[0].rdata);
            received++;
        }

        // Falling edge
        sp.clk = 0; sp.tick();
    }

    if (received != expected) {
        std::cerr << "WARNING: rows: expected " << expected << " received " << received << "\n";
    } else {
        std::cout << "Rows written to rows_out.txt (32 vectors received)\n\n";
    }

    out.close();
}

// ============================================================================
// Test 2: Write 32 columns, read 32 columns back (columns written/read as vectors)
// - capture valid_out while issuing reads
// - drain pipeline after issuing
// - detect duplicate returned vectors (useful for debugging duplicates)
// ============================================================================
void test_write_read_cols(scratchpad& sp) {
    std::cout << "Running: Column Read/Write (Vector Dump)...\n";

    std::ofstream out("cols_out.txt");
    if (!out.is_open()) {
        std::cerr << "Error: could not open cols_out.txt\n";
        return;
    }

    // Create test matrix (unique values starting at 100)
    std::array<std::array<uint16_t, 32>, 32> test;
    for (int r = 0; r < 32; r++)
        for (int c = 0; c < 32; c++)
            test[r][c] = 100 + r * 32 + c;

    // --------------------------
    // WRITE ALL 32 COLUMNS (atomic per-column)
    // --------------------------
    for (int col = 0; col < 32; col++) {
        sp.sp_input_if[1].valid_in = 1;
        sp.sp_input_if[1].wen = 1;
        sp.sp_input_if[1].addr = 0;
        sp.sp_input_if[1].col_id = col;
        sp.sp_input_if[1].num_rows = 32;
        sp.sp_input_if[1].row_or_col = 1; // column mode
        
        // Extract column col into wdata
        for (int r = 0; r < 32; r++) {
            sp.sp_input_if[1].wdata[r] = test[r][col];
        }

        sp.clk = 1; sp.tick();
        sp.clk = 0; sp.tick();
    }
    // De-assert write signals
    sp.sp_input_if[1].valid_in = 0;
    sp.sp_input_if[1].wen = 0;

    // --------------------------
    // ISSUE READS WHILE CAPTURING COMPLETIONS
    // --------------------------
    const int expected = 32;
    int issued = 0;
    int received = 0;
    int safety = 5000;

    std::array<uint16_t, 32> prev_vec = {0};
    bool have_prev = false;

    while ((issued < expected || received < expected) && safety-- > 0) {
        // Issue read if needed
        if (issued < expected) {
            sp.sp_input_if[1].valid_in = 1;
            sp.sp_input_if[1].wen = 0;
            sp.sp_input_if[1].addr = 0;
            sp.sp_input_if[1].col_id = issued;
            sp.sp_input_if[1].num_rows = 32;
            sp.sp_input_if[1].row_or_col = 1;
            issued++;
        } else {
            sp.sp_input_if[1].valid_in = 0;
        }

        // Rising edge: capture if valid_out
        sp.clk = 1; sp.tick();

        if (sp.sp_output_if[1].valid) {
            // Duplicate detection (helpful for debugging)
            if (have_prev && vec_equal(prev_vec, sp.sp_output_if[1].rdata)) {
                std::cerr << "WARNING: duplicate vector received for column read #" << received << "\n";
            }
            prev_vec = sp.sp_output_if[1].rdata;
            have_prev = true;

            write_vector_line(out, sp.sp_output_if[1].rdata);
            received++;
        }

        // Falling edge
        sp.clk = 0; sp.tick();
    }

    if (received != expected) {
        std::cerr << "WARNING: cols: expected " << expected << " received " << received << "\n";
    } else {
        std::cout << "Columns written to cols_out.txt (32 vectors received)\n\n";
    }

    out.close();
}

// ============================================================================
// Test 3: Latency timing test (keeps original semantics)
// ============================================================================
void test_latency_timing(scratchpad& sp) {
    std::cout << "Running: Verify 13-Cycle Read Latency...\n";

    std::ofstream log("test_latency_timing.txt");
    if (!log.is_open()) {
        std::cerr << "Error: could not open test_latency_timing.txt\n";
        return;
    }

    // Write a row (address 4, row 5)
    sp.sp_input_if[0].valid_in = 1;
    sp.sp_input_if[0].wen = 1;
    sp.sp_input_if[0].addr = 4;
    sp.sp_input_if[0].row_id = 5;
    sp.sp_input_if[0].num_cols = 32;
    sp.sp_input_if[0].row_or_col = 0;

    for (int i = 0; i < 32; i++)
        sp.sp_input_if[0].wdata[i] = 42;

    sp.clk = 1; sp.tick();
    sp.clk = 0; sp.tick();

    sp.sp_input_if[0].valid_in = 0;
    sp.sp_input_if[0].wen = 0;

    // Issue read
    sp.sp_input_if[0].valid_in = 1;
    sp.sp_input_if[0].wen = 0;
    sp.sp_input_if[0].addr = 4;
    sp.sp_input_if[0].row_id = 5;
    sp.sp_input_if[0].num_cols = 32;

    int read_cycle = sp.cycle_count;
    log << "Read issued at cycle: " << read_cycle << "\n";

    sp.clk = 1; sp.tick();
    sp.clk = 0; sp.tick();
    sp.sp_input_if[0].valid_in = 0;

    bool data_received = false;
    int cycles_until_data = 0;

    for (int i = 0; i < 40; i++) {
        sp.clk = 1; sp.tick();

        log << "Cycle " << sp.cycle_count << ": valid=" << (int)sp.sp_output_if[0].valid << "\n";
        if (sp.sp_output_if[0].valid && !data_received) {
            cycles_until_data = sp.cycle_count - read_cycle - 1;
            data_received = true;
            log << "valid went high at cycle: " << sp.cycle_count << "\n";
            log << "Cycles from read to valid: " << cycles_until_data << "\n";

            bool correct = true;
            for (int j = 0; j < 32; j++) {
                uint16_t val = sp.sp_output_if[0].rdata[j];
                if (val != 42) {
                    correct = false;
                    log << "Data mismatch at index " << j << ": expected 42, got " << val << "\n";
                }
            }

            log << "Data correct: " << (correct ? "yes" : "no") << "\n";
            log << "Observed latency: " << cycles_until_data << "\n";
        }

        sp.clk = 0; sp.tick();

        if (data_received) break;
    }

    if (!data_received) {
        log << "FAIL: valid never went high within 40 cycles\n";
        std::cerr << "FAIL: valid never went high within 40 cycles\n";
    }

    log.close();
    std::cout << "Latency test wrote test_latency_timing.txt\n\n";
}

// ============================================================================
// MAIN
// ============================================================================
int main() {
    scratchpad sp;

    // Reset pulses
    sp.rst_n = 0;
    sp.clk = 1; sp.tick();
    sp.clk = 0; sp.tick();
    sp.rst_n = 1;

    test_write_read_rows(sp);

    // Reset between tests
    sp.rst_n = 0;
    sp.clk = 1; sp.tick();
    sp.clk = 0; sp.tick();
    sp.rst_n = 1;

    test_write_read_cols(sp);

    // Reset and latency test
    sp.rst_n = 0;
    sp.clk = 1; sp.tick();
    sp.clk = 0; sp.tick();
    sp.rst_n = 1;

    test_latency_timing(sp);

    std::cout << "All tests completed.\n";
    return 0;
}
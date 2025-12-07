#include <scratchpad.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// -----------------------------------------------------------------------------
// Helper: write a 32-element BF16 vector to a file as a single line
// -----------------------------------------------------------------------------
void write_vector_line(std::ofstream &file, const Eigen::Matrix<Eigen::bfloat16, 32, 1> &vec) {
    for (int i = 0; i < 32; i++) {
        file << std::setw(10) << std::fixed << std::setprecision(4)
             << static_cast<float>(vec(i));
        if (i < 31) file << " ";
    }
    file << "\n";
}

// Helper: compare two vectors for equality (by float value)
bool vec_equal(const Eigen::Matrix<Eigen::bfloat16, 32, 1>& a, const Eigen::Matrix<Eigen::bfloat16, 32, 1>& b) {
    for (int i = 0; i < 32; ++i) {
        if (static_cast<float>(a(i)) != static_cast<float>(b(i))) return false;
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
    Eigen::Matrix<Eigen::bfloat16, 32, 32> test;
    for (int r = 0; r < 32; r++)
        for (int c = 0; c < 32; c++)
            test(r,c) = Eigen::bfloat16(r * 32 + c);

    // --------------------------
    // WRITE ALL 32 ROWS (atomic per-row)
    // --------------------------
    for (int row = 0; row < 32; row++) {
        sp.valid_in_sp1 = 1;
        sp.write_sp1 = 1;
        sp.sp_addr_sp1 = 0;
        sp.row_id_sp1 = row;
        sp.num_cols_sp1 = 32;
        sp.row_or_col_sp1 = 0; // row mode
        sp.wdata_sp1 = test.row(row).transpose();

        sp.clk = 1; sp.tick();
        sp.clk = 0; sp.tick();
    }
    // De-assert write signals
    sp.valid_in_sp1 = 0;
    sp.write_sp1 = 0;

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
            sp.valid_in_sp1 = 1;
            sp.write_sp1 = 0;
            sp.sp_addr_sp1 = 0;
            sp.row_id_sp1 = issued;
            sp.num_cols_sp1 = 32;
            sp.row_or_col_sp1 = 0;
            issued++;
        } else {
            sp.valid_in_sp1 = 0;
        }

        // Rising edge: let module process; capture output if available
        sp.clk = 1; sp.tick();

        if (sp.valid_out_sp1) {
            write_vector_line(out, sp.rdata_sp1);
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
    Eigen::Matrix<Eigen::bfloat16, 32, 32> test;
    for (int r = 0; r < 32; r++)
        for (int c = 0; c < 32; c++)
            test(r,c) = Eigen::bfloat16(100 + r * 32 + c);

    // --------------------------
    // WRITE ALL 32 COLUMNS (atomic per-column)
    // --------------------------
    for (int col = 0; col < 32; col++) {
        sp.valid_in_sp2 = 1;
        sp.write_sp2 = 1;
        sp.sp_addr_sp2 = 0;
        sp.col_id_sp2 = col;
        sp.num_rows_sp2 = 32;
        sp.row_or_col_sp2 = 1; // column mode
        sp.wdata_sp2 = test.col(col);

        sp.clk = 1; sp.tick();
        sp.clk = 0; sp.tick();
    }
    // De-assert write signals
    sp.valid_in_sp2 = 0;
    sp.write_sp2 = 0;

    // --------------------------
    // ISSUE READS WHILE CAPTURING COMPLETIONS
    // --------------------------
    const int expected = 32;
    int issued = 0;
    int received = 0;
    int safety = 5000;

    Eigen::Matrix<Eigen::bfloat16, 32, 1> prev_vec; prev_vec.setZero();
    bool have_prev = false;

    while ((issued < expected || received < expected) && safety-- > 0) {
        // Issue read if needed
        if (issued < expected) {
            sp.valid_in_sp2 = 1;
            sp.write_sp2 = 0;
            sp.sp_addr_sp2 = 0;
            sp.col_id_sp2 = issued;
            sp.num_rows_sp2 = 32;
            sp.row_or_col_sp2 = 1;
            issued++;
        } else {
            sp.valid_in_sp2 = 0;
        }

        // Rising edge: capture if valid_out
        sp.clk = 1; sp.tick();

        if (sp.valid_out_sp2) {
            // Duplicate detection (helpful for debugging)
            if (have_prev && vec_equal(prev_vec, sp.rdata_sp2)) {
                std::cerr << "WARNING: duplicate vector received for column read #" << received << "\n";
            }
            prev_vec = sp.rdata_sp2;
            have_prev = true;

            write_vector_line(out, sp.rdata_sp2);
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

    // Write a row (address 10, row 5)
    sp.valid_in_sp1 = 1;
    sp.write_sp1 = 1;
    sp.sp_addr_sp1 = 10;
    sp.row_id_sp1 = 5;
    sp.num_cols_sp1 = 32;
    sp.row_or_col_sp1 = 0;

    for (int i = 0; i < 32; i++)
        sp.wdata_sp1(i) = Eigen::bfloat16(42.0f);

    sp.clk = 1; sp.tick();
    sp.clk = 0; sp.tick();

    sp.valid_in_sp1 = 0;
    sp.write_sp1 = 0;

    // Issue read
    sp.valid_in_sp1 = 1;
    sp.write_sp1 = 0;
    sp.sp_addr_sp1 = 10;
    sp.row_id_sp1 = 5;
    sp.num_cols_sp1 = 32;

    int read_cycle = sp.cycle_count;
    log << "Read issued at cycle: " << read_cycle << "\n";

    sp.clk = 1; sp.tick();
    sp.clk = 0; sp.tick();
    sp.valid_in_sp1 = 0;

    bool data_received = false;
    int cycles_until_data = 0;

    for (int i = 0; i < 40; i++) {
        sp.clk = 1; sp.tick();

        log << "Cycle " << sp.cycle_count << ": valid_out_sp1=" << (int)sp.valid_out_sp1 << "\n";
        if (sp.valid_out_sp1 && !data_received) {
            cycles_until_data = sp.cycle_count - read_cycle - 1;
            data_received = true;
            log << "valid_out_sp1 went high at cycle: " << sp.cycle_count << "\n";
            log << "Cycles from read to valid_out: " << cycles_until_data << "\n";

            bool correct = true;
            for (int j = 0; j < 32; j++) {
                float val = static_cast<float>(sp.rdata_sp1(j));
                if (val != 42.0f) {
                    correct = false;
                    log << "Data mismatch at index " << j << ": expected 42.0, got " << val << "\n";
                }
            }

            log << "Data correct: " << (correct ? "yes" : "no") << "\n";
            log << "Observed latency: " << cycles_until_data << "\n";
        }

        sp.clk = 0; sp.tick();

        if (data_received) break;
    }

    if (!data_received) {
        log << "FAIL: valid_out_sp1 never went high within 40 cycles\n";
        std::cerr << "FAIL: valid_out_sp1 never went high within 40 cycles\n";
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

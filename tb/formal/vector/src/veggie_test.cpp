#include <veggie.hpp>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cassert>

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

// Helper: create test vector with pattern
std::array<uint16_t, 32> create_test_vector(uint16_t base) {
    std::array<uint16_t, 32> vec;
    for (int i = 0; i < 32; i++) {
        vec[i] = base + i;
    }
    return vec;
}

// Helper: print vector
void print_vector(const std::array<uint16_t, 32>& vec, const std::string& prefix = "") {
    if (!prefix.empty()) std::cout << prefix;
    for (int i = 0; i < 32; i++) {
        std::cout << vec[i];
        if (i < 31) std::cout << ", ";
    }
    std::cout << "\n";
}

// ============================================================================
// Test 1: Lane Write/Read Test
// Tests the 5 write ports and 2 read ports for lanes
// ============================================================================
void test_lane_write_read(veggie& vrf) {
    std::cout << "=== Test 1: Lane Write/Read ===" << "\n";
    
    std::ofstream out("test_lane_wr.txt");
    if (!out.is_open()) {
        std::cerr << "Error: could not open test_lane_wr.txt\n";
        return;
    }

    // Initialize ALL signals
    vrf.vrf_lane_vd.fill(0);
    vrf.vrf_lane_vs.fill(0);
    vrf.vrf_lane_wen.fill(0);
    vrf.vrf_lane_ren.fill(0);
    for (auto& arr : vrf.vrf_lane_vwdata) arr.fill(0);

    // Write to 5 different registers using the 5 write ports
    std::array<uint16_t, 32> test_vecs[5];
    for (int i = 0; i < 5; i++) {
        test_vecs[i] = create_test_vector(i * 100);
    }

    // Write each register
    for (int i = 0; i < 5; i++) {
        // IMPORTANT: Clear all write enables first
        vrf.vrf_lane_wen.fill(0);
        
        // Setup THIS write
        vrf.vrf_lane_vd[i] = i;
        vrf.vrf_lane_wen[i] = 1;
        vrf.vrf_lane_vwdata[i] = test_vecs[i];
        
        // Clock
        vrf.tick();
        vrf.clk = 1; 
        vrf.tick();
        vrf.clk = 0;
    }

    // Disable all writes
    vrf.vrf_lane_wen.fill(0);

    // Read back using read port 0
    int pass_count = 0;
    for (int i = 0; i < 5; i++) {
        vrf.vrf_lane_vs[0] = i;
        vrf.vrf_lane_ren[0] = 1;
        
        vrf.clk = 0; vrf.tick();
        vrf.clk = 1; vrf.tick();
        vrf.clk = 0; vrf.tick();

        if (vrf.vfr_lane_dvalid[0]) {
            bool match = vec_equal(vrf.vrf_lane_vrdata[0], test_vecs[i]);
            out << "Read VRF[" << i << "]: " << (match ? "PASS" : "FAIL") << "\n";
            if (match) pass_count++;
            write_vector_line(out, vrf.vrf_lane_vrdata[0]);
        } else {
            out << "Read VRF[" << i << "]: FAIL (no valid)\n";
        }
    }

    vrf.vrf_lane_ren[0] = 0;

    std::cout << "Lane Write/Read: " << pass_count << "/5 tests passed\n";
    out.close();
}

// ============================================================================
// Test 2: System Array Write/Read Test
// Tests the 1 write port and 2 read ports for system array
// ============================================================================
void test_sysarr_write_read(veggie& vrf) {
    std::cout << "\n=== Test 2: System Array Write/Read ===" << "\n";
    
    std::ofstream out("test_sysarr_wr.txt");
    if (!out.is_open()) {
        std::cerr << "Error: could not open test_sysarr_wr.txt\n";
        return;
    }

    // Write to 10 different registers
    int pass_count = 0;
    for (int i = 0; i < 10; i++) {
        std::array<uint16_t, 32> test_vec = create_test_vector(1000 + i * 10);
        
        // Write
        vrf.vrf_sys_vd[0] = 10 + i;  // Write to registers 10-19
        vrf.vrf_sys_wen[0] = 1;
        vrf.vrf_sys_vwdata[0] = test_vec;

        vrf.clk = 0; vrf.tick();
        vrf.clk = 1; vrf.tick();
        vrf.clk = 0; vrf.tick();

        // Disable write
        vrf.vrf_sys_wen[0] = 0;

        // Read back using read port 0
        vrf.vrf_sys_vs[0] = 10 + i;
        vrf.vrf_sys_ren[0] = 1;

        vrf.clk = 0; vrf.tick();
        vrf.clk = 1; vrf.tick();
        vrf.clk = 0; vrf.tick();

        if (vrf.vfr_sys_dvalid[0]) {
            bool match = vec_equal(vrf.vrf_sys_vrdata[0], test_vec);
            out << "SysArr VRF[" << (10 + i) << "]: " << (match ? "PASS" : "FAIL") << "\n";
            if (match) pass_count++;
            write_vector_line(out, vrf.vrf_sys_vrdata[0]);
        } else {
            out << "SysArr VRF[" << (10 + i) << "]: FAIL (no valid)\n";
        }

        vrf.vrf_sys_ren[0] = 0;
    }

    std::cout << "SysArr Write/Read: " << pass_count << "/10 tests passed\n";
    out.close();
}

// ============================================================================
// Test 3: Scratchpad Write/Read Test
// Tests the 2 write ports and 2 read ports for scratchpad
// ============================================================================
void test_scratchpad_write_read(veggie& vrf) {
    std::cout << "\n=== Test 3: Scratchpad Write/Read ===" << "\n";
    
    std::ofstream out("test_sp_wr.txt");
    if (!out.is_open()) {
        std::cerr << "Error: could not open test_sp_wr.txt\n";
        return;
    }

    // Write to registers using both write ports
    std::array<uint16_t, 32> test_vec0 = create_test_vector(2000);
    std::array<uint16_t, 32> test_vec1 = create_test_vector(3000);

    vrf.vrf_sp_vd[0] = 20;
    vrf.vrf_sp_vd[1] = 21;
    vrf.vrf_sp_wen[0] = 1;
    vrf.vrf_sp_wen[1] = 1;
    vrf.vrf_sp_vwdata[0] = test_vec0;
    vrf.vrf_sp_vwdata[1] = test_vec1;

    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();

    // Disable writes
    vrf.vrf_sp_wen[0] = 0;
    vrf.vrf_sp_wen[1] = 0;

    // Read back using both read ports simultaneously
    vrf.vrf_sp_vs[0] = 20;
    vrf.vrf_sp_vs[1] = 21;
    vrf.vrf_sp_ren[0] = 1;
    vrf.vrf_sp_ren[1] = 1;

    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();

    int pass_count = 0;

    if (vrf.vfr_sp_dvalid[0]) {
        bool match = vec_equal(vrf.vrf_sp_vrdata[0], test_vec0);
        out << "SP VRF[20] port 0: " << (match ? "PASS" : "FAIL") << "\n";
        if (match) pass_count++;
        write_vector_line(out, vrf.vrf_sp_vrdata[0]);
    }

    if (vrf.vfr_sp_dvalid[1]) {
        bool match = vec_equal(vrf.vrf_sp_vrdata[1], test_vec1);
        out << "SP VRF[21] port 1: " << (match ? "PASS" : "FAIL") << "\n";
        if (match) pass_count++;
        write_vector_line(out, vrf.vrf_sp_vrdata[1]);
    }

    vrf.vrf_sp_ren[0] = 0;
    vrf.vrf_sp_ren[1] = 0;

    std::cout << "Scratchpad Write/Read: " << pass_count << "/2 tests passed\n";
    out.close();
}

// ============================================================================
// Test 4: Mask Register File Test
// Tests the 3 write ports and 3 read ports for masks
// ============================================================================
void test_mask_write_read(veggie& vrf) {
    std::cout << "\n=== Test 4: Mask Register File ===" << "\n";
    
    std::ofstream out("test_mask_wr.txt");
    if (!out.is_open()) {
        std::cerr << "Error: could not open test_mask_wr.txt\n";
        return;
    }

    // Write to 3 mask registers
    uint32_t test_masks[3] = {0xAAAAAAAA, 0x55555555, 0xF0F0F0F0};
    
    for (int i = 0; i < 3; i++) {
        vrf.vmrf_vd[i] = i;
        vrf.vmrf_mwen[i] = 1;
        vrf.vmrf_wdata[i] = test_masks[i];
    }

    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();

    // Disable writes
    for (int i = 0; i < 3; i++) {
        vrf.vmrf_mwen[i] = 0;
    }

    // Read back using all 3 read ports
    for (int i = 0; i < 3; i++) {
        vrf.vmrf_vs[i] = i;
        vrf.vmrf_mren[i] = 1;
    }

    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();

    int pass_count = 0;
    for (int i = 0; i < 3; i++) {
        if (vrf.vmrf_mvalid[i]) {
            bool match = (vrf.vmrf_rdata[i] == test_masks[i]);
            out << "Mask[" << i << "]: " << (match ? "PASS" : "FAIL");
            out << " (expected: 0x" << std::hex << test_masks[i];
            out << ", got: 0x" << vrf.vmrf_rdata[i] << std::dec << ")\n";
            if (match) pass_count++;
        } else {
            out << "Mask[" << i << "]: FAIL (no valid)\n";
        }
    }

    for (int i = 0; i < 3; i++) {
        vrf.vmrf_mren[i] = 0;
    }

    std::cout << "Mask Register File: " << pass_count << "/3 tests passed\n";
    out.close();
}

// ============================================================================
// Test 5: Reduction Write Test
// Tests the reduction write path
// ============================================================================
void test_reduction_write(veggie& vrf) {
    std::cout << "\n=== Test 5: Reduction Write ===" << "\n";
    
    std::ofstream out("test_reduction.txt");
    if (!out.is_open()) {
        std::cerr << "Error: could not open test_reduction.txt\n";
        return;
    }

    std::array<uint16_t, 32> reduction_vec = create_test_vector(5000);
    
    // Write via reduction path
    vrf.reduction_vd = 30;
    vrf.reduction_valid = 1;
    vrf.reduction_wdata = reduction_vec;

    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();

    vrf.reduction_valid = 0;

    // Read back using lane read port
    vrf.vrf_lane_vs[0] = 30;
    vrf.vrf_lane_ren[0] = 1;

    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();

    bool pass = false;
    if (vrf.vfr_lane_dvalid[0]) {
        pass = vec_equal(vrf.vrf_lane_vrdata[0], reduction_vec);
        out << "Reduction write to VRF[30]: " << (pass ? "PASS" : "FAIL") << "\n";
        write_vector_line(out, vrf.vrf_lane_vrdata[0]);
    } else {
        out << "Reduction write to VRF[30]: FAIL (no valid)\n";
    }

    vrf.vrf_lane_ren[0] = 0;

    std::cout << "Reduction Write: " << (pass ? "PASS" : "FAIL") << "\n";
    out.close();
}

// ============================================================================
// Test 6: Concurrent Multi-Port Access
// ============================================================================
void test_concurrent_access(veggie& vrf) {
    std::cout << "\n=== Test 6: Concurrent Multi-Port Access ===" << "\n";
    
    std::ofstream out("test_concurrent.txt");
    if (!out.is_open()) {
        std::cerr << "Error: could not open test_concurrent.txt\n";
        return;
    }

    // Write to multiple registers across different port groups
    std::array<uint16_t, 32> lane_vec = create_test_vector(100);
    std::array<uint16_t, 32> sys_vec = create_test_vector(200);
    std::array<uint16_t, 32> sp_vec = create_test_vector(300);

    vrf.vrf_lane_vd[0] = 40;
    vrf.vrf_lane_wen[0] = 1;
    vrf.vrf_lane_vwdata[0] = lane_vec;

    vrf.vrf_sys_vd[0] = 41;
    vrf.vrf_sys_wen[0] = 1;
    vrf.vrf_sys_vwdata[0] = sys_vec;

    vrf.vrf_sp_vd[0] = 42;
    vrf.vrf_sp_wen[0] = 1;
    vrf.vrf_sp_vwdata[0] = sp_vec;

    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();

    // Disable all writes
    vrf.vrf_lane_wen[0] = 0;
    vrf.vrf_sys_wen[0] = 0;
    vrf.vrf_sp_wen[0] = 0;

    // Read back from all three simultaneously
    vrf.vrf_lane_vs[0] = 40;
    vrf.vrf_lane_ren[0] = 1;

    vrf.vrf_sys_vs[0] = 41;
    vrf.vrf_sys_ren[0] = 1;

    vrf.vrf_sp_vs[0] = 42;
    vrf.vrf_sp_ren[0] = 1;

    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();

    int pass_count = 0;

    if (vrf.vfr_lane_dvalid[0] && vec_equal(vrf.vrf_lane_vrdata[0], lane_vec)) {
        out << "Concurrent lane read: PASS\n";
        pass_count++;
    } else {
        out << "Concurrent lane read: FAIL\n";
    }

    if (vrf.vfr_sys_dvalid[0] && vec_equal(vrf.vrf_sys_vrdata[0], sys_vec)) {
        out << "Concurrent sys read: PASS\n";
        pass_count++;
    } else {
        out << "Concurrent sys read: FAIL\n";
    }

    if (vrf.vfr_sp_dvalid[0] && vec_equal(vrf.vrf_sp_vrdata[0], sp_vec)) {
        out << "Concurrent sp read: PASS\n";
        pass_count++;
    } else {
        out << "Concurrent sp read: FAIL\n";
    }

    vrf.vrf_lane_ren[0] = 0;
    vrf.vrf_sys_ren[0] = 0;
    vrf.vrf_sp_ren[0] = 0;

    std::cout << "Concurrent Access: " << pass_count << "/3 tests passed\n";
    out.close();
}


// ============================================================================
// MAIN
// ============================================================================
int main() {
    std::cout << "Starting veggie testbench...\n";
    
    veggie vrf;

    // Initialize clock to 0
    vrf.clk = 0;

    // Initial reset
    vrf.rst_n = 0;
    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();
    vrf.rst_n = 1;

    std::cout << "Reset complete, starting tests...\n\n";

    test_lane_write_read(vrf);
    
    // Reset between tests
    vrf.rst_n = 0;
    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();
    vrf.rst_n = 1;

    test_sysarr_write_read(vrf);

    vrf.rst_n = 0;
    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();
    vrf.rst_n = 1;

    test_scratchpad_write_read(vrf);

    vrf.rst_n = 0;
    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();
    vrf.rst_n = 1;

    test_mask_write_read(vrf);

    vrf.rst_n = 0;
    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();
    vrf.rst_n = 1;

    test_reduction_write(vrf);

    vrf.rst_n = 0;
    vrf.clk = 0; vrf.tick();
    vrf.clk = 1; vrf.tick();
    vrf.clk = 0; vrf.tick();
    vrf.rst_n = 1;

    test_concurrent_access(vrf);

    std::cout << "\n=== All tests completed ===" << "\n";
    std::cout << "Check output files for detailed results:\n";
    std::cout << "  - test_lane_wr.txt\n";
    std::cout << "  - test_sysarr_wr.txt\n";
    std::cout << "  - test_sp_wr.txt\n";
    std::cout << "  - test_mask_wr.txt\n";
    std::cout << "  - test_reduction.txt\n";
    std::cout << "  - test_concurrent.txt\n";

    // Optionally dump entire VRF state
    try {
        vrf.dump("final_state");
        std::cout << "\nFinal VRF state dumped to ./results/final_state_results.txt\n";
    } catch (const std::exception& e) {
        std::cerr << "Error dumping VRF: " << e.what() << "\n";
    }

    return 0;
}
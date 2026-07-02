// ============================================================================
// inst_parser_dpi_pkg.sv
// SV DPI-C import declarations for all C++ model wrappers:
//   - Scheduler (inst_parser_dpi)
//   - Systolic Array (sysarray_dpi)
//   - Scratchpad (scratchpad_dpi)
//   - Veggie / VRF (veggie_dpi)
//
// Owner: Vedant Sharma
// Location: rtl/include/vector/
// ============================================================================

package inst_parser_dpi_pkg;

    // Lifecycle
    import "DPI-C" function void dpi_scheduler_init(input string program_path);
    import "DPI-C" function void dpi_scheduler_destroy();

    // Per-cycle
    import "DPI-C" function void dpi_set_ready_signals(
        input bit lane_alu_ready,
        input bit lane_mul_ready,
        input bit lane_exp_ready,
        input bit sys_ready,
        input bit sp_ready
    );
    import "DPI-C" function void dpi_scheduler_tick(input bit rst_n);

    // Completion
    import "DPI-C" function bit dpi_get_all_issued();

    // Element-by-element DPI functions
    import "DPI-C" function void dpi_veggie_write_vector_elem(
        input byte unsigned vr_idx, input int elem_idx, input shortint unsigned val);
    import "DPI-C" function shortint unsigned dpi_veggie_read_vector_elem(
        input byte unsigned vr_idx, input int elem_idx);
    import "DPI-C" function void dpi_scratchpad_write_elem(
        input int port, input int elem, input shortint unsigned val);
    import "DPI-C" function shortint unsigned dpi_scratchpad_read_elem(
        input int port, input int elem);
    import "DPI-C" function void dpi_scratchpad_preload_row_val(
        input int sp_id, input byte unsigned addr, input byte unsigned row_id,
        input byte unsigned num_cols, input shortint unsigned val);
    import "DPI-C" function byte unsigned dpi_get_sp_wen(input int idx);
    import "DPI-C" function shortint unsigned dpi_get_lane_v2_broadcast_elem(input int idx, input int elem);
    import "DPI-C" function void dpi_sysarr_set_weight_elem(input int elem, input shortint unsigned val);
    import "DPI-C" function void dpi_sysarr_set_activation_elem(input int elem, input shortint unsigned val);
    import "DPI-C" function void dpi_sysarr_set_weight_valid(input bit valid);
    import "DPI-C" function void dpi_sysarr_set_activation_valid(input bit valid);
    import "DPI-C" function shortint unsigned dpi_sysarr_get_output_elem(input int elem);

    // Lane signals (idx = 0 or 1)
    import "DPI-C" function bit           dpi_get_lane_valid_in    (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_lane_vd          (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_lane_fu_sel      (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_lane_alu_op      (input int idx);
    import "DPI-C" function bit           dpi_get_lane_broadcast_v2(input int idx);
    import "DPI-C" function bit           dpi_get_lane_broadcast   (input int idx);
    import "DPI-C" function bit           dpi_get_lane_clear       (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_lane_imm8        (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_lane_imm5        (input int idx);
    import "DPI-C" function bit           dpi_get_lane_rm          (input int idx);
    import "DPI-C" function void dpi_get_lane_v2_broadcast(
        input int idx,
        output bit [15:0] vec [0:31]
    );

    // Reduction
    import "DPI-C" function bit           dpi_get_reduction_mode();
    import "DPI-C" function byte unsigned  dpi_get_reduction_imm();

    // Systolic scheduler signals
    import "DPI-C" function bit           dpi_get_sys_valid_in();
    import "DPI-C" function byte unsigned  dpi_get_sys_vd();
    import "DPI-C" function bit           dpi_get_sys_weight();
    import "DPI-C" function byte unsigned  dpi_get_sys_vs1();
    import "DPI-C" function byte unsigned  dpi_get_sys_vs2();
    import "DPI-C" function bit           dpi_get_sys_ren(input int idx);

    // Scratchpad scheduler signals (idx = 0 or 1)
    import "DPI-C" function bit           dpi_get_sp_valid_in (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_sp_vd       (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_sp_rs1      (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_sp_num_cols (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_sp_sid      (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_sp_row_num  (input int idx);

    // Veggie VRF read control (idx = 0 or 1)
    import "DPI-C" function byte unsigned  dpi_get_veggie_vs1  (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_veggie_vs2  (input int idx);
    import "DPI-C" function byte unsigned  dpi_get_veggie_rs1  (input int idx);
    import "DPI-C" function bit           dpi_get_veggie_ren  (input int idx);

    // Mask signals (idx = 0, 1, or 2)
    import "DPI-C" function byte unsigned  dpi_get_mask_vmrf_vs  (input int idx);
    import "DPI-C" function bit           dpi_get_mask_vmrf_mren(input int idx);

    import "DPI-C" function void dpi_sysarr_init();
    import "DPI-C" function void dpi_sysarr_destroy();

    import "DPI-C" function void dpi_sysarr_set_weight(
        input bit [15:0] vec [0:31],
        input bit valid
    );
    import "DPI-C" function void dpi_sysarr_set_activation(
        input bit [15:0] vec [0:31],
        input bit valid
    );
    import "DPI-C" function void dpi_sysarr_set_psum(
        input bit [15:0] vec [0:31],
        input bit valid
    );

    import "DPI-C" function void dpi_sysarr_tick(input bit rst_n);

    import "DPI-C" function bit  dpi_sysarr_get_valid();
    import "DPI-C" function bit  dpi_sysarr_get_ready();
    import "DPI-C" function void dpi_sysarr_get_output(
        output bit [15:0] vec [0:31]
    );
    import "DPI-C" function void dpi_sysarr_clear_psums();

    import "DPI-C" function void dpi_scratchpad_init();
    import "DPI-C" function void dpi_scratchpad_destroy();

    import "DPI-C" function void dpi_scratchpad_set_request(
        input int           port,
        input bit           valid,
        input bit           wen,
        input byte unsigned addr,
        input byte unsigned row_id,
        input byte unsigned col_id,
        input byte unsigned num_rows,
        input byte unsigned num_cols,
        input bit           row_or_col
    );
    import "DPI-C" function void dpi_scratchpad_set_wdata(
        input int port,
        input bit [15:0] vec [0:31]
    );

    import "DPI-C" function void dpi_scratchpad_tick(input bit rst_n);

    import "DPI-C" function bit  dpi_scratchpad_get_valid(input int port);
    import "DPI-C" function void dpi_scratchpad_get_rdata(
        input int port,
        output bit [15:0] vec [0:31]
    );

    import "DPI-C" function void dpi_veggie_init();
    import "DPI-C" function void dpi_veggie_destroy();
    import "DPI-C" function void dpi_veggie_tick(input bit rst_n);

    // Lane ports
    import "DPI-C" function void dpi_veggie_set_lane_vs  (input int idx, input byte unsigned vs);
    import "DPI-C" function void dpi_veggie_set_lane_ren (input int idx, input bit ren);
    import "DPI-C" function void dpi_veggie_set_lane_vd  (input int idx, input byte unsigned vd);
    import "DPI-C" function void dpi_veggie_set_lane_wen (input int idx, input bit wen);
    import "DPI-C" function void dpi_veggie_set_lane_wdata(input int idx, input bit [15:0] vec [0:31]);
    import "DPI-C" function bit  dpi_veggie_get_lane_valid(input int idx);
    import "DPI-C" function void dpi_veggie_get_lane_rdata(input int idx, output bit [15:0] vec [0:31]);

    // Sys ports
    import "DPI-C" function void dpi_veggie_set_sys_vs   (input int idx, input byte unsigned vs);
    import "DPI-C" function void dpi_veggie_set_sys_ren  (input int idx, input bit ren);
    import "DPI-C" function void dpi_veggie_set_sys_vd   (input int idx, input byte unsigned vd);
    import "DPI-C" function void dpi_veggie_set_sys_wen  (input int idx, input bit wen);
    import "DPI-C" function void dpi_veggie_set_sys_wdata(input int idx, input bit [15:0] vec [0:31]);
    import "DPI-C" function bit  dpi_veggie_get_sys_valid(input int idx);
    import "DPI-C" function void dpi_veggie_get_sys_rdata(input int idx, output bit [15:0] vec [0:31]);

    // SP ports
    import "DPI-C" function void dpi_veggie_set_sp_vs    (input int idx, input byte unsigned vs);
    import "DPI-C" function void dpi_veggie_set_sp_ren   (input int idx, input bit ren);
    import "DPI-C" function void dpi_veggie_set_sp_vd    (input int idx, input byte unsigned vd);
    import "DPI-C" function void dpi_veggie_set_sp_wen   (input int idx, input bit wen);
    import "DPI-C" function void dpi_veggie_set_sp_wdata (input int idx, input bit [15:0] vec [0:31]);
    import "DPI-C" function bit  dpi_veggie_get_sp_valid (input int idx);
    import "DPI-C" function void dpi_veggie_get_sp_rdata (input int idx, output bit [15:0] vec [0:31]);

    // Mask ports (idx = 0, 1, or 2)
    import "DPI-C" function void         dpi_veggie_set_mask_vs   (input int idx, input byte unsigned vs);
    import "DPI-C" function void         dpi_veggie_set_mask_ren  (input int idx, input bit ren);
    import "DPI-C" function void         dpi_veggie_set_mask_vd   (input int idx, input byte unsigned vd);
    import "DPI-C" function void         dpi_veggie_set_mask_wen  (input int idx, input bit wen);
    import "DPI-C" function void         dpi_veggie_set_mask_wdata(input int idx, input int unsigned data);
    import "DPI-C" function bit          dpi_veggie_get_mask_valid(input int idx);
    import "DPI-C" function int unsigned dpi_veggie_get_mask_rdata(input int idx);

    // Reduction write
    import "DPI-C" function void dpi_veggie_set_reduction(
        input byte unsigned vd,
        input bit valid,
        input bit [15:0] vec [0:31]
    );

    // Direct access (preload at init)
    import "DPI-C" function void         dpi_veggie_write_vector(input byte unsigned idx, input bit [15:0] vec [0:31]);
    import "DPI-C" function void         dpi_veggie_read_vector (input byte unsigned idx, output bit [15:0] vec [0:31]);
    import "DPI-C" function void         dpi_veggie_write_mask  (input byte unsigned idx, input int unsigned data);
    import "DPI-C" function int unsigned dpi_veggie_read_mask   (input byte unsigned idx);

    // Utility
    import "DPI-C" function bit dpi_veggie_get_ready();

endpackage
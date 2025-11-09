/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

module swizzle (scpad_if.swizzle swizz);

    import scpad_pkg::*;

    logic [ROW_IDX_WIDTH-1:0] abs_row;

    always_comb begin
        swizz.swizz_res.xbar_desc.valid_mask = '0;
        swizz.swizz_res.xbar_desc.shift_mask = '0;
        swizz.swizz_res.xbar_desc.slot_mask  = '0;

        for (int bank_id = 0; bank_id < NUM_COLS; bank_id++) begin
            if (swizz.swizz_req.row_or_col) begin // row-major read
                abs_row = swizz.swizz_req.spad_addr + swizz.swizz_req.row_id;
                swizz.swizz_res.xbar_desc.valid_mask[bank_id] = (bank_id <= swizz.swizz_req.num_cols);
                swizz.swizz_res.xbar_desc.shift_mask[bank_id] = COL_IDX_WIDTH'((bank_id ^ (abs_row & (NUM_COLS-1))) & (NUM_COLS-1));
                swizz.swizz_res.xbar_desc.slot_mask[bank_id]  = abs_row;
            end else begin
                abs_row = swizz.swizz_req.spad_addr + ROW_IDX_WIDTH'(bank_id);
                swizz.swizz_res.xbar_desc.valid_mask[bank_id] = (bank_id <= swizz.swizz_req.num_rows);
                swizz.swizz_res.xbar_desc.shift_mask[bank_id] = COL_IDX_WIDTH'((swizz.swizz_req.col_id ^ (abs_row & (NUM_COLS-1))) & (NUM_COLS-1));
                swizz.swizz_res.xbar_desc.slot_mask[bank_id]  = abs_row;
            end
        end
    end

endmodule
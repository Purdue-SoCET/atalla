/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

module swizzle(scpad_if.swizzle swizz);

    import scpad_pkg::*;

    logic  msb;
    logic [ROW_IDX_WIDTH-1:0]  abs_row;
    logic [COL_IDX_WIDTH-1:0]  base_low;
    logic [COL_IDX_WIDTH-2:0] base0;
    logic [COL_IDX_WIDTH-2:0]  canon_base;
    logic [COL_IDX_WIDTH-1:0]  canon_col;

    localparam int H = (NUM_COLS >> 1); 

    always_comb begin
        swizz.swizz_res.xbar_desc.valid_mask = '0;
        swizz.swizz_res.xbar_desc.shift_mask = '0;
        swizz.swizz_res.xbar_desc.slot_mask  = '0;
        swizz.swizz_res.xbar_desc.rom_id = '0;

        if (swizz.swizz_req.row_or_col) begin
            abs_row = swizz.swizz_req.spad_addr + swizz.swizz_req.row_id;
            canon_base = '0;
            canon_col  = abs_row[COL_IDX_WIDTH-1:0];

        end else begin
            base_low = swizz.swizz_req.spad_addr[COL_IDX_WIDTH-1:0];
            base0 = base_low[COL_IDX_WIDTH-2:0];
            msb = base_low[COL_IDX_WIDTH-1];

            if (!msb) begin
                // msb == 0: canon_base = base_low, canon_col = col_id
                canon_base = base_low[COL_IDX_WIDTH-2:0];
                canon_col  = swizz.swizz_req.col_id;
            end else begin
                // msb == 1: canon_base = base0, canon_col = col_id ^ H
                canon_base = base0;
                canon_col  = swizz.swizz_req.col_id ^ COL_IDX_WIDTH'(H);
            end
        end

        swizz.swizz_res.xbar_desc.rom_id = {canon_base, canon_col};

        for (int bank_id = 0; bank_id < NUM_COLS; bank_id++) begin
            if (swizz.swizz_req.row_or_col) begin // row-major read
                abs_row = swizz.swizz_req.spad_addr + swizz.swizz_req.row_id;
                swizz.swizz_res.xbar_desc.valid_mask[bank_id] = (bank_id < swizz.swizz_req.num_cols);  
                swizz.swizz_res.xbar_desc.shift_mask[bank_id] = COL_IDX_WIDTH'((bank_id ^ (abs_row & (NUM_COLS-1))) & (NUM_COLS-1));
                swizz.swizz_res.xbar_desc.slot_mask[bank_id]  = abs_row;

            end else begin
                abs_row = swizz.swizz_req.spad_addr + ROW_IDX_WIDTH'(bank_id);
                swizz.swizz_res.xbar_desc.valid_mask[bank_id] = (bank_id < swizz.swizz_req.num_rows); 
                swizz.swizz_res.xbar_desc.shift_mask[bank_id] = COL_IDX_WIDTH'((swizz.swizz_req.col_id ^ (abs_row & (NUM_COLS-1))) & (NUM_COLS-1));
                swizz.swizz_res.xbar_desc.slot_mask[bank_id]  = abs_row;
            end
        end
    end


endmodule
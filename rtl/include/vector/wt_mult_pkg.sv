`ifndef WT_MULT_PKG
`define WT_MULT_PKG

package wt_mult_pkg;
    function int num_reduction_layers(int width, bit sign);
        // See reduction_tree.py for code to generate this
        /* verilator public */
        if (width < 3) begin
            return 0;
        end else if (width < 4) begin
            return 1;
        end else if (width < 5) begin
            return 3;
        end else if (width < 7) begin
            return 4;
        end else if (width < 10) begin
            return 5;
        end else if (width < 14) begin
            return 6;
        end else if (width < 21) begin
            return (width == 20 && sign) ? 8 : 7;
        end else if (width < 30) begin
            return 8;
        end else if (width < 43) begin
            return 9;
        end else if (width < 64) begin
            return 10;
        end else if (width < 65) begin
            return 11;
        end else begin
            assert(width <= 64) else $error("max_width should be less than 64");
        end
    endfunction

    function int wt_delay(int width, bit sign, int stage_depth, bit merge_prods_reduce, bit merge_reduce_final);
        /* verilator public */
        return int'(num_reduction_layers(width, sign) / stage_depth) +
            !merge_prods_reduce + !merge_reduce_final;
    endfunction
endpackage

`endif

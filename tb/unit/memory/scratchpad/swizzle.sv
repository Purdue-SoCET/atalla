`timescale 1ps/1ps

`include "scpad_if.sv"
import scpad_pkg::*;
import golden_swizzle_pkg::*;

module swizzle_tb;

    localparam CLK_PERIOD = 10; 
    
    logic clk, n_rst;

    always #(CLK_PERIOD/2) clk = ~clk;

    scpad_if sif(clk, n_rst);
    
    head #(.IDX(0)) DUT (sif);

    initial begin
        n_rst = 0;
        repeat (5) @(posedge clk);
        n_rst = 1;
    end

    string fname, wavepath; 
    getenv("WAVEPATH", wavepath);
    $sformat(fname, "%s/swizzle_tb.vcd", wavepath); 

    // initial begin 
    //     $dumpfile(fname);
    //     $dumpvars(0);
    // end 

    test PROG (.swizz(sif.swizz)); 

    initial begin
        #(10_000 * CLK_PERIOD) $fatal(1, "[TB] Timeout");
    end

endmodule

// Here is where the logic lives. 
program test (scpad_if.swizzle swizz);

    task automatic check_swizzle_once(scpad_if.swizzle swizz_if);
      byte unsigned g_valid[MAX_LANES];
      int unsigned  g_shift[MAX_LANES];
      int unsigned  g_slot [MAX_LANES];
      int unsigned  g_rom;

      int rc = dpi_swizzle_rtl_equivalent(
        swizz_if.swizz_req.row_or_col,
        swizz_if.swizz_req.spad_addr,
        swizz_if.swizz_req.num_rows,
        swizz_if.swizz_req.num_cols,
        swizz_if.swizz_req.row_id,
        swizz_if.swizz_req.col_id,
        g_valid, g_shift, g_slot, g_rom
      );
      assert(rc==0) else $fatal("DPI error rc=%0d", rc);

      // Compare rom_id
      assert(swizz_if.swizz_res.xbar_desc.rom_id == g_rom)
        else $fatal("rom_id mismatch rtl=%0d golden=%0d", swizz_if.swizz_res.xbar_desc.rom_id, g_rom);

      // Compare arrays
      for (int i = 0; i < MAX_LANES; i++) begin
        assert(swizz_if.swizz_res.xbar_desc.valid_mask[i] == g_valid[i])
          else $fatal("valid mismatch i=%0d rtl=%0d golden=%0d", i, swizz_if.swizz_res.xbar_desc.valid_mask[i], g_valid[i]);

        assert(swizz_if.swizz_res.xbar_desc.shift_mask[i] == g_shift[i])
          else $fatal("shift mismatch i=%0d rtl=%0d golden=%0d", i, swizz_if.swizz_res.xbar_desc.shift_mask[i], g_shift[i]);

        assert(swizz_if.swizz_res.xbar_desc.slot_mask[i] == g_slot[i])
          else $fatal("slot mismatch i=%0d rtl=%0d golden=%0d", i, swizz_if.swizz_res.xbar_desc.slot_mask[i], g_slot[i]);
      end
    endtask

    initial begin 

        <Code here> 

        $display("[TB] Head TB PASSED");
        $finish(0);

    end 

endprogram
`include "dram_pkg.svh"
`include "ddr_controller_if.sv"

module nb_wdata_queue_prop
    import dram_pkg::*;
(
    input logic CLK,
    input logic nRST,
    input logic [ID_NUM-1:0] bwvalid,
    input logic [$clog2(ID_NUM)-1:0] bw_arb,
    input logic bwready, 
    input logic be_write,
    input logic [$clog2(ID_NUM)-1:0] be_wid,
    input logic [ID_NUM-1:0] ddr_we 
    );

/*
    covergroup wdq_cg @(posedge CLK) // TODO: FIX COVERPOINTS 
        awdata : coverpoint {wstrb, wdq_slot, wready};
        barb_wdata : coverpoint {be_wid, be_write};
        bresp : coverpoint {bwready, bwvalid, bwresp, bwid};
        
    endgroup
*/
    //wdq_cg wdqcg;
    logic lock;
    initial begin
	lock = 1;	
	while (!nRST) begin
	 @(posedge CLK);
 	end
	lock = 1'b0;
    end

   

    property AXI_wdata_handshake(int i); //ensures proper handshake.
        @(posedge CLK) disable iff (!nRST || lock)
        (bwvalid[i] && bwready && (bw_arb == i)) |=> !bwvalid[i];
    endproperty

    property AXI_wdata_wait(int i); //ensures proper handshake.
        @(posedge CLK) disable iff (!nRST || lock)
        (bwvalid[i] && !(bwready && (bw_arb == i))) |=>   (bwvalid[i]); 
    endproperty

    property AXI_wdata_handshake_cycle(int i); //ensures proper handshake.
        @(posedge CLK) disable iff (!nRST || lock)
        (bwvalid[i] && bwready ) |-> bwvalid[i]; 
    endproperty

    property wdata_tCWL(int i); //ensures CWL parameter upheld
        @(posedge CLK) disable iff (!nRST || lock)
        (be_write && (be_wid == i) ) |-> (!ddr_we[i])[*(tCWL + 'b1)];
    endproperty

    property AXI_wdata_response(int i); //ensures response is ready from wdata queue after data sent.
        @(posedge CLK) disable iff (!nRST|| lock)
        $fell(ddr_we[i]) |-> bwvalid[i]; 
    endproperty 

    property ddr_burst_arbitration;

        @(posedge CLK) disable iff (!nRST)
        $onehot0(ddr_we);

    endproperty
    genvar i;
    generate 
  
    	for(i = 0; i < ID_NUM; i++) begin
    		assert_handshake_valid : assert property (AXI_wdata_handshake(i))
	    		else $error("valid did not go low after handshake for wdata queue %d", i);
		assert_handshake_wait : assert property (AXI_wdata_wait(i))
			else $error("bwvalid not stable when waiting for handshake, queue %d", i);
		assert_handshake_cycle : assert property (AXI_wdata_handshake_cycle(i))
			else $error("bwvalid not stable during handshake cycle, queue %d", i);
		assert_tCWL_param : assert property (wdata_tCWL( i)) 
			else $error("CWL timing parameter not upheld, queue %d", i);
		assert_bresp : assert property (AXI_wdata_response( i))
			else $error("bwvalid not high after transmitting data, queue %d", i);	
    	end
    endgenerate
        
endmodule 


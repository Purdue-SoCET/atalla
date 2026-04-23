
`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

import dram_pkg::*;

module nb_rdata_queue  #(Q_ID = 0, ID_NUM = 8) (
    input logic CLK, CLKx2,  nRST,
    logic rready, logic rid, 
    inout wire DQS_t, wire DQS_c, wire [63:0] DQ, wire [7:0] DM_n 
    , output logic rvalid, logic [63:0] rdata,  logic rlast,
    logic [1:0] rresp, logic preamble_detected, logic rd_pop_id
  );  

//AXI clock domain bursting control.
logic clear_axi;
logic cnt_en_axi;
logic rollover_axi;

flex_counter #(.SIZE(4'd3)) BEAT_CNT_AXI (CLK, nRST, clear_axi, cnt_en_axi, 4'd7, rollover_axi);

typedef enum logic [1:0] {IDLE, VALID, BURSTING} axi_rdata_state_t;

axi_rdata_state_t raxi_state, raxi_state_next;


  //DRAM clock domain control states.
  typedef enum logic [5:0] {IDLE, PREAMBLE ,  RECEIVING, BURST_DONE_POP0, BURST_DONE_POP1, BURST_DONE_POP2, BURST_DONE0, BURST_DONE1, BURST_DONE_POP2} rdata_ctrl_state_t;
  
  rdata_ctrl_state_t rcv_ctrl;
  rdata_ctrl_state_t rcv_ctrl_next;
  

  parameter DEPTH = 8; 
  parameter PTR_W = $clog2(DEPTH); 
  //register file (flip flops that store the data/metadata)
  logic [DEPTH-1:0][63:0] regs;
  //pointers
  logic [PTR_W-1:0] dram_ptr;
  logic [PTR_W-1:0] read_ptr;
  logic [PTR_W-1:0] dram_ptr_next;
  logic [PTR_W-1:0] read_ptr_next;
  //intermediate
  logic full;
  logic empty;
  //fsm states
  typedef enum logic [1:0] {EMPTY, ACTIVE, FULL} fifo_state_t;
  fifo_state_t next_fifo_state;
  fifo_state_t fifo_state;

  logic burst_done; //signals burst is done (FROM_DRAM).
  logic burst_done_unsynch; //synced to dram clock domain (FROM_DRAM).
  logic preamble_detected_unsynch; //synced to dram clock domain.
  logic rd_pop_id_unsynch; //synced to dram clock domain.
  logic ren; //enabling read bursts to AXI.
  logic clear_dram; //clears beat counter for bursts (dram).
  logic cnt_en_dram; //enable signal for beat counter (dran).
  logic rollover_dram; //rollover of beat counter (dram).
  
  //reg file logic
	

  always_ff @ (posedge CLKx2, negedge nRST) begin
    
    if(!nRST) begin
      for(int i = 0; i < DEPTH; i++)
        regs[i] <= 'b0;
    end else if(rcv_ctrl == RECEIVING)
      regs[dram_ptr] <= DQ;
    else

  end

  
  
  //write pointer logic
  
  	//regs for pointers
  always_ff @(posedge CLK, negedge nRST) begin
    if(!nRST) begin
      read_ptr <= {PTR_W{1'b0}};
    end else begin
      read_ptr <= read_ptr_next;
    end
  end

  always_ff@(posedge CLKx2, negedge nRST) begin
    if(!nRST) begin
      dram_ptr <= {PTR_W{1'b0}};
    end else begin
      dram_ptr <= dram_ptr_next; 
    end

  end
  
  //TODO fix this read pointer increment logics
  always_comb begin : WRITE_PTR_NEXT

    if(raxi_state == BURSTING) begin

        read_ptr_next = read_ptr + 'b1;

    end else begin
        read_ptr_next = read_ptr;
    end

  end

  assign dram_ptr_next = (rcv_ctrl == RECEIVING) ? dram_ptr + 'b1 : dram_ptr; 
  

    
  //fsm for everything full or empty
  
  always_ff @(posedge CLK, negedge nRST) begin
    if(!nRST)
      fifo_state <= EMPTY;
    else
      fifo_state <= next_fifo_state;
  end
  
  //logic [255:0] one;
  //assign one = 'b1;
  logic [PTR_W-1:0] inc_r_ptr;
  logic [PTR_W-1:0] inc_w_ptr;

  assign inc_r_ptr = read_ptr + 'b1;
  assign inc_w_ptr = dram_ptr + 'b1;
  
  //TODO fix internal states here.
  always_comb begin : FSM_NEXT_STATE
    
    case(fifo_state)
      
      EMPTY: begin
        if(rready)
          next_fifo_state = ACTIVE;
        else
          next_fifo_state = EMPTY;
      end
      
      ACTIVE: begin
        //if( && wen)
          //next_fifo_state = ACTIVE;
        if(burst_done)
          next_fifo_state = FULL;
        else if(rollover_axi && (inc_r_ptr == write_ptr))
          next_fifo_state = EMPTY;
        else
          next_fifo_state = ACTIVE;
      end
      
      FULL: begin
        if(rready) //TODO and this one.
          next_fifo_state = ACTIVE;
        else if(burst_done)
          next_fifo_state = FULL;
        else
          next_fifo_state = FULL;
      end
      default: begin
        next_fifo_state = EMPTY;
      end
      
    endcase
    
  end
  
  always_comb begin : FSM_OUTPUTS
    
    case(fifo_state)
      EMPTY: begin
        full = 1'b0;
        empty = 1'b1;
      end
      ACTIVE : begin
        full = 1'b0;
        empty = 1'b0;
      end
      FULL : begin
      	full = 1'b1;
      	empty = 1'b0;
      end
      default: begin
        full = 1'b0;
        empty = 1'b0;
      end
    endcase
  end

//   assign full_o = full;
//   assign empty_o = empty;

//Below is some edge detection logic for the DQS_t signal to detect the read preamble.
logic DQS_t_prev;
logic edge_detected;
always_ff @(posedge CLKx2, negedge nRST) begin
  if(!nRST) begin
    DQS_t_prev <= 1'bz;
  end else begin
    DQS_t_prev <= DQS_t;
  end
end

always_comb begin : EDGE_DET
  edge_detected = 1'b0;
  if( (DQS_t_prev === 1'bz)  && (DQS_t === 1'b0)) 
    edge_detected = 1'b1;

end
  

  
  flex_counter #(.SIZE(4'd3)) BEAT_CNT_DRAM (CLKx2, nRST, clear_dram, cnt_en_dram, 4'd7, rollover_dram);


  always_comb begin : NEXT_RDATA_CTRL
    
    rcv_ctrl_next = rcv_ctrl;
  case(rcv_ctrl)

	IDLE: begin
		if( (rid == Q_ID) && edge_detected) 
			rcv_cntrl_next = PREAMBLE; 
		else 
			rcv_ctrl_next = IDLE;
	  end
	PREAMBLE: begin 
    rcv_ctrl_next = RECEIVING;
	end	
  
  RECEIVING: begin
    if(rollover)
      rcv_ctrl_next = BURST_DONE_POP0;
  end
	BURST_DONE_POP0: begin
    rcv_ctrl_next = BURST_DONE_POP1;
	end
  
  BURST_DONE_POP1: begin
    rcv_ctrl_next = BURST_DONE_POP2; 
  end
  BURST_DONE_POP2: begin
    rcv_ctrl_next = BURST_DONE0;
  end
	BURST_DONE0: begin 
    rcv_ctrl_next = BURST_DONE1;
	end
  BURST_DONE1: begin
    rcv_ctrl_next = BURST_DONE2;
  end
  BURST_DONE2: begin
    rcv_ctrl_next = IDLE;
  end

  endcase

  end

  always_ff @(posedge CLKx2, negedge nRST) begin

    if(!nRST) begin
      rcv_ctrl <= IDLE;
    end else begin
      rcv_ctrl <= rcv_ctrl_next;
    end

  end




always_comb begin : RCV_CTRL_OUT

    clear_dram = 'b1;
    cnt_en_dram = 'b0;
    preamble_detected_unsynch = 1'b0;
    rd_pop_id_unsynch = 1'b0;
    burst_done_unsynch = 1'b0;
 case(rcv_ctrl)
	PREAMBLE: begin 
		preamble_detected_unsynch = 1'b1;
	end
	RECEIVING: begin
		clear_dram = 'b0; 
		cnt_en_dram = 'b1; 
    preamble_detected_unsynch = 1'b1;
	end
    BURST_DONE_POP0, BURST_DONE_POP1, BURST_DONE_POP2  : rd_pop_id_unsynch = 'b1;
    BURST_DONE0, BURST_DONE1, BURST_DONE2 : burst_done_unsynch = 1'b1; 
 endcase

  end
  
//synchronizers for the three unsynchronized signals.
always_ff @(posedge CLK, negedge nRST) begin
  if(!nRST) begin
    preamble_detected1 <= 1'b0;
    preamble_detected <= 1'b0;
    rd_pop_id1 <= 1'b0;
    rd_pop_id <= 1'b0;
    burst_done1 <= 1'b0;
    burst_done <= 1'b0; 
  end else begin
    preamble_detected1 <= preamble_detected_unsynch;
    preamble_detected <= preamble_detected1;
    rd_pop_id1 <= rd_pop_id_unsynch;
    rd_pop_id <= rd_pop_id1;
    burst_done1 <= burst_done_unsynch;
    burst_done <= burst_done1;

  end

end

//Logic for controlling bursts into axi rdata channel.
logic clear_axi;
logic cnt_en_axi;
logic rollover_axi;

flex_counter #(.SIZE(4'd3)) BEAT_CNT_AXI (CLK, nRST, clear_axi, cnt_en_axi, 4'd7, rollover_axi);

typedef enum logic [1:0] {IDLE, VALID, BURSTING} axi_rdata_state_t;

axi_rdata_state_t raxi_state, raxi_state_next;

always_ff @(posedge CLK, negedge nRST) begin
  if(!nRST) begin
    raxi_state <= IDLE;
  end else begin
    raxi_state <= raxi_state_next;
  end
end

always_comb begin : AXI_STATE_NEXT

  raxi_state_next = raxi_state;
  case(raxi_state)

    IDLE : begin
      if(burst_done) begin
        raxi_state_next = VALID;
      end else begin
        raxi_state_next = IDLE;
      end
    end
    VALID : begin
      if(rready) begin
        raxi_state_next = BURSTING;
      end else begin
        raxi_state_next = VALID;
      end
    end
    BURSTING: begin
      if(rollover_axi) begin
        raxi_state_next = IDLE;
      end else begin
        raxi_state_next = BURSTING;
      end
    end

  endcase


end

always_comb begin : AXI_STATE_OUTPUTS

  case(raxi_state)

    rvalid = 1'b0;
    rlast = 1'b0;
    rresp = 'b0;
    VALID: begin
      rvalid = 1'b1;
    end
    BURSTING: begin
      rvalid = 1'b1;
      rlast = rollover_axi;
    end

  endcase

end

assign rdata = regs[read_ptr];



endmodule
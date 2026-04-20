
`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

import dram_pkg::*;

module nb_wdata_queue  #(Q_ID = 0, ID_NUM = 8) (
    input logic CLK, nRST,
    input wdq_slot_t wdq_slot, logic bwready, logic wvalid, logic wlast, logic [$clog2(ID_NUM)-1:0] be_wid, logic be_write, 
    logic [$clog2(ID_NUM)-1:0] bw_arb , output logic wready, bwvalid, logic [1:0] bwresp, logic [$clog2(ID_NUM)-1:0] bwid, 
    logic [63:0] ddr_wdata_data, logic ddr_wdata_en, logic [7:0] ddr_wdata_mask, logic ddr_we
  );  

    
  


  typedef struct packed {
    logic [63:0] wdata;
    logic [7:0] wstrb;
    logic wvalid; 
  } DATA_Q_Slot_t;

  DATA_Q_Slot_t data_in;
  parameter DEPTH = 8; 
  parameter PTR_W = $clog2(DEPTH); 
  //register file (flip flops that store the data/metadata)
  DATA_Q_Slot_t [DEPTH-1:0] regs;
  //pointers
  logic [PTR_W-1:0] dram_ptr;
  logic [PTR_W-1:0] write_ptr;
  logic [PTR_W-1:0] dram_ptr_next;
  logic [PTR_W-1:0] write_ptr_next;
  //intermediate
  logic full;
  logic empty;
  //fsm states
  typedef enum logic [1:0] {EMPTY, ACTIVE, FULL} fifo_state_t;
  fifo_state_t next_fifo_state;
  fifo_state_t fifo_state;

  logic wen; //write enable for wdata queue to fifo.
  logic clear; //clears beat counter for bursts.
  logic cnt_en; //enable signal for beat counter.
  logic rollover; //rollover of beat counter.
  
  //reg file logic
	
  always_ff @ (posedge CLK, negedge nRST) begin
    
    if(!nRST) begin
      for(int i = 0; i < DEPTH; i++)
        regs[i] <= DATA_Q_Slot_t'({ 32'b0, 8'b1111_1111, 1'b0});
    end else if(wen)
      regs[dram_ptr] <= data_in;
    else
      regs[write_ptr] <= data_in; 
    
  end
  
  //write pointer logic
  
  	//regs for pointers
  always_ff @(posedge CLK, negedge nRST) begin
    if(!nRST) begin
      dram_ptr <= {PTR_W{1'b0}};
      write_ptr <= {PTR_W{1'b0}};
    end else begin
      dram_ptr <= dram_ptr_next;
      write_ptr <= write_ptr_next;
    end
  end
  
  //assign write_ptr_next = (wvalid && !full) ? write_ptr + 'b1 : write_ptr;
  always_comb begin : WRITE_PTR_NEXT

    if(wvalid && (wdq_slot.wid == Q_ID) && !full && !wlast) begin

        write_ptr_next = write_ptr + 32'b1;

    end else if(wvalid && (wdq_slot.wid == Q_ID) && !full && wlast) begin
        write_ptr_next = write_ptr + ('d8 - wdq_slot.wlen);
    end else begin
        write_ptr_next = write_ptr;
    end

  end


  assign dram_ptr_next = (wen && !empty) ? dram_ptr + 'b1 : dram_ptr; 
  
  //push data logic
  
    
  //assign data_in = () ? {wdata, wstrb, wvalid} : regs[write_ptr];  
  always_comb begin : DATA_NEXT

    if(wvalid && (wdq_slot.wid == Q_ID) && !full) begin
        data_in = DATA_Q_Slot_t'({wdq_slot.wdata, wdq_slot.wstrb, wvalid} );
    end else if(wen)
        data_in = DATA_Q_Slot_t'({ regs[dram_ptr].wdata, 8'b1111_1111, regs[dram_ptr].wvalid });
    else 
	data_in = regs[write_ptr];

  end
  
  //pop data logic
  
  assign ddr_wdata_data = regs[dram_ptr].wdata; 
//  assign ddr_wdata_en = regs[dram_ptr].wvalid;
  assign ddr_wdata_mask = regs[dram_ptr].wstrb;
  
  //fsm for everything full or empty
  
  always_ff @(posedge CLK, negedge nRST) begin
    if(!nRST)
      fifo_state <= EMPTY;
    else
      fifo_state <= next_fifo_state;
  end
  
  //logic [255:0] one;
  //assign one = 'b1;
  logic [PTR_W-1:0] inc_w_ptr;
  logic [PTR_W-1:0] inc_r_ptr;

  assign inc_w_ptr = write_ptr + 'b1;
  assign inc_r_ptr = dram_ptr + 'b1;
  
  always_comb begin : FSM_NEXT_STATE
    
    case(fifo_state)
      
      EMPTY: begin
        if(wvalid)
          next_fifo_state = ACTIVE;
        else if(wen)
          next_fifo_state = EMPTY;
        else
          next_fifo_state = EMPTY;
      end
      
      ACTIVE: begin
        if(wvalid && wen)
          next_fifo_state = ACTIVE;
        else if(wvalid && wlast && (wdq_slot.wid == Q_ID))
          next_fifo_state = FULL;
        else if(wen && (inc_r_ptr == write_ptr))
          next_fifo_state = EMPTY;
        else
          next_fifo_state = ACTIVE;
      end
      
      FULL: begin
        if(wen)
          next_fifo_state = ACTIVE;
        else if(wvalid)
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

  assign wready = !full;

  
  flex_counter #(.SIZE(4'd4)) BEAT_CNT (CLK, nRST, clear, cnt_en, 4'd7, rollover);

  logic clear_cwl; //clears cwl timer.
  logic cnt_en_cwl; //enables cwl timer.
  logic rollover_cwl; //rollover of cwl timer. 
  flex_counter #(.SIZE(6'd32)) T_CWL_TIM (CLK, nRST, clear_cwl, cnt_en_cwl, (tCWL - 'b1), rollover_cwl);

  typedef enum logic [1:0] {IDLE, CWL_WAIT, WRITING, RESP} cnt_ctrl_state_t;
  
  cnt_ctrl_state_t cnt_ctrl; 
  cnt_ctrl_state_t cnt_ctrl_next;
  always_comb begin : NEXT_CNT_CTRL 
    
    cnt_ctrl_next = cnt_ctrl;
    case(cnt_ctrl)

	IDLE: begin
		if( (be_wid == Q_ID) && be_write) 
			cnt_ctrl_next = CWL_WAIT; 
		else 
			cnt_ctrl_next = IDLE;
	      end
	CWL_WAIT: begin 
		if( rollover_cwl )  
			cnt_ctrl_next = WRITING; 
		else 
			cnt_ctrl_next = CWL_WAIT;
		end	
	WRITING: begin
		 if( rollover ) 
			cnt_ctrl_next = RESP; 
		 else 
			cnt_ctrl_next = WRITING;
		 end
	RESP: begin 
		if(bwready && (bw_arb == Q_ID)) 
			cnt_ctrl_next = IDLE;   
		else 
			cnt_ctrl_next = RESP;
	      end

    endcase

  end

  always_ff @(posedge CLK, negedge nRST) begin

    if(!nRST) begin
      cnt_ctrl <= IDLE;
    end else begin
      cnt_ctrl <= cnt_ctrl_next;
    end

  end
  

  always_comb begin : CNT_CTRL

    wen = 'b0;
    clear = 'b1;
    cnt_en = 'b0;
    clear_cwl = 'b1;
    cnt_en_cwl = 'b0;
    bwid = Q_ID;
    bwresp = 2'b0; 
    bwvalid = 'b0;
    ddr_we = 'b0;
    ddr_wdata_en = 'b0;
    case(cnt_ctrl)
	CWL_WAIT: begin 
		cnt_en_cwl = 'b1; 
		clear_cwl = 'b0;
	end
	WRITING: begin
	       	wen = 'b1; 
		clear = 'b0; 
		cnt_en = 'b1; 
		ddr_we = 'b1;
		ddr_wdata_en = 'b1;
	end
        RESP : bwvalid = 'b1;
    endcase

  end

  
  

endmodule




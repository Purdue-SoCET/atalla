module memory_arbiter_basic(
  input logic CLK, nRST,
  ram_if.tb rfif,
  arbiter_caches_if.caches cif
);

  // Outputs to scratchpad
  logic[63:0] load_data;
  logic       sLoad_hit, sStore_hit;
  logic[1:0]  sLoad_row;
  
  // Inputs to arbiter from scratchpad
  logic[63:0] store_data;
  logic[31:0] load_addr, store_addr;
  logic       sLoad, sStore;

  // Inputs to arbiter from scheduler
  // logic       dreq, ireq;
  //      cif.dREN, cif.dWEN, cif.iREN
  //      cif.daddr, cif.iaddr

  // WAIT SIGNALS
  logic sp_wait; //, dwait, iwait;
  //             cif.dwait, cif.iwait

  // State definitions
  typedef enum logic [2:0] {
      IDLE     = 3'b000,
      SP_LOAD  = 3'b001,
      SP_STORE = 3'b010,
      DCACHE   = 3'b011,
      ICACHE   = 3'b100
  } arbiter_states;

  arbiter_states arbiter_state, next_arbiter_state;

  always_ff @ (posedge CLK, negedge nRST) begin
    if(!nRST) begin
      arbiter_state <= IDLE;
    end
    else begin
      arbiter_state <= next_arbiter_state;
    end
  end

  //NEXT STATE LOGIC
  always_comb begin
    next_arbiter_state = arbiter_state;
    case(arbiter_state)
      IDLE: begin
        if(sLoad) next_arbiter_state = SP_LOAD;
        else if(sStore) next_arbiter_state = SP_STORE;
        else if(cif.dREN || cif.dWEN) next_arbiter_state = DCACHE;
        else if(cif.dREN) next_arbiter_state = ICACHE;
      end

      SP_LOAD: begin
        if(sp_wait) next_arbiter_state = SP_LOAD;
        else next_arbiter_state = IDLE;
      end

      SP_STORE: begin
        if(sp_wait) next_arbiter_state = SP_STORE;
        else next_arbiter_state = IDLE;
      end

      DCACHE: begin
        if(cif.dwait) next_arbiter_state = DCACHE;
        else next_arbiter_state = IDLE;
      end

      ICACHE: begin
        if(cif.iwait) next_arbiter_state = ICACHE;
        else next_arbiter_state = IDLE;
      end
    endcase
  end

  //OUTPUT LOGIC
  always_comb begin
    load_data = '0;
    sLoad_hit = '0;
    sStore_hit = '0;
    sLoad_row = '0;
    store_data = '0;
    load_addr = '0;
    store_addr = '0;
    sLoad = '0;
    sStore = '0;
    sp_wait = '1;
    dwait = '1;
    iwait = '1;
    rfif.WEN = 0;
    rfif.wsel = 0;
    rfif.rsel = 0;
    rfif.wdat = 0;
case(arbiter_state)
      SP_LOAD: begin
        rfif.rsel = load_addr;
        load_data = rfif.rdat;
        sp_wait = rfif.ramhit ? 0 : 1;
        sLoad_row = sLoad_row + 1;
        sLoad_hit = 1'b1;
      end

      SP_STORE: begin
        rfif.WEN = 1;
        rfif.wdat = store_data;
        rfif.wsel = store_addr;
        sp_wait = rfif.ramhit ? 0 : '1;
        sStore_hit = 1'b1;
      end

      DCACHE: begin
        // Add DCACHE-specific logic here
      end

      ICACHE: begin
        // Add ICACHE-specific logic here
      end
    endcase
  end

endmodule
module memory_arbiter_basic(
  input logic CLK, nRST
);

  // Variable Initialization
  logic sreq, sWEN, sREN, swait,
        ireq,       iREN, iwait,
        dreq, dWEN, dREN, dwait;
  logic next_sreq, next_sWEN, next_sREN, next_swait,
        next_ireq,            next_iREN, next_iwait,
        next_dreq, next_dWEN, next_dREN, next_dwait;
  
  // State definitions
  typedef enum logic [2:0] {
      IDLE     = 3'b000,
      GRANT_SP = 3'b001,
      GRANT_I  = 3'b010,
      GRANT_D  = 3'b011,
      ACCESS   = 3'b100
  } arbiter_states;

  arbiter_states arbiter_state, next_arbiter_state;

  always_ff @ (posedge CLK, negedge nRST) begin
    if(!nRST) begin
      sreq = '0;
      sWEN = '0;
      sREN = '0;
      swait = '0;
      ireq = '0;
      iREN = '0;
      iwait = '0;
      dreq = '0;
      dWEN = '0;
      dREN = '0;
      dwait = '0;
      arbiter_state = IDLE;
    end
    else begin
      sreq = next_sreq;
      sWEN = next_sWEN;
      sREN = next_sREN;
      swait = next_swait;
      ireq = next_ireq;
      iREN = next_iREN;
      iwait = next_iwait;
      dreq = next_dreq;
      dWEN = next_dWEN;
      dREN = next_dREN;
      dwait = next_dwait;
      arbiter_state = next_arbiter_state;
    end
  end

  //NEXT STATE LOGIC
  always_comb begin
    case(arbiter_state)
      IDLE: begin
        if(sreq) begin
          next_arbiter_state = GRANT_SP;
        end
        else if(dreq && !sreq) begin
          next_arbiter_state = GRANT_D;
        end
        else if(ireq && !dreq && !sreq) begin
          next_arbiter_state = GRANT_I;
        end
      end

      GRANT_SP: begin
        if(swait) begin
          next_arbiter_state = GRANT_SP;
        end
        else begin
          next_arbiter_state = ACCESS;
        end
      end

      GRANT_I: begin
        if(iwait) begin
          next_arbiter_state = GRANT_I;
        end
        else begin
          next_arbiter_state = ACCESS;
        end
      end

      GRANT_D: begin
        if(dwait) begin
          next_arbiter_state = GRANT_D;
        end
        else begin
          next_arbiter_state = ACCESS;
        end
      end

      ACCESS: begin
        next_arbiter_state = IDLE;
      end
    endcase
  end



  //TODO: COMMUNICATION WITH OTHER MODULES
  //OUTPUT LOGIC
  always_comb begin
    next_sreq = sreq;
    next_sWEN = sWEN;
    next_sREN = sREN;
    next_swait = swait;
    next_ireq = ireq;
    next_iREN = iREN;
    next_iwait = iwait;
    next_dreq = dreq;
    next_dWEN = dWEN;
    next_dREN = dREN;
    next_dwait = dwait;
    case(arbiter_state)
      IDLE: begin
      
      end

      GRANT_SP: begin
      
      end

      GRANT_I: begin
      
      end

      GRANT_D: begin
      
      end

      ACCESS: begin
      
      end
    endcase
  end

endmodule

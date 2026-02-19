// ------------------------------------------------------------
// valu.sv
// Vector Lane ALU with BF16 add/sub, logical ops, and comparisons
// 2-cycle pipeline to match addsub_bf16 latency, subject to change based off adder changes for bf16
// Owner: Vedant Sharma
// ------------------------------------------------------------

`include "vector_pkg.vh"
`include "valu_if.vh"

module valu (
    input logic CLK,
    input logic nRST,
    valu_if.valu alu_if
);

    // This alu is kinda fucked rn, I went under the assumption that there's no mid-flight backpressure from the collector.
    // ik ik, probably going to have that kind of thing, so I have a feeling I may have to add a stall signal into the adder itself which is kinda scary and I don't want to mess with it rn
    // buttttt it is needed for the L1 testing so guess I'll have to do it.

    import vector_pkg::*;

    /*
        Please note:
         this implementation of the ALU is going to be based off cycle/step based formatting
        mainly for me to easily actually understnad what I'm doing
        plus it's easier to debug and test in the long run. Not to mention very easy to read as well.
        Thank you @mixuan for the idea from add_bf16.
    */

    // Cycle 0:
    // Skip computation if mask is 0 and rm is 0 (i.e., no operation)
    logic skip_compute;
    assign skip_compute = !alu_if.in.mask && !alu_if.in.rm;


    // Cycle 0:
    // operation handling and set up adder config
    logic is_logical;
    logic is_mgt, is_mlt, is_meq, is_mneq;
    logic addsub_op;

    always_comb begin
        is_mgt = (alu_if.in.aluop == ALU_MGT);
        is_mlt = (alu_if.in.aluop == ALU_MLT);
        is_meq = (alu_if.in.aluop == ALU_MEQ);
        is_mneq = (alu_if.in.aluop == ALU_MNEQ);
        
        is_logical = (alu_if.in.aluop == ALU_AND) || (alu_if.in.aluop == ALU_OR) || (alu_if.in.aluop == ALU_XOR) || (alu_if.in.aluop == ALU_NOT);
        
        // Subtract for SUB and all compare operations (compare uses subtraction to check sign)
        addsub_op = (alu_if.in.aluop == ALU_SUB) || is_mgt || is_mlt || is_meq || is_mneq;
    end


    // The prior implementation from chase or whoever made ALU used nan detection, but I'm pretty sure the adder already handles that.
    // My only question is whether its required for the logical ops, bc those completely bypass adder.
    // My thinking is if your feeding a random ahh NaN value into the ALU you're expecting a bitwise op on the actual thing itself so it should be fine.

    // BF add/sub setup, has 2 cycle latency inside
    // feed 0's into adder if skip_compute, wish we could completely invalidate the adder and just not even have to run 0's but idk if thats possible.
    // Inputs go directly into adder, meaning no extra delays for this
    logic [15:0] addsub_in1, addsub_in2;
    logic [15:0] addsub_out;
    logic addsub_overflow, addsub_underflow, addsub_invalid;

    assign addsub_in1 = skip_compute ? '0 : alu_if.in.v1;
    assign addsub_in2 = skip_compute ? '0 : alu_if.in.v2;

    // Instantiate BF16 add/sub module
    addsub_bf16 u_addsub (
        .clk(CLK),
        .nRST(nRST),
        .bf1_in(addsub_in1),
        .bf2_in(addsub_in2),
        .op(addsub_op),
        .bf_out(addsub_out),
        .overflow(addsub_overflow),
        .underflow(addsub_underflow),
        .invalid(addsub_invalid)
    );

    // Still Cycle 0 for this:

    // Logical stuff!
    // I'm going to attempt to write this as a completely seperate thing from the rest which is why its all seperated btw
    // I'm pretty sure I need to add logical support into the ALU as that was needed anyway

    // technically can literally make this a purely comb thing and make this one cycle, need to check with Jing if thats actually a good thing or not
    // For now I'm going to make it go thru the pipeline stage to be safe. Making it match up with adder latency
    logic [ESZ-1:0] logical_result;

    always_comb begin
        if (skip_compute) begin
            logical_result = '0;
        end
        else begin
            case (alu_if.in.aluop)
                ALU_AND: logical_result = alu_if.in.v1 & alu_if.in.v2;
                ALU_OR: logical_result = alu_if.in.v1 | alu_if.in.v2;
                ALU_XOR: logical_result = alu_if.in.v1 ^ alu_if.in.v2;
                ALU_NOT: logical_result = ~alu_if.in.v1;
                default: logical_result = '0;
            endcase
        end
    end



    // Cycle 1:
    // Finally adding the pipeline stage stuff now.
    // Need this to delay metadata for some ops to align with add/sub output, also needed to delay the lgocial ops

    logic [ESZ-1:0] v1_s1, v2_s1;
    logic [ESZ-1:0] logical_s1;
    logic is_logical_s1;
    logic is_mgt_s1, is_mlt_s1, is_meq_s1, is_mneq_s1;
    logic rm_s1;
    logic skip_s1;
    logic valid_s1;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            v1_s1 <= '0;
            v2_s1 <= '0;
            logical_s1 <= '0;
            is_logical_s1 <= 1'b0;
            is_mgt_s1 <= 1'b0;
            is_mlt_s1 <= 1'b0;
            is_meq_s1 <= 1'b0;
            is_mneq_s1 <= 1'b0;
            rm_s1 <= 1'b0;
            skip_s1 <= 1'b0;
            valid_s1 <= 1'b0;
        end
        else begin
            v1_s1 <= alu_if.in.v1;
            v2_s1 <= alu_if.in.v2;
            logical_s1 <= logical_result;
            is_logical_s1 <= is_logical;
            is_mgt_s1 <= is_mgt;
            is_mlt_s1 <= is_mlt;
            is_meq_s1 <= is_meq;
            is_mneq_s1 <= is_mneq;
            rm_s1 <= alu_if.in.rm;
            skip_s1 <= skip_compute;
            valid_s1 <= alu_if.in.valid_in;
        end
    end

    // Cycle 2:
    // Pipeline stage 2, output generation, everything should be aligned w adder, but will have test quite a bit to make sure.
    // bummy ahh pipeline suffered from the cntrl c cntr v method HAAHHAHAHA, swear if i had to do that again i would cry
    logic [ESZ-1:0] v1_s2, v2_s2;
    logic [ESZ-1:0] logical_s2;
    logic is_logical_s2;
    logic is_mgt_s2, is_mlt_s2, is_meq_s2, is_mneq_s2;
    logic rm_s2;
    logic skip_s2;
    logic valid_s2;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            v1_s2 <= '0;
            v2_s2 <= '0;
            logical_s2 <= '0;
            is_logical_s2 <= 1'b0;
            is_mgt_s2 <= 1'b0;
            is_mlt_s2 <= 1'b0;
            is_meq_s2 <= 1'b0;
            is_mneq_s2 <= 1'b0;
            rm_s2 <= 1'b0;
            skip_s2 <= 1'b0;
            valid_s2 <= 1'b0;
        end
        else begin
            v1_s2 <= v1_s1;
            v2_s2 <= v2_s1;
            logical_s2 <= logical_s1;
            is_logical_s2 <= is_logical_s1;
            is_mgt_s2 <= is_mgt_s1;
            is_mlt_s2 <= is_mlt_s1;
            is_meq_s2 <= is_meq_s1;
            is_mneq_s2 <= is_mneq_s1;
            rm_s2 <= rm_s1;
            skip_s2 <= skip_s1;
            valid_s2 <= valid_s1;
        end
    end

    // Alright still on cycle 2:
    // this is for the compare logic stuff, plus handling the output mux

    logic v1_lt_v2;
    logic v1_eq_v2;

    assign v1_lt_v2 = addsub_out[15];
    assign v1_eq_v2 = (addsub_out == 16'h0000) || (addsub_out == 16'h8000); // negative 0 i genuinely hate you with a burning passion...

    
    
    // Output muxing logic:
    logic [ESZ-1:0] result_out;

    always_comb begin
        if (skip_s2) begin
            // Masked off and not reduction: output 0
            result_out = '0;
        end
        else if (is_logical_s2) begin
            // Logical ops: use delayed combinational result
            result_out = logical_s2;
        end
        else if (is_mgt_s2) begin
            if (rm_s2) begin
                // Reduction mode MGT: output max(v1, v2)
                result_out = v1_lt_v2 ? v2_s2 : v1_s2;
            end
            else begin
                // Normal mode MGT: output 1 if v1 > v2, else 0
                result_out = {15'b0, ~v1_lt_v2 && ~v1_eq_v2};
            end
        end
        else if (is_mlt_s2) begin
            if (rm_s2) begin
                // Reduction mode MLT: output min(v1, v2)
                result_out = v1_lt_v2 ? v1_s2 : v2_s2;
            end
            else begin
                // Normal mode MLT: output 1 if v1 < v2, else 0
                result_out = {15'b0, v1_lt_v2};
            end
        end
        else if (is_meq_s2) begin
            // MEQ: output 1 if v1 == v2, else 0
            result_out = {15'b0, v1_eq_v2};
        end
        else if (is_mneq_s2) begin
            // MNEQ: output 1 if v1 != v2, else 0
            result_out = {15'b0, ~v1_eq_v2};
        end
        else begin
            // Default: ADD or SUB, use adder output directly
            result_out = addsub_out;
        end
    end

    
    // regular handshake stuff
    logic ready_reg;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            ready_reg <= 1'b1;
        end
        else begin
            if (valid_s2 && !alu_if.in.ready_out) begin
                ready_reg <= 1'b0;
            end
            else begin
                ready_reg <= 1'b1;
            end
        end
    end

    // Outputs
    assign alu_if.out.result = result_out;
    assign alu_if.out.valid_out = valid_s2;
    assign alu_if.out.ready_in = ready_reg;

endmodule

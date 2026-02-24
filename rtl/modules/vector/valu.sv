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

    import vector_pkg::*;

    /*
        Please note:
         this implementation of the ALU is going to be based off cycle/step based formatting
        mainly for me to easily actually understnad what I'm doing
        plus it's easier to debug and test in the long run. Not to mention very easy to read as well.
        Thank you @mixuan for the idea from add_bf16.

        Also note: logical ops are now nixxed, removed the ISA for vv and vi instructions.
        Also using new adder w start/stall for power savings when masking and for backpressure from collector.
    */

    // Cycle 0:
    // Skip computation if mask is 0 and rm is 0 (i.e., no operation)
    logic skip_compute;
    assign skip_compute = !alu_if.in.mask && !alu_if.in.rm;

    // Cycle 0:
    // Stall logic: stall if valid instruction is in cycle 2 and we're not ready to accept new input (ready_out = 0)
    logic stall;
    assign stall = valid_s2 && !alu_if.in.ready_out;

    // Cycle 0:
    // operation handling and set up adder config
    logic is_mgt, is_mlt, is_meq, is_mneq;
    logic addsub_op;

    always_comb begin
        is_mgt = (alu_if.in.aluop == ALU_MGT);
        is_mlt = (alu_if.in.aluop == ALU_MLT);
        is_meq = (alu_if.in.aluop == ALU_MEQ);
        is_mneq = (alu_if.in.aluop == ALU_MNEQ);
        
        // Subtract for SUB and all compare operations (compare uses subtraction to check sign)
        addsub_op = (alu_if.in.aluop == ALU_SUB) || is_mgt || is_mlt || is_meq || is_mneq;
    end


    // The prior implementation from chase or whoever made ALU used nan detection, but I'm pretty sure the adder already handles that.
    // My only question is whether its required for the logical ops, bc those completely bypass adder.
    // My thinking is if your feeding a random ahh NaN value into the ALU you're expecting a bitwise op on the actual thing itself so it should be fine.

    // BF add/sub setup, has 2 cycle latency inside
    // We can now simply turn off adder for when skip compute is true for power savings, which helps a lot. W low hanging fruit.
    // Also has stall now for pipeline backpressure control.
    // Inputs go directly into adder, meaning no extra delays for this
    logic [15:0] addsub_out;
    logic addsub_enable;
    logic addsub_overflow, addsub_underflow, addsub_invalid; // technically could remove these for ALU by leaving them as not connected outs for addsub module, but might help w debug so let it be

    // Enable adder only when inputs are valid, we aren't masked, and there's no stall. (stall is based off ready_out)
    assign addsub_enable = alu_if.in.valid_in && !skip_compute && !stall;


    // Instantiate BF16 add/sub module
    addsub_bf16 u_addsub (
        .clk(CLK),
        .nRST(nRST),
        .start(addsub_enable),
        .stall(stall),
        .bf1_in(alu_if.in.v1),
        .bf2_in(alu_if.in.v2),
        .op(addsub_op),
        .bf_out(addsub_out),
        .overflow(addsub_overflow),
        .underflow(addsub_underflow),
        .invalid(addsub_invalid)
    );

    // Deleted all logical stuff that was here.

    // Cycle 1:
    // Finally adding the pipeline stage stuff now.
    // Need this to delay metadata for some ops to align with add/sub output
    // Only passes thru when not stalled

    logic [ESZ-1:0] v1_s1, v2_s1;
    logic is_mgt_s1, is_mlt_s1, is_meq_s1, is_mneq_s1;
    logic rm_s1;
    logic skip_s1;
    logic valid_s1;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            v1_s1 <= '0;
            v2_s1 <= '0;
            is_mgt_s1 <= 1'b0;
            is_mlt_s1 <= 1'b0;
            is_meq_s1 <= 1'b0;
            is_mneq_s1 <= 1'b0;
            rm_s1 <= 1'b0;
            skip_s1 <= 1'b0;
            valid_s1 <= 1'b0;
        end
        else if (!stall) begin
            v1_s1 <= alu_if.in.v1;
            v2_s1 <= alu_if.in.v2;
            is_mgt_s1 <= is_mgt;
            is_mlt_s1 <= is_mlt;
            is_meq_s1 <= is_meq;
            is_mneq_s1 <= is_mneq;
            rm_s1 <= alu_if.in.rm;
            skip_s1 <= skip_compute;
            valid_s1 <= alu_if.in.valid_in;
        end
        // else hold values (stall condition)
    end

    // Cycle 2:
    // Pipeline stage 2, output generation, everything should be aligned w adder, but will have test quite a bit to make sure.
    // Only passes thru when not stalled
    logic [ESZ-1:0] v1_s2, v2_s2;
    logic is_mgt_s2, is_mlt_s2, is_meq_s2, is_mneq_s2;
    logic rm_s2;
    logic skip_s2;
    logic valid_s2;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            v1_s2 <= '0;
            v2_s2 <= '0;
            is_mgt_s2 <= 1'b0;
            is_mlt_s2 <= 1'b0;
            is_meq_s2 <= 1'b0;
            is_mneq_s2 <= 1'b0;
            rm_s2 <= 1'b0;
            skip_s2 <= 1'b0;
            valid_s2 <= 1'b0;
        end
        else if (!stall) begin
            v1_s2 <= v1_s1;
            v2_s2 <= v2_s1;
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
            // Default: ADD or SUB, use adder output directly (this includes reduction sum when rm=1, since reduction sum is just normal add)
            result_out = addsub_out;
        end
    end

    // Outputs w handshake
    assign alu_if.out.result = result_out;
    assign alu_if.out.valid_out = valid_s2;
    assign alu_if.out.ready_in = !stall;

endmodule

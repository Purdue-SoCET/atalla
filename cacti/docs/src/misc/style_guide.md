# SoCET AI Hardware SystemVerilog Coding Guide

### Written by: Malcolm McClymont
### Last updated: 1/15/2026

## Introduction

This guide is designed for engineers developing and testing hardware within the AI Hardware team. It provides a set of guidelines meant to facilitate large scale collaboration by making RTL code easy to read, modify, and test. These rules are split into three categories based on severity:

1. **SHALL/SHALL NOT** rules; these must be followed at (almost) all times. Any **SHALL RULE VIOLATIONS** must include comments that thoroughly explain how the rule is being violated and why. Anyone who deviates from these rules should not be surprised if asked to rewrite their code.

2. **SHOUD/SHOULD NOT** rules; these practices are strongly encouraged, but not strictly mandatory. Violating these rules does not require an explicit comment but may warrant rewriting code.

3. **MAY/MAY NOT** rules; these are practices that could improve code legibility or testability but are situational and should be applied at the engineer’s discretion.

Perceptive readers will notice that there are no absolute rules in this guide; engineers should always evaluate if a rule should be followed and provide documentation if they decide not to follow it.

## Formatting

- Engineers **SHALL** use spaces as tabs, with 4 spaces per tab.

    VSCode can be configured to do this, but here are some commands for a .vimrc file that enables this:

    ```
    autocmd BufNewFile,BufRead *.sv,*.v set tabstop=4
    autocmd BufNewFile,BufRead *.sv,*.v set shiftwidth=4
    autocmd BufNewFile,BufRead *.sv,*.v set expandtab
    ```

- Engineers **SHALL** minimize dead (commented out) code. If large sections of code are commented out (3 or more lines) then a pointer comment **SHALL** be used or the comment should be deleted.

- Engineers **SHALL** consolidate code. Dead code and active code should be in separate groups, not intermixed.

    An example of these two rules:

    ```
    Bad! Notice how the dead and alive lines are mixed.

    ...

    always_comb begin : input_buses 
        // cu.input_type = 1'b0; 
        cu.input_row = '0;
        cu.input_load = 1'b0;
        // cu.weight_row = '0;
        // cu.weight_load = 1'b0;
        cu.partials_row = '0;
        cu.partials_load = 1'b0;
        if (cu.input_en) begin
            cu.input_row = cu.row_in_en;
            cu.input_load = 1'b1;
        end else if (cu.weight_en) begin
            // cu.input_type = 1'b1;
            // cu.weight_row = cu.row_in_en;
            // cu.weight_load = 1'b1;
        end
        if (cu.partial_en) begin
            cu.partials_row = cu.row_ps_en;
            cu.partials_load = 1'b1;
        end
    end

    ...
    ```

    ```
    Better, dead lines are grouped together

    ...
    always_comb begin : input_buses 
        cu.input_row = '0;
        cu.input_load = 1'b0;
        cu.partials_row = '0;
        cu.partials_load = 1'b0;

        // cu.weight_row = '0;
        // cu.weight_load = 1'b0;
        // cu.input_type = 1'b0;

        if (cu.input_en) begin
            cu.input_row = cu.row_in_en;
            cu.input_load = 1'b1;
        end else if (cu.weight_en) begin
            // cu.input_type = 1'b1;
            // cu.weight_row = cu.row_in_en;
            // cu.weight_load = 1'b1;
        end
        if (cu.partial_en) begin
            cu.partials_row = cu.row_ps_en;
            cu.partials_load = 1'b1;
        end
    end
    ...
    ```

    ```
    Best, pointer comments are used to move commented blocks away from the active code. Ideally, dead lines should be at end of file or deleted entirely.

    ...
    always_comb begin : input_buses 
        cu.input_row = '0;
        cu.input_load = 1'b0;
        cu.partials_row = '0;
        cu.partials_load = 1'b0;

        //[1]

        if (cu.input_en) begin
            cu.input_row = cu.row_in_en;
            cu.input_load = 1'b1;
        end else if (cu.weight_en) begin
            //[2]
        end
        if (cu.partial_en) begin
            cu.partials_row = cu.row_ps_en;
            cu.partials_load = 1'b1;
        end
    end
    ...

    endmodule

    //[1]
    // cu.weight_row = '0;
    // cu.weight_load = 1'b0;
    // cu.input_type = 1'b0;

    //[2]
    // cu.input_type = 1'b1;
    // cu.weight_row = cu.row_in_en;
    // cu.weight_load = 1'b1;
    ```

- Signal names **SHALL NOT** exceed 30 characters. Additionally, their names **SHOULD** be intuitive.

- Module names **SHALL** be intuitive.

- All always_comb and always_ff blocks **SHALL** have names. 

- Blocks that share many signals or interact closely **SHOULD** be adjacent in the code. In other words, achieve spatial locality. 
    - However, always_comb blocks **SHOULD** be grouped with other always_comb blocks. The same applies to always_ff blocks.

- Unless a block's name makes its function obvious, every block **SHOULD** come with a comment describing what it does

    For example:

    ```
    //Detailed comment describing function of block
    always_comb begin : <block name> 
    ...
    end

    ...

    //Detailed comment describing function of block
    always_ff begin : <block name>
    ...
    end
    ```

- Any outstanding fixes/modifications to code **SHOULD** be documented using a TODO comment

- When applicable, RTL and code **SHALL** use “manager” and “subordinate” as opposed to “master” and “slave”.

## Verilator Linter

- Engineers **SHALL NOT** have any Verilator linter warnings in code within main branch

- Engineers **SHALL NOT** use lint_off to disable warnings
    - All of the Verilator warnings and their meanings can be found here: https://verilator.org/guide/latest/warnings.html

    For example:

    ```
    always_comb begin : <block name>
        ...

        //Bad! Why are they getting a truncate warning?
        //Engineer should explain this with a comment or fix it.

        /* verilator lint_off WIDTHTRUNC */
        curr_input_row = iteration[l];
        /* verilator lint_off WIDTHTRUNC */

        ...
    end
    ```


## Testbenches

- Engineers **SHALL** only print messages for failing test cases, but include a “test complete” message too. These failing tests **SHALL** include a timestamp.

For example:
```
//This will set %t to print in nanoseconds. Replace -9 with -12 for ps.
$timeformat(-9, 2, " ns"); 

...

if(tb_out != golden_out) begin
    $display("Output mismatch for test %0d at %0t", i, $time);
    failed_cases += 1;
end

...
```

- Testbenches **SHALL** use `timescale 1ps/1ps.

- TODO: Expand this section

## Interfaces

- Engineers **SHALL** include an ifndef to avoid repeatedly including an interface
- Modports **SHALL** follow the format x_y, where x and y represent the two modules the interface connects 


For example:
```
//Good

module backend #(parameter logic [SCPAD_ID_WIDTH-1:0] IDX = '0) (
    scpad_if.backend_sched bshif, //Connects backend to scheduler
    scpad_if.backend_body bbif,  //Connects backend to scratchpad body
    scpad_if.backend_dram bdrif //Conects backend to DRAM
);

...

endmodule
```

- TODO: Expand this section



## Synthesizable Logic

- Plus and minus **SHALL** be the only arithmetic operators directly used in synthesizable logic. 

For example:
```
//Good
assign c = a + b;
//Bad!
assign c = a * b;

//Good. Create an instance of an operational unit from a written Verilog module.
mult_module M0(.a(a), .b(b), .c(c))

```
- When using a for loop in synthesizable code, its intended function **SHALL** be thoroughly commented. This also applies to generate for loops.

- Any use of always_latch **SHALL** come with extensive documentation on its intended function.

- Functions **MAY** be used in synthesized logic, but **SHALL** only contain combinational logic.
    - SystemVerilog doesn't actually support sequential logic in functions.

For example:
```
//Good, only contains combinational logic.
function [7:0] addition (input [7:0] in_a, input [7:0] in_b);
    addition = in_a + in_b;
endfunction

...

always_comb begin
    c = addition(a, b);
end
```

## Combinational Logic
- Engineers **SHALL NOT** use nested ternary logic. Use an if/else or case block instead for this.

For example:
```
    //Bad! Nested ternary logic, hard to read.
    result = a ? b : c ? d : e;

    //Good. Use a different control structure.
    if(a) begin
        result = b;
    else if (c) begin
        result = d;
    else begin
        result = e;
    end

    //Also acceptable
    if(a) begin
        result = b;
    else begin
        result = c ? d : e;
    end
```

-  Any modules that are fully combinational **MAY** have the clk and n_rst input signals removed.

## Sequential Logic
- Sequential elements **SHALL** only use posedge clk and negedge n_rst in their sensitivity lists.

- Engineers **SHALL** only use packed arrays in synthesziable modules. Testbenches may use either packed or unpacked arrays.

For example:
```
logic [7:0] data; //Packed array
logic data [7:0]; //Unpacked array
```

- FSMs **SHALL** always use enums as state names.

- Engineers **SHOULD** always use explicit next_state logic.

- Any sequential elements that do not strictly require an n_rst signal **SHOULD NOT** have one. However, you **SHALL** comment which elements do not have an n_rst signal
    - Determining which elements do not need an n_rst signal **SHOULD** be done after the design is fully verified.
    - Signals used for write enable by any modules **SHALL** always have an n_rst signal

## Forbidden Structures

The following SystemVerilog structures **SHALL NOT** be used:
- Programs
- Fork/join
- Always@
- Z-state logic/tri-state buffers
- Classes and polymorphism **SHALL** be avoided. Typedef statements within packages **SHALL** be used instead.
- Any datatypes indicating the strength of a signal (supply1, strong1, weak1, etc.)
- Force statements
- Triple equal signs equality operators (===)
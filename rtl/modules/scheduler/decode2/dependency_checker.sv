// Navya Datla 2/12/2026

module dependency_checker #(
    parameter NUM_SCALAR_REGS    = 256,
    parameter SCALAR_READ_PORTS  = 4,
    parameter SCALAR_WRITE_PORTS = 4,

    parameter NUM_VECTOR_REGS    = 256,
    parameter VECTOR_READ_PORTS  = 4,
    parameter VECTOR_WRITE_PORTS = 4,

    parameter NUM_MASK_REGS      = 32,
    parameter MASK_READ_PORTS    = 2,
    parameter MASK_WRITE_PORTS   = 2
)(
    input  logic clk,
    input  logic n_rst,

    dependency_checker_if.dc dc_if
);

    logic [NUM_SCALAR_REGS-1:0] scalar_dependency_table;
    logic [NUM_VECTOR_REGS-1:0] vector_dependency_table;
    logic [NUM_MASK_REGS-1:0] mask_dependency_table;

    logic [SCALAR_READ_PORTS-1:0] scalar_hit;
    logic [VECTOR_READ_PORTS-1:0] vector_hit;
    logic [MASK_READ_PORTS-1:0]   mask_hit;

    logic scalar_hazard;
    logic vector_hazard;
    logic mask_hazard;


    always_ff @(posedge clk, negedge n_rst) begin
        int i;
        int w;
        if (!n_rst) begin
            for (i = 0; i < NUM_SCALAR_REGS; i++)
                scalar_dependency_table[i] <= 1'b0;

            for (i = 0; i < NUM_VECTOR_REGS; i++)
                vector_dependency_table[i] <= 1'b0;

            for (i = 0; i < NUM_MASK_REGS; i++)
                mask_dependency_table[i] <= 1'b0;
        end
        else begin

            // Mark destination registers as busy in Decode 2
            for (w = 0; w < SCALAR_WRITE_PORTS; w++) begin
                if (dc_if.scalar_WEN[w])
                    scalar_dependency_table[dc_if.scalar_wsel[w]] <= 1'b1;
            end

            for (w = 0; w < VECTOR_WRITE_PORTS; w++) begin
                if (dc_if.vector_WEN[w])
                    vector_dependency_table[dc_if.vector_wsel[w]] <= 1'b1;
            end

            for (w = 0; w < MASK_WRITE_PORTS; w++) begin
                if (dc_if.mask_WEN[w])
                    mask_dependency_table[dc_if.mask_wsel[w]] <= 1'b1;
            end

            // Clear scalar bits on WB
            for (w = 0; w < SCALAR_WRITE_PORTS; w++) begin
                if (dc_if.scalar_WB_WEN[w])
                    scalar_dependency_table[dc_if.scalar_WB_wsel[w]] <= 1'b0;
            end

            // Clear scalar bits on SDMA WB
            if (dc_if.scalar_SDMA_WEN)
                scalar_dependency_table[dc_if.scalar_SDMA_wsel] <= 1'b0;

            // Clear vector bits on WB 
            for (w = 0; w < VECTOR_WRITE_PORTS; w++) begin
                if (dc_if.vector_WB_WEN[w])
                    vector_dependency_table[dc_if.vector_WB_wsel[w]] <= 1'b0;
            end

            // Clear mask bits on WB 
            for (w = 0; w < MASK_WRITE_PORTS; w++) begin
                if (dc_if.mask_WB_WEN[w])
                    mask_dependency_table[dc_if.mask_WB_wsel[w]] <= 1'b0;
            end

        end
    end

    always_comb begin
        // int i;

        // // Check source registers for RAW hazards
        // scalar_hazard = 1'b0;
        // vector_hazard = 1'b0;
        // mask_hazard   = 1'b0;

        // for (i = 0; i < SCALAR_READ_PORTS; i++) begin
        //     if (dc_if.scalar_REN[i] & scalar_dependency_table[dc_if.scalar_rsel[i]])
        //         scalar_hazard = 1'b1;
        // end

        // for (i = 0; i < VECTOR_READ_PORTS; i++) begin
        //     if (dc_if.vector_REN[i] & vector_dependency_table[dc_if.vector_rsel[i]])
        //         vector_hazard = 1'b1;
        // end

        // for (i = 0; i < MASK_READ_PORTS; i++) begin
        //     if (dc_if.mask_REN[i] & mask_dependency_table[dc_if.mask_rsel[i]])
        //         mask_hazard = 1'b1;
        // end

        
        
        for (int i = 0; i < SCALAR_READ_PORTS; i++) begin
            scalar_hit[i] = dc_if.scalar_REN[i] & scalar_dependency_table[dc_if.scalar_rsel[i]];
        end
        for (int i = 0; i < VECTOR_READ_PORTS; i++) begin
            //vector_hit[i] = dc_if.vector_REN[i] & vector_dependency_table[dc_if.vector_rsel[i]];
            vector_hit[i] = '0;
        end
        for (int i = 0; i < MASK_READ_PORTS; i++) begin
            //mask_hit[i] = dc_if.mask_REN[i] & mask_dependency_table[dc_if.mask_rsel[i]];
            mask_hit[i] = '0;
        end

        scalar_hazard = |scalar_hit;
        vector_hazard = |vector_hit;
        mask_hazard   = |mask_hit;

    end

    assign dc_if.dependencies_ready = ~(scalar_hazard | vector_hazard | mask_hazard);
    
endmodule
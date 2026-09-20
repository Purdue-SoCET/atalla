// Navya Datla 2/12/2026

module dependency_checker #(
    parameter NUM_SCALAR_REGS    = 256,
    parameter SCALAR_READ_PORTS  = 4,
    parameter SCALAR_WRITE_PORTS = 4,

    parameter NUM_VECTOR_REGS    = 256,
    parameter VECTOR_READ_PORTS  = 4,
    parameter VECTOR_WRITE_PORTS = 4,

    parameter NUM_MASK_REGS      = 16,
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

    assign dc_if.scalar_halt_ready = |scalar_dependency_table;
    assign dc_if.vector_halt_ready = |vector_dependency_table;
    assign dc_if.mask_halt_ready = |mask_dependency_table;

    logic [SCALAR_READ_PORTS-1:0] scalar_hit;
    logic [VECTOR_READ_PORTS-1:0] vector_hit;
    logic [MASK_READ_PORTS-1:0]   mask_hit;

    logic scalar_hazard;
    logic vector_hazard;
    logic mask_hazard;


    always_ff @(posedge clk, negedge n_rst) begin
        int i;
        int w;
        // Reset
        if (!n_rst) begin
            for (i = 0; i < NUM_SCALAR_REGS; i++)
                scalar_dependency_table[i] <= 1'b0;

            for (i = 0; i < NUM_VECTOR_REGS; i++)
                vector_dependency_table[i] <= 1'b0;

            for (i = 0; i < NUM_MASK_REGS; i++)
                mask_dependency_table[i] <= 1'b0;
        end
        else begin
            
            // Clear scalar bits on WB
            for (w = 0; w < SCALAR_WRITE_PORTS; w++) begin
                if (dc_if.scalar_WB_WEN[w])
                    scalar_dependency_table[dc_if.scalar_WB_wsel[w]] <= 1'b0;
                if (dc_if.scalar_SDMA_WB_WEN[w])
                    scalar_dependency_table[dc_if.scalar_SDMA_WB_wsel[w]] <= 1'b0; //SDMA instr reserved scalar reg, clear it on WB
            end

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

            //Set has greater priority than clear 
            // Mark destination registers as busy only when source regs are already ready (prevents issue where a instr uses a packet as src and dest but it's not ready yet)
            if (dc_if.ready) begin
                for (w = 0; w < SCALAR_WRITE_PORTS; w++) begin
                    if (dc_if.scalar_WEN[w])
                        scalar_dependency_table[dc_if.scalar_wsel[w]] <= 1'b1;
                    if (dc_if.vector_s_WEN[w])
                        scalar_dependency_table[dc_if.vector_s_wsels[w]] <= 1'b1; //check vector s wsels too since vec instrs can write to scalar regs
                    if (dc_if.SDMA_scalar_WEN[w])
                        scalar_dependency_table[dc_if.SDMA_scalar_rs1s[w]] <= 1'b1; //if SDMA instr is writing to scalar reg, mark it as busy
                end

                for (w = 0; w < VECTOR_WRITE_PORTS; w++) begin
                    if (dc_if.vector_v_WEN[w])
                        vector_dependency_table[dc_if.vector_v_wsels[w]] <= 1'b1;
                end

                for (w = 0; w < MASK_WRITE_PORTS; w++) begin
                    if (dc_if.vector_m_WEN[w])
                        mask_dependency_table[dc_if.vector_m_wsels[w]] <= 1'b1;
                    else if (dc_if.scalar_m_WEN[w]) begin
                        mask_dependency_table[dc_if.scalar_wsel[w][3:0]] <= 1'b1;
                    end
                end
            end

        end
    end

    logic scalar_RAW;
    logic scalar_WAW;
    logic vector_RAW;
    logic vector_WAW;
    logic mask_RAW;
    logic mask_WAW;

    always_comb begin        
        
        for (int i = 0; i < SCALAR_READ_PORTS; i++) begin
            scalar_RAW = dc_if.scalar_REN[i] & scalar_dependency_table[dc_if.scalar_rsel[i]];
            scalar_WAW = (dc_if.scalar_WEN[i] & scalar_dependency_table[dc_if.scalar_wsel[i]]) | (dc_if.vector_s_WEN[i] & scalar_dependency_table[dc_if.vector_s_wsels[i]]); //check WAW against both scalar and vector instructions since vec instrs can write to scalar regs
            //Note: i don't think sdma needs waw checking since it "writes back" to its source reg which will be checked for raw already and then set
            scalar_hit[i] = scalar_RAW | scalar_WAW;
        end
        for (int i = 0; i < VECTOR_READ_PORTS; i++) begin
            vector_RAW = dc_if.vector_REN[i] & vector_dependency_table[dc_if.vector_rsel[i]];
            vector_WAW = dc_if.vector_v_WEN[i] & vector_dependency_table[dc_if.vector_v_wsels[i]];
            vector_hit[i] = vector_RAW | vector_WAW;
        end
        for (int i = 0; i < MASK_READ_PORTS; i++) begin
            mask_RAW = dc_if.mask_REN[i] & mask_dependency_table[dc_if.mask_rsel[i]];
            mask_WAW = dc_if.vector_m_WEN[i] & mask_dependency_table[dc_if.vector_m_wsels[i]];
            mask_hit[i] = mask_RAW | mask_WAW;
        end

        scalar_hazard = |scalar_hit;
        vector_hazard = |vector_hit;
        mask_hazard   = |mask_hit;

    end

    assign dc_if.dependencies_ready = ~(scalar_hazard | vector_hazard | mask_hazard);
    
endmodule
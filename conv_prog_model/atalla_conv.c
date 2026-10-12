/*
 * Saandiya KPS Mohan
 * mohan76@purdue.edu
 *
 * ======================================================================================
 * ATALLA PROGRAMMING MODEL: CONVOLUTION KERNEL
 * ======================================================================================
 * * This code is not standard C. It is a kernel specification for the Atalla Compiler.
 * It defines how to map high-level Conv2D parameters to the specific 
 * Vector-Scalar ISA and Systolic Array primitives of the hardware.
 */

// --- 1. ABSTRACT TYPES (Hardware Resources) ---
typedef opaque GlobalTile;  // Descriptor for a tensor slice in DRAM
typedef opaque ScpadTile;   // Descriptor for a tensor slice in SRAM (Scratchpad)
typedef opaque VectorReg;   // Represents a 32-wide Vector Register (v0-v31)
typedef opaque ScalarReg;   // Represents a Scalar Register

// --- 2. ISA INTRINSICS (The Instruction Set) ---

// Memory Movement (DMA Engine)
// Moves data between Global Memory (DRAM) and On-Chip Scratchpads
void SDMA_LD_0(ScpadTile dest, GlobalTile src); // Load to SCPAD0 (Input Activations)
void SDMA_LD_1(ScpadTile dest, GlobalTile src); // Load to SCPAD1 (Weights/Bias)
void SDMA_ST_1(VectorReg src, GlobalTile dest); // Store from SCPAD1 (Outputs)

// Scratchpad Allocation (Compiler Directive)
// Allocates space in the specific memory bank
ScpadTile _alloc_scpad0(int height, int width);
ScpadTile _alloc_scpad1(int height, int width);

// Vector Load (Vector Unit)
// Loads a contiguous row from a Scratchpad Tile into a Vector Register
// offset: flat index start within the tile
// len: number of valid elements to load (rest are zeroed)
void VM_LD(VectorReg dest, ScpadTile src, int offset, int len);

// Vector Arithmetic (Vector Unit - VLIW)
// Corresponds to 'mset', 'shift', 'add' in assembly
void MSET_VI(VectorReg mask, int window_size, int shift_offset); 
void VSHR_VV(VectorReg dest, VectorReg src, int shift_amt, int dir); // dir: 1=Left(Align), 0=Right(Place)
void VAND_VV(VectorReg dest, VectorReg src, VectorReg mask); // Apply Mask
void VADD_VV(VectorReg dest, VectorReg src1, VectorReg src2); // Accumulate

// Systolic Array Compute
// Dispatches the Weight Vector (B) to the SA
void LW_VI(VectorReg B_row); 
// Dispatches the Toeplitz Vector (A) and Psum Vector to the SA
void GEMM_VV(VectorReg C, VectorReg A_row, VectorReg psum);


// --- 3. TILING PLANNER (Software Host) ---
// This runs on the Host CPU to generate the list of work units (Tiles)
// It implements the Overlapping Input Logic verified in C.

struct ConvTileDesc {
    GlobalTile A_g;   // Input Spatial Tile (Overlapping)
    GlobalTile B_g;   // Weight Tile (Flattened)
    GlobalTile C_g;   // Output Spatial Tile
    
    // Metadata for Address Calculation
    int h_out_start;  // Global Output H index for this block
    int w_out_start;  // Global Output W index for this block
    int k_start;      // Kernel Reduction dimension start
    int j_start;      // Output Channel start
};

vector<ConvTileDesc> plan_conv2d(
    GlobalTensor Input, GlobalTensor Weights, GlobalTensor Output,
    int H_in, int W_in, int C_in, int H_out, int W_out, int C_out,
    int Kh, int Kw, int Stride, int Pad, int Dilation
) {
    vector<ConvTileDesc> groups;

    // Hardware Constants
    const int TM = 32; // Output Block Height/Width (and SA Height)
    const int TN = 32; // Output Channels (SA Width)
    const int TK = 32; // Reduction/Kernel Chunk Size

    // 1. Calculate Overlapping Input Tile Size for a 32x32 Output Block
    int K_eff_h = (Kh - 1) * Dilation + 1;
    int K_eff_w = (Kw - 1) * Dilation + 1;
    int T_h_req = (TM - 1) * Stride + K_eff_h;
    int T_w_req = (TM - 1) * Stride + K_eff_w;
    
    // Clip to Max Scratchpad Size if necessary (logic from C lib)
    int T_h = (T_h_req > 32) ? 32 : T_h_req; // Example constraint
    int T_w = (T_w_req > 32) ? 32 : T_w_req;

    // 2. Iterate over Spatial Output Blocks (2D Blocking)
    for (int h = 0; h < H_out; h += TM) {
        for (int w = 0; w < W_out; w += TM) {
            
            // Calculate Overlapping Input Region
            int in_h = h * Stride - Pad;
            int in_w = w * Stride - Pad;

            GlobalTile A_g = make_input_tile(Input, in_h, in_w, T_h, T_w); // 32x32 or 64x64
            GlobalTile C_g = make_output_tile(Output, h, w, TM, TM);

            // 3. Iterate over Output Channels
            for (int j = 0; j < C_out; j += TN) {
                
                // 4. Iterate over Reduction Dimension (Input Ch + Kernel Size)
                int K_total = C_in * Kh * Kw;
                for (int k = 0; k < K_total; k += TK) {
                    
                    GlobalTile B_g = make_weight_tile(Weights, k, j, TK, TN);
                    
                    groups.push_back(ConvTileDesc{
                        .A_g = A_g, .B_g = B_g, .C_g = C_g,
                        .h_out_start = h, .w_out_start = w,
                        .k_start = k, .j_start = j
                    });
                }
            }
        }
    }
    return groups;
}


// --- 4. EXECUTION KERNEL (Device) ---
// This defines the exact instruction stream for the Atallax01 Core.

void execute_conv2d(ConvTileDesc* tiles, int num_tiles, ConvParams params) {
    
    // Registers
    VectorReg v_row, v_mask, v_accum, v_zero;
    const int TM = 32; 
    const int TN = 32;
    const int TK = 32;

    // Process Tile Groups
    for (int t = 0; t < num_tiles; t++) {
        ConvTileDesc group = tiles[t];

        // 1. ALLOCATE SCRATCHPAD
        // sc_A: Input Spatial Tile (e.g. 32x32)
        ScpadTile sc_RAW = _alloc_scpad0(group.A_g.height, group.A_g.width); 
        // sc_B: Weight Matrix Tile (32x32)
        ScpadTile sc_B   = _alloc_scpad1(TK, TN); 
        // sc_C: Output Accumulator Tile (32x32)
        ScpadTile sc_C   = _alloc_scpad1(TM, TN);

        // 2. LOAD DATA (SDMA)
        // Load overlapping spatial input (Only needs to happen once per spatial block)
        // (Compiler optimization: hoist this out if contiguous groups share A_g)
        SDMA_LD_0(sc_RAW, group.A_g); 
        SDMA_LD_1(sc_B,   group.B_g);
        
        // Load partial sums if k > 0, else zero out
        if (group.k_start > 0) SDMA_LD_1(sc_C, group.C_g);
        else                   MSET_VI(v_accum, 0, 0); // Clear accumulator logic

        // 3. COMPUTE LOOP (The "Batching Engine")
        // Iterate over the TM (32) output patches we need to produce in this block
        for (int m = 0; m < TM; m++) {
            
            // --- A. ADDRESS GENERATION (Scalar Core) ---
            // Map 'm' (patch index) to spatial coordinates in sc_RAW
            // Corresponds to: local_patch_idx = ii + m
            int r_local = m / 32; // simplified for 1D strip of 32 patches
            int c_local = m % 32; 
            
            // Calculate Window Start in sc_RAW (Input Window)
            int local_w_start = c_local * params.stride; 
            int local_h_start = r_local * params.stride;

            // Initialize Accumulator Vector for this Row (Row 'm' of Matrix A)
            // v_accum corresponds to sc_A[m] in C code
            // MSET_VI used to clear register (sets to 0)
            // (Or use logical XOR v_accum, v_accum)
            
            // --- B. VECTOR TRANSFORM (Mask, Shift, Add) ---
            // This loop builds the Toeplitz vector for Patch 'm'
            // Iterates over the Kernel Rows (Kh)
            
            int start_channel = group.k_start / (params.Kh * params.Kw);
            int tile_c = start_channel; // relative to loaded tile

            for (int kh = 0; kh < params.Kh; kh++) {
                
                // 1. VECTOR LOAD (UnAligned / Centered) 
                // Load from sc_RAW starting at the window column
                int row_offset = tile_c * (32 * 32) + (local_h_start + kh) * 32;
                int load_addr  = row_offset + local_w_start;
                
                // Calculate valid pixels remaining in this row (Boundary Check)
                int valid_pixels = 32 - local_w_start; 
                
                // Issue Vector Load
                VM_LD(v_row, sc_RAW, load_addr, valid_pixels);

                // 2. CREATE MASK 
                // Create 111000... mask for Kernel Width (Kw)
                MSET_VI(v_mask, params.Kw, 0);
                
                // 3. APPLY MASK
                VAND_VV(v_row, v_row, v_mask);

                // 4. ALIGN SHIFT (Left)
                // Shift Left by 0 (Already aligned by Load) - No-op in this logic, 
                // but kept for architectural consistency if load was aligned to row start.
                // VSHR_VV(v_row, v_row, 0, 1); 

                // 5. PLACE SHIFT (Right) 
                // Shift to final position in the flattened vector (TK=32)
                int global_k = start_channel * (params.Kh * params.Kw) + kh * params.Kw;
                int shift_place = global_k - group.k_start;

                if (shift_place >= 0) {
                    // Standard Case: Shift Right
                    VSHR_VV(v_row, v_row, shift_place, 0); // 0 = Right
                    VADD_VV(v_accum, v_accum, v_row);      // Accumulate to A_row
                } 
                else {
                    // Straddle Case. Row started previously.
                    // We need the tail end.: Shift Left
                    int shift_left = -shift_place;
                    VSHR_VV(v_row, v_row, shift_left, 1);  // 1 = Left
                    VADD_VV(v_accum, v_accum, v_row);
                }
            } // End Kernel Row Loop

            // --- C. SYSTOLIC ARRAY DISPATCH ---
            // Dispatch the constructed Toeplitz Vector (v_accum) and Partial sums (v_psum) 
            // This vector represents ONE row of the A matrix.
            // The SA will multiply this vector against the Weights (v_B)
            // and accumulate into the Output Vector register (v_C) at row 'm'.
            LW_VI(v_B);
            GEMM_SA(v_C, v_accum, v_psum);
            
        } // End Patch Loop (m)

        // 4. STORE RESULT (SDMA)
        SDMA_ST_1(v_C, group.C_g);
        
    } // End Tile Group Loop
}
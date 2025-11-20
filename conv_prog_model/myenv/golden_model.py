import numpy as np
import torch
import torch.nn.functional as F

class AtallaGoldenConv:
    def __init__(self, in_channels, out_channels, kernel_size, stride=1, padding=0):
        self.in_channels = in_channels
        self.out_channels = out_channels
        self.kernel_size = kernel_size
        self.stride = stride
        self.padding = padding
        
        # Initialize random weights and bias
        # Shape: [Out_Channels, In_Channels, K_H, K_W]
        self.weights = np.random.randn(out_channels, in_channels, kernel_size, kernel_size).astype(np.float32)
        # Shape: [Out_Channels]
        self.bias = np.random.randn(out_channels).astype(np.float32)

    def get_output_shape(self, h_in, w_in):
        """Calculates the dimensions of the output feature map."""
        h_out = (h_in + 2 * self.padding - self.kernel_size) // self.stride + 1
        w_out = (w_in + 2 * self.padding - self.kernel_size) // self.stride + 1
        return int(h_out), int(w_out)

    def im2col_naive(self, input_data):
        """
        Transforms the input image into a matrix (Toeplitz-like structure) 
        suitable for GEMM.
        
        Input: [C, H, W]
        Output: [C * K * K, H_out * W_out]
        """
        c, h, w = input_data.shape
        k = self.kernel_size
        h_out, w_out = self.get_output_shape(h, w)
        
        # Apply Padding
        img_padded = np.pad(input_data, 
                           ((0, 0), (self.padding, self.padding), (self.padding, self.padding)), 
                           mode='constant')
        
        # Create the column matrix
        col = np.zeros((c * k * k, h_out * w_out))
        
        col_idx = 0
        for y in range(h_out):
            for x in range(w_out):
                # Determine the window based on stride
                y_start = y * self.stride
                x_start = x * self.stride
                y_end = y_start + k
                x_end = x_start + k
                
                # Extract the patch [C, K, K]
                patch = img_padded[:, y_start:y_end, x_start:x_end]
                
                # Flatten the patch into a single column vector and store it
                col[:, col_idx] = patch.reshape(-1)
                col_idx += 1
                
        return col

    def forward_manual(self, x):
        """
        Executes the convolution using the GEMM approach (Atalla Logic).
        """
        batch_size, c, h, w = x.shape
        h_out, w_out = self.get_output_shape(h, w)
        
        # Reshape Weights for GEMM: [F, C*K*K]
        # This corresponds to the "Weight Packing" strategy
        weights_col = self.weights.reshape(self.out_channels, -1)
        
        output = np.zeros((batch_size, self.out_channels, h_out, w_out))
        
        for i in range(batch_size):
            # 1. Im2Col (Construct input matrix)
            # In Atalla code, this is where you use mset/shift/masks
            input_col = self.im2col_naive(x[i])
            
            # 2. GEMM Execution
            # result_col shape: [F, H_out * W_out]
            gemm_result = weights_col @ input_col
            
            # 3. Add Bias (Broadcast)
            gemm_result += self.bias[:, np.newaxis]
            
            # 4. Reshape back to image format [F, H_out, W_out]
            output[i] = gemm_result.reshape(self.out_channels, h_out, w_out)
            
        return output

    def verify_with_pytorch(self, input_np):
        """
        Test Plan verification step.
        """
        # Convert numpy to torch tensors
        input_tensor = torch.from_numpy(input_np)
        weight_tensor = torch.from_numpy(self.weights)
        bias_tensor = torch.from_numpy(self.bias)
        
        # Run PyTorch Standard Conv2d
        torch_out = F.conv2d(input_tensor, weight_tensor, bias_tensor, 
                             stride=self.stride, padding=self.padding)
        
        # Run Our Manual Model
        my_out = self.forward_manual(input_np)
        
        # Compare
        match = np.allclose(torch_out.numpy(), my_out, atol=1e-5)
        diff = np.abs(torch_out.numpy() - my_out).max()
        
        return match, diff

# --- Main Test Harness ---
if __name__ == "__main__":
    print("--- Initializing Convolution Golden Model (Im2Col Strategy) ---")
    
    # Test Parameters
    BATCH = 1
    IN_C = 3    # RGB Image
    OUT_C = 2   # Number of Filters
    IMG_H = 128
    IMG_W = 128
    KERNEL = 3
    STRIDE = 1
    PAD = 1
    
    # 1. Create the Model
    model = AtallaGoldenConv(IN_C, OUT_C, KERNEL, stride=STRIDE, padding=PAD)
    
    # 2. Create Random Input [N, C, H, W]
    input_data = np.random.randn(BATCH, IN_C, IMG_H, IMG_W).astype(np.float32)
    
    print(f"Input Shape: {input_data.shape}")
    print(f"Kernel Shape: {model.weights.shape}")
    
    # 3. Run Verification
    is_correct, max_diff = model.verify_with_pytorch(input_data)
    
    print("\n--- Verification Results ---")
    if is_correct:
        print(f"✅ SUCCESS: Manual model matches PyTorch! (Max Diff: {max_diff:.8f})")
        print("This confirms the Im2Col -> GEMM logic is valid.")
    else:
        print(f"❌ FAILED: Mismatch detected. (Max Diff: {max_diff:.8f})")
        
    # 4. Print Intermediate Matrices (For C/Atalla Debugging)
    print("\n--- Debugging Data for C Implementation ---")
    input_col_matrix = model.im2col_naive(input_data[0])
    print(f"Im2Col Matrix Shape (Input to GEMM): {input_col_matrix.shape}")
    print("First 5 columns of Im2Col Matrix:")
    print(input_col_matrix[:, :5])
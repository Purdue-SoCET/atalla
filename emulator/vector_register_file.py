import numpy as np

class VectorRegisterFile:
    """
    Simple vector register file model.
    Stores 256 vector registers (v0-v255) as a dictionary.
    Each vector register is a NumPy array of 32 elements, with each element
    being a 32-bit float (np.float32).
    Register v0 is hardwired to a vector of zeros.
    """
    def __init__(self, num_regs=256, vec_len=32):
        """
        Initialize the vector register file.
        
        Args:
            num_regs (int): The number of vector registers.
            vec_len (int): The number of elements (lanes) in each vector register.
        """
        self.num_regs = num_regs
        self.vec_len = vec_len
        # Initialize all registers to a vector (NumPy array) of zeros
        # {0: np.array([0., 0., ..., 0.]), 1: np.array([0., 0., ..., 0.]), ...}
        self.regs = {i: np.zeros(self.vec_len, dtype=np.float32) for i in range(self.num_regs)}

    def read(self, reg_num):
        """
        Read a vector from a register.
        
        Args:
            reg_num (int): The register number to read from.
            
        Returns:
            np.ndarray: A NumPy array of np.float32 values representing the vector.
        """
        if reg_num == 0:
            # v0 is hardwired to a vector of zeros
            return np.zeros(self.vec_len, dtype=np.float32)
        
        # Get the register, defaulting to a zero vector if it doesn't exist
        return self.regs.get(reg_num, np.zeros(self.vec_len, dtype=np.float32))

    def write(self, reg_num, data):
        """
        Write a vector (list or array of data) to a register.
        
        Args:
            reg_num (int): The register number to write to.
            data (list or np.ndarray): The list or array of values to write.
        
        Raises:
            ValueError: If the data is not a list/array or not of the correct vector length.
        """
        # v0 cannot be written to
        if reg_num != 0:
            if not isinstance(data, (list, np.ndarray)):
                raise ValueError(f"Data for v{reg_num} must be a list or NumPy array.")
            
            if len(data) != self.vec_len:
                raise ValueError(f"Data for v{reg_num} must be of length {self.vec_len}, but got {len(data)}.")
                
            # Convert data to a np.float32 array and store it
            self.regs[reg_num] = np.array(data, dtype=np.float32)

    def __str__(self):
        """
        Helper to pretty-print the register file state.
        Prints the first 4 elements and the last element of each vector for brevity.
        Displays the raw 32-bit hex representation of the float32 values.
        """
        s = ""
        for i in range(self.num_regs):
            vec = self.read(i)
            s += f"v{i:<2}: ["
            if self.vec_len > 5:
                # Show first 4 elements and last element
                # Use .view(np.uint32) to show the 32-bit hex representation
                s += ", ".join([f"0x{e.view(np.uint32):08X}" for e in vec[:4]])
                s += f", ..., 0x{vec[-1].view(np.uint32):08X}"
            else:
                # Show all elements if vector is short
                s += ", ".join([f"0x{e.view(np.uint32):08X}" for e in vec])
            s += "]\n"
        return s
    
    def dump_to_file(self, filename):
        """
        Write the entire register file state to a text file.
        Each line will contain one full vector register, with elements
        represented as 32-bit hex values.
        """
        with open(filename, "w") as f:
            for i in range(self.num_regs):
                vec = self.read(i)
                f.write(f"v{i:<2}: [")
                # Write all elements as 32-bit hex values
                f.write(", ".join([f"0x{e.view(np.uint32):08X}" for e in vec]))
                f.write("]\n")

# --- Example Usage ---
if __name__ == "__main__":
    # 1. Create the register file
    vregs = VectorRegisterFile(num_regs=8, vec_len=32) # Using 8 regs for a short example
    
    # 2. Create some sample data
    # (e.g., 1.0, -2.5, 3.14, ...)
    my_data = [1.0, -2.5, 3.14] + [0.5] * 28 + [-9.9]
    
    print("--- Initial State ---")
    print(vregs)
    
    # 3. Write data to v1
    try:
        vregs.write(1, my_data)
        print("\n--- Wrote data to v1 ---")
    except ValueError as e:
        print(f"Error: {e}")

    # 4. Write to v0 (should be ignored)
    vregs.write(0, my_data)
    print("\n--- Tried to write to v0 (should have no effect) ---")

    # 5. Read data from v1
    read_data = vregs.read(1)
    print(f"\nRead from v1 (first 5 elements): {read_data[:5]}")
    print(f"Read from v0 (first 5 elements): {vregs.read(0)[:5]}")
    
    # 6. Show final state
    print("\n--- Final State (showing hex representations) ---")
    print(vregs)
    
    # 7. Dump to file
    try:
        vregs.dump_to_file("vregs_dump.txt")
        print("\n--- Dumped register state to vregs_dump.txt ---")
    except IOError as e:
        print(f"Error dumping file: {e}")
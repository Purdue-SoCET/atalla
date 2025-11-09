class VectorRegisterFile:
    """
    Simple vector register file model.
    Stores 32 vector registers (v0-v31) as a dictionary.
    Each vector register is a list of 32 elements, with each element being 16 bits wide.
    Register v0 is hardwired to a vector of zeros.
    """
    def __init__(self, num_regs=32, vec_len=32):
        """
        Initialize the vector register file.
        
        Args:
            num_regs (int): The number of vector registers.
            vec_len (int): The number of elements (lanes) in each vector register.
        """
        self.num_regs = num_regs
        self.vec_len = vec_len
        # Initialize all registers to a vector (list) of zeros
        # {0: [0, 0, ..., 0], 1: [0, 0, ..., 0], ...}
        self.regs = {i: [0] * self.vec_len for i in range(self.num_regs)}

    def read(self, reg_num):
        """
        Read a vector from a register.
        
        Args:
            reg_num (int): The register number to read from.
            
        Returns:
            list: A list of integers representing the vector.
        """
        if reg_num == 0:
            # v0 is hardwired to a vector of zeros
            return [0] * self.vec_len
        
        # Get the register, defaulting to a zero vector if it doesn't exist
        # (though __init__ should prevent this)
        return self.regs.get(reg_num, [0] * self.vec_len)

    def write(self, reg_num, data):
        """
        Write a vector (list of data) to a register.
        
        Args:
            reg_num (int): The register number to write to.
            data (list): The list of 16-bit integers to write.
        
        Raises:
            ValueError: If the data is not a list or not of the correct vector length.
        """
        # v0 cannot be written to
        if reg_num != 0:
            if not isinstance(data, list):
                raise ValueError(f"Data for v{reg_num} must be a list.")
            
            if len(data) != self.vec_len:
                raise ValueError(f"Data for v{reg_num} must be a list of length {self.vec_len}, but got {len(data)}.")
                
            # Mask each element to 16 bits (0xFFFF)
            masked_data = [d & 0xFFFF for d in data]
            self.regs[reg_num] = masked_data

    def __str__(self):
        """
        Helper to pretty-print the register file state.
        Prints the first 4 elements and the last element of each vector for brevity.
        """
        s = ""
        for i in range(self.num_regs):
            vec = self.read(i)
            s += f"v{i:<2}: ["
            if self.vec_len > 5:
                # Show first 4 elements and last element
                s += ", ".join([f"0x{e:04X}" for e in vec[:4]])
                s += f", ..., 0x{vec[-1]:04X}"
            else:
                # Show all elements if vector is short
                s += ", ".join([f"0x{e:04X}" for e in vec])
            s += "]\n"
        return s
    
    def dump_to_file(self, filename):
        """
        Write the entire register file state to a text file.
        Each line will contain one full vector register.
        """
        with open(filename, "w") as f:
            for i in range(self.num_regs):
                vec = self.read(i)
                f.write(f"v{i:<2}: [")
                # Write all elements as 16-bit hex values
                f.write(", ".join([f"0x{e:04X}" for e in vec]))
                f.write("]\n")
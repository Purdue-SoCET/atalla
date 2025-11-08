class RegisterFile:
    """
    Simple register file model.
    Stores 32 registers (x0-x31) as a dictionary: {reg_num: data}.
    Register x0 is hardwired to 0.
    """
    def __init__(self, num_regs=256):
        # {0: 0, 1: 0, 2: 0, ..., 31: 0}
        self.regs = {i: 0 for i in range(num_regs)}

    def read(self, reg_num):
        """Read data from a register."""
        if reg_num == 0:
            return 0
        return self.regs.get(reg_num, 0)

    def write(self, reg_num, data):
        """Write data to a register."""
        if reg_num != 0:
            self.regs[reg_num] = data & 0xFFFFFFFF  # Mask to 32 bits

    def __str__(self):
        """Helper to pretty-print the register file state."""
        s = ""
        for i in range(len(self.regs)):
            if i % 4 == 0 and i != 0:
                s += "\n"
            s += f"x{i:<2}: 0x{self.read(i):08X}  "
        return s
    
    def dump_to_file(self, filename):
        """
        Write the entire register file state to a text file.
        """
        with open(filename, "w") as f:
            for i in range(len(self.regs)):
                if i % 4 == 0 and i != 0:
                    f.write("\n")
                f.write(f"x{i:<2}: 0x{self.read(i):08X}  ")
class ScalarRegisterFile:
    """
    Simple register file model.
    Stores registers as a dictionary: {reg_num: data}.
    For scalar (x) regs, register 0 is hardwired to 0. Mask (m) regs use
    ``zero_reg_hardwired=False`` so m0 is a normal predicate register.
    """
    def __init__(self, num_regs=256, *, zero_reg_hardwired: bool = True):
        self.zero_reg_hardwired = zero_reg_hardwired
        self.regs = {i: 0 for i in range(num_regs)}

    def read(self, reg_num):
        """Read data from a register."""
        if reg_num == 0 and self.zero_reg_hardwired:
            return 0
        return self.regs.get(reg_num, 0)

    def write(self, reg_num, data):
        """Write data to a register."""
        if reg_num == 0 and self.zero_reg_hardwired:
            return
        self.regs[reg_num] = data & 0xFFFFFFFF  # Mask to 32 bits

    def __str__(self):
        s = ""
        for i in range(len(self.regs)):
            # Force cast to python int() to fix the numpy format error
            val = int(self.read(i))
            
            if i % 4 == 0:
                s += "\n"
            s += f"x{i:<2}: 0x{val:08X}  "
        return s
    
    def dump_to_file(self, filename):
        """
        Write the entire register file state to a text file.
        """
        with open(filename, "w") as f:
            for i in range(len(self.regs)):
                if i % 4 == 0 and i != 0:
                    f.write("\n")
                f.write(f"x{i:<2}: 0x{int(self.read(i)):08X}  ")


def mask_register_file(num_regs: int = 16) -> ScalarRegisterFile:
    """Predicate registers for vector masks: m0 writable; default all lanes active."""
    m = ScalarRegisterFile(num_regs=num_regs, zero_reg_hardwired=False)
    m.write(0, 0xFFFFFFFF)
    return m
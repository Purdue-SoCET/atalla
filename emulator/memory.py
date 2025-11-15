class Memory:
    """
    Dual-memory model for the AI chip emulator.

    - Instruction Memory: 160-bit words (stored as Python int)
    - Data Memory: 32-bit words

    Memory file format:
        <addr>: <data>
        ...
        DATA MEM
        <addr>: <data>
        ...

    Lines before 'DATA MEM' belong to instruction memory.
    Lines after belong to data memory.
    """

    def __init__(self, filename=None):
        self.instr_mem = {}  # {address: 160-bit word}
        self.data_mem = {}   # {address: 32-bit word}

        if filename:
            self.load_from_file(filename)

    # ------------------------------------------------------------
    # File loading
    # ------------------------------------------------------------
    def load_from_file(self, filename):
        mode = "INSTR"

        with open(filename, "r") as f:
            for line_num, line in enumerate(f, start=1):
                # Remove comments and whitespace
                line = line.split("#")[0].strip()
                if not line:
                    continue

                # Section change
                if line.upper().startswith("DATA MEM"):
                    mode = "DATA"
                    continue

                # Parse "<addr>: <data>"
                try:
                    addr_str, data_str = [x.strip() for x in line.split(":")]
                except ValueError:
                    raise ValueError(f"Invalid format at line {line_num}: '{line}'")

                # REMOVE ALL SPACES inside hex data (this is the critical change)
                data_str = data_str.replace(" ", "").replace("_", "")

                # Convert
                try:
                    addr = int(addr_str, 16)
                    data = int(data_str, 16)
                except ValueError:
                    raise ValueError(f"Invalid hex at line {line_num}: '{line}'")

                # Store to correct memory
                if mode == "INSTR":
                    if data.bit_length() > 160:
                        raise ValueError(f"Instruction too large at line {line_num}")
                    self.instr_mem[addr] = data
                else:
                    if data.bit_length() > 32:
                        raise ValueError(f"Data value too large at line {line_num}")
                    self.data_mem[addr] = data

    # ------------------------------------------------------------
    # Instruction memory access
    # ------------------------------------------------------------
    def read_instr(self, addr):
        """Read 160-bit instruction word (default 0)."""
        return self.instr_mem.get(addr, 0)

    def write_instr(self, addr, data):
        """Write 160-bit instruction word."""
        self.instr_mem[addr] = data & ((1 << 160) - 1)

    # ------------------------------------------------------------
    # Data memory access
    # ------------------------------------------------------------
    def read_data(self, addr):
        """Read 32-bit data word (default 0)."""
        return self.data_mem.get(addr, 0)

    def write_data(self, addr, data):
        """Write 32-bit data word."""
        self.data_mem[addr] = data & 0xFFFFFFFF

    # ------------------------------------------------------------
    # Dump to file
    # ------------------------------------------------------------
    def dump_to_file(self, filename):
        """
        Dumps instruction and data memory back to a file
        using the original combined format.
        """
        with open(filename, "w") as f:
            # Instruction mem
            for addr in sorted(self.instr_mem.keys()):
                val = self.instr_mem[addr]
                f.write(f"{addr:08X}: {val:040X}\n")  # 160 bits → 40 hex chars

            f.write("\nDATA MEM\n")

            # Data mem
            for addr in sorted(self.data_mem.keys()):
                val = self.data_mem[addr]
                f.write(f"{addr:08X}: {val:08X}\n")

    # ------------------------------------------------------------
    # Convenience operators (default to data memory)
    # ------------------------------------------------------------
    def __getitem__(self, addr):
        return self.read_data(addr)

    def __setitem__(self, addr, data):
        self.write_data(addr, data)

    def __contains__(self, addr):
        return addr in self.data_mem or addr in self.instr_mem

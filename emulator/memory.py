class Memory:
    """
    Simple memory model for the AI chip emulator.
    Stores memory as a dictionary: {address: data}.
    """

    def __init__(self, filename=None, word_size=4):
        self.mem = {}
        self.word_size = word_size  # bytes per address step
        if filename:
            self.load_from_file(filename)

    def load_from_file(self, filename):
        """
        Loads memory contents from a text file formatted as:
            <address>: <data>
        Example:
            00000000: DEADBEEF
            00000004: 8C130004
        Lines starting with '#' are ignored.
        """
        with open(filename, "r") as f:
            for line_num, line in enumerate(f, start=1):
                # Remove comments and whitespace
                line = line.split("#")[0].strip()
                if not line:
                    continue

                try:
                    addr_str, data_str = [x.strip() for x in line.split(":")]
                    addr = int(addr_str, 16)
                    data = int(data_str, 16)
                    self.mem[addr] = data
                except ValueError:
                    raise ValueError(f"Invalid format at line {line_num}: {line.strip()}")

    def read(self, addr):
        """Return word at address (default 0 if not present)."""
        return self.mem.get(addr, 0)

    def write(self, addr, data):
        """Write a word to address."""
        self.mem[addr] = data & 0xFFFFFFFF  # mask to 32 bits

    def dump_to_file(self, filename):
        """
        Write the entire memory contents back to a file.
        Sorted by address for deterministic output.
        """
        with open(filename, "w") as f:
            for addr in sorted(self.mem.keys()):
                f.write(f"{addr:08X}: {self.mem[addr]:08X}\n")

    def __getitem__(self, addr):
        return self.read(addr)

    def __setitem__(self, addr, data):
        self.write(addr, data)

    def __contains__(self, addr):
        return addr in self.mem

    def __len__(self):
        return len(self.mem)

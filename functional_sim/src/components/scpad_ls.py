import struct
from typing import Callable

# from matplotlib.pyplot import title

from ..misc.memory import Memory
from .scpad import Scratchpad
from .vector_register_file import VectorRegisterFile
from .perf_metrics import PerfMetrics

def identity_swizzle(addr: int) -> int:
    return addr

# ============================================================
# Vector Load: Scratchpad -> Vector Register
# ============================================================
def scpad_to_vreg(
    *,
    scpad: Scratchpad,
    vregs: VectorRegisterFile,
    scpad_addr: int,   # If rc=0: Slot Index. If rc=1: Bank Index.
    vd: int,           # Destination Vector Register Index
    rc: int = 0,       # 0 = Row Mode (across banks), 1 = Column Mode (down slots)
    rc_id: int = 0,
    num_rows: int = 31,
    num_cols: int = 31
):
    """
    Loads a vector from Scratchpad into a Vector Register.
    
    rc=0 (Row): VREG[i] = SCPAD.banks[i][scpad_addr]
    rc=1 (Col): VREG[i] = SCPAD.banks[scpad_addr][i]
    """
    vector_data = []

    # Default lengths if not provided
    if rc == 0:
        length = num_rows  # Row mode -> width is number of banks
    else:
        length = num_cols  # Col mode -> width is number of slots

    if rc == 1:
        # --- COL MODE ---
        # Fixed Slot (scpad_addr), Iterate Banks
        slot = int(scpad_addr % scpad.S + rc_id)
        for bank in range(0, length+1):
            if bank >= scpad.B:
                break
            val = scpad.banks[bank][slot]
            vector_data.append(val)

    elif rc == 0:
        # --- ROW MODE ---
        # Fixed Bank (scpad_addr), Iterate Slots
        bank = scpad_addr % scpad.B + rc_id
        for i in range(0,length+1):
            slot = i % scpad.S 
            val = scpad.banks[bank][slot]
            vector_data.append(val)

    # Write result to Vector Register
    vregs.write(vd, vector_data)


# ============================================================
# Vector Store: Vector Register -> Scratchpad
# ============================================================
def vreg_to_scpad(
    *,
    scpad: Scratchpad,
    vregs: VectorRegisterFile,
    scpad_addr: int,   # If rc=0: Slot Index. If rc=1: Bank Index.
    vs: int,           # Source Vector Register Index
    rc: int = 0,       # 0 = Row Mode, 1 = Column Mode
    rc_id: int = 0,
    num_rows: int = 31,
    num_cols: int = 31
):
    """
    Stores a Vector Register into the Scratchpad.

    rc=0 (Row): SCPAD.banks[i][scpad_addr] = VREG[i]
    rc=1 (Col): SCPAD.banks[scpad_addr][i] = VREG[i]
    """
    # Read vector data
    vector_data = vregs.read(vs)
    
    if rc == 1:
        # --- COL MODE ---
        # Fixed Slot (scpad_addr), Iterate Banks
        slot = int (scpad_addr % scpad.S + rc_id)
        for bank, val in enumerate(vector_data):
            if bank >= num_cols + 1:
                break
            scpad.banks[bank][slot] = val

    elif rc == 0:
        # --- ROW MODE ---
        # Fixed Bank (scpad_addr), Iterate Slots
        bank = scpad_addr % scpad.B + rc_id
        for i, val in enumerate(vector_data):
            slot = i % scpad.S
            if i >= num_rows + 1:
                break
            scpad.banks[bank][slot] = val  


# ============================================================
# DMA LOAD: GMEM -> Scratchpad
# ============================================================
def sdma_load(
    *,
    gmem: Memory,
    scpad: Scratchpad,
    gmem_base: int,
    scpad_base_row: int,
    tile_id: str,
    NR: int,
    NC: int,
    perf_metrics: PerfMetrics = None,
    swizzle: Callable[[int], int] = identity_swizzle,
):
    """
    for i in range(NR):
        for j in range(NC):
            SCPAD[(scpad_ptr * i) + j] = GMEM[ swizzle((gmem_ptr * i) + j) ]
    """

    # Register tile metadata in scratchpad
    scpad.tiles[tile_id] = {
        "rows": NR,
        "cols": NC,
        "base_row": scpad_base_row
    }

    for i in range(0, NR+1):
        row_vals = []

        # Read from GMEM
        for j in range(0, NC+1):
            g_addr = gmem_base + (i * (NC+1) + j) * 2
            raw_val = gmem.read_data(g_addr)
            if perf_metrics is not None:
                # GMEM BF16 payload is 2 bytes per element.
                perf_metrics.increment("bytes_loaded", 2)
            raw_val = raw_val << 16


            # 1. Pack the int into 4 bytes (little-endian 'I' for unsigned int)
            # 2. Unpack those 4 bytes as a float ('f')
            fp32_val = struct.unpack('<f', struct.pack('<I', raw_val & 0xFFFFFFFF))[0]

            row_vals.append(fp32_val)

        # Write into scratchpad banks
        slot = (scpad_base_row + i) % scpad.S
        for bank, val in enumerate(row_vals):
            if bank >= scpad.B:
                break
            scpad.banks[bank][slot] = val


# ============================================================
# DMA STORE: Scratchpad -> GMEM
# ============================================================
def sdma_store(
    *,
    gmem: Memory,
    scpad: Scratchpad,
    scpad_base_row: int,
    gmem_base: int,
    tile_id: str,
    NR: int,
    NC: int,
    swizzle: Callable[[int], int] = identity_swizzle,
):
    """
    for i in range(NR):
        for j in range(NC):
            GMEM[(gmem_ptr * i) + j] = SCPAD[ swizzle((scpad_ptr * i) + j) ]
    """

    for i in range(0, NR+1):
        slot = (scpad_base_row + i) % scpad.S
        for j in range(0, NC+1):
            bank = j
            if bank >= scpad.B:
                break
            val = scpad.banks[bank][slot]
            bits = struct.unpack('<I', struct.pack('<f', val))[0]
            bits = bits >> 16
            #x_shifted = struct.unpack('<f', struct.pack('<I', bits & 0xFFFFFFFF))[0]
            g_addr = gmem_base + (i * (NC+1) + j) * 2
            gmem.write_data(g_addr, bits)


def dump_scpad_rc(scpad: Scratchpad, file=None):
    if not file:
        for b in range(scpad.B):
            print(f"Bank {b}: {scpad.banks[b]}")
    else: 
        with open(file, "w") as f:
            for b in range(scpad.B):
                f.write(f"Bank {b}: {scpad.banks[b]}\n")


if __name__ == "__main__":
    gmem = Memory()
    scpad = Scratchpad(slots_per_bank=16)

    # Initialize GMEM
    for i in range(64):
        gmem.write_data(i, i + 100)

    # LOAD 4x4 tile
    sdma_load(
        gmem=gmem,
        scpad=scpad,
        gmem_base=0,
        scpad_base_row=0,
        tile_id="A",
        NR=1,
        NC=4
    )

    dump_scpad_rc(scpad=scpad, title="I hate this")

    # STORE tile back
    sdma_store(
        gmem=gmem,
        scpad=scpad,
        scpad_base_row=0,
        gmem_base=32,
        tile_id="A",
        NR=4,
        NC=4
    )

    print("\nGMEM after STORE:")
    for i in range(16):
        print(32 + i, "->", gmem.read_data(32 + i))
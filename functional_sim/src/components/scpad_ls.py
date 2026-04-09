import struct
from typing import Callable, Optional

# from matplotlib.pyplot import title

from ..misc.memory import Memory
from .scpad import Scratchpad
from .vector_register_file import VectorRegisterFile
from .perf_metrics import PerfMetrics

def identity_swizzle(addr: int) -> int:
    return addr


def _scpad_cell_to_f32(val) -> float:
    """Scratchpad may hold floats, raw int bits, empty string, or tile tags."""
    if val == "" or val is None:
        return 0.0
    if isinstance(val, str):
        return 0.0
    if isinstance(val, int):
        return struct.unpack("<f", struct.pack("<I", val & 0xFFFFFFFF))[0]
    return float(val)


# Compiler stack spills use rs1 = x33 - {64,128,192,256}; col-mode scratchpad maps
# (addr+rc_id)%S so those bases collide. Route them to linear BF16 in GMEM.
# The 64-byte spacing matches 32 lanes * 2 bytes, not 32 lanes * 4 bytes; using
# fp32 here makes adjacent spill slots overlap and clobber each other.
# Do NOT use addr >= constant: tensor bases (e.g. C_GMEM == 0x6000) overlap that range.
# x33 is the vector spill high-water mark (harness sets it above scalar stack).
GMEM_VECTOR_SPILL_BELOW = 768


def is_gmem_vector_spill(scpad_addr: int, vec_sp_top: int) -> bool:
    """True if rs1 is in the [x33-spill_window, x33] stack spill band (linear fp32)."""
    a = int(scpad_addr) & 0xFFFFFFFF
    top = int(vec_sp_top) & 0xFFFFFFFF
    if top < 0x1000:
        return False
    low = (top - GMEM_VECTOR_SPILL_BELOW) & 0xFFFFFFFF
    return low <= a <= top


# ppci may emit vreg.ld/st with rs1 = byte address in DRAM (e.g. C_GMEM + row offset).
# Those must read/write packed BF16 like sdma_*, not scratchpad (addr%32) geometry.
GMEM_BF16_VECTOR_BASE = 0x1000


def is_gmem_bf16_vector_linear(scpad_addr: int, vec_sp_top: int) -> bool:
    a = int(scpad_addr) & 0xFFFFFFFF
    if a < GMEM_BF16_VECTOR_BASE:
        return False
    return not is_gmem_vector_spill(a, vec_sp_top)


def dram_bf16_vec_ld_to_vreg(
    *,
    gmem: Memory,
    vregs: VectorRegisterFile,
    base_byte: int,
    vd: int,
    num_cols: int = 31,
):
    n = min(int(num_cols) + 1, 32)
    b = int(base_byte)
    vector_data = []
    for i in range(n):
        h = gmem.read_bf16_le(b + i * 2)
        raw_val = h << 16
        fp32_val = struct.unpack("<f", struct.pack("<I", raw_val & 0xFFFFFFFF))[0]
        vector_data.append(fp32_val)
    vregs.write(vd, vector_data)


def dram_bf16_vec_st_from_vreg(
    *,
    gmem: Memory,
    vregs: VectorRegisterFile,
    base_byte: int,
    vs: int,
    num_cols: int = 31,
):
    n = min(int(num_cols) + 1, 32)
    vector_data = vregs.read(vs)
    b = int(base_byte)
    for i in range(min(n, len(vector_data))):
        bits = struct.unpack("<I", struct.pack("<f", float(vector_data[i])))[0]
        bits = bits >> 16
        gmem.write_bf16_le(b + i * 2, bits)


def dram_vec_ld_to_vreg(
    *,
    gmem: Memory,
    vregs: VectorRegisterFile,
    base_byte: int,
    vd: int,
    num_cols: int = 31,
):
    n = min(int(num_cols) + 1, 32)
    vector_data = []
    b = int(base_byte)
    for i in range(n):
        h = gmem.read_bf16_le(b + i * 2)
        raw_val = h << 16
        vector_data.append(
            struct.unpack("<f", struct.pack("<I", raw_val & 0xFFFFFFFF))[0]
        )
    vregs.write(vd, vector_data)


def dram_vec_st_from_vreg(
    *,
    gmem: Memory,
    vregs: VectorRegisterFile,
    base_byte: int,
    vs: int,
    num_cols: int = 31,
):
    n = min(int(num_cols) + 1, 32)
    vector_data = vregs.read(vs)
    b = int(base_byte)
    for i in range(min(n, len(vector_data))):
        bits = struct.unpack("<I", struct.pack("<f", float(vector_data[i])))[0]
        gmem.write_bf16_le(b + i * 2, bits >> 16)


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
        # One column across banks at slot (base + row); wrap so base+row never exceeds S-1.
        slot = (int(scpad_addr) + int(rc_id)) % scpad.S
        n_banks = min(length + 1, scpad.B)
        for bank in range(n_banks):
            val = scpad.banks[bank][slot]
            vector_data.append(val)

    elif rc == 0:
        # --- ROW MODE ---
        # Fixed bank (base + row), iterate slots; wrap bank index to scratchpad geometry.
        bank = (int(scpad_addr) + int(rc_id)) % scpad.B
        n_iter = min(length + 1, scpad.S)
        for i in range(n_iter):
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
        slot = (int(scpad_addr) + int(rc_id)) % scpad.S
        n_banks = min(int(num_cols) + 1, scpad.B)
        for bank in range(min(n_banks, len(vector_data))):
            scpad.banks[bank][slot] = vector_data[bank]

    elif rc == 0:
        # --- ROW MODE ---
        bank = (int(scpad_addr) + int(rc_id)) % scpad.B
        n_iter = min(int(num_rows) + 1, scpad.S, len(vector_data))
        for i in range(n_iter):
            slot = i % scpad.S
            scpad.banks[bank][slot] = vector_data[i]


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
    row_stride_elems: Optional[int] = None,
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

    stride = (NC + 1) if row_stride_elems is None else int(row_stride_elems)

    for i in range(0, NR+1):
        row_vals = []

        # Read from GMEM
        for j in range(0, NC+1):
            g_addr = gmem_base + (i * stride + j) * 2
            h = gmem.read_bf16_le(g_addr)
            if perf_metrics is not None:
                # GMEM BF16 payload is 2 bytes per element.
                perf_metrics.increment("bytes_loaded", 2)
            raw_val = h << 16


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
    row_stride_elems: Optional[int] = None,
    perf_metrics: Optional[PerfMetrics] = None,
    swizzle: Callable[[int], int] = identity_swizzle,
):
    """
    for i in range(NR):
        for j in range(NC):
            GMEM[(gmem_ptr * i) + j] = SCPAD[ swizzle((scpad_ptr * i) + j) ]
    """

    stride = (NC + 1) if row_stride_elems is None else int(row_stride_elems)

    for i in range(0, NR+1):
        slot = (scpad_base_row + i) % scpad.S
        for j in range(0, NC+1):
            bank = j
            if bank >= scpad.B:
                break
            val = scpad.banks[bank][slot]
            bits = struct.unpack("<I", struct.pack("<f", _scpad_cell_to_f32(val)))[0]
            bits = bits >> 16
            g_addr = gmem_base + (i * stride + j) * 2
            gmem.write_bf16_le(g_addr, bits)
            if perf_metrics is not None:
                perf_metrics.increment("bytes_written", 2)


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
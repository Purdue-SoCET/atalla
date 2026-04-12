import struct
from typing import Callable, Optional

# from matplotlib.pyplot import title

from ..misc.memory import Memory
from .scpad import Scratchpad
from .vector_register_file import VectorRegisterFile
from .perf_metrics import PerfMetrics

def identity_swizzle(addr: int) -> int:
    return addr


def _lane_count_from_num_cols(num_cols: int, max_lanes: int) -> int:
    num_cols = int(num_cols)
    if num_cols < 0:
        raise ValueError(f"num_cols must be >= 0, got {num_cols}")
    return min(num_cols + 1, max_lanes)


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
    scpad_base_addr: int,
    row_offset: int,
    vd: int,
    num_cols: int,
):
    """
    VM load to scratch: rs1 = base slot/bank index, rs2 = row offset, num_cols = 0..31
    (lane count = num_cols + 1). Lanes map to banks at the selected slot.
    """
    slot = int(scpad_base_addr + row_offset) % scpad.S
    lane_count = _lane_count_from_num_cols(num_cols=num_cols, max_lanes=scpad.B)
    vector_data = [scpad.banks[bank][slot] for bank in range(lane_count)]
    vregs.write(vd, vector_data)


# ============================================================
# Vector Store: Vector Register -> Scratchpad
# ============================================================
def vreg_to_scpad(
    *,
    scpad: Scratchpad,
    vregs: VectorRegisterFile,
    scpad_base_addr: int,
    row_offset: int,
    vs: int,
    num_cols: int,
):
    vector_data = vregs.read(vs)
    slot = int(scpad_base_addr + row_offset) % scpad.S
    lane_count = _lane_count_from_num_cols(num_cols=num_cols, max_lanes=scpad.B)
    lane_count = min(lane_count, len(vector_data))
    for bank in range(lane_count):
        scpad.banks[bank][slot] = vector_data[bank]


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
    NR and NC from SDMA metadata are encoded as (N−1): loops use i in 0..NR and j in 0..NC
    (inclusive), i.e. (NR+1)×(NC+1) BF16 elements per tile, with GMEM row stride (NC+1) words.
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
    Same NR/NC (N−1) convention and (NC+1) row stride as sdma_load.
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

    dump_scpad_rc(scpad=scpad)

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
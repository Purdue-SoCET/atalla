import struct
from typing import Optional

# from typing import Callable  # if you re-enable swizzle below
from ..misc.memory import Memory
from .scpad import Scratchpad
from .vector_register_file import VectorRegisterFile
from .perf_metrics import PerfMetrics

BF16_ELEM_BYTES = 2

# If you restore swizzle on GMEM addresses, define a default and add the param back:
# def identity_swizzle(addr: int) -> int:
#     return addr


def _lane_count_from_num_cols(num_cols: int, max_lanes: int) -> int:
    num_cols = int(num_cols)
    if num_cols < 0:
        raise ValueError(f"num_cols must be >= 0, got {num_cols}")
    return min(num_cols + 1, max_lanes)


def _spad_row_bytes(scpad: Scratchpad) -> int:
    return int(scpad.B) * BF16_ELEM_BYTES


def _addr_to_row(scpad: Scratchpad, spad_addr: int) -> int:
    row_bytes = _spad_row_bytes(scpad)
    if row_bytes <= 0:
        raise ValueError(f"Invalid scratchpad row size: {row_bytes}")
    return int(spad_addr) // row_bytes


def _dram_stride_cols(*, tile_cols: int, full_num_cols: Optional[int]) -> int:
    # full_num_cols is DRAM row stride (full matrix width). Keep a compatibility
    # fallback to contiguous subtile layout when metadata was encoded without it.
    if full_num_cols is None:
        return tile_cols

    stride = int(full_num_cols)
    if stride <= 0:
        return tile_cols
    if stride < tile_cols:
        raise ValueError(
            f"full_num_cols ({stride}) must be >= tile_cols ({tile_cols})"
        )
    return stride


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
    VM load: rs1 = scratchpad byte address of tile base; rs2 = row offset from
    addr_to_row(rs1); num_cols is 0-indexed max column (num_cols + 1 lanes).
    Lane i maps to bank i at the selected slot.
    """
    base_row = _addr_to_row(scpad, scpad_base_addr)
    slot = int(base_row + row_offset) % scpad.S
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
    """
    VM store: same rs1/rs2/num_cols semantics as scpad_to_vreg; lane i maps to bank i.
    """
    vector_data = vregs.read(vs)
    base_row = _addr_to_row(scpad, scpad_base_addr)
    slot = int(base_row + row_offset) % scpad.S
    lane_count = _lane_count_from_num_cols(num_cols=num_cols, max_lanes=scpad.B)
    lane_count = min(lane_count, len(vector_data))
    for bank in range(lane_count):
        scpad.banks[bank][slot] = vector_data[bank]


# ============================================================
# DMA LOAD: GMEM -> Scratchpad
# ============================================================
# Legacy / experimental hooks (commented out — not part of the current signature):
#   row_stride_elems: Optional[int] = None
#       Override DRAM row stride in elements; if None, use full_num_cols / _dram_stride_cols
#       or fall back to tile width (NC+1). Older call sites used (metadata&0xFFFFF)+1 here.
#   swizzle: Callable[[int], int] = identity_swizzle
#       Remap a linear BF16 element index to a byte offset for non-linear GMEM layouts.
#       Wire into g_addr computation if you reintroduce it (import Callable, define identity_swizzle).
def sdma_load(
    *,
    gmem: Memory,
    scpad: Scratchpad,
    gmem_base: int,
    spad_addr: int,
    tile_id: str,
    NR: int,
    NC: int,
    full_num_cols: Optional[int] = None,
    perf_metrics: Optional[PerfMetrics] = None,
):
    """
    NR and NC in SDMA metadata are (N−1): tile is (NR+1)×(NC+1) BF16 elements.
    DRAM row stride uses full_num_cols from rs3 low bits when provided; else tile width (NC+1).
    """
    tile_rows = int(NR) + 1
    tile_cols = int(NC) + 1
    dram_stride_cols = _dram_stride_cols(
        tile_cols=tile_cols, full_num_cols=full_num_cols
    )
    base_row = _addr_to_row(scpad, spad_addr)

    scpad.tiles[tile_id] = {
        "rows": tile_rows,
        "cols": tile_cols,
        "base_row": base_row,
    }

    for i in range(tile_rows):
        row_vals = []
        for j in range(tile_cols):
            g_addr = int(gmem_base) + (i * dram_stride_cols + j) * BF16_ELEM_BYTES
            h = gmem.read_bf16_le(g_addr)
            if perf_metrics is not None:
                perf_metrics.increment("bytes_loaded", BF16_ELEM_BYTES)
            raw_val = int(h) << 16
            fp32_val = struct.unpack("<f", struct.pack("<I", raw_val & 0xFFFFFFFF))[0]
            row_vals.append(fp32_val)

        slot = (base_row + i) % scpad.S
        for bank, val in enumerate(row_vals):
            if bank >= scpad.B:
                break
            scpad.banks[bank][slot] = val


# ============================================================
# DMA STORE: Scratchpad -> GMEM
# ============================================================
# Same legacy hooks as sdma_load (commented out).
def sdma_store(
    *,
    gmem: Memory,
    scpad: Scratchpad,
    spad_addr: int,
    gmem_base: int,
    tile_id: str,
    NR: int,
    NC: int,
    full_num_cols: Optional[int] = None,
    perf_metrics: Optional[PerfMetrics] = None,
):
    """Same NR/NC (N−1) convention and DRAM stride rules as sdma_load."""
    tile_rows = int(NR) + 1
    tile_cols = int(NC) + 1
    dram_stride_cols = _dram_stride_cols(
        tile_cols=tile_cols, full_num_cols=full_num_cols
    )
    base_row = _addr_to_row(scpad, spad_addr)

    for i in range(tile_rows):
        slot = (base_row + i) % scpad.S
        for j in range(tile_cols):
            bank = j
            if bank >= scpad.B:
                break
            val = scpad.banks[bank][slot]
            bits = struct.unpack("<I", struct.pack("<f", _scpad_cell_to_f32(val)))[0]
            bits = (bits >> 16) & 0xFFFF
            g_addr = int(gmem_base) + (i * dram_stride_cols + j) * BF16_ELEM_BYTES
            gmem.write_bf16_le(g_addr, bits)
            if perf_metrics is not None:
                perf_metrics.increment("bytes_stored", BF16_ELEM_BYTES)


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

    for i in range(64):
        gmem.write_data(i, i + 100)

    sdma_load(
        gmem=gmem,
        scpad=scpad,
        gmem_base=0,
        spad_addr=0,
        tile_id="A",
        NR=1,
        NC=4,
    )

    dump_scpad_rc(scpad=scpad)

    sdma_store(
        gmem=gmem,
        scpad=scpad,
        spad_addr=0,
        gmem_base=32,
        tile_id="A",
        NR=4,
        NC=4,
    )

    print("\nGMEM after STORE:")
    for i in range(16):
        print(32 + i, "->", gmem.read_data(32 + i))

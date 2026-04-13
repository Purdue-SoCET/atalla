import struct
from typing import Callable, Optional

# from matplotlib.pyplot import title

from ..misc.memory import Memory
from .scpad import Scratchpad
from .vector_register_file import VectorRegisterFile
from .perf_metrics import PerfMetrics

BF16_ELEM_BYTES = 2

def identity_swizzle(addr: int) -> int:
    return addr


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
    VM load semantics:
    - rs1 provides scratchpad byte address of tile base
    - rs2 provides row_id offset from addr_to_row(rs1)
    - num_cols is 0-indexed max column, so transfer width = num_cols + 1 lanes
    - lane i maps to bank i at the selected slot
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
    VM store semantics:
    - rs1 provides scratchpad byte address of tile base
    - rs2 provides row_id offset from addr_to_row(rs1)
    - num_cols is 0-indexed max column, so transfer width = num_cols + 1 lanes
    - lane i maps to bank i at the selected slot
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
    perf_metrics: PerfMetrics = None,
    swizzle: Callable[[int], int] = identity_swizzle,
):
    """
    for i in range(NR):
        for j in range(NC):
            SCPAD[(scpad_ptr * i) + j] = GMEM[ swizzle((gmem_ptr * i) + j) ]
    """

    tile_rows = int(NR) + 1
    tile_cols = int(NC) + 1
    dram_stride_cols = _dram_stride_cols(tile_cols=tile_cols, full_num_cols=full_num_cols)
    base_row = _addr_to_row(scpad, spad_addr)

    # Register tile metadata in scratchpad
    scpad.tiles[tile_id] = {
        "rows": tile_rows,
        "cols": tile_cols,
        "base_row": base_row,
    }

    for i in range(tile_rows):
        row_vals = []

        # Read from GMEM
        for j in range(tile_cols):
            g_addr = int(gmem_base) + (i * dram_stride_cols + j) * BF16_ELEM_BYTES
            g_addr = swizzle(g_addr)
            raw_val = gmem.read_data(g_addr)
            if perf_metrics is not None:
                # GMEM BF16 payload is 2 bytes per element.
                perf_metrics.increment("bytes_loaded", BF16_ELEM_BYTES)
            raw_val = raw_val << 16


            # 1. Pack the int into 4 bytes (little-endian 'I' for unsigned int)
            # 2. Unpack those 4 bytes as a float ('f')
            fp32_val = struct.unpack('<f', struct.pack('<I', raw_val & 0xFFFFFFFF))[0]

            row_vals.append(fp32_val)

        # Write into scratchpad banks
        slot = (base_row + i) % scpad.S
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
    spad_addr: int,
    gmem_base: int,
    tile_id: str,
    NR: int,
    NC: int,
    full_num_cols: Optional[int] = None,
    swizzle: Callable[[int], int] = identity_swizzle,
):
    """
    for i in range(NR):
        for j in range(NC):
            GMEM[(gmem_ptr * i) + j] = SCPAD[ swizzle((scpad_ptr * i) + j) ]
    """

    tile_rows = int(NR) + 1
    tile_cols = int(NC) + 1
    dram_stride_cols = _dram_stride_cols(tile_cols=tile_cols, full_num_cols=full_num_cols)
    base_row = _addr_to_row(scpad, spad_addr)

    for i in range(tile_rows):
        slot = (base_row + i) % scpad.S
        for j in range(tile_cols):
            bank = j
            if bank >= scpad.B:
                break
            val = scpad.banks[bank][slot]
            bits = struct.unpack('<I', struct.pack('<f', val))[0]
            bits = bits >> 16
            #x_shifted = struct.unpack('<f', struct.pack('<I', bits & 0xFFFFFFFF))[0]
            g_addr = int(gmem_base) + (i * dram_stride_cols + j) * BF16_ELEM_BYTES
            g_addr = swizzle(g_addr)
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
        spad_addr=0,
        tile_id="A",
        NR=1,
        NC=4
    )

    dump_scpad_rc(scpad=scpad)

    # STORE tile back
    sdma_store(
        gmem=gmem,
        scpad=scpad,
        spad_addr=0,
        gmem_base=32,
        tile_id="A",
        NR=4,
        NC=4
    )

    print("\nGMEM after STORE:")
    for i in range(16):
        print(32 + i, "->", gmem.read_data(32 + i))
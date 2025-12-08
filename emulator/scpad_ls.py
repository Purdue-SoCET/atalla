from typing import Callable
from memory import Memory
from scpad import Scratchpad


def identity_swizzle(addr: int) -> int:
    return addr


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

    for i in range(NR):
        row_vals = []

        # Read from GMEM
        for j in range(NC):
            g_addr = swizzle(gmem_base + i * NC + j)
            row_vals.append(gmem.read_data(g_addr))

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

    for i in range(NR):
        slot = (scpad_base_row + i) % scpad.S

        for j in range(NC):
            bank = j
            if bank >= scpad.B:
                break

            val = scpad.banks[bank][slot]
            g_addr = swizzle(gmem_base + i * NC + j)
            gmem.write_data(g_addr, val)

if __name__ == "__main__":
    gmem = Memory()
    scpad = Scratchpad(slots_per_bank=8)

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
        NR=4,
        NC=4
    )

    print("Scratchpad after LOAD:")
    for b in range(scpad.B):
        print(f"Bank {b}: {scpad.banks[b]}")

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

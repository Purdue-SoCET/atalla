NUM_BANKS = 32  

def composeinv(c, pi):
    return [y for x, y in sorted(zip(pi, c))]

def controlbits(pi):
    n = len(pi)
    m = 1
    while 1 << m < n:
        m += 1
    assert 1 << m == n

    if m == 1:
        return [pi[0]]
    p = [pi[x ^ 1] for x in range(n)]
    q = [pi[x] ^ 1 for x in range(n)]

    piinv = composeinv(list(range(n)), pi)
    p, q = composeinv(p, q), composeinv(q, p)

    c = [min(x, p[x]) for x in range(n)]
    p, q = composeinv(p, q), composeinv(q, p)
    for _ in range(1, m - 1):
        cp, p, q = composeinv(c, q), composeinv(p, q), composeinv(q, p)
        c = [min(c[x], cp[x]) for x in range(n)]

    f = [c[2 * j] % 2 for j in range(n // 2)]
    F = [x ^ f[x // 2] for x in range(n)]
    Fpi = composeinv(F, piinv)
    l = [Fpi[2 * k] % 2 for k in range(n // 2)]
    L = [y ^ l[y // 2] for y in range(n)]
    M = composeinv(Fpi, L)
    subM = [[M[2 * j + e] // 2 for j in range(n // 2)] for e in range(2)]
    subz = map(controlbits, subM)
    z = [s for s0s1 in zip(*subz) for s in s0s1]
    return f + z + l


class AddressBlock:
    @staticmethod
    def _row_lane(abs_row: int, cols: int):
        low5 = abs_row & (NUM_BANKS - 1)
        banks = [(lane ^ low5) & (NUM_BANKS - 1) for lane in range(NUM_BANKS)]
        slots = [abs_row] * NUM_BANKS
        valid = [(lane < cols) for lane in range(NUM_BANKS)]
        return banks, slots, valid

    @staticmethod
    def _col_lane(base_row: int, col_id: int, rows: int):
        banks = []
        slots = []
        valid = []
        for lane in range(NUM_BANKS):
            abs_row = base_row + lane
            bank = (col_id ^ (abs_row & (NUM_BANKS - 1))) & (NUM_BANKS - 1)
            banks.append(bank)
            slots.append(abs_row)
            valid.append(lane < rows)
        return banks, slots, valid


def permutation_for_shape(rows: int, cols: int):
    lane_bank, _, _ = AddressBlock._col_lane(
        base_row=rows,
        col_id=cols,
        rows=rows,
    )
    pi = list(lane_bank)
    assert sorted(pi) == list(range(NUM_BANKS)), "not a full permutation"
    return pi


def dump_controlbits_mem(filename: str):
    cb_len = len(controlbits(list(range(NUM_BANKS))))
    assert cb_len == 144

    hex_width = (cb_len + 3) // 4 

    with open(filename, "w") as f:
        for row_idx in range(NUM_BANKS):   
            rows = row_idx
            for col_idx in range(NUM_BANKS):  
                cols = col_idx

                pi = permutation_for_shape(rows, cols)
                cbits = controlbits(pi)  

                if rows == 5 and cols == 7:
                    print(pi)
                    print(cbits)

                bitstring = "".join(str(b) for b in reversed(cbits))
                value = int(bitstring, 2)
                f.write(f"{value:0{hex_width}X}\n")

    print(f"Wrote {filename} with 1024 lines of {cb_len}-bit control words.")


if __name__ == "__main__":
    dump_controlbits_mem("controlbits.mem")

import re
import sys
import math

FLOAT_RE = re.compile(r"np\.float32\(([^)]+)\)")

def parse_scratchpad(path: str, base_row: int = 1, rows: int = 4, cols: int = 4):
    # Expect lines like:
    # Bank 0: ['', np.float32(0.031982422), ...]
    banks = {}
    with open(path, "r") as f:
        for line in f:
            line = line.strip()
            if not line.startswith("Bank "):
                continue
            bank_id = int(line.split(":")[0].split()[1])
            vals_str = line.split(":", 1)[1]

            # Extract all np.float32(x) occurrences in order
            vals = [None] * 64
            floats = FLOAT_RE.findall(vals_str)

            # This dump includes '' placeholders; we can approximate by scanning tokens
            # More robust: tokenize by commas and pick float entries.
            tokens = [t.strip() for t in vals_str.strip()[1:-1].split(",")]  # inside [...]
            parsed = []
            for t in tokens:
                m = FLOAT_RE.search(t)
                if m:
                    parsed.append(float(m.group(1)))
                elif t.strip("'\"") == "":
                    parsed.append(None)
                else:
                    # sometimes prints like 1.0 without np.float32
                    try:
                        parsed.append(float(t))
                    except:
                        parsed.append(None)

            banks[bank_id] = parsed

    # Reconstruct tile: out[r][c] = bank[c][base_row + r]
    out = [[None for _ in range(cols)] for _ in range(rows)]
    for r in range(rows):
        for c in range(cols):
            out[r][c] = banks.get(c, [None] * 999)[base_row + r]
    return out

def parse_ref(path: str):
    ref = []
    with open(path, "r") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            ref.append([float(x) for x in line.split()])
    return ref

def main():
    if len(sys.argv) != 3:
        print("usage: python3 compare_softmax.py <scpad_out> <ref_out>")
        sys.exit(2)

    scpad_path, ref_path = sys.argv[1], sys.argv[2]

    got = parse_scratchpad(scpad_path, base_row=1, rows=4, cols=4)
    ref = parse_ref(ref_path)

    tol = 1e-3  # BF16-level tolerance (increased)
    ok = True

    print("Got (from scratchpad):")
    for r in got:
        print(" ".join("None" if v is None else f"{v:.9f}" for v in r))

    print("\nRef (PyTorch BF16-rounded):")
    for r in ref:
        print(" ".join(f"{v:.9f}" for v in r))

    print("\nDiffs:")
    for i in range(4):
        for j in range(4):
            gv = got[i][j]
            rv = ref[i][j]
            if gv is None:
                print(f"({i},{j}) missing in scratchpad")
                ok = False
                continue
            diff = abs(gv - rv)
            if diff > tol:
                print(f"({i},{j}) got={gv:.9f} ref={rv:.9f} diff={diff:.9f}  ❌")
                ok = False
            else:
                print(f"({i},{j}) got={gv:.9f} ref={rv:.9f} diff={diff:.9f}  ✅")

    if not ok:
        print("\nFAIL")
        sys.exit(1)
    print("\nPASS")

if __name__ == "__main__":
    main()
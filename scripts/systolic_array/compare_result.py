from __future__ import annotations
from dataclasses import dataclass
from typing import List

# ---------------- Matrix Data Class ----------------

@dataclass
class Matrix:
    test_num: int                  # e.g. 5
    matrix_idx: int                # e.g. 0,1,... inside that test
    data: List[List[int]]          # matrix data (uint16 hex values)


# ---------------- Parsing ----------------

def _parse_hex_row(line: str) -> List[int]:
    parts = [p.strip() for p in line.split(",") if p.strip()]
    row: List[int] = []
    for p in parts:
        if p.lower().startswith("0x"):
            p = p[2:]
        row.append(int(p, 16) & 0xFFFF)
    return row


def parse_matrices(file_path) -> List[Matrix]:
    """
    Returns flat list of Matrix objects.
    Each Matrix contains:
        test_num
        matrix_idx (within test)
        data
    """

    with open(file_path, "r") as f:
        text = f.read()

    matrices: List[Matrix] = []

    cur_test: int | None = None
    cur_data: List[List[int]] = []
    cur_idx: int = 0

    def flush():
        nonlocal cur_data, cur_idx
        if cur_test is not None and cur_data:
            matrices.append(Matrix(cur_test, cur_idx, cur_data))
            cur_idx += 1
            cur_data = []

    for raw in text.splitlines():
        line = raw.strip()

        # blank line → new matrix boundary
        if line == "":
            flush()
            continue

        # new test header
        if line.startswith("Test "):
            flush()

            # parse test number
            rest = line[len("Test "):].strip()
            num = ""
            for ch in rest:
                if ch.isdigit():
                    num += ch
                else:
                    break
            if num == "":
                raise ValueError(f"Invalid test header: {raw}")

            cur_test = int(num)
            cur_idx = 0
            continue

        # hex row
        row = _parse_hex_row(line)
        if row:
            cur_data.append(row)

    flush()
    return matrices


# ---------------- Access helpers ----------------

def get_matrix(mats: List[Matrix], test_num: int, matrix_idx: int) -> Matrix | None:
    for m in mats:
        if m.test_num == test_num and m.matrix_idx == matrix_idx:
            return m
    return None


# ---------------- Compare Matrices ----------------

def compare_matrices(expected_results, results):
    a_map = {(m.test_num, m.matrix_idx): m for m in expected_results}
    b_map = {(m.test_num, m.matrix_idx): m for m in results}

    keys = set(a_map) | set(b_map)

    for t, mid in sorted(keys):
        A = a_map.get((t, mid))
        B = b_map.get((t, mid))

        if A is None:
            print(f"Test {t} Matrix {mid} missing in expected_result")
            continue
        if B is None:
            print(f"Test {t} Matrix {mid} missing in result")
            continue

        isPass = True
        for r in range(len(A.data)):
            for c in range(len(A.data[r])):
                if int(A.data[r][c]) != int(B.data[r][c]):
                    print(f"Test {t} Matrix {mid} FAILED")
                    break
                    isPass = False

        if isPass:
            print(f"Test {t} Matrix {mid} PASSED")

def compare_results(expected_result_path, result_path):
    expected_results = parse_matrices(expected_result_path)
    results = parse_matrices(result_path)

    compare_matrices(expected_results, results)

# ---------------- Example usage ----------------

if __name__ == "__main__":
    import sys

    if len(sys.argv) != 2:
        print("Usage: python compare_result.py <file.txt>")
        raise SystemExit(2)

    mats = parse_matrices(sys.argv[1])

    # Print summary
    for m in mats:
        rows = len(m.data)
        cols = len(m.data[0]) if rows else 0
        print(f"Test {m.test_num} Matrix {m.matrix_idx} shape=({rows},{cols})")
        for row in m.data:
            print(",".join(f"0x{v:04X}" for v in row))

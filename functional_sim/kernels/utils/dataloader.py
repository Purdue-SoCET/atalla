from pathlib import Path
import numpy as np

def load_tile_data(data_path: Path, n: int) -> list:
    """Load an N×N tile from a CSV file and return a flat list of floats (row-major)."""
    tile = np.loadtxt(data_path, delimiter=',')
    if tile.ndim == 1:
        tile = tile.reshape(1, -1)
    if tile.shape != (n, n):
        raise ValueError(
            f"Tile shape mismatch: expected ({n}, {n}), got {tile.shape}. "
            f"Check --n and the data file."
        )
    return tile.flatten(order='C').tolist()
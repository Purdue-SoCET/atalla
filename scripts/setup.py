import os
import subprocess

def git_path() -> str:
    git_root = (
        subprocess.Popen(
            ["git", "rev-parse", "--show-toplevel"], stdout=subprocess.PIPE
        )
        .communicate()[0]
        .rstrip()
        .decode("utf-8")
    )
    return os.path.abspath(os.path.join(git_root))

ROOT_PATH = git_path()
OUT_DIR = f"{ROOT_PATH}/out"
os.makedirs(OUT_DIR, exist_ok=True)
path = os.path.expanduser("~/.bashrc")

with open(path, "a") as f:
    f.write(f"\nexport ATALLA_ROOT={ROOT_PATH}\n")
    f.write(f"\nexport UVM_HOME={ROOT_PATH}/UVM_1.2\n")
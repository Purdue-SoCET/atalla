#!/usr/bin/env python3
"""
Shmoo Cleanup & Kill Script
---------------------------
Forcefully terminates all running parallel shmoo jobs (bash scripts)
and deletes the generated .sh files. Retains all .log files.
"""

import subprocess
import sys
from pathlib import Path

def main():
    print("╔══════════════════════════════════════════╗")
    print("║        Shmoo Process Killer & Cleanup    ║")
    print("╚══════════════════════════════════════════╝")
    print("This script will:")
    print("  1. Kill all running shmoo_overnight*.sh processes")
    print("  2. Kill all running shmoo_generated_adders*.sh processes")
    print("  3. Delete the generated .sh scripts in the current directory")
    print("  4. KEEP all .log files intact\n")
    
    confirm = input("Are you sure you want to proceed? [y/N]: ").strip().lower()
    if confirm != 'y':
        print("Aborted.")
        sys.exit(0)

    print("\n--- 1. Terminating Processes ---")
    
    # pkill searches the full command line (-f) and sends SIGTERM.
    # It returns 0 if it killed something, 1 if no matching process was found.
    targets = ["shmoo_overnight", "shmoo_generated_adders"]
    for target in targets:
        cmd = f"pkill -f {target}"
        print(f"Executing: {cmd}")
        result = subprocess.run(cmd, shell=True, capture_output=True)
        if result.returncode == 0:
            print(f"  -> Successfully sent kill signal to '{target}' processes.")
        else:
            print(f"  -> No running processes found matching '{target}'.")

    print("\n--- 2. Cleaning up Shell Scripts ---")
    cwd = Path.cwd()
    deleted_count = 0
    
    # Gather both types of generated shell scripts
    sh_files = list(cwd.glob("shmoo_overnight*.sh")) + list(cwd.glob("shmoo_generated_adders*.sh"))
    
    # CRITICAL: Filter out the templates so we don't accidentally delete your master files
    files_to_delete = [f for f in sh_files if "template" not in f.name.lower()]

    if not files_to_delete:
        print("  -> No generated shell scripts found to delete.")
    else:
        for f in files_to_delete:
            try:
                f.unlink()
                print(f"  -> Deleted: {f.name}")
                deleted_count += 1
            except Exception as e:
                print(f"  -> ERROR: Failed to delete {f.name} - {e}")

    print(f"\nCleanup complete! Deleted {deleted_count} shell script(s).")
    print("All .log files have been preserved. You can now safely run your launcher script again.")

if __name__ == "__main__":
    main()

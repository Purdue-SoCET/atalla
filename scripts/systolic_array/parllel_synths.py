#!/usr/bin/env python3
"""
Parallel Shmoo Launcher (Single Batch Mode)
-----------------------
- Asks user for N (number of parallel jobs)
- Scans backup .tar.gz files to determine already-completed alignTree configs
- Takes ONLY the first N remaining configs
- Divides those configs across N Flowkit instances (1 per instance)
- Copies and patches template scripts for each job
- Launches all jobs in parallel with timestamped logging
"""

import os
import re
import sys
import shutil
import subprocess
import itertools
from pathlib import Path
from datetime import datetime

# ==========================================
# CONFIG — edit these paths as needed
# ==========================================
HOME                  = Path.home()
MASTER_MODULES_DIR    = Path.cwd() / "master_modules_32"
BACKUP_DIR            = Path("/home/asicfab/a/karania/atalla/reports/sysarr_32_input_fp_adder")
TEMPLATE_OVERNIGHT    = Path.cwd() / "shmoo_overnight_template.sh"
TEMPLATE_ADDERS       = Path.cwd() / "shmoo_generated_adders_template.sh"
NTFY_TOPIC            = "karani-xbskdh-shmoo-alert"

# All 5-bit alignTree configs from 00000 to 11111
ALL_CONFIGS = [format(i, '05b') for i in range(32)]  # 00000 → 11111

OFF_LIMITS_CONFIGS = {"00000"}
# ==========================================
# HELPERS
# ==========================================

def timestamp() -> str:
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S")

def log(msg: str):
    print(f"[{timestamp()}] {msg}")

def get_completed_configs() -> set:
    """Scan backup dir for .tar.gz files and extract completed alignTree configs."""
    completed = set()
    if not BACKUP_DIR.exists():
        log(f"WARNING: Backup directory not found: {BACKUP_DIR}")
        return completed
    for f in BACKUP_DIR.glob("backup_alignTree_*_*.tar.gz"):
        m = re.search(r"backup_alignTree_([01]{5})_", f.name)
        if m:
            completed.add(m.group(1))
    return completed

def check_flowkit(n: int) -> Path:
    """Verify Flowkit{n} directory exists; raise if not."""
    fk = HOME / f"Flowkit{n}" / "Flowkit"
    if not fk.exists():
        raise FileNotFoundError(
            f"Flowkit directory not found: {fk}\n"
            f"  → Please create it before launching instance {n}."
        )
    return fk

def copy_and_patch_scripts(instance_n: int, flowkit_dir: Path, configs: list[str]) -> tuple[Path, Path]:
    """
    Copy both templates into cwd as shmoo_overnight{n}.sh and
    shmoo_generated_adders{n}.sh, then patch all instance-specific values.
    Returns (overnight_path, adders_path).
    """
    overnight_dst = Path.cwd() / f"shmoo_overnight{instance_n}.sh"
    adders_dst    = Path.cwd() / f"shmoo_generated_adders{instance_n}.sh"

    # --- Copy templates ---
    shutil.copy2(TEMPLATE_OVERNIGHT, overnight_dst)
    shutil.copy2(TEMPLATE_ADDERS,    adders_dst)

    # Since we are in single-batch mode, there's exactly 1 config per instance
    target_config = configs[0]
    target_adder_tree = f"alignTree_{target_config}"

    # --- Patch overnight script ---
    text = overnight_dst.read_text()
    
    # 1. Globally replace ANY hardcoded alignTree_XXXXX with the target one
    text = re.sub(r'alignTree_[01]{5}', target_adder_tree, text)
    
    # 2. Replace reference to the adders script
    text = re.sub(r'shmoo_generated_adders\w*\.sh',
                  f'shmoo_generated_adders{instance_n}.sh', text)
                  
    # 3. Replace ntfy notification string
    text = re.sub(r'(curl\s+-d\s+["\']).*?(["\'])',
                  lambda m: f'{m.group(1)}shmoo_overnight{instance_n} done{m.group(2)}',
                  text)
    overnight_dst.write_text(text)
    overnight_dst.chmod(0o755)

    # --- Patch adders script ---
    text = adders_dst.read_text()
    
    # 1. Globally replace ANY hardcoded alignTree_XXXXX with the target one
    text = re.sub(r'alignTree_[01]{5}', target_adder_tree, text)
    
    # 2. Point FLOWKIT_DIR to the correct Flowkit{n}
    text = re.sub(r'(FLOWKIT_DIR\s*=\s*")[^"]*(")',
                  f'\\1{flowkit_dir}\\2', text)
    text = re.sub(r"(FLOWKIT_DIR\s*=\s*')[^']*(')",
                  f"\\1{flowkit_dir}\\2", text)
                  
    adders_dst.write_text(text)
    adders_dst.chmod(0o755)

    return overnight_dst, adders_dst


def divide_configs(configs: list[str], n: int) -> list[list[str]]:
    """Round-robin distribute configs across N instances as evenly as possible."""
    buckets: list[list[str]] = [[] for _ in range(n)]
    for i, cfg in enumerate(configs):
        buckets[i % n].append(cfg)
    return buckets


def launch_instance(instance_n: int, overnight_script: Path, log_file: Path) -> subprocess.Popen:
    """Launch overnight script in background with timestamped log output."""
    cmd = (
        f'bash {overnight_script} 2>&1 '
        f'| awk \'{{ print strftime("[%Y-%m-%d %H:%M:%S]"), $0; fflush() }}\' '
        f'>> {log_file}'
    )
    proc = subprocess.Popen(cmd, shell=True, executable="/bin/bash")
    return proc


def print_job_table(assignments: list[dict]):
    """Pretty-print a summary table of all parallel jobs."""
    col_w = max(len(str(a["configs"])) for a in assignments) + 2
    header = f"{'Instance':<10} {'Flowkit Dir':<35} {'Log File':<28} {'# Configs':<10} {'alignTree Configs'}"
    print()
    print("=" * (len(header) + 5))
    print(" PARALLEL SHMOO JOB PLAN ".center(len(header) + 5, "="))
    print("=" * (len(header) + 5))
    print(header)
    print("-" * (len(header) + 5))
    for a in assignments:
        cfg_str = ", ".join(a["configs"]) if a["configs"] else "(none)"
        print(f"  Job {a['n']:<6} {str(a['flowkit']):<35} {a['log']:<28} {len(a['configs']):<10} {cfg_str}")
    print("=" * (len(header) + 5))
    print()


# ==========================================
# MAIN
# ==========================================

def main():
    print()
    print("╔══════════════════════════════════════════╗")
    print("║      Parallel Shmoo Launcher             ║")
    print("╚══════════════════════════════════════════╝")
    print()

    # 1. Get N from user
    while True:
        try:
            raw = input("Enter the number of parallel shmoo instances (N): ").strip()
            n = int(raw)
            if n < 1:
                raise ValueError
            break
        except ValueError:
            print("  Please enter a positive integer.")

    # 2. Check templates exist
    for tmpl in (TEMPLATE_OVERNIGHT, TEMPLATE_ADDERS):
        if not tmpl.exists():
            log(f"ERROR: Template not found: {tmpl}")
            sys.exit(1)

    # 3. Check all Flowkit{n} dirs exist upfront before doing anything else
    flowkit_dirs: dict[int, Path] = {}
    errors = []
    for i in range(1, n + 1):
        try:
            flowkit_dirs[i] = check_flowkit(i)
        except FileNotFoundError as e:
            errors.append(str(e))
    if errors:
        print()
        for e in errors:
            log(f"ERROR: {e}")
        print()
        log("Aborting — fix the missing Flowkit directories and re-run.")
        sys.exit(1)

    # 4. Determine which configs are already done
    log("Scanning backup directory for completed alignTree configs...")
    completed = get_completed_configs()
    remaining = [c for c in ALL_CONFIGS if c not in completed and c not in OFF_LIMITS_CONFIGS]

    log(f"Total configs:     {len(ALL_CONFIGS)}  (00000 → 11111)")
    log(f"Already completed: {len(completed)}   {sorted(completed) if completed else '(none)'}")
    log(f"Remaining to run:  {len(remaining)}")

    if not remaining:
        log("All configs already completed. Nothing to do.")
        sys.exit(0)

    # 5. Limit work to ONLY the first N remaining configurations
    configs_to_run = remaining[:n]
    log(f"Single batch limit requested: running ONLY the first {len(configs_to_run)} configs from the remaining list.")

    # Divide only this single batch across N instances
    buckets = divide_configs(configs_to_run, n)

    # 6. Build assignment metadata
    assignments = []
    for i in range(1, n + 1):
        assignments.append({
            "n":       i,
            "flowkit": flowkit_dirs[i],
            "configs": buckets[i - 1],
            "log":     f"shmoo_overnight{i}.log",
        })

    # 7. Show job plan and ask for confirmation
    print_job_table(assignments)

    confirm = input("Proceed with launching all jobs? [y/N]: ").strip().lower()
    if confirm != "y":
        log("Aborted by user.")
        sys.exit(0)

    # 8. Copy & patch scripts, then launch
    procs: list[tuple[int, subprocess.Popen]] = []
    for a in assignments:
        if not a["configs"]:
            log(f"Instance {a['n']}: no configs assigned, skipping.")
            continue

        log(f"Instance {a['n']}: copying and patching scripts...")
        overnight_script, _ = copy_and_patch_scripts(
            a["n"], a["flowkit"], a["configs"]
        )

        log_file = Path.cwd() / a["log"]
        log(f"Instance {a['n']}: launching → {a['log']}")
        proc = launch_instance(a["n"], overnight_script, log_file)
        procs.append((a["n"], proc))

    print()
    log(f"All {len(procs)} instance(s) launched. Waiting for completion...")
    log("You can follow progress with:  tail -f shmoo_overnight<N>.log")
    print()

    # 9. Wait for all and report (includes basic Ctrl+C catching)
    overall_ok = True
    try:
        for instance_n, proc in procs:
            ret = proc.wait()
            if ret == 0:
                log(f"Instance {instance_n} completed successfully (exit 0).")
            else:
                log(f"ERROR: Instance {instance_n} exited with code {ret}.")
                overall_ok = False
    except KeyboardInterrupt:
        print()
        log("Ctrl+C detected! Aborting and sending kill signal to parallel jobs...")
        
        # 1. Kill the bash wrapper scripts
        subprocess.run("pkill -f shmoo_overnight", shell=True)
        subprocess.run("pkill -f shmoo_generated_adders", shell=True)
        
        # 2. Kill the orphaned EDA tools they spawned (add any others you use)
        subprocess.run(f"pkill -u {os.environ.get('USER')} -x 'genus|innovus|virtuoso'", shell=True)
        
        log("Cleanup complete. Exiting.")
        sys.exit(1)

    print()
    if overall_ok:
        log("All shmoo instances finished successfully.")
    else:
        log("One or more instances finished with errors — check the logs above.")
    sys.exit(0 if overall_ok else 1)


if __name__ == "__main__":
    main()

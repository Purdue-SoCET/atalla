import argparse
import json

from src.emulator import run 
from src.misc.memory import Memory
from src.components.scalar_register_file import ScalarRegisterFile
from src.components.vector_register_file import VectorRegisterFile
from src.components.execute import ExecuteUnit
from src.components.scpad import Scratchpad

if __name__ == "__main__":

    ap = argparse.ArgumentParser(description="AI Chip Emulator")
    ap.add_argument("--input_file", type=str, default="./tests/complex/edit_mem.in", help="Path to memory initialization file")
    ap.add_argument("--packet_length", type=int, default=4, help="Number of instructions per packet (default=4)")
    ap.add_argument("--output_mem_file", type=str, default="./out/output_mem.out", help="Path to output file")
    ap.add_argument("--output_sreg_file", type=str, default="./out/output_sregs.out", help="Path to output scalar registers file")
    ap.add_argument("--output_vreg_file", type=str, default="./out/output_vregs.out", help="Path to output vector registers file")
    ap.add_argument("--output_mreg_file", type=str, default="./out/output_mregs.out", help="Path to output matrix registers file")
    ap.add_argument("--output_scpad_file0", type=str, default="./out/output_scpad0.out", help="Path to output scratchpad 0 file")
    ap.add_argument("--output_scpad_file1", type=str, default="./out/output_scpad1.out", help="Path to output scratchpad 1 file")
    ap.add_argument("--metrics_json", type=str, default="", help="Optional path to write perf metrics JSON")
    ap.add_argument("--conv_marker_addr", type=lambda x: int(x, 0), default="0x90", help="Marker address for conv-only scoped metrics")
    ap.add_argument("--debug", action="store_true", help="Enable debug mode with verbose output")
    args = ap.parse_args()

    mem = Memory(args.input_file)

    sregs = ScalarRegisterFile()
    mregs = ScalarRegisterFile(num_regs=16) # Mask Registers (32-bit for 32-element vectors)
    vregs = VectorRegisterFile() 
    SP0 = Scratchpad(slots_per_bank=32)
    SP1 = Scratchpad(slots_per_bank=32)
    EU = ExecuteUnit()

    pc = 0x00000000  

    print(f"[INFO] Setup complete. Starting emulation with packet length {args.packet_length}...\n")

    metrics = run(
        mem, sregs, mregs, vregs, SP0, SP1, EU, pc, args.packet_length,
        args.output_mem_file, args.output_sreg_file, args.output_vreg_file, args.output_mreg_file,
        args.output_scpad_file0, args.output_scpad_file1,
        debug=args.debug,
        conv_marker_addr=args.conv_marker_addr,
    )

    whole = metrics["whole_run"]
    conv = metrics["conv_region"]
    print("[PERF] Whole run:")
    print(
        f"  instr={whole['instr_retired']} ops={whole['ops_modeled']:.1f} "
        f"bytes_loaded={whole['bytes_loaded']} bytes_stored={whole['bytes_stored']} "
        f"AI(load)={whole['arithmetic_intensity_loaded']:.6f} est_cycles={whole['estimated_cycles']:.1f}"
    )
    print("[PERF] Conv region:")
    print(
        f"  instr={conv['instr_retired']} ops={conv['ops_modeled']:.1f} "
        f"bytes_loaded={conv['bytes_loaded']} bytes_stored={conv['bytes_stored']} "
        f"AI(load)={conv['arithmetic_intensity_loaded']:.6f} est_cycles={conv['estimated_cycles']:.1f}"
    )

    if args.metrics_json:
        with open(args.metrics_json, "w") as f:
            json.dump(metrics, f, indent=2)
        print(f"[PERF] Wrote metrics JSON: {args.metrics_json}")

# python3 -m run --input_file ./tests/complex/edit_mem.in 
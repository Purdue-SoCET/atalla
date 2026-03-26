import argparse

try:
    from .src.functional_sim import run
    from .src.misc.memory import Memory
    from .src.components.scalar_register_file import ScalarRegisterFile
    from .src.components.vector_register_file import VectorRegisterFile
    from .src.components.execute import ExecuteUnit
    from .src.components.scpad import Scratchpad
except Exception:
    from src.functional_sim import run
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
    ap.add_argument("--output_perf_file", type=str, default="./out/output_perf_metrics.out", help="Path to output performance metrics file")
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

    run(mem, sregs, mregs, vregs, SP0, SP1, EU, pc, args.packet_length, args.output_mem_file, args.output_sreg_file, args.output_vreg_file, args.output_mreg_file, args.output_scpad_file0, args.output_scpad_file1, args.output_perf_file, debug=args.debug)

# python3 -m run --input_file ./tests/complex/edit_mem.in 
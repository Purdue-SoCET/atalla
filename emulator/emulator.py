"""
emulator.py
------------
Test harness for the memory subsystem.
Loads memory contents from an input file, prints them, and writes them back out.
"""

# Support both package and standalone execution
try:
    from .memory import Memory
except ImportError:
    from memory import Memory


def main():
    mem_file = "mem.txt"
    out_file = "output_mem.txt"

    # Load memory
    mem = Memory(mem_file)
    print(f"[INFO] Loaded {len(mem)} memory entries from '{mem_file}'.")

    # Print all loaded memory entries
    print("\n--- Memory Contents ---")
    for addr in sorted(mem.mem.keys()):
        print(f"0x{addr:08X}: 0x{mem.read(addr):08X}")

    # Write new data
    mem.write(0x10, 0xCAFEBABE)

    # Dump memory to output file
    mem.dump_to_file(out_file)
    print(f"\n[INFO] Wrote updated memory to '{out_file}'.")


if __name__ == "__main__":
    main()

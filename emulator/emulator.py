"""
emulator.py
------------
Test harness for the memory subsystem.
Loads memory contents from an input file, prints them, and writes them back out.
"""

# Support both package and standalone execution
try:
    from .memory import Memory
    from .scalar_register_file import RegisterFile
except ImportError:
    from memory import Memory
    from scalar_register_file import RegisterFile

def decode(instruction):
    """
    Decodes a 32-bit instruction based on the custom 7-8-8-8 format:
    Bits 31:     Unused
    Bits 30-23:  rs2 / immediate (8 bits)
    Bits 22-15:  rs1 (8 bits)
    Bits 14-7:   rd (8 bits)
    Bits 6-0:    opcode (7 bits)
    """
    opcode = instruction & 0x7F       # bits 6:0
    rd = (instruction >> 7) & 0xFF    # bits 14:7
    rs1 = (instruction >> 15) & 0xFF  # bits 22:15
    
    # This field is used for both rs2 and the immediate
    field4 = (instruction >> 23) & 0xFF # bits 30:23
    
    # --- Instruction Set ---
    # We will invent opcodes for this example.
    
    # Opcode 0x01: 'ADD' (R-type) uses rd, rs1, rs2
    if opcode == 0x01:
        return {
            'name': 'ADD',
            'rd': rd,
            'rs1': rs1,
            'rs2': field4  # Use field4 as rs2
        }

    # Opcode 0x02: 'ADDI' (I-type) uses rd, rs1, imm
    elif opcode == 0x02:
        # We need to sign-extend the 8-bit immediate
        imm = field4
        if (imm & 0x80):  # if 7th bit (MSB) is 1
            imm = imm - 0x100  # Compute two's complement (e.g., 0xFF becomes -1)
            
        return {
            'name': 'ADDI',
            'rd': rd,
            'rs1': rs1,
            'imm': imm  # Use field4 as immediate
        }
    
    # Fallback for any other opcode
    return {
        'name': 'UNKNOWN',
        'opcode': opcode
    }

def execute(decoded_inst, regs):
    """
    Executes the logic for a decoded instruction.
    Updates the 'regs' (RegisterFile) object.
    """
    name = decoded_inst['name']

    if name == 'ADD':
        rd = decoded_inst['rd']
        rs1_val = regs.read(decoded_inst['rs1'])
        rs2_val = regs.read(decoded_inst['rs2'])
        
        result = rs1_val + rs2_val
        regs.write(rd, result)
        print(f"[EXEC] ADD x{rd}, x{decoded_inst['rs1']}, x{decoded_inst['rs2']}  (Result: 0x{result:08X})")

    elif name == 'ADDI':
        rd = decoded_inst['rd']
        rs1_val = regs.read(decoded_inst['rs1'])
        imm_val = decoded_inst['imm']

        result = rs1_val + imm_val
        regs.write(rd, result)
        print(f"[EXEC] ADDI x{rd}, x{decoded_inst['rs1']}, {imm_val}  (Result: 0x{result:08X})")
        
    elif name == 'UNKNOWN':
        print(f"[ERROR] Unknown instruction with opcode 0x{decoded_inst['opcode']:X}")


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

    # Initialize Registers and Program Counter
    regs = RegisterFile()  # <-- This works because you imported it
    pc = 0x00000000  # Program Counter, starts at address 0

    print("\n--- Starting Simulation ---")

    # 2. Main Simulation Loop
    while True:
        # 3. Fetch
        instruction_word = mem.read(pc)
        
        if instruction_word == 0:
            print(f"\n[INFO] Reached end of program (instruction is 0x0 at 0x{pc:08X}). Halting.")
            break
        
        print(f"\n--- PC: 0x{pc:08X} ---")
        print(f"[FETCH] Read 0x{instruction_word:08X}")

        # 4. Decode
        decoded_inst = decode(instruction_word)
        print(f"[DECODE] {decoded_inst}")

        # 5. Execute
        execute(decoded_inst, regs)

        # 6. Advance Program Counter
        pc += 4  # Move to the next 4-byte instruction

    # Dump scalar regs to output file
    out_regs_file = "output_regs.txt"
    regs.dump_to_file(out_regs_file)
    print(f"\n[INFO] Wrote final register state to '{out_regs_file}'.")

    # Dump regs to terminal
    # print("\n--- Final Register State ---")
    # print(regs)

    # Write new data
    # mem.write(0x10, 0xCAFEBABE)

    # Dump memory to output file
    mem.dump_to_file(out_file)
    print(f"\n[INFO] Wrote updated memory to '{out_file}'.")


if __name__ == "__main__":
    main()

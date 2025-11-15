"""
emulator.py
------------
Test harness for the memory subsystem.
Loads memory contents from an input file, prints them, and writes them back out.
"""

# Support both package and standalone execution
try:
    from .memory import Memory
    from .scalar_register_file import ScalarRegisterFile
    from .vector_register_file import VectorRegisterFile
    from .decode import decode_packet
    from .execute import ExecuteUnit
except ImportError:
    from memory import Memory
    from scalar_register_file import ScalarRegisterFile
    from vector_register_file import VectorRegisterFile
    from decode import decode_packet
    from execute import ExecuteUnit

def main():
    mem_file = "mem.txt"
    out_file = "output_mem.txt"
    out_reg_file = "output_regs.txt"

    # Load memory
    mem = Memory(mem_file)
    #print(f"[INFO] Loaded {len(mem)} memory entries from '{mem_file}'.")

    # Print all loaded memory entries
    print("\n--- Inst Mem Contents ---")
    for addr in sorted(mem.instr_mem.keys()):
        print(f"0x{addr:08X}: 0x{mem.read_instr(addr):08X}")

    print("\n--- Data Mem Contents ---")
    for addr in sorted(mem.data_mem.keys()):
        print(f"0x{addr:08X}: 0x{mem.read_data(addr):08X}")

    # Initialize Registers and Program Counter
    sregs = ScalarRegisterFile()
    mregs = ScalarRegisterFile(num_regs=2)
    vregs = VectorRegisterFile()
    pc = 0x00000000  # Program Counter, starts at address 0

    #eecute object
    EU = ExecuteUnit()


    halt = False
    while(not(halt)):
        dec_packet = decode_packet(mem.read_instr(pc))
        print(pc)
        print(mem.read_instr(pc))
        print(dec_packet)
        br = False
        

        for inst in dec_packet:
            m = inst['mnemonic']
            if(m == "nop.s" or m == "barrier.s"):
                continue
            elif(m == "halt.s"):
                halt = True
            elif(m == "jal" or m == "jalr" or inst['type'] == "BR"):
                br = True
                if(m == "jal"):
                    brtarg = pc + (inst['imm'])
                    sregs.write(inst['rd'], pc + 20)
                elif(m == "jalr"):
                    brtarg = sregs.read(inst['rs1']) + (inst['imm'])
                    sregs.write(inst['rd'], pc + 20)
                elif(m == "beq.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) == sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 20
                elif(m == "bne.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) != sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 20
                elif(m == "blt.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) < sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 20
                elif(m == "bge.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) >= sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 20
                elif(m == "bgt.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) > sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 20
                elif(m == "ble.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) <= sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 20
            elif(m == "lw.s"):
                sregs.write(inst['rd'], mem.read_data(sregs.read(inst['rs1']) + inst['imm']))
            elif(m == "sw.s"):
                mem.write_data(sregs.read(inst['rs1']) + inst['imm'], inst['rd'])
            #vector load/store here

            #spad movement here
            elif(m == "lui.s"):
                mem.write_data(inst['rd'], (inst['imm']<<7))
            elif(m == "mv.mts"):
                sregs.write(inst['rd'], mregs.read(inst['vms']))
            elif(m == "mv.stm"):
                mregs.write(inst['vmd'], sregs.read(inst['rs1']))
            elif m in ("add.s", "addi.s", "add.bf"):
                if(m == "add.s" or m == "add.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("sub.s", "subi.s", "sub.bf"):
                if(m == "sub.s" or m == "sub.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("mul.s", "muli.s", "mul.bf"):
                if(m == "mul.s" or m == "mul.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("div.s", "divi.s", "div.bf"):
                if(m == "div.s" or m == "div.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("mod.s", "modi.s"):
                if(m == "mod.s"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("or.s", "ori.s"):
                if(m == "or.s"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("and.s", "andi.s"):
                if(m == "and.s"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("xor.s", "xori.s"):
                if(m == "xor.s"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("sll.s", "slli.s"):
                if(m == "sll.s"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("srl.s", "srli.s"):
                if(m == "srl.s"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("sra.s", "srai.s"):
                if(m == "sra.s"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("slt.s", "slti.s", "slt.bf"):
                if(m == "slt.s" or m == "slt.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("sltu.s", "sltui.s", "sltu.bf"):
                if(m == "sltu.s" or m == "sltu.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m == "stbf.s":
                src1 = sregs.read(inst['rs1'])
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m == "bfts.s":
                src1 = sregs.read(inst['rs1'])
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m.endswith(".vv"):
                src1 = sregs.read(inst['vs1'])
                src2 = sregs.read(inst['vs2'])
                WBdata = EU.execute(m, vA=src1, vB=src2)
                sregs.write(inst['rd'], WBdata)
            # ---------------- VI (Vector-Immediate) ----------------
            elif m.endswith(".vi"):
                src1 = sregs.read(inst['vs1'])
                src2 = inst['imm']
                WBdata = EU.execute(m, vA=src1, vB=src2)
                sregs.write(inst['rd'], WBdata)
            # ---------------- VS (Vector-Scalar) ----------------
            elif m.endswith(".vs"):
                src1 = sregs.read(inst['vs1'])
                src2 = sregs.read(inst['rs1'])
                WBdata = EU.execute(m, vA=src1, vB=src2)
                sregs.write(inst['rd'], WBdata)

            # ---------------- UNKNOWN ----------------
            else:
                raise ValueError(f"Unknown mnemonic: {m}")
            
        
        if(br):
            pc = brtarg
        else:
            pc = pc + 20


    # Dump memory to output file
    #sregs.dump_to_file(out_reg_file)
    mem.dump_to_file(out_file)
    print(f"\n[INFO] Wrote updated memory to '{out_file}'.")


if __name__ == "__main__":
    main()

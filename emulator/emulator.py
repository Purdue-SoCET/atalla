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
    from .scpad import Scratchpad
    from .scpad_ls import *
    import struct
    from typing import Sequence, List
except ImportError:
    from memory import Memory
    from scalar_register_file import ScalarRegisterFile
    from vector_register_file import VectorRegisterFile
    from decode import decode_packet
    from execute import ExecuteUnit
    from scpad import Scratchpad
    from scpad_ls import *
    import struct
    from typing import Sequence, List

def apply_mask(
        v1: np.ndarray, #the old vector
        v2: np.ndarray, #the new vector
        mask: int) -> np.ndarray:
    v1 = np.asarray(v1)
    v2 = np.asarray(v2)

    assert v1.shape == v2.shape, "Vectors must be same shape"

    # Create boolean mask vector from scalar mask
    # bit i of mask applies to lane i
    mask_vec = ((mask >> np.arange(v1.size)) & 1).astype(bool)

    # Select values
    return np.where(mask_vec, v2, v1)

def fp32_to_hex(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]

def hex_to_fp32(x):
    return struct.unpack('<f', struct.pack('<I', x & 0xFFFFFFFF))[0]

def apply_imm_vector_op(
    imm: int,
    vs: Sequence[np.float32],
    r_in: np.float32,
) -> List[np.float32]:
    # Immediate field extraction
    imm6 = (imm >> 6) & 1
    imm5 = (imm >> 5) & 1
    idx  = imm & 0b1_1111  # imm[0:4]

    print(imm6)
    print(imm5)
    print(idx)

    vl = len(vs)
    zero = np.float32(0.0)

    vd: List[np.float32] = [zero] * vl

    for i in range(vl):
        if imm6:
            vd[i] = r_in
        elif imm5:
            vd[i] = r_in if i == idx else zero
        else:
            vd[i] = r_in if i == idx else vs[i]

    return vd


def main():
    mem_file = "Testing/unit_tests/bf_R.txt" # need to change this to target different mem test files
    out_file = "output_mem.txt"
    out_sreg_file = "output_sregs.txt"
    out_vreg_file = "output_vregs.txt"
    out_mreg_file = "output_mregs.txt"

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
    mregs = ScalarRegisterFile(num_regs=16)
    vregs = VectorRegisterFile()
    gemm_weights = np.zeros((32, 32))
    num_weights = 0
    pc = 0x00000000  # Program Counter, starts at address 0

    #eecute object
    EU = ExecuteUnit()

    #Scratchpad object
    SP0 = Scratchpad(slots_per_bank=32)
    SP1 = Scratchpad(slots_per_bank=32)
    tile_id0 = 0
    tile_id1 = 0
    # Dic for storing tileID and addr
    tileID0Dict = {}
    tileID1Dict = {}


    halt = False
    while(not(halt)):
        dec_packet = decode_packet(mem.read_instr(pc))
        print(pc)
        # print(mem.read_instr(pc))
        for item in dec_packet:
            print(item)
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
                    sregs.write(inst['rd'], pc + 24)
                elif(m == "jalr"):
                    brtarg = sregs.read(inst['rs1']) + (inst['imm'])
                    sregs.write(inst['rd'], pc + 24)
                elif(m == "beq.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) == sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 24
                elif(m == "bne.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) != sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 24
                elif(m == "blt.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) < sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 24
                elif(m == "bge.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) >= sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 24
                elif(m == "bgt.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) > sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 24
                elif(m == "ble.s"):
                    sregs.write(inst['rs1'], sregs.read(inst['rs1']) + inst['incr_imm'])
                    if(sregs.read(inst['rs1']) <= sregs.read(inst['rs2'])):
                        brtarg = pc + (inst['imm'])
                    else:
                        brtarg = pc + 24
            elif(m == "lw.s"):
                sregs.write(inst['rd'], mem.read_data(sregs.read(inst['rs1']) + inst['imm']))
            elif(m == "sw.s"):
                mem.write_data(sregs.read(inst['rs1']) + inst['imm'], sregs.read(inst['rd']))
            elif(m == "lhw.s"):
                temp = mem.read_data(sregs.read(inst['rs1']) + inst['imm'])
                temp = temp << 16
                print(temp)
                sregs.write(inst['rd'], temp)
            elif(m == "shw.s"):
                temp = sregs.read(inst['rd'])
                temp = temp >> 16
                mem.write_data(sregs.read(inst['rs1']) + inst['imm'], temp)
            #vector load/store here
            elif m == "vreg.ld":
                # # 1. Select Scratchpad based on 'sp' field (0=SP0, 1=SP1)
                # if inst.get('sp', 0) == 1 
                if inst['sid'] == 1:
                    target_sp = SP1 
                else:
                    target_sp = SP0
                
                # 2. Get address from Scalar Register (rs1)
                addr = sregs.read(inst['rs1'])
                
                # 3. Call the interface function
                scpad_to_vreg(
                    scpad=target_sp,
                    vregs=vregs,
                    scpad_addr=addr,
                    vd=inst['vd'],        # Destination Vector Reg
                    rc=inst['rc'],
                    # rc=inst.get('rc', 0)  # 0=Row Mode, 1=Col Mode
                )

            elif m == "vreg.st":
                # 1. Select Scratchpad
                # target_sp = SP1 if inst.get('sp', 0) == 1 else SP0
                if inst['sid'] == 1:
                    target_sp = SP1 
                else:
                    target_sp = SP0
                
                # 2. Get address
                addr = sregs.read(inst['rs1'])
                
                # 3. Call the interface function
                vreg_to_scpad(
                    scpad=target_sp,
                    vregs=vregs,
                    scpad_addr=addr,
                    vs=inst['vd'],        # VM-type uses 'vd' field as the register index
                    rc=inst['rc']
                    # rc=inst.get('rc', 0)
                )

            #scpad load/store here

            elif(m == "scpad.ld"):
                if inst['sid'] == 0:
                    if(inst['rs1/rd1'] in tileID0Dict.keys()):
                        localID = tileID0Dict[inst['rs1/rd1']]
                    else:
                        tile_id0 += 1
                        tileID0Dict[inst['rs1/rd1']] = tile_id0
                        localID = tileID0Dict[inst['rs1/rd1']]
                    sdma_load(gmem=mem, scpad=SP0, gmem_base=sregs.read(inst['rs2']), scpad_base_row=sregs.read(inst['rs1/rd1']), tile_id=localID, NR=inst['num_rows'], NC=inst['num_cols'])
                elif inst['sid'] == 1:
                    if(inst['rs1/rd1'] in tileID1Dict.keys()):
                        localID = tileID1Dict[inst['rs1/rd1']]
                    else:
                        tile_id1 += 1
                        tileID1Dict[inst['rs1/rd1']] = tile_id1
                        localID = tileID1Dict[inst['rs1/rd1']]
                    sdma_load(gmem=mem, scpad=SP1, gmem_base=sregs.read(inst['rs2']), scpad_base_row=sregs.read(inst['rs1/rd1']), tile_id=localID, NR=inst['num_rows'], NC=inst['num_cols'])

            elif(m == "scpad.st"):
                if inst['sid'] == 0:
                    if(inst['rs1/rd1'] in tileID0Dict.keys()):
                        localID = tileID0Dict[inst['rs1/rd1']]
                    else:
                        tile_id0 += 1
                        tileID0Dict[inst['rs1/rd1']] = tile_id0
                        localID = tileID0Dict[inst['rs1/rd1']]
                    sdma_store(gmem=mem, scpad=SP0, scpad_base_row=sregs.read(inst['rs1/rd1']), gmem_base=sregs.read(inst['rs2']), tile_id=tile_id0, NR=inst['num_rows'], NC=inst['num_cols'])
                elif inst['sid'] == 1:
                    if(inst['rs1/rd1'] in tileID1Dict.keys()):
                        localID = tileID1Dict[inst['rs1/rd1']]
                    else:
                        tile_id1 += 1
                        tileID1Dict[inst['rs1/rd1']] = tile_id1
                        localID = tileID1Dict[inst['rs1/rd1']]
                    sdma_store(gmem=mem, scpad=SP1, scpad_base_row=sregs.read(inst['rs1/rd1']), gmem_base=sregs.read(inst['rs2']), tile_id=tile_id1, NR=inst['num_rows'], NC=inst['num_cols'])
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
                    if(m == "add.bf"):
                        src1 = hex_to_fp32(src1)
                        src2 = hex_to_fp32(src2)
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                if(m == "add.bf"):
                    WBdata = fp32_to_hex(WBdata)
                print(inst['rd'])
                sregs.write(inst['rd'], WBdata)
            elif m in ("sub.s", "subi.s", "sub.bf"):
                if(m == "sub.s" or m == "sub.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                    if(m == "sub.bf"):
                        src1 = hex_to_fp32(src1)
                        src2 = hex_to_fp32(src2)
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                if(m == "sub.bf"):
                    WBdata = fp32_to_hex(WBdata)
                print(WBdata)
                sregs.write(inst['rd'], WBdata)
            elif m in ("mul.s", "muli.s", "mul.bf"):
                if(m == "mul.s" or m == "mul.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                    if(m == "mul.bf"):
                        src1 = hex_to_fp32(src1)
                        src2 = hex_to_fp32(src2)
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                if(m == "mul.bf"):
                    WBdata = fp32_to_hex(WBdata)
                sregs.write(inst['rd'], WBdata)
            elif m in ("div.s", "divi.s", "div.bf"):
                if(m == "div.s" or m == "div.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                    if(m == "div.bf"):
                        src1 = hex_to_fp32(src1)
                        src2 = hex_to_fp32(src2)
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                if(m == "div.bf"):
                    WBdata = fp32_to_hex(WBdata)
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
                    if(m == "slt.bf"):
                        src1 = hex_to_fp32(src1)
                        src2 = hex_to_fp32(src2)
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m in ("sltu.s", "sltui.s", "sltu.bf"):
                if(m == "sltu.s" or m == "sltu.bf"):
                    src1 = sregs.read(inst['rs1'])
                    src2 = sregs.read(inst['rs2'])
                    if(m == "sltu.bf"):
                        src1 = hex_to_fp32(src1)
                        src2 = hex_to_fp32(src2)
                else:
                    src1 = sregs.read(inst['rs1'])
                    src2 = inst['imm']
                WBdata = EU.execute(m, sA=src1, sB=src2)
                sregs.write(inst['rd'], WBdata)
            elif m == "stbf.s":
                src1 = sregs.read(inst['rs1'])
                src1 = np.float32(src1)
                temp = fp32_to_hex(src1)
                sregs.write(inst['rd'], temp)
            elif m == "bfts.s":
                src1 = sregs.read(inst['rs1'])
                src1 = hex_to_fp32(src1)
                src1 = np.int32(src1)
                sregs.write(inst['rd'], src1)
            # ---------------- VV (Vector-Vector) ----------------
            elif m.endswith(".vv"):
                # ------------ GEMM ------------------------------
                if (m == "gemm.vv"):
                    vregs.write(inst['vd'], vregs.read(inst['vs1']) @ gemm_weights + vregs.read(inst['vs2']))
                else:
                    src1 = vregs.read(inst['vs1'])
                    src2 = vregs.read(inst['vs2'])
                    WBdata = EU.execute(m, vA=src1, vB=src2, slr=0)
                    mask = mregs.read(inst['mask'])
                    old_vec = vregs.read(inst['vd'])
                    new_vec = apply_mask(v1=old_vec, v2=WBdata, mask=mask)
                    vregs.write(inst['vd'], new_vec)
            # ---------------- MVV (Vector-Vector) ---------------
            elif m.endswith(".mvv"):
                src1 = vregs.read(inst['vs1'])
                src2 = vregs.read(inst['vs2'])
                WBdata = EU.execute(m, vA=src1, vB=src2, slr=0)
                mask = mregs.read(inst['mask'])
                old_vec = vregs.read(inst['vmd'])
                bits = format(old_vec & 0xFFFFFFFF, '032b')
                bit_vector = [int(b) for b in bits]
                new_vec = apply_mask(v1=bit_vector, v2=WBdata, mask=mask)
                new_vec = new_vec.astype(np.uint32)
                value = np.uint32(0)
                for i, bit in enumerate(new_vec):
                    value |= bit << i
                mregs.write(inst['vmd'], value)
            # ---------------- VI (WEIGHTS ONLY) ----------------
            elif (m == "lw.vi"):
                src1 = vregs.read(inst['vs1'])
    
                if num_weights < 32:
                    # Initial fill: Place at the next available slot from left to right
                    gemm_weights[:, num_weights] = src1
                    num_weights += 1
                else:
                    # Matrix is full: Shift everything to the right and insert at the left (index 0)
                    # gemm_weights[:, 1:] moves columns 0-30 to positions 1-31
                    gemm_weights[:, 1:] = gemm_weights[:, :-1]
                    gemm_weights[:, 0] = src1
            elif (m == "vmov.vts"):
                src1 = vregs.read(inst['vs1'])
                temp = fp32_to_hex(src1[inst['imm8']])
                sregs.write(inst['rd'], temp)
            # ---------------- VI (Vector-Immediate) ----------------
            elif m.endswith(".vi") and (m != "lw.vi"):
                src1 = vregs.read(inst['vs1'])
                src2 = inst['imm']
                nmask = mregs.read(inst['mask'])
                print(nmask)
                if(m == 'shift.vi'):
                    slr = (src2 >> 5) & 0b1
                    imm = src2 & 0b1_1111
                else:
                    slr = 0
                    imm = src2 << 16
                    imm = struct.unpack('<f', struct.pack('<I', temp & 0xFFFFFFFF))[0]
                WBdata = EU.execute(m, vA=src1, sA=imm, slr=slr, mask=nmask)
                old_vec = vregs.read(inst['vd'])
                if(m != 'shift.vi' and m != 'rsum.vi' and m != 'rmin.vi' and m != 'rmax.vi'):
                    new_vec = apply_mask(v1=old_vec, v2=WBdata, mask=mask)
                elif(m == 'rsum.vi' or m == 'rmin.vi' or m == 'rmax.vi'):
                    new_vec = apply_imm_vector_op(imm=imm, vs=src1, r_in=WBdata)
                else:
                    new_vec = WBdata
                vregs.write(inst['vd'], new_vec)
            # ---------------- VS (Vector-Scalar) ----------------
            elif m.endswith(".vs"):
                src1 = vregs.read(inst['vs1'])
                if(m == 'shift.vs'):
                    slr = (inst['rs1'] >> 5) & 0b1
                    src2 = inst['rs1'] & 0b1_1111
                else:
                    slr = 0
                    src2 = sregs.read(inst['rs1'])
                    src2 = hex_to_fp32(int(src2))
                WBdata = EU.execute(m, vA=src1, sA=src2, slr=slr)
                mask = mregs.read(inst['mask'])
                old_vec = vregs.read(inst['vd'])
                if(m != 'shift.vs'):
                    new_vec = apply_mask(v1=old_vec, v2=WBdata, mask=mask)
                else:
                    new_vec = WBdata
                vregs.write(inst['vd'], new_vec)
            # ---------------- MVS (Vector-Scalar) ---------------
            elif m.endswith(".mvs"):
                src1 = vregs.read(inst['vs1'])
                slr = 0
                src2 = sregs.read(inst['rs1'])
                src2 = hex_to_fp32(int(src2))
                WBdata = EU.execute(m, vA=src1, sA=src2, slr=slr)
                mask = mregs.read(inst['mask'])
                old_mask = mregs.read(inst['vmd'])
                bits = format(old_mask & 0xFFFFFFFF, '032b')
                bit_vector = [int(b) for b in bits]
                new_vec = apply_mask(v1=bit_vector, v2=WBdata, mask=mask)
                new_vec = new_vec.astype(np.uint32)
                value = np.uint32(0)
                for i, bit in enumerate(new_vec):
                        value |= bit << i
                mregs.write(inst['vmd'], value)
            # ---------------- UNKNOWN ----------------
            else:
                raise ValueError(f"Unknown mnemonic: {m}")
            
        
        if(br):
            pc = brtarg
        else:
            pc = pc + 24


    # Dump memory to output file
    sregs.dump_to_file(out_sreg_file)
    vregs.dump_to_file(out_vreg_file)
    mregs.dump_to_file(out_mreg_file)
    # print(sregs)
    mem.dump_to_file(out_file)
    print(f"\n[INFO] Wrote updated memory to '{out_file}'.")

    #dump scpad0
    dump_scpad_rc(scpad=SP0, title="SCPAD0 DUMP")

    #dump scpad1
    dump_scpad_rc(scpad=SP1, title="SCPAD1 DUMP")

if __name__ == "__main__":
    main()

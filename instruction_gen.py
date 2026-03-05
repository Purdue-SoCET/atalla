import sys
from pathlib import Path

# Add the parent directory (src/) to the Python path
sys.path.insert(0, str(Path(__file__).parent.parent))

from opcode_table import OPCODES

# # def encode_instruction(instr_dict):
#     """
#     Encodes an instruction dictionary into a 40-bit hexadecimal string.
    
#     Args:
#         instr_dict: Dictionary containing instruction fields like:
#                    {'opcode', 'mnemonic', 'type', 'vd', 'rs1', ...}
    
#     Returns:
#         String: 10-character hexadecimal representation (40 bits)
#     """
#     opcode = instr_dict['opcode']
#     instr_type = instr_dict['type']
    
#     # Initialize 40-bit instruction to 0
#     instruction = 0
    
#     # Opcode is always bits [6:0]
#     instruction |= (opcode & 0x7F)
    
#     # Encode based on instruction type
#     if instr_type == "R":
#         # R-Type: rd 7-14, rs1 15-22, rs2 23-30
#         rd = instr_dict.get('rd', 0)
#         rs1 = instr_dict.get('rs1', 0)
#         rs2 = instr_dict.get('rs2', 0)
        
#         instruction |= (rd & 0xFF) << 7
#         instruction |= (rs1 & 0xFF) << 15
#         instruction |= (rs2 & 0xFF) << 23
        
#     elif instr_type == "BR":
#         # BR-Type: incr-imm7 7-13, i1 14, rs1 15-22, rs2 23-30, imm9 31-39
#         incr_imm = instr_dict.get('incr_imm', 0)
#         imm1 = instr_dict.get('imm1', 0)
#         rs1 = instr_dict.get('rs1', 0)
#         rs2 = instr_dict.get('rs2', 0)
#         imm9 = instr_dict.get('imm9', 0)
        
#         instruction |= (incr_imm & 0x7F) << 7
#         instruction |= (imm1 & 0x1) << 14
#         instruction |= (rs1 & 0xFF) << 15
#         instruction |= (rs2 & 0xFF) << 23
#         instruction |= (imm9 & 0x1FF) << 31
        
#     elif instr_type == "I":
#         # I-Type: rd 7-14, rs1 15-22, imm12 23-34
#         rd = instr_dict.get('rd', 0)
#         rs1 = instr_dict.get('rs1', 0)
#         imm12 = instr_dict.get('imm12', instr_dict.get('imm', 0))
        
#         instruction |= (rd & 0xFF) << 7
#         instruction |= (rs1 & 0xFF) << 15
#         instruction |= (imm12 & 0xFFF) << 23
        
#     elif instr_type == "M":
#         # M-Type: rd 7-14, rs1 15-22, imm12 23-34
#         rd = instr_dict.get('rd', 0)
#         rs1 = instr_dict.get('rs1', 0)
#         imm12 = instr_dict.get('imm12', instr_dict.get('imm', 0))
        
#         instruction |= (rd & 0xFF) << 7
#         instruction |= (rs1 & 0xFF) << 15
#         instruction |= (imm12 & 0xFFF) << 23
        
#     elif instr_type == "MI":
#         # MI-Type: rd 7-14, imm25 15-39
#         rd = instr_dict.get('rd', 0)
#         imm25 = instr_dict.get('imm25', instr_dict.get('imm', 0))
        
#         instruction |= (rd & 0xFF) << 7
#         instruction |= (imm25 & 0x1FFFFFF) << 15
        
#     elif instr_type == "S":
#         # S-Type: special instructions, no operands
#         pass
        
#     elif instr_type == "VV":
#         # VV-Type: vd 7-14, vs1 15-22, vs2 23-30, mask 31-34, sac 35-39
#         vd = instr_dict.get('vd', 0)
#         vs1 = instr_dict.get('vs1', 0)
#         vs2 = instr_dict.get('vs2', 0)
#         mask = instr_dict.get('mask', 0)
#         sac = instr_dict.get('sac', 0)
        
#         instruction |= (vd & 0xFF) << 7
#         instruction |= (vs1 & 0xFF) << 15
#         instruction |= (vs2 & 0xFF) << 23
#         instruction |= (mask & 0xF) << 31
#         instruction |= (sac & 0x1F) << 35
        
#     elif instr_type == "VS":
#         # VS-Type: vd 7-14, vs1 15-22, rs1 23-30, mask 31-34
#         vd = instr_dict.get('vd', 0)
#         vs1 = instr_dict.get('vs1', 0)
#         rs1 = instr_dict.get('rs1', 0)
#         mask = instr_dict.get('mask', 0)
        
#         instruction |= (vd & 0xFF) << 7
#         instruction |= (vs1 & 0xFF) << 15
#         instruction |= (rs1 & 0xFF) << 23
#         instruction |= (mask & 0xF) << 31
        
#     elif instr_type == "VI":
#         # VI-Type: vd 7-14, vs1 15-22, imm8 23-30, mask 31-34, imm5 35-39
#         vd = instr_dict.get('vd', 0)
#         vs1 = instr_dict.get('vs1', 0)
#         imm8 = instr_dict.get('imm8', 0)
#         mask = instr_dict.get('mask', 0)
#         imm5 = instr_dict.get('imm5', 0)
        
#         instruction |= (vd & 0xFF) << 7
#         instruction |= (vs1 & 0xFF) << 15
#         instruction |= (imm8 & 0xFF) << 23
#         instruction |= (mask & 0xF) << 31
#         instruction |= (imm5 & 0x1F) << 35
        
#     elif instr_type == "VM":
#         # VM-Type: vd 7-14, rs1 15-22, num_cols 23-27, num_rows 28-32, sid 33, rc 34, rc_id 35-39
#         vd = instr_dict.get('vd', 0)
#         rs1 = instr_dict.get('rs1', 0)
#         num_cols = instr_dict.get('num_cols', 0)
#         num_rows = instr_dict.get('num_rows', 0)
#         sid = instr_dict.get('sid', 0)
#         rc = instr_dict.get('rc', 0)
#         rc_id = instr_dict.get('rc_id', 0)
        
#         instruction |= (vd & 0xFF) << 7
#         instruction |= (rs1 & 0xFF) << 15
#         instruction |= (num_cols & 0x1F) << 23
#         instruction |= (num_rows & 0x1F) << 28
#         instruction |= (sid & 0x1) << 33
#         instruction |= (rc & 0x1) << 34
#         instruction |= (rc_id & 0x1F) << 35
        
#     elif instr_type == "SDMA":
#         # SDMA: rs1/rd1 7-14, rs2 15-22, num_cols 23-27, num_rows 28-32, sid 33
#         rs1_rd1 = instr_dict.get('rs1', instr_dict.get('rd1', 0))
#         rs2 = instr_dict.get('rs2', 0)
#         num_cols = instr_dict.get('num_cols', 0)
#         num_rows = instr_dict.get('num_rows', 0)
#         sid = instr_dict.get('sid', 0)
        
#         instruction |= (rs1_rd1 & 0xFF) << 7
#         instruction |= (rs2 & 0xFF) << 15
#         instruction |= (num_cols & 0x1F) << 23
#         instruction |= (num_rows & 0x1F) << 28
#         instruction |= (sid & 0x1) << 33
        
#     elif instr_type == "MTS":
#         # MTS: rd 7-14, vms 15-22
#         rd = instr_dict.get('rd', 0)
#         vms = instr_dict.get('vms', 0)
        
#         instruction |= (rd & 0xFF) << 7
#         instruction |= (vms & 0xFF) << 15
        
#     elif instr_type == "STM":
#         # STM: vmd 7-14, rs1 15-22
#         vmd = instr_dict.get('vmd', 0)
#         rs1 = instr_dict.get('rs1', 0)
        
#         instruction |= (vmd & 0xFF) << 7
#         instruction |= (rs1 & 0xFF) << 15
    
#     # Convert to 40-bit hex (10 hex characters)
#     hex_str = format(instruction, '010x')
#     return hex_str
def encode_instruction(instr_dict):
    """
    Encodes an instruction dictionary into a 40-bit hexadecimal string.
    
    Args:
        instr_dict: Dictionary containing instruction fields like:
                   {'opcode': 22, 'rd': 2, 'rs1': 0, 'imm': 10}
                   Note: 'mnemonic' and 'type' are optional - will be looked up from opcode
    
    Returns:
        String: 10-character hexadecimal representation (40 bits)
    """
    opcode = instr_dict['opcode']
    
    # Look up instruction type from opcode table if not provided
    if 'type' in instr_dict:
        instr_type = instr_dict['type']
    else:
        if opcode not in OPCODES:
            raise ValueError(f"Unknown opcode: {opcode}")
        _, instr_type = OPCODES[opcode]
    
    # Initialize 40-bit instruction to 0
    instruction = 0
    
    # Opcode is always bits [6:0]
    instruction |= (opcode & 0x7F)
    
    # Encode based on instruction type
    if instr_type == "R":
        # R-Type: rd 7-14, rs1 15-22, rs2 23-30
        rd = instr_dict.get('rd', 0)
        rs1 = instr_dict.get('rs1', 0)
        rs2 = instr_dict.get('rs2', 0)
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (rs2 & 0xFF) << 23
        
    elif instr_type == "BR":
        # BR-Type: incr-imm7 7-13, i1 14, rs1 15-22, rs2 23-30, imm9 31-39
        incr_imm = instr_dict.get('incr_imm', 0)
        imm1 = instr_dict.get('imm1', 0)
        rs1 = instr_dict.get('rs1', 0)
        rs2 = instr_dict.get('rs2', 0)
        imm9 = instr_dict.get('imm9', 0)
        
        instruction |= (incr_imm & 0x7F) << 7
        instruction |= (imm1 & 0x1) << 14
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (rs2 & 0xFF) << 23
        instruction |= (imm9 & 0x1FF) << 31
        
    elif instr_type == "I":
        # I-Type: rd 7-14, rs1 15-22, imm12 23-34
        rd = instr_dict.get('rd', 0)
        rs1 = instr_dict.get('rs1', 0)
        imm12 = instr_dict.get('imm12', instr_dict.get('imm', 0))
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (imm12 & 0xFFF) << 23
        
    elif instr_type == "M":
        # M-Type: rd 7-14, rs1 15-22, imm12 23-34
        rd = instr_dict.get('rd', 0)
        rs1 = instr_dict.get('rs1', 0)
        imm12 = instr_dict.get('imm12', instr_dict.get('imm', 0))
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (imm12 & 0xFFF) << 23
        
    elif instr_type == "MI":
        # MI-Type: rd 7-14, imm25 15-39
        rd = instr_dict.get('rd', 0)
        imm25 = instr_dict.get('imm25', instr_dict.get('imm', 0))
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (imm25 & 0x1FFFFFF) << 15
        
    elif instr_type == "S":
        # S-Type: special instructions, no operands
        pass
        
    elif instr_type == "VV":
        # VV-Type: vd 7-14, vs1 15-22, vs2 23-30, mask 31-34, sac 35-39
        vd = instr_dict.get('vd', 0)
        vs1 = instr_dict.get('vs1', 0)
        vs2 = instr_dict.get('vs2', 0)
        mask = instr_dict.get('mask', 0)
        sac = instr_dict.get('sac', 0)
        
        instruction |= (vd & 0xFF) << 7
        instruction |= (vs1 & 0xFF) << 15
        instruction |= (vs2 & 0xFF) << 23
        instruction |= (mask & 0xF) << 31
        instruction |= (sac & 0x1F) << 35
        
    elif instr_type == "VS":
        # VS-Type: vd 7-14, vs1 15-22, rs1 23-30, mask 31-34
        vd = instr_dict.get('vd', 0)
        vs1 = instr_dict.get('vs1', 0)
        rs1 = instr_dict.get('rs1', 0)
        mask = instr_dict.get('mask', 0)
        
        instruction |= (vd & 0xFF) << 7
        instruction |= (vs1 & 0xFF) << 15
        instruction |= (rs1 & 0xFF) << 23
        instruction |= (mask & 0xF) << 31
        
    elif instr_type == "VI":
        # VI-Type: vd 7-14, vs1 15-22, imm8 23-30, mask 31-34, imm5 35-39
        vd = instr_dict.get('vd', 0)
        vs1 = instr_dict.get('vs1', 0)
        imm8_1 = instr_dict.get('imm8_1', 0)
        mask = instr_dict.get('mask', 0)
        imm8_2 = instr_dict.get('imm8_2', 0)
        
        instruction |= (vd & 0xFF) << 7
        instruction |= (vs1 & 0xFF) << 15
        instruction |= (imm8_1 & 0xFF) << 23
        instruction |= (mask & 0xF) << 31
        instruction |= (imm8_2 & 0xFF) << 35
        
    elif instr_type == "VM":
        # VM-Type: vd 7-14, rs1 15-22, num_cols 23-27, num_rows 28-32, sid 33, rc 34, rc_id 35-39
        vd = instr_dict.get('vd', 0)
        rs1 = instr_dict.get('rs1', 0)
        num_cols = instr_dict.get('num_cols', 0)
        num_rows = instr_dict.get('num_rows', 0)
        sid = instr_dict.get('sid', 0)
        rc = instr_dict.get('rc', 0)
        rc_id = instr_dict.get('rc_id', 0)
        
        instruction |= (vd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15
        instruction |= (num_cols & 0x1F) << 23
        instruction |= (num_rows & 0x1F) << 28
        instruction |= (sid & 0x1) << 33
        instruction |= (rc & 0x1) << 34
        instruction |= (rc_id & 0x1F) << 35
        
    elif instr_type == "SDMA":
        # SDMA: rs1/rd1 7-14, rs2 15-22, num_cols 23-27, num_rows 28-32, sid 33
        rs1_rd1 = instr_dict.get('rs1', instr_dict.get('rd1', 0))
        rs2 = instr_dict.get('rs2', 0)
        num_cols = instr_dict.get('num_cols', 0)
        num_rows = instr_dict.get('num_rows', 0)
        sid = instr_dict.get('sid', 0)
        
        instruction |= (rs1_rd1 & 0xFF) << 7
        instruction |= (rs2 & 0xFF) << 15
        instruction |= (num_cols & 0x1F) << 23
        instruction |= (num_rows & 0x1F) << 28
        instruction |= (sid & 0x1) << 33
        
    elif instr_type == "MTS":
        # MTS: rd 7-14, vms 15-22
        rd = instr_dict.get('rd', 0)
        vms = instr_dict.get('vms', 0)
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (vms & 0xFF) << 15
        
    elif instr_type == "STM":
        # STM: vmd 7-14, rs1 15-22
        vmd = instr_dict.get('vmd', 0)
        rs1 = instr_dict.get('rs1', 0)
        
        instruction |= (vmd & 0xFF) << 7
        instruction |= (rs1 & 0xFF) << 15

    elif instr_type == "VTS":
        imm8 = instr_dict.get('imm8', 0)
        vs1 = instr_dict.get('vs1', 0)
        rd = instr_dict.get('rd', 0)
        
        instruction |= (rd & 0xFF) << 7
        instruction |= (vs1 & 0xFF) << 15
        instruction |= (imm8 & 0xFF) << 23

    elif instr_type == "MVV":
        vmd = instr_dict.get('vmd', 0)
        vs1 = instr_dict.get('vs1', 0)
        vs2 = instr_dict.get('vs2', 0)
        mask = instr_dict.get('mask', 0)
        
        instruction |= (vmd & 0xF) << 7
        instruction |= (vs1 & 0xFF) << 11
        instruction |= (vs2 & 0xFF) << 19
        instruction |= (mask & 0xF) << 27

    elif instr_type == "MVS":
        vmd = instr_dict.get('vmd', 0)
        vs1 = instr_dict.get('vs1', 0)
        rs1 = instr_dict.get('rs1', 0)
        mask = instr_dict.get('mask', 0)
        
        instruction |= (vmd & 0xF) << 7
        instruction |= (vs1 & 0xFF) << 11
        instruction |= (rs1 & 0xFF) << 19
        instruction |= (mask & 0xF) << 27
    
    # Convert to 48-bit hex (12 hex characters)
    hex_str = format(instruction, '012x')
    return hex_str

# Test with your examples
test1 = {'opcode': 0b0010110, 'imm12': 120, 'rs1': 0, 'rd': 1} #addi r1 = 120
test2 = {'opcode': 0b0010110, 'imm12': 15, 'rs1': 0, 'rd': 2} #addi r2 = 15
test3 = {'opcode': 0b0000011, 'rs2': 1, 'rs1': 2, 'rd': 3} #addi r3 = r1 * r2

print(f"Instruction: {encode_instruction(test1)}")
print(f"Instruction: {encode_instruction(test2)}")
print(f"Instruction: {encode_instruction(test3)}")
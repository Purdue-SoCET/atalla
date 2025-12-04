import numpy as np
import struct

def float16_conv(value):
    value = f'{value[2]}{value[3]}{value[0]}{value[1]}' # Hard coded big endian to little endian swap
    #print(value)
    byte_data = bytes.fromhex(value)
    return np.frombuffer(byte_data, dtype=np.float16)[0]

while True:
    instruction = input("command (format: [a/m] [operand1] [operand2])   ").split()
    operands_string = instruction[1::]
    operands_fp = list(map(float16_conv, operands_string))
    print(f'operands: {operands_string[0]} aka {operands_fp[0]}, {operands_string[1]} aka {operands_fp[1]}')
    if(instruction[0] == "m"):
        result = operands_fp[0] * operands_fp[1]
        result_fp_hex = str(struct.pack(">e", result).hex())
        print(f'result: {result} aka {result_fp_hex}')
    elif(instruction[0] == "a"):
        result = operands_fp[0] + operands_fp[1]
        result_fp_hex = str(struct.pack(">e", result).hex())
        print(f'result: {result} aka {result_fp_hex}')
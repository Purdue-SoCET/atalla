// predictor


#include "svdpi.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <svdpi.h>
#include <xmmintrin.h> // FTZ handinling header
#include <pmmintrin.h> // DAZ handling header

// Floating point vs bf16 structure
// FP32: Sign (1 bit), Exponent (8 bits), Mantissa (23 bits)
//       [31]          [30:23]            [22:0]
// bf16: Sign (1 bit), Exponent (8 bits), Mantissa (7 bits)
//       [15]          [14:7]             [6:0]
//
// How to calculate floating point value:
// (-1)^Sign * 1.Mantissa(base 10) * 2^(Exponent(base10) - 127)


float bf16_to_f32(uint16_t bf16_bits)
{
	uint32_t f32_bits = ((uint32_t) bf16_bits) << 16;
	float fp32;
	memcpy(&fp32, &f32_bits, sizeof(fp32));
	return fp32;
}

uint32_t fp32_to_bf16(float fp32) // mimics hardware implementation
{
	uint32_t value; // value
	memcpy(&value, &fp32, sizeof(value));
	uint32_t sign = (val >>  31) & 1; // sign of floating point (1 bit)
	uint32_t exponent = (val >> 23) & 0xFF // exponent of floating point (8 bits)
	uint32_t mantissa = val & 0x7FFFFF; // mantissa of fp (23 bits)

	// go to 16 bits
	// round_up = guard & (rnd | sticky | lsb) - structure of reducer.sv
	
	uint32_t guard = (mantissa >> 15) & 1; // 15th bit of mantissa
	uint32_t rnd = (mantissa >> 14) & 1; // 14th bit of mantissa
	uint32_t sticky = (mantissa & 0x3FFF) ? 1 : 0; // logical or of last 14 mantissa bits
	uint32_t lsb = (mantissa >> 16) & 1; // lsb of mantissa

	uint32_t round = guard & (rnd | sticky | lsb); //determine wether or not to round
	uint32_t rounded_mantissa = (mantissa >> 16) + round; // round

	// in case of overload after rounding - adjust exponent; same as RTL
	int32_t new_exponent = exponent + (rounded_mantissa >> 7);
	uint32_t final_mantissa = rounded_mantissa & 0x7F;

	// Output formatting matching reducer.sv edge cases

	if (exponent == 0xFF)
	{
		return (sign << 15) | 0x7F80 | (mant ? 0x0040 : 0); // return a bf16 with nan or infinity
	} else if (new_exponent >= 0xFF)
	{
		return (sign << 15) | 0x7F80; // Overflow
	} else if (new_exponent <= 0)
	{
		return (sign << 15); // Underflow (FTZ) - return signed 0
	}

	return (sign << 15) | (new_exp << 7) | final_mant; //bf16
}

void predict_systolic_array_output(unsigned int N, const svOpenArrayHandle weight_matrix, const svOpenArrayHandle input_matrix, svOpenArrayHandle output_matrix) 
	// no partials because they are zeroed in module
{
	_MM_SET_FLUSH_ZERO_MODE(_MM_FLUSH_ZERO_ON); // set FTZ
        _MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON); // set DAZ

	uint16_t* weights = (uint16_t*)svGetArrayPtr(weight_matrix);
    	uint16_t* inputs = (uint16_t*)svGetArrayPtr(input_matrix);
    	uint16_t* outputs = (uint16_t*)svGetArrayPtr(output_matrix);
	float accumulator;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			accumulator = 0.0f;

			for (int k = 0; k < N; k++)
			{
				float a = bf16_to_float32(inputs[i * N + k]);
                		float b = bf16_to_float32(weights[k * N + j]);
				accumulator += (a*b);
			}

			outputs[i * N + j] = fp32_to_bf16(accumulator);
		}
	}
}




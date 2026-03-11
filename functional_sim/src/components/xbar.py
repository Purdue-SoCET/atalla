from ..misc.scpad_common import * 

class Xbar:
    @staticmethod
    def route(shift_mask, input_vals, num_banks=NUM_BANKS):
        assert len(shift_mask) == num_banks
        assert len(input_vals) == num_banks

        out = [0] * num_banks
        for i, b in enumerate(shift_mask):
            if b is not None and 0 <= b < num_banks:
                out[b] = input_vals[i]
        return out
NUM_BANKS = 32
LOG2B = 5  
H = NUM_BANKS >> 1

class AddressBlock:
    def _xor(abs_row: int, col_id: int) -> int:
        low5 = abs_row & (NUM_BANKS - 1)
        return (col_id ^ low5) & (NUM_BANKS - 1)

    @staticmethod
    def _row_lane(abs_row: int, cols: int):
        banks = [] 
        slots = [] 
        valid = []
        for lane in range(NUM_BANKS):
            banks.append(AddressBlock._xor(abs_row, lane))
            slots.append(abs_row)
            valid.append(lane < cols)
        return banks, slots, valid

    @staticmethod
    def _col_lane(base_row: int, col_id: int, rows: int):
        banks = []
        slots = []
        valid = []
        for lane in range(NUM_BANKS):
            abs_row = base_row + lane
            banks.append(AddressBlock._xor(abs_row, col_id))
            slots.append(abs_row)
            valid.append(lane < rows)
        return banks, slots, valid

    @staticmethod
    def gen_masks_row(base_row: int, row_id: int, cols: int):
        abs_row = base_row + row_id
        lane_bank, lane_slot, lane_valid = AddressBlock._row_lane(abs_row, cols)

        shift_mask_lane2bank = [(lane_bank[i] if lane_valid[i] else None) for i in range(NUM_BANKS)]
        slot_mask = [None] * NUM_BANKS
        for i in range(NUM_BANKS):
            if lane_valid[i]:
                b = lane_bank[i]
                slot_mask[b] = lane_slot[i] 


        return shift_mask_lane2bank, slot_mask, lane_bank, lane_slot, lane_valid

    @staticmethod
    def gen_masks_col(base_row: int, col_id: int, rows: int):
        lane_bank, lane_slot, lane_valid = AddressBlock._col_lane(base_row, col_id, rows)

        shift_mask_lane2bank = [(lane_bank[i] if lane_valid[i] else None) for i in range(NUM_BANKS)]
        slot_mask = [None] * NUM_BANKS
        for i in range(NUM_BANKS):
            if lane_valid[i]:
                b = lane_bank[i]
                slot_mask[b] = lane_slot[i]  

        return shift_mask_lane2bank, slot_mask, lane_bank, lane_slot, lane_valid


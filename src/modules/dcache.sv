import cpu_types_pkg::*;

module dcache (
	input logic CLK, nRST,
	datapath_cache_if.dcache dcif,
	caches_if.dcache cif
);

typedef struct packed {
	//left table
	logic [25:0] left_tag;
	word_t left_data1, left_data2;
	logic left_dirty, left_valid;
	//right table
	logic [25:0] right_tag;
	word_t right_data1, right_data2;
	logic right_dirty, right_valid;
} dcache_t;

typedef enum logic[3:0] {
	IDLE, WB1, WB2, LD1, LD2, FLUSH1, FLUSH2, DIRTY, CNT, HALT
} state_t;

//Declaration
dcache_t ht[7:0];
integer i;

logic offset;
logic [25:0] tag;
logic [2:0] ind, row_trunc;

logic miss, available[7:0], next_available[7:0];
logic [4:0] row, next_row;
word_t hit_count, next_hit_count;

state_t state, next_state;
//Seperate my input address
assign offset = dcif.dmemaddr[2];
assign ind = dcif.dmemaddr[5:3];
assign tag = dcif.dmemaddr[31:6];
assign row_trunc = row[2:0] - 1;
//IDLE state
logic [25:0] left_tag, right_tag;
word_t left_data1, left_data2, right_data1, right_data2;
logic left_dirty, left_valid, right_dirty, right_valid;


always_ff @(posedge CLK or negedge nRST) begin
	if(~nRST) begin
		 for (i = 0; i < 8; i++) begin
		 	ht[i].left_tag <= 0;
		 	ht[i].left_data1 <= 0;
		 	ht[i].left_data2 <= 0;
		 	ht[i].left_dirty <= 0;
		 	ht[i].left_valid <= 0;

		 	ht[i].right_tag <= 0;
		 	ht[i].right_data1 <= 0;
		 	ht[i].right_data2 <= 0;
		 	ht[i].right_dirty <= 0;
		 	ht[i].right_valid <= 0;


		 end
	end else begin
		ht[ind].left_data1 <= left_data1;
		ht[ind].left_data2 <= left_data2;
		ht[ind].right_data1 <= right_data1;
		ht[ind].right_data2 <= right_data2;
		ht[ind].left_dirty <= left_dirty;
		ht[ind].right_dirty <= right_dirty;
		ht[ind].left_tag <= left_tag;
		ht[ind].left_valid <= left_valid;
		ht[ind].right_tag <= right_tag;
		ht[ind].right_valid <= right_valid;
	end
end

//State Machine
always_ff @(posedge CLK or negedge nRST) begin
	if(~nRST) begin
		 state <= IDLE;
		 for (i = 0; i < 8; i++)
		 	available[i] <= 0;
		 row <= 0;
		 hit_count <= 0;
	end else begin
		 state <= next_state;
		 for (i = 0; i < 8; i++)
		 	available[i] <= next_available[i];
		 row <= next_row;
		 hit_count <= next_hit_count;
	end
end

//Next State Logic
always_comb begin : NEXT_LOGIC
	next_state = state;
	next_row = row;
	case(state)
		IDLE : begin
			if (dcif.halt) next_state = DIRTY;
			else if (miss) begin
				if (available[ind] == 0) begin
					next_state = ht[ind].left_dirty? WB1:LD1;
				end else begin
					next_state = ht[ind].right_dirty? WB1:LD1;
				end
			end
		end
		WB1 : begin
			if (~cif.dwait) next_state = WB2;
		end
		WB2 : begin
			if (~cif.dwait) next_state = LD1;
		end
		LD1 : begin
			if (~cif.dwait) next_state = LD2;
		end
		LD2 : begin
			if (~cif.dwait) next_state = IDLE;
		end
		DIRTY : begin
			if (row < 8) begin
				if(ht[row[2:0]].left_dirty) begin
					next_state = FLUSH1;
				end
			end else begin
				if(ht[row[2:0]].right_dirty) begin
					next_state = FLUSH1;
				end
			end
			next_row = row + 1;
		 	if(row == 5'b10000)
		 		next_state = CNT;
		end
		FLUSH1 : begin
			if (~cif.dwait) next_state = FLUSH2;
		end
		FLUSH2 : begin
			if (~cif.dwait) next_state = DIRTY;
		end
		CNT : begin
			if (~cif.dwait) next_state = HALT;
		end
	endcase // state
end

//Output Logic
assign dcif.flushed = state == HALT;
integer j;
always_comb begin : OUTPUT_LOGIC
	miss = 0;
	dcif.dhit = 0;
	dcif.dmemload = 0;
	cif.dREN = 0;
	cif.dWEN = 0;
	cif.daddr = 0;
	cif.dstore = 0;

	left_data1 = ht[ind].left_data1; 
	left_data2 = ht[ind].left_data2;
	right_data1 = ht[ind].right_data1;
	right_data2 = ht[ind].right_data2;
	left_dirty = ht[ind].left_dirty;
	right_dirty = ht[ind].right_dirty;
	left_valid = ht[ind].left_valid; 
	right_valid = ht[ind].right_valid;
	left_tag = ht[ind].left_tag;
	right_tag = ht[ind].right_tag;

	for(j = 0; j < 8; j++) next_available[j] = available[j];
	next_hit_count = hit_count;

	case(state)
		IDLE : begin
			if (dcif.halt) next_hit_count = hit_count;
			else if (dcif.dmemREN) begin
				if ((tag == ht[ind].left_tag) && ht[ind].left_valid) begin
					dcif.dhit = 1;
					dcif.dmemload = offset? ht[ind].left_data2:ht[ind].left_data1;
					next_available[ind] = 1;
					next_hit_count = hit_count + 1;
				end else if ((tag == ht[ind].right_tag) && ht[ind].right_valid) begin
					dcif.dhit = 1;
					dcif.dmemload = offset? ht[ind].right_data2:ht[ind].right_data1;
					next_available[ind] = 0;
					next_hit_count = hit_count + 1;
				end else begin
					miss = 1;
					next_hit_count = hit_count - 1;
				end
			end else if (dcif.dmemWEN) begin
				if ((tag == ht[ind].left_tag)) begin
					dcif.dhit = 1;
					left_dirty = 1;
					next_available[ind] = 1;
					next_hit_count = hit_count + 1;
					if(offset == 0) left_data1 = dcif.dmemstore;
					else left_data2 = dcif.dmemstore;
				end else if ((tag == ht[ind].right_tag)) begin
					dcif.dhit = 1;
					right_dirty = 1;
					next_available[ind] = 0;
					next_hit_count = hit_count + 1;
					if(offset == 0) right_data1 = dcif.dmemstore;
					else right_data2 = dcif.dmemstore;
				end else begin
					miss = 1;
					next_hit_count = hit_count - 1;
				end
			end
		end
		WB1 : begin
			cif.dWEN = 1;
			if(available[ind] == 0) begin
				cif.daddr = {ht[ind].left_tag, ind, 3'b000};
				cif.dstore = ht[ind].left_data1;
			end else begin
				cif.daddr = {ht[ind].right_tag, ind, 3'b000};
				cif.dstore = ht[ind].right_data1;
			end
		end
		WB2 : begin
			cif.dWEN = 1;
			if(available[ind] == 0) begin
				cif.daddr = {ht[ind].left_tag, ind, 3'b100};
				cif.dstore = ht[ind].left_data2;
			end else begin
				cif.daddr = {ht[ind].right_tag, ind, 3'b100};
				cif.dstore = ht[ind].right_data2;
			end
		end
		LD1 : begin
			cif.dREN = 1;
			cif.daddr = {tag, ind, 3'b000};
			if (available[ind] == 0) begin
				left_data1 = cif.dload;
			end else begin
				right_data1 = cif.dload;
			end
		end
		LD2 : begin
			cif.dREN = 1;
			cif.daddr = {tag, ind, 3'b100};
			if (available[ind] == 0) begin
				left_data2 = cif.dload;
				left_tag = tag;
				left_dirty = 0;
				left_valid = 1;
			end else begin
				right_data2 = cif.dload;
				right_tag = tag;
				right_dirty = 0;
				right_valid = 1;
			end
		end
		FLUSH1 : begin
			cif.dWEN = 1;
			if(row - 1 < 8) begin
				cif.daddr = {ht[row_trunc].left_tag, row_trunc, 3'b000};
				cif.dstore = ht[row_trunc].left_data1;
			end else begin
				cif.daddr = {ht[row_trunc].right_tag, row_trunc, 3'b000};
				cif.dstore = ht[row_trunc].right_data1;
			end
		end
		FLUSH2 : begin
			cif.dWEN = 1;
			if(row - 1 < 8) begin
				cif.daddr = {ht[row_trunc].left_tag, row_trunc, 3'b100};
				cif.dstore = ht[row_trunc].left_data2;
			end else begin
				cif.daddr = {ht[row_trunc].right_tag, row_trunc, 3'b100};
				cif.dstore = ht[row_trunc].right_data2;
			end
		end
		CNT : begin
			cif.dWEN = 1;
			cif.daddr = 32'h00003100;
			cif.dstore = hit_count; 
		end
	endcase // state
end

endmodule // dcache
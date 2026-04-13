`timescale 1ns/1ps
`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

module nb_barb(
    input logic CLK, nRST,
    ddr_controller_if.backend_arb barb
);
    import dram_pkg::*;
 
    //Selected bank priority encoder instantiation and logic. 
    logic [$clog2(BANK_NUM)-1:0] selected_bank;
    logic selected_bank_ready;
    priority_enc #(.BANK_NUM(16)) ENCODER_SEL ((barb.be_queue_ready & barb.be_arb), selected_bank, selected_bank_ready);

    //tCCD timers instantiations.
    logic rollover_L, rollover_S;
    logic en_L, en_S;
    flex_counter #(.SIZE(12)) TCCD_L_TIM ( //these timers are cleared on successful handshakes.
        CLK, nRST, selected_bank_ready, en_L, tCCD_L[11:0], rollover_L 
    );
    flex_counter #(.SIZE(12)) TCCD_S_TIM (
        CLK, nRST, selected_bank_ready, en_S , tCCD_S[11:0], rollover_S 
    );

    //tCCD timers enable logic. Also tracks previous command
    fsm_t prev_cmd;
    logic n_en_L, n_en_S;
    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST)  begin
            en_L <= 'b1;
            en_S <= 'b1;
        end else begin
            en_L <= n_en_L;
            en_S <= n_en_S;
        end
    end 

    always_comb begin: N_EN
        n_en_L = selected_bank_ready ? 'b1 : (rollover_L ? 'b0 : en_L);
        n_en_S = selected_bank_ready ? 'b1 : (rollover_S ? 'b0 : en_S);
    end

    //tFAW logic and SR instantiation. 
    logic [tFAW:0] sr_window;
    logic four_access; 
    logic [3:0] access_cnt;
    flex_sr #(.SIZE(tFAW + 'b1)) ACTIVATE_WINDOW (CLK, nRST, 1'b1, 1'b0, selected_bank_ready & (barb.be_cmd[selected_bank] == ACT) , {(tFAW + 'b1){1'b0}}, sr_window);
    
    integer i;
    assign four_access = (access_cnt >= 'd4);
    always_comb begin : COUNT_ACCESSES
        access_cnt = 'b0;

        for(i = 0; i < tFAW + 'b1; i++) begin
            if(sr_window[i]) begin
                access_cnt += 'b1;
            end
        end
    end

    //simple round robin logic for priority.
    logic [BANK_NUM-1:0] priority_sr;
    flex_sr #(.SIZE(BANK_NUM), .RING(1'b1)) PRIORITY_SR (CLK, nRST, selected_bank_ready, 1'b0, 1'b0,  {BANK_NUM{1'b0}} , priority_sr); 

    //Priority encoder for finding bank with priority.
    logic [$clog2(BANK_NUM)-1:0] priority_idx;
    logic idrc; //I don't really care about what this bit is, it should always be one. 
    priority_enc #(.BANK_NUM(16)) ENCODER_PRI (priority_sr, priority_idx, idrc);

    //  register storing bank group of the last command. This ensures the compliance of timing parameters of two 
    //  successive transactions that target the same bank group. This timimg parameter, tCCD_L, is slightly more 
    //  than the tCCD_S that dictates the time between two different successive transactions that target
    //  different bank groups. 
    //  This also tracks the previous command for refresh purposes
    logic [$clog2(BANK_NUM)-3:0]  prev_group;
    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            prev_group <= 'b0;
        end else if(selected_bank_ready) begin
            prev_group <= selected_bank[$clog2(BANK_NUM)-3:0];
        end
    end
    
    logic [2*BANK_NUM-1:0] be_arb_next; 
    always_ff @(posedge CLK, negedge nRST) begin
	if(!nRST)
		barb.be_arb <= 'b0;
	else 
		barb.be_arb <= (be_arb_next[2 * BANK_NUM - 1:BANK_NUM] | be_arb_next[BANK_NUM-1:0]);	
    end

    logic [$clog2(ID_NUM)-1:0] selected_bank_next; 
    logic selected_bank_ready_next;

    priority_enc #(.BANK_NUM(16)) ENCODER_NEXT ((be_arb_next & barb.be_queue_ready), selected_bank_next, selected_bank_ready_next);
    //Combinational block for selecting bank based on priority.
    //logic [$clog2(BANK_NUM):0] k;
    //logic [$clog2(BANK_NUM):0] x;
    logic [BANK_NUM*2-1:0] mask;
    logic [BANK_NUM*2-1:0] be_queue_ready_double;
    logic [BANK_NUM*2-1:0] be_cmd_double_ref;
    logic [BANK_NUM*2-1:0] be_cmd_double_act;
    logic [BANK_NUM*2-1:0] bg_mask;  
    logic ref_re_next; 
    dram_state_t state_next;
    logic [RANK_BITS-1:0] RA0_next;
    logic [BANK_GROUP_BITS-1:0] BG0_next;
    logic [BANK_BITS-1:0] BA0_next;
    logic [ROW_BITS-1:0] R0_next;
    logic [COLUMN_BITS-1:0] C0_next; 
    assign mask = {(BANK_NUM*2){1'b1}} << priority_idx;
    assign bg_mask = ({BG_MASK, BG_MASK} << prev_group) | { {(2*BANK_NUM - ($clog2(BANK_NUM)-2)){1'b0}}  , prev_group};
    assign be_queue_ready_double = {barb.be_queue_ready, barb.be_queue_ready} & mask; 
    assign be_cmd_double_ref = {enum_compare(barb.be_cmd, {(BANK_NUM){fsm_t'(REF)}}), enum_compare(barb.be_cmd, {(BANK_NUM){fsm_t'(REF)}} ) } & mask; 
    assign be_cmd_double_act = {enum_compare(barb.be_cmd, {(BANK_NUM){fsm_t'(ACT)}}), enum_compare(barb.be_cmd, {(BANK_NUM){fsm_t'(ACT)}} ) } & mask;
    assign RA0_next = 0;
    assign BG0_next = selected_bank_next[$clog2(BANK_NUM)-3:0];
    assign BA0_next = selected_bank_next[$clog2(BANK_NUM)-1:$clog2(BANK_NUM)-2]; 
    assign R0_next = barb.be_r[selected_bank_next]; 
    assign C0_next = barb.be_c[selected_bank_next]; 
    always_comb begin : ARB_BLOCK
	be_arb_next = 'b0;
	ref_re_next = 1'b0;
	state_next = NOP; 
        if(rollover_S && !rollover_L) begin

	    be_arb_next = ( (be_queue_ready_double & (~be_cmd_double_ref) & ( four_access ? ~(be_cmd_double_act) : {(2*BANK_NUM){1'b1}}) & (bg_mask) ) &  ~(be_queue_ready_double & (~be_cmd_double_ref) & (four_access ? ~(be_cmd_double_act) : {(BANK_NUM*2){1'b1}} ) & (bg_mask) - 'b1 )); 
		
	    if(!selected_bank_ready_next) begin
		state_next = NOP; 
	    end else begin
		case(barb.be_cmd[selected_bank_next])
				
			ACT: begin
				state_next = ACTIVATE;
			end
			FSM_READ: begin
				state_next = READ;
			end
			FSM_WRITE: begin
				state_next = WRITE;
			end
			PRE: begin
				state_next = PRECHARGE; 
			end
	
		endcase	
	    end
	    /*
            for(k = 'b0; k < (BANK_NUM << 1) ; k++) begin
                if(be_queue_ready_double[k] && ( (prev_group != k[1:0]) && (prev_group != k[BANK_NUM + 'b1:BANK_NUM]) ) && (!be_cmd_double_ref[k])  ) begin
                    if( (be_cmd_double_act[k]) &&  !four_access  || (be_cmd_double_act[k]) ) begin
                        be_arb_next[k[$clog2(BANK_NUM)-1:0]] = 1'b1;
                        break;
                    end
                end

            end
	    */
        end else if (rollover_L) begin

            //Handling refreshes
            if( (barb.be_cmd == {BANK_NUM{REF}}) && (barb.be_queue_ready == {BANK_NUM{1'b1}}) ) begin 
		ref_re_next = 1'b1;
		state_next = REFRESH; 
		

                be_arb_next = {(BANK_NUM * 2){1'b1}};

            end else begin //Now the default case for for selecting banks after rollover_L is reached.

		be_arb_next = (be_queue_ready_double & ~be_cmd_double_ref & (four_access ? ~(be_cmd_double_act) : {(2*BANK_NUM){1'b1}})) & ~(be_queue_ready_double & ~be_cmd_double_ref & (four_access ? ~(be_cmd_double_act) : {(2*BANK_NUM){1'b1}} ) - 'b1 );
	/*
                for(x = 'b0; x < BANK_NUM; x++) begin
                    if(be_queue_ready_double[x]) begin
                        if( be_cmd_double_act[x] && !four_access || (be_cmd_double_ref[x]) ) begin
                            be_arb_next[x[$clog2(BANK_NUM)-1:0]] = 1'b1;
                            break;
                        end
                    end
                end
		*/
		
	    if(!selected_bank_ready_next) begin
		state_next = NOP; 
	    end else begin
		case(barb.be_cmd[selected_bank_next])
				
			ACT: begin
				state_next = ACTIVATE;
			end
			FSM_READ: begin
				state_next = READ;
			end
			FSM_WRITE: begin
				state_next = WRITE;
			end
			PRE: begin
				state_next = PRECHARGE; 
			end
	
		endcase	
	    end

            end

        end


    end
    
    always_ff @(posedge CLK, negedge nRST) begin
	
	    if(!nRST) begin
		barb.ref_re <= 1'b0;
		barb.state <= IDLE;
		barb.nstate <= IDLE;
		barb.RA0 <= 'b0;
		barb.BG0 <= 'b0;
		barb.BA0 <= 'b0;
		barb.R0 <= 'b0;
		barb.C0 <= 'b0;
	    end
	    else begin
		barb.ref_re <= ref_re_next;
		barb.state <= state_next;
		barb.nstate <= IDLE;
		barb.RA0 <= RA0_next;
		barb.BG0 <= BG0_next;
		barb.BA0 <= BA0_next;
		barb.R0 <= R0_next;
		barb.C0 <= C0_next; 
	    end
	
    end

    //logic for pushing metadata to the read id queue for storing in-flight read IDs.
    assign barb.be_push_id = selected_bank_ready && (fsm_t'(barb.be_cmd[selected_bank]) == FSM_READ);
    assign barb.be_rid = barb.be_id[selected_bank];
    assign barb.be_rlen = barb.be_len[selected_bank];

    //logic for commanding write data queues to burst data to DRAM.
    assign barb.be_wid = barb.be_id[selected_bank];
    assign barb.be_write = selected_bank_ready && (fsm_t'(barb.be_cmd[selected_bank]) == FSM_WRITE);
    
   
 
endmodule 

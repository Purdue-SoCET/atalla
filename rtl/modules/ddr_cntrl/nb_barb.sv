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
    logic timer_clear_S, timer_clear_L;
    assign timer_clear_S = ~init_cif.init_done | selected_bank_ready | rollover_S;
    assign timer_clear_L = ~init_cif.init_done | selected_bank_ready;

    flex_counter #(.SIZE(12)) TCCD_L_TIM (
        CLK, nRST, timer_clear_L, 1'b1, tCCD_L[11:0], rollover_L 
    );
    flex_counter #(.SIZE(12)) TCCD_S_TIM (
        CLK, nRST, timer_clear_S, 1'b1, tCCD_S[11:0], rollover_S 
    );

    //init fsm
    ddr_controller_if init_cif();

    // init_start_reg: high on reset release so init begins immediately;
    // cleared once init_done fires to prevent re-initialization.
    logic init_start_reg, init_start_next;
    always_comb begin : INIT_START_COMB
        init_start_next = init_cif.init_done ? 1'b0 : init_start_reg;
    end
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) init_start_reg <= 1'b1;
        else        init_start_reg <= init_start_next;
    end
    assign init_cif.init_start = init_start_reg;

    init_state INIT_FSM (
        .CLK  (CLK),
        .nRST (nRST),
        .isif (init_cif.init_ctrl)
    );

    assign barb.init_done = init_cif.init_done;

    // Both counters run continuously. timer_clear_S self-resets tCCD_S on
    // every rollover (producing a periodic pulse). timer_clear_L resets on
    // handshake or init. No enable gating needed.
    fsm_t prev_cmd;

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
    logic prev_group_valid;
    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            prev_group       <= 'b0;
            prev_group_valid <= 1'b0;
        end else if(selected_bank_ready) begin
            prev_group       <= selected_bank[$clog2(BANK_NUM)-3:0];
            prev_group_valid <= 1'b1;
        end
    end
    
    logic [2*BANK_NUM-1:0] be_arb_next;
    logic [BANK_NUM-1:0]   be_arb_folded;
    logic [BANK_NUM-1:0]   be_arb_held;  // sticky: stay high until FSM clears be_queue_ready
    assign be_arb_folded = be_arb_next[2*BANK_NUM-1:BANK_NUM] | be_arb_next[BANK_NUM-1:0];

    // Hold be_arb asserted on the selected bank until the FSM deasserts be_queue_ready
    // for that bank (indicating the command has been consumed).  A new arbitration
    // result can always override.
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST)
            barb.be_arb <= 'b0;
        else if (|be_arb_folded)
            barb.be_arb <= be_arb_folded;           // new grant overrides
        else
            barb.be_arb <= barb.be_arb & barb.be_queue_ready; // clear bits whose queue entry is gone
    end

    logic [$clog2(BANK_NUM)-1:0] selected_bank_next; 
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
    assign bg_mask = prev_group_valid
        ? (({BG_MASK, BG_MASK} << prev_group) | { {(2*BANK_NUM - ($clog2(BANK_NUM)-2)){1'b0}}, prev_group})
        : {(BANK_NUM*2){1'b1}};
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

	    be_arb_next = ( (be_queue_ready_double & (~be_cmd_double_ref) & ( four_access ? ~(be_cmd_double_act) : {(2*BANK_NUM){1'b1}}) & (bg_mask) ) &  ~((be_queue_ready_double & (~be_cmd_double_ref) & (four_access ? ~(be_cmd_double_act) : {(BANK_NUM*2){1'b1}} ) & (bg_mask)) - 'b1 )); 
		
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

		be_arb_next = (be_queue_ready_double & ~be_cmd_double_ref & (four_access ? ~(be_cmd_double_act) : {(2*BANK_NUM){1'b1}})) & ~((be_queue_ready_double & ~be_cmd_double_ref & (four_access ? ~(be_cmd_double_act) : {(2*BANK_NUM){1'b1}} )) - 'b1 );
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
    
    logic ref_re_ff_next;
    dram_state_t state_ff_next, nstate_ff_next;
    logic [RANK_BITS-1:0]       RA0_ff_next;
    logic [BANK_GROUP_BITS-1:0] BG0_ff_next;
    logic [BANK_BITS-1:0]       BA0_ff_next;
    logic [ROW_BITS-1:0]        R0_ff_next;
    logic [COLUMN_BITS-1:0]     C0_ff_next;

    always_comb begin : SIG_GEN_FF_NEXT
        if (!init_cif.init_done) begin
            ref_re_ff_next  = 1'b0;
            state_ff_next   = init_cif.init_state;
            nstate_ff_next  = init_cif.next_init_state;
            RA0_ff_next     = '0;
            BG0_ff_next     = '0;
            BA0_ff_next     = '0;
            R0_ff_next      = '0;
            C0_ff_next      = '0;
        end else begin
            ref_re_ff_next  = ref_re_next;
            state_ff_next   = state_next;
            nstate_ff_next  = IDLE;
            RA0_ff_next     = RA0_next;
            BG0_ff_next     = BG0_next;
            BA0_ff_next     = BA0_next;
            R0_ff_next      = R0_next;
            C0_ff_next      = C0_next;
        end
    end

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            barb.ref_re <= 1'b0;
            barb.state  <= IDLE;
            barb.nstate <= IDLE;
            barb.RA0    <= '0;
            barb.BG0    <= '0;
            barb.BA0    <= '0;
            barb.R0     <= '0;
            barb.C0     <= '0;
        end else begin
            barb.ref_re <= ref_re_ff_next;
            barb.state  <= state_ff_next;
            barb.nstate <= nstate_ff_next;
            barb.RA0    <= RA0_ff_next;
            barb.BG0    <= BG0_ff_next;
            barb.BA0    <= BA0_ff_next;
            barb.R0     <= R0_ff_next;
            barb.C0     <= C0_ff_next;
        end
    end

    //logic for pushing metadata to the read id queue for storing in-flight read IDs.
    assign barb.be_push_id = selected_bank_ready && (fsm_t'(barb.be_cmd[selected_bank]) == FSM_READ);
    assign barb.be_rid = barb.be_id[selected_bank];
    assign barb.be_rlen = barb.be_len[selected_bank];

    //logic for commanding write data queues to burst data to DRAM.
    assign barb.be_wid   = barb.be_id[selected_bank];
    assign barb.be_write = selected_bank_ready && (fsm_t'(barb.be_cmd[selected_bank]) == FSM_WRITE);

    // rf_enable: high whenever init is complete
    assign barb.rf_enable = init_cif.init_done;

    // rf_done: strobes all-ones for exactly one cycle on the rising edge of
    // ref_re.  ref_re can stay high for two cycles (rollover_L clears one
    // cycle after selected_bank_ready fires), so mask the second cycle out.
    logic ref_re_prev;
    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) ref_re_prev <= 1'b0;
        else        ref_re_prev <= barb.ref_re;
    end
    assign barb.rf_done = {BANK_NUM{barb.ref_re & ~ref_re_prev}};



endmodule 

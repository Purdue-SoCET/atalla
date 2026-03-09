`timescale 1ns/10ps

module nb_bank_queue(
    input logic CLK, nRST,
    ddr_controller_if.backend_arb barb
);

    //Selected bank priority encoder instantiation and logic. 
    logic [$clog2(BANK_NUM)-1:0] selected_bank;
    logic selected_bank_ready;
    priority_encoder_16to4 ENCODER_SEL ((barb.be_queue_ready & barb.be_arb), selected_bank, selected_bank_ready);

    //tCCD timers instantiations.
    logic rollover_L, rollover_S;
    logic en_L, en_S;
    flex_counter #(SIZE = 12) TCCD_L_TIM ( //these timers are cleared on successful handshakes.
        CLK, nRST, selected_bank_ready, en_L, tCCD_L, rollover_L
    );
    flex_counter #(SIZE = 12) TCCD_S_TIM (
        CLK, nRST, selected_bank_ready, en_S , tCCD_S, rollover_S
    );
    //tCCD timers enable logic.
    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST)  begin
            en_L = 'b1;
            en_S = 'b1;
        end else begin
            en_L = selected_bank_ready ? 'b1 : (rollover_L ? 'b0 : en_L );
            en_S = selected_bank_ready ? 'b1 : (rollover_S ? 'b0 : en_S );
        end
    end 

    //tFAW logic and SR instantiation. 
    logic [tFAW:0] sr_window;
    logic four_access; 
    logic [3:0] access_cnt;
    flex_sr #(.SIZE(tFAW + 'b1)) ACTIVATE_WINDOW (CLK, nRST, 1'b1, 1'b0, selected_bank_ready & (barb.cmd[selected_bank] == ACT) , 'b0, sr_window);
    
    integer i;
    four_access = (access_cnt >= 'd4);
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
    flex_sr #(.SIZE(BANK_NUM), .RING(1'b1)) PRIORITY_SR (CLK, nRST, selected_bank_ready, 1'b0, 1'b0,  'b0, priority);

    //Priority encoder for finding bank with priority.
    logic [$clog(BANK_NUM)-1:0] priority_idx;
    logic idrc; //I don't really care about what this bit is, it should always be one. 
    priority_encoder_16to4 ENCODER_PRI (priority_sr, priority_idx, idrc);

    //  register storing bank group of the last command. This ensures the compliance of timing parameters of two 
    //  successive transactions that target the same bank group. This timimg parameter, tCCD_L, is slightly more 
    //  than the tCCD_S that dictates the time between two different successive transactions that target
    //  different bank groups. 
    logic [BANK_NUM-1:0]  prev_group;
    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            prev_group <= 'b0;
        end else if(selected_bank_ready) begin
            prev_group <= selected_bank[1:0];
        end
    end

    //Combinational block for selecting bank based on priority.
    logic [$clog2(BANK_NUM)-1:0] k;
    logic [$clog2(BANK_NUM)-1:0] idx;
    always_comb begin : ARB_BLOCK
        barb.be_arb = 'b0;
        if(rollover_S && !rollover_L) begin

            for(k = 'b0; k < BANK_NUM; k++) begin
                idx = k + priority_idx;
                if(barb.be_queue_ready[idx] && (prev_group != idx[1:0]) && (barb.be_cmd[idx] != REF) ) begin
                    if( (barb.be_cmd[idx] == ACT) &&  !four_access  || (barb.be_cmd[idx] != ACT) ) begin
                        barb.be_arb[idx] = 1'b1;
                        break;
                    end
                end

            end
        end else if (rollover_L) begin

            //Handling refreshes
            if( (barb.be_cmd == {BANK_NUM{REF}}) && (barb.be_queue_ready == {BANK_NUM{1'b1}}) ) begin 

                barb.be_arb = {BANK_NUM{1'b1}};

            end else begin //Now the default case for for selecting banks after rollover_L is reached.

                for(k = 'b0; k < BANK_NUM; k++) begin
                    idx = k + priority_idx;
                    if(barb.be_queue_ready[idx]) begin
                        if( (barb.be_cmd[idx] == ACT) && !four_access || (barb.be_cmd[idx] != ACT) ) begin
                            barb.be_arb[idx] = 1'b1;
                            break;
                        end
                    end
                end

            end

        end


    end


endmodule 
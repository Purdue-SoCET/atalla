`include vector_if.vh
`include vector_pkg.vh

module vector_top
(
    input logic CLK, nRST,
    vector_if vif()
);

    import vector_pkg::*;

    logic veggie_out_t s1_in;
    logic veggie_out_t s1_out;



    assign vif.CLK = CLK;
    assign vif.nRST = nRST;

    //Veggie

    assign vif.veggie.veggie_in = scheduler.signal; //?? idk what scheduler is sending or what to call this
    assign

    assign veggie_out = opbuff_in;

    //Pipeline Latch #1

    always_ff @(posedge CLK, negedge nRST) begin
    {
        if (!nRST) begin
            s1_out <= '0;
        end
        else begin
            s1_out <= s1_in;
        end
    }

//need connection from veggie out to opbuff in
//need 



endmodule
module sramNios (CLOCK_50, LEDR, SW, KEY);
	input CLOCK_50; // 50MHz clock.
	output [9:0] LEDR;
	input [9:0] SW;
	input [3:0] KEY;
	
	wire [7:0] data_in;
	wire [7:0] data_out;
	wire trans_en;
	wire char_sent;
	wire load;
	wire char_recv;
	
	
	nios_system u0 (
        .clk_clk          (CLOCK_50),          //       clk.clk
        .leds_export      (LEDR[7:0]),      //      leds.export
        .reset_reset_n    (KEY[0]),    //     reset.reset_n
        .data_out_export  (data_out),  //  data_out.export
        .trans_en_export  (trans_en),  //  trans_en.export
        .char_sent_export (char_sent), // char_sent.export
        .load_export      (load),      //      load.export
        .data_in_export   (data_in),   //   data_in.export
        .char_recv_export (char_recv)  // char_recv.export
   );

endmodule


    
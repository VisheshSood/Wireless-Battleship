module communications (CLOCK_50, LEDR, KEY, GPIO_0);
	input CLOCK_50; // 50MHz clock.
	output [9:0] LEDR;
	input [3:0] KEY;
	inout [35:0] GPIO_0;
	
	wire [7:0] data_in;
	wire [7:0] data_out;
	wire trans_en;
	wire char_sent;
	wire load;
	reg char_waiting;
	
	// 16x 9600 BPS Baud
	wire clk16x;
	clock16x c0 (CLOCK_50, clk16x);
	
	// Transmit-side BSC
	wire sr_clock_trans;
	bsc bsc0 (sr_clock_trans, clk16x, trans_en);
	
	// Transmit-side Shift Register
	wire PISO_out;
	PISOSR10bit p0 (PISO_out, load, sr_clock_trans, data_out, ~KEY[0]);
	
	// Transmit Output Buffer
	buffer buf0 (GPIO_0[1], PISO_out, trans_en);
	
	// Transmit-side BIC
	bic bic0 (char_sent, sr_clock_trans, trans_en);
	
	// recieving char modules
	wire recv_en;
	
	startBitDetect sbd0 (recv_en, GPIO_0[0], char_received);
	
	wire sr_clock_recv;
	bsc bsc1 (sr_clock_recv, clk16x, recv_en);
	
	wire char_received;
	bic bic1 (char_received, sr_clock_recv, recv_en);
	
	SIPOSR10bit s0 (data_in, GPIO_0[0], ~sr_clock_recv, ~KEY[0]);
		
	nios_system u0 (
        .clk_clk          (CLOCK_50),  //       clk.clk
        .leds_export      (LEDR[7:0]), //      leds.export
        .reset_reset_n    (KEY[0]),    //     reset.reset_n
        .data_out_export  (data_out),  //  data_out.export
        .trans_en_export  (trans_en),  //  trans_en.export
        .char_sent_export (char_sent), // char_sent.export
        .load_export      (load),      //      load.export
        .data_in_export   (data_in),   //   data_in.export
        .char_recv_export (char_waiting)  // char_recv.export
   );
	
	always @(posedge char_received)
		char_waiting <= 1'b1;
		
endmodule


    
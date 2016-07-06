module communications (CLOCK_50, LEDR, KEY, serial_in, serial_out, rowSink, greenDriver, redDriver);
	input CLOCK_50; // 50MHz clock.
	output [9:0] LEDR;
	input [3:0] KEY;
	input serial_in;
	output serial_out;
	// LED array
	output [7:0] rowSink, greenDriver, redDriver;
	
	// SRAM
    wire [7:0] data;
	wire [10:0] address;
	wire notOutEn, readnWrite, chipSelect;
	
	sram RAM (data, address, notOutEn, readnWrite, chipSelect);
	
	// Comms
	wire [7:0] data_in;
	wire [7:0] data_out;
	reg [7:0] xx;
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
	buffer buf0 (serial_out, PISO_out, trans_en);
	
	// Transmit-side BIC
	bicTransmit bic0 (char_sent, sr_clock_trans, trans_en);
	
	// Receiving-side modules
	wire recv_en;
	startBitDetect sbd0 (recv_en, serial_in, char_received);
	
	wire sr_clock_recv;
	bsc bsc1 (sr_clock_recv, clk16x, recv_en);
	
	wire char_received;
	wire char_read;
	bicReceive bic1 (char_received, ~sr_clock_recv, recv_en, char_read);
	
	SIPOSR10bit s0 (data_in, serial_in, ~sr_clock_recv, ~KEY[0]);
	
	assign LEDR[9] = char_received;
	
	// LED array
	reg [7:0][7:0] yourShots, yourBoard;
	ledDriver (
		.greenDriver(greenDriver),
		.redDriver(redDriver), 
		.rowSink(rowSink), 
		.redArray(yourShots), 
		.greenArray(yourBoard), 
		.boardKey(KEY[1]), 
		.clk(CLOCK_50)
	);
	
    nios_system u0 (
        .address_export    (address),    //    address.export
        .char_read_export  (char_read),  //  char_read.export
        .char_recv_export  (char_received),  //  char_recv.export
        .char_sent_export  (char_sent),  //  char_sent.export
        .chipreset_export  (chipSelect),  //  chipreset.export
        .clk_clk           (CLOCK_50),           //        clk.clk
        .data_export       (data),       //       data.export
        .data_in_export    (data_in),    //    data_in.export
        .data_out_export   (data_out),   //   data_out.export
        .leds_export       (LEDR[7:0]),       //       leds.export
        .load_export       (load),       //       load.export
        .notouten_export   (notOutEn),   //   notouten.export
        .readnwrite_export (readnWrite), // readnwrite.export
        .reset_reset_n     (KEY[0]),     //      reset.reset_n
        .trans_en_export   (trans_en),    //   trans_en.export
		  .yourboard0_export	(yourBoard[7]),
		  .yourboard1_export	(yourBoard[6]),
		  .yourboard2_export	(yourBoard[5]),
		  .yourboard3_export	(yourBoard[4]),
		  .yourboard4_export	(yourBoard[3]),
		  .yourboard5_export	(yourBoard[2]),
		  .yourboard6_export	(yourBoard[1]),
		  .yourboard7_export	(yourBoard[0]),
		  .yourshots0_export	(yourShots[7]),
		  .yourshots1_export	(yourShots[6]),
		  .yourshots2_export	(yourShots[5]),
		  .yourshots3_export	(yourShots[4]),
		  .yourshots4_export	(yourShots[3]),
		  .yourshots5_export	(yourShots[2]),
		  .yourshots6_export	(yourShots[1]),
		  .yourshots7_export	(yourShots[0])
    );

			
endmodule


    
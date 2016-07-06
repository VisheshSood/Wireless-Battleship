/**
 * EE 371 Lab 4: Extending a Simple Microprocessor – Adding I/O
 * Justin Allmaras, Sean Happenny, Vishesh Sood
 * 2/16/2016
 *
 * Serial_IOTop.v
 * The top level Verilog file for our serial I/O system. 
 *
 */
 
 module Serial_IOTop (LEDR, physTx, physRx, SW, KEY, CLK);
	output [7:0] LEDR;
	output physTx;
		
	input [9:0] SW;
	input physRx, KEY, CLK;
	
	reg [7:0] TX, RX;
	wire load, charRcvd, charSent, txEnable;
	
	// SRAM
	reg [10:0] address;
	wire [7:0] data;
	wire chipSelect, outEnable, writeEnable;
	
	
	nios2_system (
		.clk_clk						(CLK),
		.reset_reset_n				(KEY),
		.receive_export			(RX),
		.charrcvd_export			(charRcvd),
		.transmit_export			(TX),
		.transmitenable_export	(txEnable),
		.load_export				(load),
		.charsent_export			(charSent),
		.switch_export				(SW),
		.led_export					(LEDR),
		
		// SRAM
		.data_export				(data),
		.outenable_export    	(enable),
		.chipselect_export		(chipSelect),
		.address_export   		(address),
		.writeenable_export		(writeEnable)
		
	);
	
	serial(
		.serDataIn 			(physRx), 
		.serDataOutBuf 	(physTx), 
		.transmitEnable 	(txEnable), 
		.charSent 			(charSent), 
		.load 				(load), 
		.parDataOut 		(TX), 
		.parDataIn 			(RX), 
		.charReceived 		(charRcvd), 
		.clk					(CLK)
		);
	
	
	sRam(
		.data			(data),
		.address		(address),
		.chipSelect	(chipSelect),
		.outEnable	(outEnable),
		.writeEnable(writeEnable),
		.clk			(CLK),
		.reset		(KEY)
	);
	 
 endmodule
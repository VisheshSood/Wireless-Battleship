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
	output [9:0] LEDR;
	output physTx;
		
	input [9:0] SW;
	input physRx, KEY, CLK;
	
	reg [7:0] dataIn, dataOut, TX, RX;
	wire load, charRcvd, charSent, txEnable;
	
	/*
	// SRAM
	reg [10:0] address;
	wire chipSelect, enable, readnWrite;
	*/
	
	nios2_system (
		.clk_clk														(CLK),
		.reset_reset_n												(KEY),
		.receive_pio_external_connection_export			(RX),
		.charrcvd_pio_external_connection_export			(charRcvd),
		.transmit_pio_external_connection_export			(TX),
		.transmitenable_pio_external_connection_export	(txEnable),
		.load_pio_external_connection_export				(load),
		.charsent_pio_external_connection_export			(charSent),
		.switch_pio_external_connection_export				(SW),
		.led_pio_external_connection_export					(LEDR),
		
		// SRAM
		.datain_pio_external_connection_export  			(dataOut),
		.dataout_pio_external_connection_export			(dataIn),
		.enable_pio_external_connection_export    		(enable),
		.chipselect_pio_external_connection_export		(chipSelect),
		.address_pio_external_connection_export   		(address),
		.readnwrite_pio_external_connection_export		(readnWrite)
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
	
	/*
	sRam(
		.dataIn		(dataIn),
		.dataOut		(dataOut),
		.address		(address),
		.chipSelect	(chipSelect),
		.enable		(enable),
		.readnWrite	(readnWrite),
		.reset		(KEY)
	);
	*/
	
 
 endmodule
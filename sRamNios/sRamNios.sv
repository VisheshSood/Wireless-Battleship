

module sRamNios (leds , chipSelect , enable , readnWrite , address , clk , rst , dataOut);
	input clk , rst;
	output [7:0] leds;
	output chipSelect , enable , readnWrite;
	output [10:0] address;
	reg [7:0] dataIn;
	output [7:0] dataOut;
	
	sRamQsys system (
		.clk_clk                                   (clk),                                   //                                clk.clk
		.reset_reset_n                             (rst),                             //                              reset.reset_n
		.led_pio_external_connection_export        (leds),        //        led_pio_external_connection.export
		.datain_export      								 (dataOut),       //       data_pio_external_connection.export
		.dataout_export									 (dataIn),
		.enable_pio_external_connection_export     (enable),     //     enable_pio_external_connection.export
		.chipselect_pio_external_connection_export (chipSelect), // chipselect_pio_external_connection.export
		.address_pio_external_connection_export    (address),    //    address_pio_external_connection.export
		.readnwrite_pio_external_connection_export (readnWrite)  // readnwrite_pio_external_connection.export
	);
	
	sRam(.dataIn(dataIn) , .dataOut(dataOut) , .address(address) , .chipSelect(chipSelect) , .enable(enable) , .readnWrite(readnWrite) , .reset(rst));
	

endmodule


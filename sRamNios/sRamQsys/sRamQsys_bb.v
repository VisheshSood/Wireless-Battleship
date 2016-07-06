
module sRamQsys (
	address_pio_external_connection_export,
	chipselect_pio_external_connection_export,
	clk_clk,
	dataout_export,
	enable_pio_external_connection_export,
	led_pio_external_connection_export,
	readnwrite_pio_external_connection_export,
	reset_reset_n,
	datain_export);	

	output	[10:0]	address_pio_external_connection_export;
	output		chipselect_pio_external_connection_export;
	input		clk_clk;
	output	[7:0]	dataout_export;
	output		enable_pio_external_connection_export;
	output	[7:0]	led_pio_external_connection_export;
	output		readnwrite_pio_external_connection_export;
	input		reset_reset_n;
	input	[7:0]	datain_export;
endmodule

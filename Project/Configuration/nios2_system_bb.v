
module nios2_system (
	address_pio_external_connection_export,
	charrcvd_pio_external_connection_export,
	charsent_pio_external_connection_export,
	chipselect_pio_external_connection_export,
	clk_clk,
	datain_pio_external_connection_export,
	dataout_pio_external_connection_export,
	enable_pio_external_connection_export,
	led_pio_external_connection_export,
	load_pio_external_connection_export,
	readnwrite_pio_external_connection_export,
	receive_pio_external_connection_export,
	reset_reset_n,
	switch_pio_external_connection_export,
	transmit_pio_external_connection_export,
	transmitenable_pio_external_connection_export);	

	output	[10:0]	address_pio_external_connection_export;
	input		charrcvd_pio_external_connection_export;
	input		charsent_pio_external_connection_export;
	output		chipselect_pio_external_connection_export;
	input		clk_clk;
	input	[7:0]	datain_pio_external_connection_export;
	output	[7:0]	dataout_pio_external_connection_export;
	output		enable_pio_external_connection_export;
	output	[7:0]	led_pio_external_connection_export;
	output		load_pio_external_connection_export;
	output		readnwrite_pio_external_connection_export;
	input	[7:0]	receive_pio_external_connection_export;
	input		reset_reset_n;
	input	[7:0]	switch_pio_external_connection_export;
	output	[7:0]	transmit_pio_external_connection_export;
	output		transmitenable_pio_external_connection_export;
endmodule

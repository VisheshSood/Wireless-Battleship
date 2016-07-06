
module nios_system (
	address_export,
	char_read_export,
	char_recv_export,
	char_sent_export,
	chipreset_export,
	clk_clk,
	data_export,
	data_in_export,
	data_out_export,
	leds_export,
	load_export,
	notouten_export,
	readnwrite_export,
	reset_reset_n,
	trans_en_export,
	yourboard0_export,
	yourboard1_export,
	yourboard2_export,
	yourboard3_export,
	yourboard4_export,
	yourboard5_export,
	yourboard6_export,
	yourboard7_export,
	yourshots0_export,
	yourshots1_export,
	yourshots2_export,
	yourshots3_export,
	yourshots4_export,
	yourshots5_export,
	yourshots6_export,
	yourshots7_export);	

	output	[10:0]	address_export;
	output		char_read_export;
	input		char_recv_export;
	input		char_sent_export;
	output		chipreset_export;
	input		clk_clk;
	inout	[7:0]	data_export;
	input	[7:0]	data_in_export;
	output	[7:0]	data_out_export;
	output	[7:0]	leds_export;
	output		load_export;
	output		notouten_export;
	output		readnwrite_export;
	input		reset_reset_n;
	output		trans_en_export;
	output	[7:0]	yourboard0_export;
	output	[7:0]	yourboard1_export;
	output	[7:0]	yourboard2_export;
	output	[7:0]	yourboard3_export;
	output	[7:0]	yourboard4_export;
	output	[7:0]	yourboard5_export;
	output	[7:0]	yourboard6_export;
	output	[7:0]	yourboard7_export;
	output	[7:0]	yourshots0_export;
	output	[7:0]	yourshots1_export;
	output	[7:0]	yourshots2_export;
	output	[7:0]	yourshots3_export;
	output	[7:0]	yourshots4_export;
	output	[7:0]	yourshots5_export;
	output	[7:0]	yourshots6_export;
	output	[7:0]	yourshots7_export;
endmodule

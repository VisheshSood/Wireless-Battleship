`include "bic.v"
`include "bsc.v"
`include "SIPOSR10bit.v"
`include "startBitDetect.v"

module serial_in_testbench;
	wire [7:0] data_in;
	wire serial_in, receive_en, sr_clock, char_received, clk;
	
	startBitDetect sbd (receive_en, serial_in, char_received);
	bic bic0 (char_received, ~sr_clock, receive_en);
	bsc bsc0 (sr_clock, clk, receive_en);
	SIPOSR10bit sipo (data_in, serial_in, ~sr_clock, rst);
	
	Tester aTester (serial_in, clk);
	
	initial
		begin 
			$dumpfile("serial_in.vcd");
			$dumpvars(4,bic0,bsc0,sipo,sbd);
	end
endmodule



module Tester(serial_in, clk);
	output reg serial_in = 1'b1;
	output reg clk = 1'b1;

	
	parameter stimDelay = 20;
	
	initial begin
		forever
			#stimDelay clk <= ~clk;
	end
		
	initial
		begin
			#(20 * stimDelay); serial_in <= 1'b0;
			#(32 * stimDelay); serial_in <= 1'b1;
			#(32 * stimDelay); serial_in <= 1'b0;
			#(32 * stimDelay); serial_in <= 1'b0;
			#(32 * stimDelay); serial_in <= 1'b1;
			#(32 * stimDelay); serial_in <= 1'b1;
			#(32 * stimDelay); serial_in <= 1'b0;
			#(32 * stimDelay); serial_in <= 1'b0;
			#(32 * stimDelay); serial_in <= 1'b1;
			#(32 * stimDelay); serial_in <= 1'b1;
			#(100 * stimDelay);
			$finish;
		end 
endmodule
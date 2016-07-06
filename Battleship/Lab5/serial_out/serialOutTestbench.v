`include "bic.v"
`include "bsc.v"
`include "PISOSR10bit.v"
`include "buffer.v"

module sramTestBench;
	wire [7:0] data_in;
	wire transmit_en, load, character_sent, sr_clock, clk, buf_in, buf_out, rst;
	
	bic bic0 (character_sent, sr_clock, transmit_en);
	bsc bsc0 (sr_clock, clk, transmit_en);
	buffer buf0 (buf_out, buf_in, transmit_en);
	PISOSR10bit piso (buf_in, load, sr_clock, data_in, rst);
	
	Tester aTester (transmit_en, data_in, load, clk);
	
	initial
		begin 
			$dumpfile("serial_out.vcd");
			$dumpvars(4,bic0,bsc0,piso,buf0);
	end
endmodule



module Tester(transmit_en, data_in, load, clk);
	output reg [7:0] data_in;
	output reg transmit_en, load;
	output reg clk = 1'b1;

	
	parameter stimDelay = 20;
	
	initial begin
		forever
			#stimDelay clk <= ~clk;
	end
		
	initial
		begin
			data_in <= 8'b10011001; load <= 1'b1; transmit_en <= 1'b0;
			#(10 *stimDelay); transmit_en <= 1'b1;
			#stimDelay; load <= 1'b0;
			#(1000 * stimDelay);
			$finish;
		end 
endmodule
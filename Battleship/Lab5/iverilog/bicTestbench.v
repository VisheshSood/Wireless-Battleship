`include "bic.v"

module bicTestBench;
	wire seq_complete, sr_clock, trans_en;
	
	bic dut (seq_complete, sr_clock, trans_en);
	
	Tester aTester (sr_clock, trans_en);
	
	initial
		begin 
			$dumpfile("bic.vcd");
			$dumpvars(1,dut);
	end
endmodule



module Tester(clk, trans_en);
	output reg clk, trans_en;

	
	parameter stimDelay = 20;
		
	initial
		begin
			clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0; trans_en = 1;
			#stimDelay clk = 1; 
			#stimDelay clk = 0;
			#stimDelay clk = 1; 
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1; 
			#stimDelay clk = 0;
			#stimDelay clk = 1; 
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			#stimDelay clk = 1;
			#stimDelay clk = 0;
			$finish;
		end 
endmodule
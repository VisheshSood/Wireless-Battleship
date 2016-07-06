
/// NOT NEEDED, SEE BSC "assign sr_clock = count[3];"

module SRclkctrl(SIPOclk, clk, rst);
	input clk, rst;
	output reg SIPOclk = 1'b0;
	reg [2:0] count = 3'b0;
	
	always @(posedge clk or posedge rst)
		if (rst) count <= 3'b0;
		else count <= count + 1'b1;
		
	always @(posedge clk or posedge rst)
		if (rst) SIPOclk <= 1'b0;
		else if (count == 3'b111) SIPOclk <= ~SIPOclk;
endmodule
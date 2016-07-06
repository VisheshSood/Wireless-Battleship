module SIPOSR10bit (dataout, datain, sr_clock, rst);
	output [7:0] dataout;
	input datain, sr_clock, rst;
	
	reg [9:0] buffer = 10'b0;
	
	assign dataout = buffer[8:1];
	
	always @(posedge sr_clock or posedge rst)
		if (rst) buffer <= 10'b0;
		else buffer <= {buffer[8:0], datain};
endmodule 
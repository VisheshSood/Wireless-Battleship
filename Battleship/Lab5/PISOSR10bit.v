module PISOSR10bit (bit_out, load, sr_clock, data, rst);
	input sr_clock, load, rst;
	input [7:0] data;
	output bit_out;
	
	reg [9:0] buffer = 10'b1111111111;
	
	assign bit_out = buffer[9];
	
	always @(posedge sr_clock or posedge rst)
		if (rst) buffer <= 10'b0;
		else if (load) buffer <= {1'b0, data, 1'b1};
		else buffer <= {buffer[8:0], 1'b1}; // shift out

endmodule

module bsc (sr_clock, clk16x, bsc_en);
	input clk16x;
	input bsc_en;
	output sr_clock;    
	
	reg [3:0] bsc_count = 4'b0;
	
	assign sr_clock = ~bsc_count[3] & bsc_en;
	
	always@(posedge clk16x)
		if (bsc_en) bsc_count <= bsc_count + 1'b1;
		else bsc_count <= 4'b0;

endmodule 
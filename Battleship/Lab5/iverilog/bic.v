module bic (seq_complete, sr_clock, trans_en);
	input trans_en, sr_clock;
	output seq_complete;
	
	reg [3:0] count = 4'b0;
	
	always@(posedge sr_clock)
		if (trans_en) count <= count + 1'b1;
		else count <= 4'b0;
	
	assign seq_complete = count[3] & ~count[2] & count[1] & count[0];
endmodule
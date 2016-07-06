module bic (seq_complete, sr_clock, bic_en);
	input bic_en, sr_clock;
	output seq_complete;
	
	reg [3:0] bic_count = 4'b0;
	
	always@(posedge sr_clock)
		if (bic_en) bic_count <= bic_count + 1'b1;
		else bic_count <= 4'b0;
	
	assign seq_complete = bic_count[3] & ~bic_count[2] & bic_count[1] & bic_count[0];
endmodule

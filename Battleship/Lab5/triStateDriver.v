module triStateDriver(out, in, trans_en);
	output out;
	input in, trans_en;
	
	assign out = trans_en ? in : 1'bz;
endmodule
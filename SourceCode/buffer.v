module buffer(buf_out, buf_in, buf_en);
	output buf_out;
	input buf_in, buf_en;
	
	assign buf_out = buf_en ? buf_in : 1'b1;
endmodule
module startBitDetect(recv_en, data_in, char_received);
	output reg recv_en = 1'b0;
	input data_in, char_received;

	always @(negedge data_in or posedge char_received)
		if (char_received) recv_en <= 1'b0;
		else recv_en <= 1'b1;
endmodule
 
 module ledDriver (greenDriver, redDriver, rowSink, redArray, greenArray, boardKey, clk);
	input boardKey, clk;
	input [7:0][7:0] redArray, greenArray;
	//output reg [7:0] led; // TODO debugging
	output reg [7:0] redDriver, greenDriver, rowSink;
	reg [2:0] count; 
	reg [19:0] slowClk;

	
	always @(posedge clk)
	begin
		slowClk = slowClk + 1;
	end
	
	always @(posedge slowClk[14])
	begin
		count <= count + 3'b001; 
	end
		
	always @(*)
	begin
		case (count[2:0]) 
				3'b000: rowSink = 8'b11111110; 
				3'b001: rowSink = 8'b11111101;
				3'b010: rowSink = 8'b11111011; 
				3'b011: rowSink = 8'b11110111; 
				3'b100: rowSink = 8'b11101111;
				3'b101: rowSink = 8'b11011111; 
				3'b110: rowSink = 8'b10111111; 
				3'b111: rowSink = 8'b01111111;
		endcase 
		redDriver = (~boardKey) ? redArray[count] : 8'b0;
		greenDriver = (boardKey) ? greenArray[count] : 8'b0;
	end
 
 endmodule
 
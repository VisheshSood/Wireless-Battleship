
module serial (serDataIn , serDataOutBuf , transmitEnable , charSent , load , parDataOut , parDataIn , charReceived , clk);
	input serDataIn , load , transmitEnable , clk;
	input [7:0] parDataOut;
	output[7:0] parDataIn;
	output serDataOutBuf , charSent , charReceived;
	wire clk16x;
	
	wire rxShift, txShift, serDataInBuf , serDataOut , receiveEnable;
	
	clock9600 dataClk (.clockIn(clk) , .clockOut(clk16x));
	
	buffer a (.out(serDataInBuf) , .in(serDataIn));
	buffer b (.out(serDataOutBuf) , .in(serDataOut));
	
	shiftRegister10StoP rxShiftReg (.dataOut(parDataIn) , .dataIn(serDataInBuf) , .registerClk(rxShift));
	shiftRegister10PtoS txShiftReg (.dataOut(serDataOut) , .dataIn(parDataOut) , .registerClk(txShift) , .load(load) , .enable(transmitEnable));
	
	counter txCounter (.shiftOut(txShift) , .charStatus(charSent) , .enable(transmitEnable) , .clk(clk16x));
	counter rxCounter (.shiftOut(rxShift) , .charStatus(charReceived) , .enable(receiveEnable) , .clk(clk16x));
	
	startBitDetect bitDet (.receiveEnable(receiveEnable) , .dataIn(serDataInBuf) , .charRcvd(charReceived));

endmodule

module clock9600 ( clockIn , clockOut );
	input clockIn;
	output reg clockOut;
	
	integer count;
	initial begin
		count = 0;
	end
	
	always @(posedge clockIn)
	begin
		count = count + 1;
		if (count < 163) 
		begin
			clockOut = 0;
		end
		else if (count >= 325)
		begin
			clockOut = 1;
			count = 1;
		end
		else
		begin
			clockOut = 1;
		end
	end
endmodule
	

module buffer(out , in);
	input in;
	output reg out;
	
	always @(in) begin
		out = in;
	end
endmodule


module shiftRegister10StoP (dataOut , dataIn , registerClk);

	input dataIn , registerClk;
   output [7:0] dataOut;
	reg [9:0] store;
	
	assign dataOut = store [8:1];
	
	// MSB sent first, so it is put in lower position and shifted up
	always @(posedge registerClk) 
	begin
		begin
			store = store << 1;
			store[0] = dataIn;
		end
	end
endmodule


module shiftRegister10PtoS (dataOut , dataIn , registerClk , load , enable);
	output reg dataOut;
	input [7:0] dataIn;
	input enable , registerClk , load;
	reg [9:0] store;
	
	
	// MSB sent first
	always @(posedge registerClk or posedge load)
	begin
		if (load)
		// Loads data into the shift register
		begin
			dataOut = 1;
			store[0] = 1;
			store[8:1] = dataIn;
			store[9] = 0;
		end
		else if(enable)
		// Outputs the data starting with the MSB onto the transmit line
		begin
			dataOut <= store[9];
			store <= store << 1;
		end
		else
		// Holds quiescent state of the line
		begin
			dataOut = 1;
			store = store;
		end
	end	
endmodule


/*module  bitIdentificationCounter (charStatus , enable , clk);
	output charStatus;
    input enable , clk;
    reg [3:0] bitCount;
	
	always @(posedge enable) 
	begin
		bitCount = 4'b0000;
	end
	
	always @(posedge clk)
	begin
		if(bitCount < 9)
		begin
			bitCount = bitCount + 1;
		end
		else
		begin
			bitCount = 4'b0000;
		end
	end

	assign charStatus = bitCount[0] & ~bitCount[1] & ~bitCount[2] & bitCount[3];
endmodule


module bitSampleCounter (bitIdentificationOut , shiftOut , clk , enable);
	output bitIdentificationOut , shiftOut;
	input enable , clk;
	
	reg [3:0] bitCount;
	
	assign shiftOut = bitCount[3];
	assign bitIdentificationOut = bitCount[0] & bitCount[1] & bitCount[2] & bitCount[3];

endmodule*/

module counter(shiftOut , charStatus , enable , clk);
	input enable , clk;
	output charStatus , shiftOut;

	reg [7:0] count;
	
	/*
	always @(posedge enable)
	begin
		count = 8'b00000000;
	end
	*/
	
	always @(posedge clk)
	begin
		if(enable)
		begin
			count = count + 8'b00000001;
		end
		else
		begin
			count = 8'b00000000;
		end
	end
	assign shiftOut = count[3] && ~count[2] && ~count[1] && ~count[0];
	assign charStatus = count[7] && ~count[6] && count[5] && ~count[4];
endmodule


module startBitDetect (receiveEnable , dataIn , charRcvd);
	input dataIn , charRcvd;
	output reg receiveEnable;	
	
	/*
	always @(negedge dataIn)
	begin
		if(!charRcvd)
		begin
			receiveEnable = 1;
		end
		else
		begin
			receiveEnable = 0;
		end
	end
	*/
	
	always @(negedge dataIn or posedge charRcvd)
	begin
		if (charRcvd)
		begin
			receiveEnable = 1'b0;
		end
		else
		begin
			receiveEnable = 1'b1;
		end
	end
endmodule



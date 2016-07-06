 module sRam(dataIn , dataOut , chipSelect , enable , readnWrite , address , reset);
	input [7:0] dataIn;
	output reg [7:0] dataOut;
	input chipSelect , enable , readnWrite , reset;
	input [10:0] address;
	
	reg [2047:0][7:0] memory;	
	
	always @(negedge enable)
	begin
		dataOut <= memory[address];
	end

	
	always @(posedge readnWrite)
	begin
		memory[address] <= dataIn;
	end
	
endmodule


//2k by 8 bits
/*module sRamDriver(data , chipSelect , writeData , readnWrite , enable);
	inout [7:0] data;
	input chipSelect , readnWrite , enable; 
	input [7:0] writeData;

	assign data = (!readnWrite && !enable) ? writeData : 8'bzzzzzzzz;

endmodule*/

/*
module sRam (data, address , chipSelect , enable , readnWrite , reset);
	inout [7:0] data;
	input [10:0] address;
	input chipSelect , enable , readnWrite , reset;
	reg [2047:0][7:0] memory;
	
	reg readyForWrite;
	reg [7:0] readData;
	
	assign data = (readnWrite && !enable) ? readData : 8'bz;
	
	
	wire [2047:0] index;
	
	parameter PROP_DELAY = 0;
	parameter T_WRITE = 0;

	
	
	always @(negedge enable) 
	begin
		if(!reset)
		begin
			#PROP_DELAY
			if(!chipSelect && readnWrite && !enable)
			begin
				readData <= memory[address];
			end
		end
	end
	
	
	always @(negedge readnWrite)
	begin
		if(!reset)
		begin
			readyForWrite <= 0;
			#PROP_DELAY
			if(enable && !chipSelect && !readnWrite)
			begin
				#(T_WRITE - PROP_DELAY)
				readyForWrite <= 1'b1;
			end
		end
	end
	
	
	always @(posedge readnWrite)
	begin
		if(!reset)
		begin
			if(enable && !chipSelect && readyForWrite)
			begin
				memory[address] <= data;
				//readyForWrite <= 1'b0;
			end
		end
	end


endmodule
*/
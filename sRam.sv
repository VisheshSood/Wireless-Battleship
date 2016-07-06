/**
 * Justin Allmaras, Sean Happenny, Vishesh Sood
 * EE 371
 * Final Project
 * 3/10/2016
 * sRam.v
 * Verilog module for a simple SRAM memory system.
 */

 module sRam(data, chipSelect, outEnable, writeEnable, address, clk, reset);
	inout [7:0] data;
	input chipSelect, outEnable, writeEnable, clk, reset;
	input [10:0] address;
	
	reg [7:0] dataTmp;
	reg [2047:0][7:0] memory;	
	
	// Tri-state device setup
	assign data = (chipSelect && outEnable && !writeEnable) ? dataTmp : 8'bz; 
	
	// Read
	always @(posedge clk)
	begin
		if (chipSelect && !writeEnable && outEnable)
		begin
			dataTmp <= memory[address];
		end
	end
	
	// Write
	always @(posedge clk)
	begin
		if (chipSelect && writeEnable)
		begin
			memory[address] <= data;
		end
	end
			
endmodule

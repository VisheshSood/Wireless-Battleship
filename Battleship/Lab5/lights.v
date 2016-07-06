module lights (CLOCK_50, LEDR, SW, KEY);
	input CLOCK_50; // 50MHz clock.
	output [9:0] LEDR;
	input [9:0] SW;
	input [3:0] KEY;
	
	nios_system u0 (
	  .clk_clk         (CLOCK_50),	//      clk.clk
	  .reset_reset_n   (KEY[0]),		//    reset.reset_n
	  .switches_export (SW[7:0]),		// switches.export
	  .leds_export     (LEDR[7:0])	//     leds.export
	);

endmodule
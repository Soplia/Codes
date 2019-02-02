`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:07:27 12/28/2011
// Design Name:   Top
// Module Name:   /home/yq/project/Genesys/SimpleCycle_MIPS/Top_tb.v
// Project Name:  SimpleCycle_MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Top_tb;

	// Inputs
	reg ClkIn;
	reg Rst;
	reg [7:0] Switch;

	// Outputs
	wire [7:0] Led;

	// Instantiate the Unit Under Test (UUT)
	Top uut (
		.ClkIn(ClkIn), 
		.Rst(Rst), 
		.Led(Led)
	);

	initial begin
		// Initialize Inputs
		ClkIn = 0;
		Rst = 1;
		Switch = 0;
		// Wait 100 ns for global Rst to finish
		#80;
       Rst = 0; 
		  
		// Add stimulus here

	end
	always #5 ClkIn = !ClkIn;
      
endmodule


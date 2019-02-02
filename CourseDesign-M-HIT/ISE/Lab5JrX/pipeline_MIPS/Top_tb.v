`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   09:25:41 04/23/2018
// Design Name:   Top
// Module Name:   F:/ISE/Lab5JrX/pipeline_MIPS/Top_tb.v
// Project Name:  pipeline_MIPS
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
	reg Clk;
	reg Rst;
	reg [7:0] Switch;

	// Outputs
	wire [31:0] Test;
	wire [7:0] Led;

	// Instantiate the Unit Under Test (UUT)
	Top uut (
		.Clk(Clk), 
		.Rst(Rst), 
		.Switch(Switch), 
		.Test(Test), 
		.Led(Led)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		Rst = 1;
		Switch = 0;

		// Wait 100 ns for global reset to finish
		#10;
       Rst = 0;
		// Add stimulus here

	end
   always #2 Clk = ! Clk;
endmodule


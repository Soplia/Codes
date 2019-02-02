`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:     
// Design Name: 
// Module Name:    ALU 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module ALU(
    input [31:0] SrcA,
    input [31:0] SrcB,
    input [3:0] ALUCtr,
    output Zero,
    output reg [31:0] ALURes
    );

assign Zero = (ALURes ==1'b0);//Zero is true if ALURes is 0;

always @ (SrcA or SrcB or ALUCtr)
begin
    case (ALUCtr)
       4'b0000: ALURes = SrcA & SrcB;		//AND
       4'b0001: ALURes = SrcA | SrcB;		//OR
       4'b0010: ALURes = SrcA + SrcB;		//add
       4'b0110: ALURes = SrcA - SrcB;		//substract
       4'b0111: ALURes = SrcA < SrcB ? 1:0;	//set on less than
       4'b1100: ALURes = ~(SrcA|SrcB);		//NOR
       default: ALURes = 32'h0;
    endcase
end

endmodule

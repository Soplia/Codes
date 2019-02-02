`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:17:40 12/07/2011 
// Design Name: 
// Module Name:    Ctr 
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
module Ctr(
    input [5:0] OpCode,
	 input [5:0] Funct,
    output reg RegDstD,
    output reg ALUSrcD,
    output reg MemToRegD,
    output reg RegWriteD,
    output reg MemWriteD,
    output reg BranchD,
    output reg [3:0] ALUControlD
    );

reg [1:0] ALUOp;

always @(OpCode)
begin
    case(OpCode)
        
        //R type
        6'b000000:
        begin
            RegDstD = 1;
            ALUSrcD = 0;
            MemToRegD = 0;
            RegWriteD = 1;
            MemWriteD = 0;
            BranchD = 0;
            ALUOp = 2'b10;
        end

        //beq
        6'b000100:
        begin
            RegDstD = 0;
            ALUSrcD = 0;
            MemToRegD = 0;
            RegWriteD = 0;
            MemWriteD = 0;
            BranchD = 1;
            ALUOp = 2'b01;
        end

        //lw
        6'b100011:
        begin
            RegDstD = 0;
            ALUSrcD = 1;
            MemToRegD = 1;
            RegWriteD = 1;
            MemWriteD = 0;
            BranchD = 0;
            ALUOp = 2'b00;
        end
	
        //sw
        6'b101011:
        begin
            RegDstD = 0;
            ALUSrcD = 1;
            MemToRegD = 0;
            RegWriteD = 0;
            MemWriteD = 1;
            BranchD = 0;
            ALUOp = 2'b00;
        end

		//Jump
        6'b000010:
        begin
            RegDstD = 0;
            ALUSrcD = 0;
            MemToRegD = 0;
            RegWriteD = 0;
            MemWriteD = 0;
            BranchD = 0;
            ALUOp = 2'b00;
        end 
        
        //default
        default:
        begin
            RegDstD = 0;
            ALUSrcD = 0;
            MemToRegD = 0;
            RegWriteD = 0;
            MemWriteD = 0;
            BranchD = 0;
            ALUOp = 2'b00;
        end
	endcase
	end
	
    always @ (ALUOp or Funct )
	begin
        casex ({ALUOp,Funct})
            8'b00xxxxxx : ALUControlD = 4'b0010;  //LW/SW :add
            8'b01xxxxxx : ALUControlD = 4'b0110;  //BEQ :substract
            8'b1xxx0000 : ALUControlD = 4'b0010;  //R-type:add 
            8'b1xxx0010 : ALUControlD = 4'b0110;  //R-type:substract
            8'b1xxx0100 : ALUControlD = 4'b0000;  //R-tyep:AND
            8'b1xxx0101 : ALUControlD = 4'b0001;  //R-type:OR
            8'b1xxx1010 : ALUControlD = 4'b0111; //R-type:set on less than
            default:     ALUControlD = 4'b0000;
        endcase
	end
endmodule

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
    output reg RegDst,
    output reg ALUSrc,
    output reg MemToReg,
    output reg RegWrite,
    output reg MemWrite,
	 output reg MemRead,
    output reg Branch,
    output reg [3:0] ALUControl,
    output reg Jump
    );

reg [1:0] ALUOp;

always @(OpCode)
begin
    case(OpCode)
        
        //R type
        6'b000000:
        begin
            RegDst = 1;
            ALUSrc = 0;
            MemToReg = 0;
            RegWrite = 1;
            MemWrite = 0;
            Branch = 0;
            ALUOp = 2'b10;
			Jump = 0;
        end

        //beq
        6'b000100:
        begin
            RegDst = 0;
            ALUSrc = 0;
            MemToReg = 0;
            RegWrite = 0;
            MemWrite = 0;
            Branch = 1;
            ALUOp = 2'b01;
            Jump = 0;
        end

        //lw
        6'b100011:
        begin
            RegDst = 0;
            ALUSrc = 1;
            MemToReg = 1;
            RegWrite = 1;
            MemWrite = 0;
            Branch = 0;
            ALUOp = 2'b00;
            Jump = 0;
        end
	
        //sw
        6'b101011:
        begin
            RegDst = 0;
            ALUSrc = 1;
            MemToReg = 0;
            RegWrite = 0;
            MemWrite = 1;
            Branch = 0;
            ALUOp = 2'b00;
            Jump = 0;
        end

		//Jump
        6'b000010:
        begin
            RegDst = 0;
            ALUSrc = 0;
            MemToReg = 0;
            RegWrite = 0;
            MemWrite = 0;
            Branch = 0;
            ALUOp = 2'b00;
            Jump = 1;
        end 
        
        //default
        default:
        begin
            RegDst = 0;
            ALUSrc = 0;
            MemToReg = 0;
            RegWrite = 0;
            MemWrite = 0;
            Branch = 0;
            ALUOp = 2'b00;
            Jump = 0;
        end
	endcase
	end
	
   always @ (ALUOp or Funct )
	begin
        casex ({ALUOp,Funct})
            8'b00xxxxxx : ALUControl = 4'b0010;  //LW/SW :add
            8'b01xxxxxx : ALUControl = 4'b0110;  //BEQ:substract
            8'b1xxx0000 : ALUControl = 4'b0010;  //R-type:add 
            8'b1xxx0010 : ALUControl = 4'b0110;  //R-type:substract
            8'b1xxx0100 : ALUControl = 4'b0000;  //R-tyep:AND
            8'b1xxx0101 : ALUControl = 4'b0001;  //R-type:OR
            8'b1xxx1010 : ALUControl = 4'b0111; //R-type:set on less than
            default:     ALUControl = 4'b0000;
        endcase
	end
endmodule

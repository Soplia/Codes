`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:35:16 12/07/2011 
// Design Name: 
// Module Name:    Top 
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

module Top(
    input ClkIn,
    input Rst,
	 input [7:0] switch,
	 output [7:0] led
    );

wire Clk;
wire RegDst;
wire ALUSrc;
wire MemToReg;
wire RegWrite;
wire MemRead;
wire MemWrite;
wire Branch;
wire Jump;

wire [5:0] Funct;
wire [3:0] ALUCtr;
wire Zero;

wire [4:0] RegARdAddr;
wire [4:0] RegBRdAddr;
wire [4:0] RegWrAddr;
wire [31:0] RegWrData;
wire [31:0] RegARdData;
wire [31:0] RegBRdData;

wire [31:0] DmemRdData;

wire [31:0] Instruction;
wire [31:0] SrcB;
wire [31:0] InstSignExt;
wire [31:0] ALURes;
reg [31:0] PC;
wire [31:0] PCPlus4;
wire [31:0] PCRes;
wire [31:0] PCJump;
wire [31:0] PCBranch;

	Clk_gen	Clock(
		.CLK_IN1(ClkIn),
		.RESET(Rst),
		.CLK_OUT1(Clk), 
      .LOCKED()	
	);
	
	assign Funct = Instruction[5:0];
	
	ALU ALU (
		.SrcA(RegARdData), 
		.SrcB(SrcB), 
		.ALUCtr(ALUCtr), 
		.Zero(Zero), 
		.ALURes(ALURes)
	);
	
	assign SrcB = (ALUSrc == 1'b1)? InstSignExt : RegBRdData;

	register register (
		.Clk(Clk), 
		.RegARdAddr(RegARdAddr), 
		.RegBRdAddr(RegBRdAddr), 
		.RegWrAddr(RegWrAddr), 
		.RegWrData(RegWrData), 
		.RegWrite(RegWrite), 
		.RegARdData(RegARdData), 
		.RegBRdData(RegBRdData)
	);
	
    assign RegWrAddr = (RegDst==1'b1)?Instruction[15:11]:Instruction[20:16];
    assign RegARdAddr = Instruction[25:21];
    assign RegBRdAddr = Instruction[20:16];
	
	Ctr Ctr (
		.OpCode(Instruction[31:26]),
		.Funct(Instruction[5:0]),
		.RegDst(RegDst), 
		.ALUSrc(ALUSrc), 
		.MemToReg(MemToReg), 
		.RegWrite(RegWrite), 
		.MemWrite(MemWrite), 
		.Branch(Branch), 
		.ALUControl(ALUCtr),
		.Jump(Jump)
	);

	Data_memory DMemory(
    .Clk(Clk),
    .DmemAddr(ALURes>>2),
    .DmemRdData(DmemRdData),
    .DmemWrite(MemWrite),
    .DmemWrData(RegBRdData)
	);


	assign RegWrData = (MemToReg==1'b1)?DmemRdData:ALURes;

	Instruction_memory IMemory(
	.ImemRdAddr({2'b00,PC[31:2]}),
	.Instruction(Instruction)
	);

    signext SignExtern (
    .Inst(Instruction[15:0]), 
    .Data(InstSignExt)
    );
	
	assign PCPlus4 = PC + 4;
	assign PCBranch = {InstSignExt[29:0],2'b0} + PCPlus4;
	assign PCRes = (Branch & Zero == 1'b1)? PCBranch: PCPlus4;
	assign PCJump = {PCPlus4[31:28],Instruction[25:0],2'b0};
	
	always @ (negedge Clk or posedge Rst)
	begin
	if(Rst == 1'b1)
		PC = 32'h0;
	else if(Jump == 1'b1)
		PC = PCJump;
	else
		PC = PCRes;
	end
	
	assign Led = PC[9:2];
	
endmodule

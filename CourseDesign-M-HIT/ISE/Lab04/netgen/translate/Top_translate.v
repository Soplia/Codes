////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: Top_translate.v
// /___/   /\     Timestamp: Thu Apr 19 13:32:30 2018
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/translate -ofmt verilog -sim Top.ngd Top_translate.v 
// Device	: 6slx16csg324-3
// Input file	: Top.ngd
// Output file	: F:\ISE\Lab04\netgen\translate\Top_translate.v
// # of Modules	: 8
// Design Name	: Top
// Xilinx        : d:\Xilinx\14.7\ISE_DS\ISE\
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module signext (
Inst, Data
);
  input [15 : 0] Inst;
  output [31 : 0] Data;
  wire [15 : 0] NlwRenamedSignal_Data;
  assign
    NlwRenamedSignal_Data[15] = Inst[15],
    NlwRenamedSignal_Data[14] = Inst[14],
    NlwRenamedSignal_Data[13] = Inst[13],
    NlwRenamedSignal_Data[12] = Inst[12],
    NlwRenamedSignal_Data[11] = Inst[11],
    NlwRenamedSignal_Data[10] = Inst[10],
    NlwRenamedSignal_Data[9] = Inst[9],
    NlwRenamedSignal_Data[8] = Inst[8],
    NlwRenamedSignal_Data[7] = Inst[7],
    NlwRenamedSignal_Data[6] = Inst[6],
    NlwRenamedSignal_Data[5] = Inst[5],
    NlwRenamedSignal_Data[4] = Inst[4],
    NlwRenamedSignal_Data[3] = Inst[3],
    NlwRenamedSignal_Data[2] = Inst[2],
    NlwRenamedSignal_Data[1] = Inst[1],
    NlwRenamedSignal_Data[0] = Inst[0],
    Data[31] = NlwRenamedSignal_Data[15],
    Data[30] = NlwRenamedSignal_Data[15],
    Data[29] = NlwRenamedSignal_Data[15],
    Data[28] = NlwRenamedSignal_Data[15],
    Data[27] = NlwRenamedSignal_Data[15],
    Data[26] = NlwRenamedSignal_Data[15],
    Data[25] = NlwRenamedSignal_Data[15],
    Data[24] = NlwRenamedSignal_Data[15],
    Data[23] = NlwRenamedSignal_Data[15],
    Data[22] = NlwRenamedSignal_Data[15],
    Data[21] = NlwRenamedSignal_Data[15],
    Data[20] = NlwRenamedSignal_Data[15],
    Data[19] = NlwRenamedSignal_Data[15],
    Data[18] = NlwRenamedSignal_Data[15],
    Data[17] = NlwRenamedSignal_Data[15],
    Data[16] = NlwRenamedSignal_Data[15],
    Data[15] = NlwRenamedSignal_Data[15],
    Data[14] = NlwRenamedSignal_Data[14],
    Data[13] = NlwRenamedSignal_Data[13],
    Data[12] = NlwRenamedSignal_Data[12],
    Data[11] = NlwRenamedSignal_Data[11],
    Data[10] = NlwRenamedSignal_Data[10],
    Data[9] = NlwRenamedSignal_Data[9],
    Data[8] = NlwRenamedSignal_Data[8],
    Data[7] = NlwRenamedSignal_Data[7],
    Data[6] = NlwRenamedSignal_Data[6],
    Data[5] = NlwRenamedSignal_Data[5],
    Data[4] = NlwRenamedSignal_Data[4],
    Data[3] = NlwRenamedSignal_Data[3],
    Data[2] = NlwRenamedSignal_Data[2],
    Data[1] = NlwRenamedSignal_Data[1],
    Data[0] = NlwRenamedSignal_Data[0];
endmodule

module Ctr_Ctr (
  RegDst, ALUSrc, MemToReg, RegWrite, MemWrite, MemRead, Branch, Jump, OpCode, Funct, ALUControl
);
  output RegDst;
  output ALUSrc;
  output MemToReg;
  output RegWrite;
  output MemWrite;
  output MemRead;
  output Branch;
  output Jump;
  input [5 : 0] OpCode;
  input [5 : 0] Funct;
  output [3 : 0] ALUControl;
  wire NlwRenamedSignal_MemRead;
  wire NlwRenamedSignal_MemToReg;
  wire NlwRenamedSig_OI_RegDst;
  wire N01;
  assign
    ALUControl[3] = NlwRenamedSignal_MemRead,
    RegDst = NlwRenamedSig_OI_RegDst,
    ALUSrc = NlwRenamedSignal_MemToReg,
    MemToReg = NlwRenamedSignal_MemToReg,
    MemWrite = NlwRenamedSignal_MemRead,
    MemRead = NlwRenamedSignal_MemRead;
  X_ZERO   XST_GND (
    .O(NlwRenamedSignal_MemRead)
  );
  X_LUT4 #(
    .INIT ( 16'h4000 ))
  \MemToReg<5>11  (
    .ADR0(OpCode[2]),
    .ADR1(OpCode[1]),
    .ADR2(OpCode[5]),
    .ADR3(OpCode[0]),
    .O(NlwRenamedSignal_MemToReg)
  );
  X_LUT5 #(
    .INIT ( 32'h1011FFFF ))
  \ALUControl<3>1  (
    .ADR0(Funct[2]),
    .ADR1(Funct[0]),
    .ADR2(Funct[1]),
    .ADR3(Funct[3]),
    .ADR4(NlwRenamedSig_OI_RegDst),
    .O(ALUControl[1])
  );
  X_LUT5 #(
    .INIT ( 32'h02400000 ))
  \ALUControl<4>1  (
    .ADR0(Funct[3]),
    .ADR1(Funct[2]),
    .ADR2(Funct[0]),
    .ADR3(Funct[1]),
    .ADR4(NlwRenamedSig_OI_RegDst),
    .O(ALUControl[0])
  );
  X_LUT4 #(
    .INIT ( 16'h0002 ))
  \Jump<5>1  (
    .ADR0(OpCode[1]),
    .ADR1(OpCode[2]),
    .ADR2(OpCode[5]),
    .ADR3(OpCode[0]),
    .O(Jump)
  );
  X_LUT4 #(
    .INIT ( 16'h0001 ))
  \RegDst<5>1  (
    .ADR0(OpCode[1]),
    .ADR1(OpCode[2]),
    .ADR2(OpCode[5]),
    .ADR3(OpCode[0]),
    .O(NlwRenamedSig_OI_RegDst)
  );
  X_LUT4 #(
    .INIT ( 16'h0002 ))
  \ALUControl<2>11  (
    .ADR0(OpCode[2]),
    .ADR1(OpCode[1]),
    .ADR2(OpCode[5]),
    .ADR3(OpCode[0]),
    .O(Branch)
  );
  X_LUT2 #(
    .INIT ( 4'hE ))
  \ALUControl<2>_SW0  (
    .ADR0(Funct[0]),
    .ADR1(Funct[2]),
    .O(N01)
  );
  X_LUT6 #(
    .INIT ( 64'h0100010001010100 ))
  \ALUControl<2>  (
    .ADR0(OpCode[5]),
    .ADR1(OpCode[1]),
    .ADR2(OpCode[0]),
    .ADR3(OpCode[2]),
    .ADR4(Funct[1]),
    .ADR5(N01),
    .O(ALUControl[2])
  );
  X_LUT4 #(
    .INIT ( 16'h4001 ))
  RegWrite1 (
    .ADR0(OpCode[2]),
    .ADR1(OpCode[1]),
    .ADR2(OpCode[5]),
    .ADR3(OpCode[0]),
    .O(RegWrite)
  );
endmodule

module Instruction_memory (
ImemRdAddr, Instruction
);
  input [31 : 0] ImemRdAddr;
  output [31 : 0] Instruction;
  wire \NlwRenamedSignal_Instruction[26] ;
  wire N36;
  wire N34;
  wire N32;
  wire N301;
  wire N281;
  wire N261;
  wire N241;
  wire N221;
  wire N201;
  wire N181;
  wire N161;
  wire N141;
  wire N12;
  wire N10;
  wire N8;
  wire N6;
  wire N41;
  wire N22;
  wire N0;
  wire \NlwRenamedSignal_Instruction[4] ;
  assign
    Instruction[31] = \NlwRenamedSignal_Instruction[26] ,
    Instruction[30] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[29] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[27] = \NlwRenamedSignal_Instruction[26] ,
    Instruction[26] = \NlwRenamedSignal_Instruction[26] ,
    Instruction[25] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[20] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[15] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[10] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[9] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[8] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[7] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[6] = \NlwRenamedSignal_Instruction[4] ,
    Instruction[4] = \NlwRenamedSignal_Instruction[4] ;
  X_LUT6 #(
    .INIT ( 64'h0000000000000002 ))
  Mram_InstMem4811 (
    .ADR0(ImemRdAddr[3]),
    .ADR1(ImemRdAddr[7]),
    .ADR2(ImemRdAddr[6]),
    .ADR3(ImemRdAddr[5]),
    .ADR4(ImemRdAddr[4]),
    .ADR5(N36),
    .O(Instruction[28])
  );
  X_LUT3 #(
    .INIT ( 8'hBF ))
  Mram_InstMem4811_SW0 (
    .ADR0(ImemRdAddr[2]),
    .ADR1(ImemRdAddr[1]),
    .ADR2(ImemRdAddr[0]),
    .O(N36)
  );
  X_LUT4 #(
    .INIT ( 16'h0001 ))
  N28 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(N34),
    .O(\NlwRenamedSignal_Instruction[26] )
  );
  X_LUT5 #(
    .INIT ( 32'h91141044 ))
  N28_SW0 (
    .ADR0(ImemRdAddr[4]),
    .ADR1(ImemRdAddr[2]),
    .ADR2(ImemRdAddr[3]),
    .ADR3(ImemRdAddr[1]),
    .ADR4(ImemRdAddr[0]),
    .O(N34)
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000002 ))
  Mram_InstMem4111 (
    .ADR0(ImemRdAddr[3]),
    .ADR1(ImemRdAddr[7]),
    .ADR2(ImemRdAddr[6]),
    .ADR3(ImemRdAddr[5]),
    .ADR4(ImemRdAddr[4]),
    .ADR5(N32),
    .O(Instruction[24])
  );
  X_LUT3 #(
    .INIT ( 8'hFB ))
  Mram_InstMem4111_SW0 (
    .ADR0(ImemRdAddr[1]),
    .ADR1(ImemRdAddr[2]),
    .ADR2(ImemRdAddr[0]),
    .O(N32)
  );
  X_LUT5 #(
    .INIT ( 32'h00000001 ))
  Mram_InstMem3911 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(ImemRdAddr[4]),
    .ADR4(N301),
    .O(Instruction[23])
  );
  X_LUT4 #(
    .INIT ( 16'hFDDB ))
  Mram_InstMem3911_SW0 (
    .ADR0(ImemRdAddr[3]),
    .ADR1(ImemRdAddr[2]),
    .ADR2(ImemRdAddr[1]),
    .ADR3(ImemRdAddr[0]),
    .O(N301)
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000001 ))
  Mram_InstMem3711 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(ImemRdAddr[4]),
    .ADR4(ImemRdAddr[3]),
    .ADR5(N281),
    .O(Instruction[22])
  );
  X_LUT3 #(
    .INIT ( 8'hD7 ))
  Mram_InstMem3711_SW0 (
    .ADR0(ImemRdAddr[0]),
    .ADR1(ImemRdAddr[1]),
    .ADR2(ImemRdAddr[2]),
    .O(N281)
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000001 ))
  Mram_InstMem3511 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(ImemRdAddr[4]),
    .ADR4(ImemRdAddr[3]),
    .ADR5(N261),
    .O(Instruction[21])
  );
  X_LUT3 #(
    .INIT ( 8'hBF ))
  Mram_InstMem3511_SW0 (
    .ADR0(ImemRdAddr[1]),
    .ADR1(ImemRdAddr[2]),
    .ADR2(ImemRdAddr[0]),
    .O(N261)
  );
  X_LUT4 #(
    .INIT ( 16'h0001 ))
  Mram_InstMem3011 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(N241),
    .O(Instruction[18])
  );
  X_LUT5 #(
    .INIT ( 32'hD7565777 ))
  Mram_InstMem3011_SW0 (
    .ADR0(ImemRdAddr[4]),
    .ADR1(ImemRdAddr[3]),
    .ADR2(ImemRdAddr[2]),
    .ADR3(ImemRdAddr[0]),
    .ADR4(ImemRdAddr[1]),
    .O(N241)
  );
  X_LUT4 #(
    .INIT ( 16'h0001 ))
  Mram_InstMem2811 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(N221),
    .O(Instruction[17])
  );
  X_LUT5 #(
    .INIT ( 32'hBAAE8890 ))
  Mram_InstMem2811_SW0 (
    .ADR0(ImemRdAddr[4]),
    .ADR1(ImemRdAddr[2]),
    .ADR2(ImemRdAddr[1]),
    .ADR3(ImemRdAddr[0]),
    .ADR4(ImemRdAddr[3]),
    .O(N221)
  );
  X_LUT4 #(
    .INIT ( 16'h0001 ))
  Mram_InstMem3211 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(N201),
    .O(Instruction[19])
  );
  X_LUT5 #(
    .INIT ( 32'h91101155 ))
  Mram_InstMem3211_SW0 (
    .ADR0(ImemRdAddr[4]),
    .ADR1(ImemRdAddr[2]),
    .ADR2(ImemRdAddr[0]),
    .ADR3(ImemRdAddr[1]),
    .ADR4(ImemRdAddr[3]),
    .O(N201)
  );
  X_LUT4 #(
    .INIT ( 16'h0001 ))
  Mram_InstMem2611 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(N181),
    .O(Instruction[16])
  );
  X_LUT5 #(
    .INIT ( 32'hBBBA8C95 ))
  Mram_InstMem2611_SW0 (
    .ADR0(ImemRdAddr[4]),
    .ADR1(ImemRdAddr[2]),
    .ADR2(ImemRdAddr[1]),
    .ADR3(ImemRdAddr[0]),
    .ADR4(ImemRdAddr[3]),
    .O(N181)
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000002 ))
  Mram_InstMem2311 (
    .ADR0(ImemRdAddr[3]),
    .ADR1(ImemRdAddr[7]),
    .ADR2(ImemRdAddr[6]),
    .ADR3(ImemRdAddr[5]),
    .ADR4(ImemRdAddr[4]),
    .ADR5(N161),
    .O(Instruction[14])
  );
  X_LUT3 #(
    .INIT ( 8'hE9 ))
  Mram_InstMem2311_SW0 (
    .ADR0(ImemRdAddr[2]),
    .ADR1(ImemRdAddr[1]),
    .ADR2(ImemRdAddr[0]),
    .O(N161)
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000002 ))
  Mram_InstMem1911 (
    .ADR0(ImemRdAddr[2]),
    .ADR1(ImemRdAddr[7]),
    .ADR2(ImemRdAddr[6]),
    .ADR3(ImemRdAddr[5]),
    .ADR4(ImemRdAddr[4]),
    .ADR5(N141),
    .O(Instruction[12])
  );
  X_LUT3 #(
    .INIT ( 8'hF8 ))
  Mram_InstMem1911_SW0 (
    .ADR0(ImemRdAddr[3]),
    .ADR1(ImemRdAddr[0]),
    .ADR2(ImemRdAddr[1]),
    .O(N141)
  );
  X_LUT5 #(
    .INIT ( 32'h00000001 ))
  Mram_InstMem1711 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(ImemRdAddr[4]),
    .ADR4(N12),
    .O(Instruction[11])
  );
  X_LUT4 #(
    .INIT ( 16'hF9BF ))
  Mram_InstMem1711_SW0 (
    .ADR0(ImemRdAddr[2]),
    .ADR1(ImemRdAddr[1]),
    .ADR2(ImemRdAddr[3]),
    .ADR3(ImemRdAddr[0]),
    .O(N12)
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000001 ))
  Mram_InstMem2111 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(ImemRdAddr[4]),
    .ADR4(ImemRdAddr[3]),
    .ADR5(N10),
    .O(Instruction[13])
  );
  X_LUT3 #(
    .INIT ( 8'h9D ))
  Mram_InstMem2111_SW0 (
    .ADR0(ImemRdAddr[2]),
    .ADR1(ImemRdAddr[1]),
    .ADR2(ImemRdAddr[0]),
    .O(N10)
  );
  X_LUT5 #(
    .INIT ( 32'h00000001 ))
  Mram_InstMem1011 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(ImemRdAddr[4]),
    .ADR4(N8),
    .O(Instruction[5])
  );
  X_LUT4 #(
    .INIT ( 16'hE9B5 ))
  Mram_InstMem1011_SW0 (
    .ADR0(ImemRdAddr[2]),
    .ADR1(ImemRdAddr[3]),
    .ADR2(ImemRdAddr[1]),
    .ADR3(ImemRdAddr[0]),
    .O(N8)
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000001 ))
  Mram_InstMem711 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(ImemRdAddr[4]),
    .ADR4(ImemRdAddr[2]),
    .ADR5(N6),
    .O(Instruction[3])
  );
  X_LUT3 #(
    .INIT ( 8'h4F ))
  Mram_InstMem711_SW0 (
    .ADR0(ImemRdAddr[3]),
    .ADR1(ImemRdAddr[0]),
    .ADR2(ImemRdAddr[1]),
    .O(N6)
  );
  X_LUT5 #(
    .INIT ( 32'h00000001 ))
  Mram_InstMem3111 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(ImemRdAddr[4]),
    .ADR4(N41),
    .O(Instruction[1])
  );
  X_LUT4 #(
    .INIT ( 16'hDFDB ))
  Mram_InstMem3111_SW0 (
    .ADR0(ImemRdAddr[3]),
    .ADR1(ImemRdAddr[2]),
    .ADR2(ImemRdAddr[1]),
    .ADR3(ImemRdAddr[0]),
    .O(N41)
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000002 ))
  Mram_InstMem121 (
    .ADR0(ImemRdAddr[3]),
    .ADR1(ImemRdAddr[7]),
    .ADR2(ImemRdAddr[6]),
    .ADR3(ImemRdAddr[5]),
    .ADR4(ImemRdAddr[4]),
    .ADR5(N22),
    .O(Instruction[0])
  );
  X_LUT3 #(
    .INIT ( 8'hFB ))
  Mram_InstMem121_SW0 (
    .ADR0(ImemRdAddr[1]),
    .ADR1(ImemRdAddr[0]),
    .ADR2(ImemRdAddr[2]),
    .O(N22)
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000001 ))
  Mram_InstMem5111 (
    .ADR0(ImemRdAddr[7]),
    .ADR1(ImemRdAddr[6]),
    .ADR2(ImemRdAddr[5]),
    .ADR3(ImemRdAddr[4]),
    .ADR4(ImemRdAddr[1]),
    .ADR5(N0),
    .O(Instruction[2])
  );
  X_LUT3 #(
    .INIT ( 8'hD5 ))
  Mram_InstMem5111_SW0 (
    .ADR0(ImemRdAddr[0]),
    .ADR1(ImemRdAddr[2]),
    .ADR2(ImemRdAddr[3]),
    .O(N0)
  );
  X_ZERO   XST_GND1 (
    .O(\NlwRenamedSignal_Instruction[4] )
  );
endmodule

module ALU_ALU (
  Zero, SrcA, SrcB, ALUCtr, ALURes
);
  output Zero;
  input [31 : 0] SrcA;
  input [31 : 0] SrcB;
  input [3 : 0] ALUCtr;
  output [31 : 0] ALURes;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<31> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<30> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<29> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<28> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<27> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<26> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<25> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<24> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<23> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<22> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<21> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<20> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<19> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<18> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<17> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<16> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<15> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<14> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<13> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<12> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<11> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<10> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<9> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<8> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<7> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<6> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<5> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<4> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<3> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<2> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<1> ;
  wire \SrcA[31]_SrcB[31]_sub_5_OUT<0> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<31> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<30> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<29> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<28> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<27> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<26> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<25> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<24> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<23> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<22> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<21> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<20> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<19> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<18> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<17> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<16> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<15> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<14> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<13> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<12> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<11> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<10> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<9> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<8> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<7> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<6> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<5> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<4> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<3> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<2> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<1> ;
  wire \SrcA[31]_SrcB[31]_add_3_OUT<0> ;
  wire N0;
  wire N1;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi_488 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<0>_489 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<0>_490 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi1_491 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<1>_492 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<1>_493 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi2_494 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<2>_495 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<2>_496 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi3_497 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<3>_498 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<3>_499 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi4_500 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<4>_501 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<4>_502 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi5_503 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<5>_504 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<5>_505 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi6_506 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<6>_507 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<6>_508 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi7_509 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<7>_510 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<7>_511 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi8_512 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<8>_513 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<8>_514 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi9_515 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<9>_516 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<9>_517 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi10_518 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<10>_519 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<10>_520 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi11_521 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<11>_522 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<11>_523 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi12_524 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<12>_525 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<12>_526 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi13_527 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<13>_528 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<13>_529 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi14_530 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<14>_531 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<14>_532 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi15_533 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<15>_534 ;
  wire \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<15>_535 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<0>_536 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<0>_537 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<1>_538 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<1>_539 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<2>_540 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<2>_541 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<3>_542 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<3>_543 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<4>_544 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<4>_545 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<5>_546 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<5>_547 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<6>_548 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<6>_549 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<7>_550 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<7>_551 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<8>_552 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<8>_553 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<9>_554 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<9>_555 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<10>_556 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<10>_557 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<11>_558 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<11>_559 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<12>_560 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<12>_561 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<13>_562 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<13>_563 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<14>_564 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<14>_565 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<15>_566 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<15>_567 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<16>_568 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<16>_569 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<17>_570 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<17>_571 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<18>_572 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<18>_573 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<19>_574 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<19>_575 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<20>_576 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<20>_577 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<21>_578 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<21>_579 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<22>_580 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<22>_581 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<23>_582 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<23>_583 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<24>_584 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<24>_585 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<25>_586 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<25>_587 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<26>_588 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<26>_589 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<27>_590 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<27>_591 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<28>_592 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<28>_593 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<29>_594 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<29>_595 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<30>_596 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<30>_597 ;
  wire \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<31>_598 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<0>_599 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<0>_600 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<1>_601 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<1>_602 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<2>_603 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<2>_604 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<3>_605 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<3>_606 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<4>_607 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<4>_608 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<5>_609 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<5>_610 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<6>_611 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<6>_612 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<7>_613 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<7>_614 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<8>_615 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<8>_616 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<9>_617 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<9>_618 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<10>_619 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<10>_620 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<11>_621 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<11>_622 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<12>_623 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<12>_624 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<13>_625 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<13>_626 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<14>_627 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<14>_628 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<15>_629 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<15>_630 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<16>_631 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<16>_632 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<17>_633 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<17>_634 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<18>_635 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<18>_636 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<19>_637 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<19>_638 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<20>_639 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<20>_640 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<21>_641 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<21>_642 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<22>_643 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<22>_644 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<23>_645 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<23>_646 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<24>_647 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<24>_648 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<25>_649 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<25>_650 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<26>_651 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<26>_652 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<27>_653 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<27>_654 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<28>_655 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<28>_656 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<29>_657 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<29>_658 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<30>_659 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<30>_660 ;
  wire \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<31>_661 ;
  wire \Zero<31>2 ;
  wire \Zero<31>3_664 ;
  wire \Zero<31>4_665 ;
  wire \Zero<31>5_666 ;
  wire N01;
  wire N2;
  wire N4;
  wire N6;
  wire N8;
  wire N10;
  wire N12;
  wire N14;
  wire N16;
  wire N18;
  wire N20;
  wire N22;
  wire N24;
  wire N26;
  wire N28;
  wire N30;
  wire N32;
  wire N34;
  wire N36;
  wire N38;
  wire N40;
  wire N42;
  wire N44;
  wire N46;
  wire N48;
  wire N50;
  wire N52;
  wire N54;
  wire N56;
  wire N58;
  wire N60;
  wire N62;
  wire [31 : 0] NlwRenamedSig_OI_ALURes;
  wire [31 : 31] Zero_0;
  wire [0 : 0] _n0109;
  assign
    ALURes[31] = NlwRenamedSig_OI_ALURes[31],
    ALURes[30] = NlwRenamedSig_OI_ALURes[30],
    ALURes[29] = NlwRenamedSig_OI_ALURes[29],
    ALURes[28] = NlwRenamedSig_OI_ALURes[28],
    ALURes[27] = NlwRenamedSig_OI_ALURes[27],
    ALURes[26] = NlwRenamedSig_OI_ALURes[26],
    ALURes[25] = NlwRenamedSig_OI_ALURes[25],
    ALURes[24] = NlwRenamedSig_OI_ALURes[24],
    ALURes[23] = NlwRenamedSig_OI_ALURes[23],
    ALURes[22] = NlwRenamedSig_OI_ALURes[22],
    ALURes[21] = NlwRenamedSig_OI_ALURes[21],
    ALURes[20] = NlwRenamedSig_OI_ALURes[20],
    ALURes[19] = NlwRenamedSig_OI_ALURes[19],
    ALURes[18] = NlwRenamedSig_OI_ALURes[18],
    ALURes[17] = NlwRenamedSig_OI_ALURes[17],
    ALURes[16] = NlwRenamedSig_OI_ALURes[16],
    ALURes[15] = NlwRenamedSig_OI_ALURes[15],
    ALURes[14] = NlwRenamedSig_OI_ALURes[14],
    ALURes[13] = NlwRenamedSig_OI_ALURes[13],
    ALURes[12] = NlwRenamedSig_OI_ALURes[12],
    ALURes[11] = NlwRenamedSig_OI_ALURes[11],
    ALURes[10] = NlwRenamedSig_OI_ALURes[10],
    ALURes[9] = NlwRenamedSig_OI_ALURes[9],
    ALURes[8] = NlwRenamedSig_OI_ALURes[8],
    ALURes[7] = NlwRenamedSig_OI_ALURes[7],
    ALURes[6] = NlwRenamedSig_OI_ALURes[6],
    ALURes[5] = NlwRenamedSig_OI_ALURes[5],
    ALURes[4] = NlwRenamedSig_OI_ALURes[4],
    ALURes[3] = NlwRenamedSig_OI_ALURes[3],
    ALURes[2] = NlwRenamedSig_OI_ALURes[2],
    ALURes[1] = NlwRenamedSig_OI_ALURes[1],
    ALURes[0] = NlwRenamedSig_OI_ALURes[0];
  X_ONE   XST_VCC (
    .O(N0)
  );
  X_ZERO   XST_GND (
    .O(N1)
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi  (
    .ADR0(SrcA[1]),
    .ADR1(SrcA[0]),
    .ADR2(SrcB[0]),
    .ADR3(SrcB[1]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi_488 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<0>  (
    .ADR0(SrcB[0]),
    .ADR1(SrcA[0]),
    .ADR2(SrcB[1]),
    .ADR3(SrcA[1]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<0>_489 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<0>  (
    .IB(N0),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi_488 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<0>_489 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<0>_490 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi1  (
    .ADR0(SrcA[3]),
    .ADR1(SrcA[2]),
    .ADR2(SrcB[2]),
    .ADR3(SrcB[3]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi1_491 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<1>  (
    .ADR0(SrcB[2]),
    .ADR1(SrcA[2]),
    .ADR2(SrcB[3]),
    .ADR3(SrcA[3]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<1>_492 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<1>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<0>_490 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi1_491 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<1>_492 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<1>_493 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi2  (
    .ADR0(SrcA[5]),
    .ADR1(SrcA[4]),
    .ADR2(SrcB[4]),
    .ADR3(SrcB[5]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi2_494 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<2>  (
    .ADR0(SrcB[4]),
    .ADR1(SrcA[4]),
    .ADR2(SrcB[5]),
    .ADR3(SrcA[5]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<2>_495 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<2>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<1>_493 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi2_494 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<2>_495 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<2>_496 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi3  (
    .ADR0(SrcA[7]),
    .ADR1(SrcA[6]),
    .ADR2(SrcB[6]),
    .ADR3(SrcB[7]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi3_497 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<3>  (
    .ADR0(SrcB[6]),
    .ADR1(SrcA[6]),
    .ADR2(SrcB[7]),
    .ADR3(SrcA[7]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<3>_498 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<3>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<2>_496 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi3_497 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<3>_498 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<3>_499 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi4  (
    .ADR0(SrcA[9]),
    .ADR1(SrcA[8]),
    .ADR2(SrcB[8]),
    .ADR3(SrcB[9]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi4_500 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<4>  (
    .ADR0(SrcB[8]),
    .ADR1(SrcA[8]),
    .ADR2(SrcB[9]),
    .ADR3(SrcA[9]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<4>_501 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<4>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<3>_499 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi4_500 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<4>_501 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<4>_502 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi5  (
    .ADR0(SrcA[11]),
    .ADR1(SrcA[10]),
    .ADR2(SrcB[10]),
    .ADR3(SrcB[11]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi5_503 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<5>  (
    .ADR0(SrcB[10]),
    .ADR1(SrcA[10]),
    .ADR2(SrcB[11]),
    .ADR3(SrcA[11]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<5>_504 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<5>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<4>_502 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi5_503 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<5>_504 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<5>_505 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi6  (
    .ADR0(SrcA[13]),
    .ADR1(SrcA[12]),
    .ADR2(SrcB[12]),
    .ADR3(SrcB[13]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi6_506 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<6>  (
    .ADR0(SrcB[12]),
    .ADR1(SrcA[12]),
    .ADR2(SrcB[13]),
    .ADR3(SrcA[13]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<6>_507 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<6>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<5>_505 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi6_506 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<6>_507 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<6>_508 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi7  (
    .ADR0(SrcA[15]),
    .ADR1(SrcA[14]),
    .ADR2(SrcB[14]),
    .ADR3(SrcB[15]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi7_509 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<7>  (
    .ADR0(SrcB[14]),
    .ADR1(SrcA[14]),
    .ADR2(SrcB[15]),
    .ADR3(SrcA[15]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<7>_510 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<7>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<6>_508 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi7_509 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<7>_510 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<7>_511 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi8  (
    .ADR0(SrcA[17]),
    .ADR1(SrcA[16]),
    .ADR2(SrcB[16]),
    .ADR3(SrcB[17]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi8_512 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<8>  (
    .ADR0(SrcB[16]),
    .ADR1(SrcA[16]),
    .ADR2(SrcB[17]),
    .ADR3(SrcA[17]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<8>_513 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<8>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<7>_511 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi8_512 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<8>_513 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<8>_514 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi9  (
    .ADR0(SrcA[19]),
    .ADR1(SrcA[18]),
    .ADR2(SrcB[18]),
    .ADR3(SrcB[19]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi9_515 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<9>  (
    .ADR0(SrcB[18]),
    .ADR1(SrcA[18]),
    .ADR2(SrcB[19]),
    .ADR3(SrcA[19]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<9>_516 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<9>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<8>_514 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi9_515 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<9>_516 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<9>_517 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi10  (
    .ADR0(SrcA[21]),
    .ADR1(SrcA[20]),
    .ADR2(SrcB[20]),
    .ADR3(SrcB[21]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi10_518 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<10>  (
    .ADR0(SrcB[20]),
    .ADR1(SrcA[20]),
    .ADR2(SrcB[21]),
    .ADR3(SrcA[21]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<10>_519 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<10>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<9>_517 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi10_518 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<10>_519 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<10>_520 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi11  (
    .ADR0(SrcA[23]),
    .ADR1(SrcA[22]),
    .ADR2(SrcB[22]),
    .ADR3(SrcB[23]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi11_521 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<11>  (
    .ADR0(SrcB[22]),
    .ADR1(SrcA[22]),
    .ADR2(SrcB[23]),
    .ADR3(SrcA[23]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<11>_522 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<11>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<10>_520 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi11_521 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<11>_522 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<11>_523 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi12  (
    .ADR0(SrcA[25]),
    .ADR1(SrcA[24]),
    .ADR2(SrcB[24]),
    .ADR3(SrcB[25]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi12_524 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<12>  (
    .ADR0(SrcB[24]),
    .ADR1(SrcA[24]),
    .ADR2(SrcB[25]),
    .ADR3(SrcA[25]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<12>_525 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<12>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<11>_523 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi12_524 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<12>_525 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<12>_526 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi13  (
    .ADR0(SrcA[27]),
    .ADR1(SrcA[26]),
    .ADR2(SrcB[26]),
    .ADR3(SrcB[27]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi13_527 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<13>  (
    .ADR0(SrcB[26]),
    .ADR1(SrcA[26]),
    .ADR2(SrcB[27]),
    .ADR3(SrcA[27]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<13>_528 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<13>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<12>_526 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi13_527 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<13>_528 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<13>_529 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi14  (
    .ADR0(SrcA[29]),
    .ADR1(SrcA[28]),
    .ADR2(SrcB[28]),
    .ADR3(SrcB[29]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi14_530 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<14>  (
    .ADR0(SrcB[28]),
    .ADR1(SrcA[28]),
    .ADR2(SrcB[29]),
    .ADR3(SrcA[29]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<14>_531 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<14>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<13>_529 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi14_530 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<14>_531 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<14>_532 )
  );
  X_LUT4 #(
    .INIT ( 16'h08AE ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi15  (
    .ADR0(SrcA[31]),
    .ADR1(SrcA[30]),
    .ADR2(SrcB[30]),
    .ADR3(SrcB[31]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi15_533 )
  );
  X_LUT4 #(
    .INIT ( 16'h9009 ))
  \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<15>  (
    .ADR0(SrcB[30]),
    .ADR1(SrcA[30]),
    .ADR2(SrcB[31]),
    .ADR3(SrcA[31]),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<15>_534 )
  );
  X_MUX2   \Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<15>  (
    .IB(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<14>_532 ),
    .IA(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lutdi15_533 ),
    .SEL(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_lut<15>_534 ),
    .O(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<15>_535 )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<0>  (
    .ADR0(SrcA[0]),
    .ADR1(SrcB[0]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<0>_536 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<0>  (
    .IB(N0),
    .IA(SrcA[0]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<0>_536 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<0>_537 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<0>  (
    .I0(N0),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<0>_536 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<0> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<1>  (
    .ADR0(SrcA[1]),
    .ADR1(SrcB[1]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<1>_538 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<1>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<0>_537 ),
    .IA(SrcA[1]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<1>_538 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<1>_539 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<1>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<0>_537 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<1>_538 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<1> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<2>  (
    .ADR0(SrcA[2]),
    .ADR1(SrcB[2]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<2>_540 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<2>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<1>_539 ),
    .IA(SrcA[2]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<2>_540 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<2>_541 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<2>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<1>_539 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<2>_540 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<2> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<3>  (
    .ADR0(SrcA[3]),
    .ADR1(SrcB[3]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<3>_542 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<3>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<2>_541 ),
    .IA(SrcA[3]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<3>_542 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<3>_543 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<3>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<2>_541 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<3>_542 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<3> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<4>  (
    .ADR0(SrcA[4]),
    .ADR1(SrcB[4]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<4>_544 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<4>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<3>_543 ),
    .IA(SrcA[4]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<4>_544 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<4>_545 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<4>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<3>_543 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<4>_544 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<4> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<5>  (
    .ADR0(SrcA[5]),
    .ADR1(SrcB[5]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<5>_546 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<5>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<4>_545 ),
    .IA(SrcA[5]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<5>_546 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<5>_547 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<5>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<4>_545 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<5>_546 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<5> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<6>  (
    .ADR0(SrcA[6]),
    .ADR1(SrcB[6]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<6>_548 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<6>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<5>_547 ),
    .IA(SrcA[6]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<6>_548 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<6>_549 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<6>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<5>_547 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<6>_548 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<6> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<7>  (
    .ADR0(SrcA[7]),
    .ADR1(SrcB[7]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<7>_550 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<7>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<6>_549 ),
    .IA(SrcA[7]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<7>_550 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<7>_551 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<7>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<6>_549 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<7>_550 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<7> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<8>  (
    .ADR0(SrcA[8]),
    .ADR1(SrcB[8]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<8>_552 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<8>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<7>_551 ),
    .IA(SrcA[8]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<8>_552 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<8>_553 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<8>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<7>_551 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<8>_552 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<8> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<9>  (
    .ADR0(SrcA[9]),
    .ADR1(SrcB[9]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<9>_554 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<9>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<8>_553 ),
    .IA(SrcA[9]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<9>_554 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<9>_555 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<9>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<8>_553 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<9>_554 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<9> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<10>  (
    .ADR0(SrcA[10]),
    .ADR1(SrcB[10]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<10>_556 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<10>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<9>_555 ),
    .IA(SrcA[10]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<10>_556 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<10>_557 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<10>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<9>_555 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<10>_556 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<10> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<11>  (
    .ADR0(SrcA[11]),
    .ADR1(SrcB[11]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<11>_558 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<11>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<10>_557 ),
    .IA(SrcA[11]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<11>_558 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<11>_559 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<11>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<10>_557 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<11>_558 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<11> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<12>  (
    .ADR0(SrcA[12]),
    .ADR1(SrcB[12]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<12>_560 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<12>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<11>_559 ),
    .IA(SrcA[12]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<12>_560 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<12>_561 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<12>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<11>_559 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<12>_560 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<12> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<13>  (
    .ADR0(SrcA[13]),
    .ADR1(SrcB[13]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<13>_562 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<13>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<12>_561 ),
    .IA(SrcA[13]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<13>_562 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<13>_563 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<13>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<12>_561 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<13>_562 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<13> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<14>  (
    .ADR0(SrcA[14]),
    .ADR1(SrcB[14]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<14>_564 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<14>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<13>_563 ),
    .IA(SrcA[14]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<14>_564 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<14>_565 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<14>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<13>_563 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<14>_564 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<14> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<15>  (
    .ADR0(SrcA[15]),
    .ADR1(SrcB[15]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<15>_566 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<15>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<14>_565 ),
    .IA(SrcA[15]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<15>_566 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<15>_567 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<15>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<14>_565 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<15>_566 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<15> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<16>  (
    .ADR0(SrcA[16]),
    .ADR1(SrcB[16]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<16>_568 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<16>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<15>_567 ),
    .IA(SrcA[16]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<16>_568 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<16>_569 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<16>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<15>_567 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<16>_568 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<16> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<17>  (
    .ADR0(SrcA[17]),
    .ADR1(SrcB[17]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<17>_570 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<17>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<16>_569 ),
    .IA(SrcA[17]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<17>_570 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<17>_571 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<17>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<16>_569 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<17>_570 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<17> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<18>  (
    .ADR0(SrcA[18]),
    .ADR1(SrcB[18]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<18>_572 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<18>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<17>_571 ),
    .IA(SrcA[18]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<18>_572 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<18>_573 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<18>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<17>_571 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<18>_572 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<18> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<19>  (
    .ADR0(SrcA[19]),
    .ADR1(SrcB[19]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<19>_574 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<19>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<18>_573 ),
    .IA(SrcA[19]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<19>_574 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<19>_575 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<19>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<18>_573 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<19>_574 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<19> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<20>  (
    .ADR0(SrcA[20]),
    .ADR1(SrcB[20]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<20>_576 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<20>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<19>_575 ),
    .IA(SrcA[20]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<20>_576 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<20>_577 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<20>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<19>_575 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<20>_576 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<20> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<21>  (
    .ADR0(SrcA[21]),
    .ADR1(SrcB[21]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<21>_578 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<21>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<20>_577 ),
    .IA(SrcA[21]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<21>_578 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<21>_579 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<21>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<20>_577 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<21>_578 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<21> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<22>  (
    .ADR0(SrcA[22]),
    .ADR1(SrcB[22]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<22>_580 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<22>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<21>_579 ),
    .IA(SrcA[22]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<22>_580 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<22>_581 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<22>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<21>_579 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<22>_580 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<22> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<23>  (
    .ADR0(SrcA[23]),
    .ADR1(SrcB[23]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<23>_582 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<23>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<22>_581 ),
    .IA(SrcA[23]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<23>_582 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<23>_583 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<23>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<22>_581 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<23>_582 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<23> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<24>  (
    .ADR0(SrcA[24]),
    .ADR1(SrcB[24]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<24>_584 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<24>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<23>_583 ),
    .IA(SrcA[24]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<24>_584 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<24>_585 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<24>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<23>_583 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<24>_584 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<24> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<25>  (
    .ADR0(SrcA[25]),
    .ADR1(SrcB[25]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<25>_586 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<25>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<24>_585 ),
    .IA(SrcA[25]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<25>_586 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<25>_587 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<25>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<24>_585 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<25>_586 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<25> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<26>  (
    .ADR0(SrcA[26]),
    .ADR1(SrcB[26]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<26>_588 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<26>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<25>_587 ),
    .IA(SrcA[26]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<26>_588 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<26>_589 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<26>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<25>_587 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<26>_588 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<26> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<27>  (
    .ADR0(SrcA[27]),
    .ADR1(SrcB[27]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<27>_590 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<27>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<26>_589 ),
    .IA(SrcA[27]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<27>_590 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<27>_591 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<27>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<26>_589 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<27>_590 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<27> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<28>  (
    .ADR0(SrcA[28]),
    .ADR1(SrcB[28]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<28>_592 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<28>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<27>_591 ),
    .IA(SrcA[28]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<28>_592 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<28>_593 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<28>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<27>_591 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<28>_592 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<28> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<29>  (
    .ADR0(SrcA[29]),
    .ADR1(SrcB[29]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<29>_594 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<29>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<28>_593 ),
    .IA(SrcA[29]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<29>_594 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<29>_595 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<29>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<28>_593 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<29>_594 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<29> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<30>  (
    .ADR0(SrcA[30]),
    .ADR1(SrcB[30]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<30>_596 )
  );
  X_MUX2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<30>  (
    .IB(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<29>_595 ),
    .IA(SrcA[30]),
    .SEL(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<30>_596 ),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<30>_597 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<30>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<29>_595 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<30>_596 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<30> )
  );
  X_LUT2 #(
    .INIT ( 4'h9 ))
  \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<31>  (
    .ADR0(SrcA[31]),
    .ADR1(SrcB[31]),
    .O(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<31>_598 )
  );
  X_XOR2   \Msub_SrcA[31]_SrcB[31]_sub_5_OUT_xor<31>  (
    .I0(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_cy<30>_597 ),
    .I1(\Msub_SrcA[31]_SrcB[31]_sub_5_OUT_lut<31>_598 ),
    .O(\SrcA[31]_SrcB[31]_sub_5_OUT<31> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<0>  (
    .ADR0(SrcA[0]),
    .ADR1(SrcB[0]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<0>_599 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<0>  (
    .IB(N1),
    .IA(SrcA[0]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<0>_599 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<0>_600 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<0>  (
    .I0(N1),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<0>_599 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<0> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<1>  (
    .ADR0(SrcA[1]),
    .ADR1(SrcB[1]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<1>_601 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<1>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<0>_600 ),
    .IA(SrcA[1]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<1>_601 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<1>_602 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<1>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<0>_600 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<1>_601 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<1> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<2>  (
    .ADR0(SrcA[2]),
    .ADR1(SrcB[2]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<2>_603 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<2>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<1>_602 ),
    .IA(SrcA[2]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<2>_603 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<2>_604 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<2>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<1>_602 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<2>_603 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<2> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<3>  (
    .ADR0(SrcA[3]),
    .ADR1(SrcB[3]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<3>_605 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<3>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<2>_604 ),
    .IA(SrcA[3]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<3>_605 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<3>_606 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<3>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<2>_604 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<3>_605 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<3> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<4>  (
    .ADR0(SrcA[4]),
    .ADR1(SrcB[4]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<4>_607 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<4>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<3>_606 ),
    .IA(SrcA[4]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<4>_607 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<4>_608 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<4>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<3>_606 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<4>_607 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<4> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<5>  (
    .ADR0(SrcA[5]),
    .ADR1(SrcB[5]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<5>_609 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<5>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<4>_608 ),
    .IA(SrcA[5]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<5>_609 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<5>_610 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<5>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<4>_608 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<5>_609 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<5> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<6>  (
    .ADR0(SrcA[6]),
    .ADR1(SrcB[6]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<6>_611 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<6>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<5>_610 ),
    .IA(SrcA[6]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<6>_611 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<6>_612 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<6>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<5>_610 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<6>_611 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<6> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<7>  (
    .ADR0(SrcA[7]),
    .ADR1(SrcB[7]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<7>_613 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<7>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<6>_612 ),
    .IA(SrcA[7]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<7>_613 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<7>_614 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<7>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<6>_612 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<7>_613 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<7> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<8>  (
    .ADR0(SrcA[8]),
    .ADR1(SrcB[8]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<8>_615 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<8>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<7>_614 ),
    .IA(SrcA[8]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<8>_615 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<8>_616 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<8>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<7>_614 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<8>_615 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<8> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<9>  (
    .ADR0(SrcA[9]),
    .ADR1(SrcB[9]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<9>_617 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<9>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<8>_616 ),
    .IA(SrcA[9]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<9>_617 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<9>_618 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<9>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<8>_616 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<9>_617 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<9> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<10>  (
    .ADR0(SrcA[10]),
    .ADR1(SrcB[10]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<10>_619 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<10>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<9>_618 ),
    .IA(SrcA[10]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<10>_619 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<10>_620 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<10>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<9>_618 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<10>_619 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<10> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<11>  (
    .ADR0(SrcA[11]),
    .ADR1(SrcB[11]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<11>_621 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<11>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<10>_620 ),
    .IA(SrcA[11]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<11>_621 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<11>_622 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<11>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<10>_620 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<11>_621 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<11> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<12>  (
    .ADR0(SrcA[12]),
    .ADR1(SrcB[12]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<12>_623 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<12>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<11>_622 ),
    .IA(SrcA[12]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<12>_623 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<12>_624 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<12>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<11>_622 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<12>_623 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<12> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<13>  (
    .ADR0(SrcA[13]),
    .ADR1(SrcB[13]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<13>_625 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<13>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<12>_624 ),
    .IA(SrcA[13]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<13>_625 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<13>_626 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<13>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<12>_624 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<13>_625 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<13> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<14>  (
    .ADR0(SrcA[14]),
    .ADR1(SrcB[14]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<14>_627 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<14>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<13>_626 ),
    .IA(SrcA[14]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<14>_627 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<14>_628 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<14>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<13>_626 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<14>_627 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<14> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<15>  (
    .ADR0(SrcA[15]),
    .ADR1(SrcB[15]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<15>_629 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<15>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<14>_628 ),
    .IA(SrcA[15]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<15>_629 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<15>_630 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<15>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<14>_628 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<15>_629 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<15> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<16>  (
    .ADR0(SrcA[16]),
    .ADR1(SrcB[16]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<16>_631 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<16>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<15>_630 ),
    .IA(SrcA[16]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<16>_631 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<16>_632 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<16>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<15>_630 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<16>_631 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<16> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<17>  (
    .ADR0(SrcA[17]),
    .ADR1(SrcB[17]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<17>_633 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<17>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<16>_632 ),
    .IA(SrcA[17]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<17>_633 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<17>_634 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<17>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<16>_632 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<17>_633 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<17> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<18>  (
    .ADR0(SrcA[18]),
    .ADR1(SrcB[18]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<18>_635 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<18>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<17>_634 ),
    .IA(SrcA[18]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<18>_635 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<18>_636 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<18>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<17>_634 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<18>_635 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<18> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<19>  (
    .ADR0(SrcA[19]),
    .ADR1(SrcB[19]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<19>_637 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<19>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<18>_636 ),
    .IA(SrcA[19]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<19>_637 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<19>_638 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<19>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<18>_636 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<19>_637 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<19> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<20>  (
    .ADR0(SrcA[20]),
    .ADR1(SrcB[20]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<20>_639 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<20>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<19>_638 ),
    .IA(SrcA[20]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<20>_639 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<20>_640 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<20>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<19>_638 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<20>_639 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<20> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<21>  (
    .ADR0(SrcA[21]),
    .ADR1(SrcB[21]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<21>_641 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<21>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<20>_640 ),
    .IA(SrcA[21]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<21>_641 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<21>_642 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<21>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<20>_640 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<21>_641 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<21> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<22>  (
    .ADR0(SrcA[22]),
    .ADR1(SrcB[22]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<22>_643 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<22>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<21>_642 ),
    .IA(SrcA[22]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<22>_643 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<22>_644 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<22>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<21>_642 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<22>_643 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<22> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<23>  (
    .ADR0(SrcA[23]),
    .ADR1(SrcB[23]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<23>_645 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<23>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<22>_644 ),
    .IA(SrcA[23]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<23>_645 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<23>_646 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<23>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<22>_644 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<23>_645 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<23> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<24>  (
    .ADR0(SrcA[24]),
    .ADR1(SrcB[24]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<24>_647 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<24>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<23>_646 ),
    .IA(SrcA[24]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<24>_647 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<24>_648 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<24>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<23>_646 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<24>_647 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<24> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<25>  (
    .ADR0(SrcA[25]),
    .ADR1(SrcB[25]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<25>_649 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<25>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<24>_648 ),
    .IA(SrcA[25]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<25>_649 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<25>_650 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<25>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<24>_648 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<25>_649 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<25> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<26>  (
    .ADR0(SrcA[26]),
    .ADR1(SrcB[26]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<26>_651 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<26>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<25>_650 ),
    .IA(SrcA[26]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<26>_651 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<26>_652 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<26>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<25>_650 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<26>_651 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<26> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<27>  (
    .ADR0(SrcA[27]),
    .ADR1(SrcB[27]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<27>_653 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<27>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<26>_652 ),
    .IA(SrcA[27]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<27>_653 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<27>_654 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<27>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<26>_652 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<27>_653 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<27> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<28>  (
    .ADR0(SrcA[28]),
    .ADR1(SrcB[28]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<28>_655 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<28>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<27>_654 ),
    .IA(SrcA[28]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<28>_655 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<28>_656 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<28>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<27>_654 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<28>_655 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<28> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<29>  (
    .ADR0(SrcA[29]),
    .ADR1(SrcB[29]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<29>_657 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<29>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<28>_656 ),
    .IA(SrcA[29]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<29>_657 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<29>_658 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<29>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<28>_656 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<29>_657 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<29> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<30>  (
    .ADR0(SrcA[30]),
    .ADR1(SrcB[30]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<30>_659 )
  );
  X_MUX2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<30>  (
    .IB(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<29>_658 ),
    .IA(SrcA[30]),
    .SEL(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<30>_659 ),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<30>_660 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<30>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<29>_658 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<30>_659 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<30> )
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<31>  (
    .ADR0(SrcA[31]),
    .ADR1(SrcB[31]),
    .O(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<31>_661 )
  );
  X_XOR2   \Madd_SrcA[31]_SrcB[31]_add_3_OUT_xor<31>  (
    .I0(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_cy<30>_660 ),
    .I1(\Madd_SrcA[31]_SrcB[31]_add_3_OUT_lut<31>_661 ),
    .O(\SrcA[31]_SrcB[31]_add_3_OUT<31> )
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000001 ))
  \Zero<31>1  (
    .ADR0(NlwRenamedSig_OI_ALURes[2]),
    .ADR1(NlwRenamedSig_OI_ALURes[1]),
    .ADR2(NlwRenamedSig_OI_ALURes[3]),
    .ADR3(NlwRenamedSig_OI_ALURes[4]),
    .ADR4(NlwRenamedSig_OI_ALURes[0]),
    .ADR5(NlwRenamedSig_OI_ALURes[5]),
    .O(Zero_0[31])
  );
  X_LUT5 #(
    .INIT ( 32'h00000001 ))
  \Zero<31>3  (
    .ADR0(NlwRenamedSig_OI_ALURes[25]),
    .ADR1(NlwRenamedSig_OI_ALURes[24]),
    .ADR2(NlwRenamedSig_OI_ALURes[26]),
    .ADR3(NlwRenamedSig_OI_ALURes[27]),
    .ADR4(NlwRenamedSig_OI_ALURes[28]),
    .O(\Zero<31>2 )
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000001 ))
  \Zero<31>4  (
    .ADR0(NlwRenamedSig_OI_ALURes[18]),
    .ADR1(NlwRenamedSig_OI_ALURes[17]),
    .ADR2(NlwRenamedSig_OI_ALURes[19]),
    .ADR3(NlwRenamedSig_OI_ALURes[20]),
    .ADR4(NlwRenamedSig_OI_ALURes[21]),
    .ADR5(NlwRenamedSig_OI_ALURes[22]),
    .O(\Zero<31>3_664 )
  );
  X_LUT3 #(
    .INIT ( 8'h01 ))
  \Zero<31>5  (
    .ADR0(NlwRenamedSig_OI_ALURes[30]),
    .ADR1(NlwRenamedSig_OI_ALURes[29]),
    .ADR2(NlwRenamedSig_OI_ALURes[31]),
    .O(\Zero<31>4_665 )
  );
  X_LUT6 #(
    .INIT ( 64'h0000000000000001 ))
  \Zero<31>6  (
    .ADR0(NlwRenamedSig_OI_ALURes[7]),
    .ADR1(NlwRenamedSig_OI_ALURes[6]),
    .ADR2(NlwRenamedSig_OI_ALURes[8]),
    .ADR3(NlwRenamedSig_OI_ALURes[9]),
    .ADR4(NlwRenamedSig_OI_ALURes[10]),
    .ADR5(NlwRenamedSig_OI_ALURes[11]),
    .O(\Zero<31>5_666 )
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<10>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[10]),
    .ADR2(SrcB[10]),
    .O(N01)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<10>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<10> ),
    .ADR4(N01),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<10> ),
    .O(NlwRenamedSig_OI_ALURes[10])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<11>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcB[11]),
    .ADR2(SrcA[11]),
    .O(N2)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<11>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<11> ),
    .ADR4(N2),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<11> ),
    .O(NlwRenamedSig_OI_ALURes[11])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<12>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcB[12]),
    .ADR2(SrcA[12]),
    .O(N4)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<12>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<12> ),
    .ADR4(N4),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<12> ),
    .O(NlwRenamedSig_OI_ALURes[12])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<13>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcB[13]),
    .ADR2(SrcA[13]),
    .O(N6)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<13>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<13> ),
    .ADR4(N6),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<13> ),
    .O(NlwRenamedSig_OI_ALURes[13])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<14>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcB[14]),
    .ADR2(SrcA[14]),
    .O(N8)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<14>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<14> ),
    .ADR4(N8),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<14> ),
    .O(NlwRenamedSig_OI_ALURes[14])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<15>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[15]),
    .ADR2(SrcB[15]),
    .O(N10)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<15>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<15> ),
    .ADR4(N10),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<15> ),
    .O(NlwRenamedSig_OI_ALURes[15])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<16>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[16]),
    .ADR2(SrcB[16]),
    .O(N12)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<16>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<16> ),
    .ADR4(N12),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<16> ),
    .O(NlwRenamedSig_OI_ALURes[16])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<17>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[17]),
    .ADR2(SrcB[17]),
    .O(N14)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<17>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<17> ),
    .ADR4(N14),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<17> ),
    .O(NlwRenamedSig_OI_ALURes[17])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<18>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[18]),
    .ADR2(SrcB[18]),
    .O(N16)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<18>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<18> ),
    .ADR4(N16),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<18> ),
    .O(NlwRenamedSig_OI_ALURes[18])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<19>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[19]),
    .ADR2(SrcB[19]),
    .O(N18)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<19>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<19> ),
    .ADR4(N18),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<19> ),
    .O(NlwRenamedSig_OI_ALURes[19])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  \_n0107<1>_SW0  (
    .ADR0(ALUCtr[2]),
    .ADR1(\SrcA[31]_SrcB[31]_add_3_OUT<1> ),
    .ADR2(\SrcA[31]_SrcB[31]_sub_5_OUT<1> ),
    .O(N20)
  );
  X_LUT6 #(
    .INIT ( 64'h11BA10AA11101000 ))
  \_n0107<1>  (
    .ADR0(ALUCtr[1]),
    .ADR1(ALUCtr[2]),
    .ADR2(SrcA[1]),
    .ADR3(ALUCtr[0]),
    .ADR4(SrcB[1]),
    .ADR5(N20),
    .O(NlwRenamedSig_OI_ALURes[1])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<20>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[20]),
    .ADR2(SrcB[20]),
    .O(N22)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<20>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<20> ),
    .ADR4(N22),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<20> ),
    .O(NlwRenamedSig_OI_ALURes[20])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<21>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[21]),
    .ADR2(SrcB[21]),
    .O(N24)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<21>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<21> ),
    .ADR4(N24),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<21> ),
    .O(NlwRenamedSig_OI_ALURes[21])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<22>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[22]),
    .ADR2(SrcB[22]),
    .O(N26)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<22>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<22> ),
    .ADR4(N26),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<22> ),
    .O(NlwRenamedSig_OI_ALURes[22])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<23>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[23]),
    .ADR2(SrcB[23]),
    .O(N28)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<23>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<23> ),
    .ADR4(N28),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<23> ),
    .O(NlwRenamedSig_OI_ALURes[23])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<24>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[24]),
    .ADR2(SrcB[24]),
    .O(N30)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<24>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<24> ),
    .ADR4(N30),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<24> ),
    .O(NlwRenamedSig_OI_ALURes[24])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<25>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[25]),
    .ADR2(SrcB[25]),
    .O(N32)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<25>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<25> ),
    .ADR4(N32),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<25> ),
    .O(NlwRenamedSig_OI_ALURes[25])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<26>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[26]),
    .ADR2(SrcB[26]),
    .O(N34)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<26>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<26> ),
    .ADR4(N34),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<26> ),
    .O(NlwRenamedSig_OI_ALURes[26])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<27>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[27]),
    .ADR2(SrcB[27]),
    .O(N36)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<27>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<27> ),
    .ADR4(N36),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<27> ),
    .O(NlwRenamedSig_OI_ALURes[27])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<28>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[28]),
    .ADR2(SrcB[28]),
    .O(N38)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<28>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<28> ),
    .ADR4(N38),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<28> ),
    .O(NlwRenamedSig_OI_ALURes[28])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<29>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[29]),
    .ADR2(SrcB[29]),
    .O(N40)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<29>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<29> ),
    .ADR4(N40),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<29> ),
    .O(NlwRenamedSig_OI_ALURes[29])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<2>_SW0  (
    .ADR0(SrcA[2]),
    .ADR1(SrcB[2]),
    .ADR2(ALUCtr[0]),
    .O(N42)
  );
  X_LUT6 #(
    .INIT ( 64'h0C1D041508190011 ))
  \_n0107<2>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(N42),
    .ADR4(\SrcA[31]_SrcB[31]_sub_5_OUT<2> ),
    .ADR5(\SrcA[31]_SrcB[31]_add_3_OUT<2> ),
    .O(NlwRenamedSig_OI_ALURes[2])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<30>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[30]),
    .ADR2(SrcB[30]),
    .O(N44)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<30>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<30> ),
    .ADR4(N44),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<30> ),
    .O(NlwRenamedSig_OI_ALURes[30])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<31>_SW0  (
    .ADR0(ALUCtr[0]),
    .ADR1(SrcA[31]),
    .ADR2(SrcB[31]),
    .O(N46)
  );
  X_LUT6 #(
    .INIT ( 64'h0C081D1904001511 ))
  \_n0107<31>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\SrcA[31]_SrcB[31]_add_3_OUT<31> ),
    .ADR4(N46),
    .ADR5(\SrcA[31]_SrcB[31]_sub_5_OUT<31> ),
    .O(NlwRenamedSig_OI_ALURes[31])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<3>_SW0  (
    .ADR0(SrcA[3]),
    .ADR1(SrcB[3]),
    .ADR2(ALUCtr[0]),
    .O(N48)
  );
  X_LUT6 #(
    .INIT ( 64'h0C1D041508190011 ))
  \_n0107<3>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(N48),
    .ADR4(\SrcA[31]_SrcB[31]_sub_5_OUT<3> ),
    .ADR5(\SrcA[31]_SrcB[31]_add_3_OUT<3> ),
    .O(NlwRenamedSig_OI_ALURes[3])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<4>_SW0  (
    .ADR0(SrcA[4]),
    .ADR1(SrcB[4]),
    .ADR2(ALUCtr[0]),
    .O(N50)
  );
  X_LUT6 #(
    .INIT ( 64'h0C1D041508190011 ))
  \_n0107<4>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(N50),
    .ADR4(\SrcA[31]_SrcB[31]_sub_5_OUT<4> ),
    .ADR5(\SrcA[31]_SrcB[31]_add_3_OUT<4> ),
    .O(NlwRenamedSig_OI_ALURes[4])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<5>_SW0  (
    .ADR0(SrcA[5]),
    .ADR1(SrcB[5]),
    .ADR2(ALUCtr[0]),
    .O(N52)
  );
  X_LUT6 #(
    .INIT ( 64'h0C1D041508190011 ))
  \_n0107<5>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(N52),
    .ADR4(\SrcA[31]_SrcB[31]_sub_5_OUT<5> ),
    .ADR5(\SrcA[31]_SrcB[31]_add_3_OUT<5> ),
    .O(NlwRenamedSig_OI_ALURes[5])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<6>_SW0  (
    .ADR0(SrcA[6]),
    .ADR1(SrcB[6]),
    .ADR2(ALUCtr[0]),
    .O(N54)
  );
  X_LUT6 #(
    .INIT ( 64'h0C1D041508190011 ))
  \_n0107<6>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(N54),
    .ADR4(\SrcA[31]_SrcB[31]_sub_5_OUT<6> ),
    .ADR5(\SrcA[31]_SrcB[31]_add_3_OUT<6> ),
    .O(NlwRenamedSig_OI_ALURes[6])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<7>_SW0  (
    .ADR0(SrcA[7]),
    .ADR1(SrcB[7]),
    .ADR2(ALUCtr[0]),
    .O(N56)
  );
  X_LUT6 #(
    .INIT ( 64'h0C1D041508190011 ))
  \_n0107<7>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(N56),
    .ADR4(\SrcA[31]_SrcB[31]_sub_5_OUT<7> ),
    .ADR5(\SrcA[31]_SrcB[31]_add_3_OUT<7> ),
    .O(NlwRenamedSig_OI_ALURes[7])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<8>_SW0  (
    .ADR0(SrcA[8]),
    .ADR1(SrcB[8]),
    .ADR2(ALUCtr[0]),
    .O(N58)
  );
  X_LUT6 #(
    .INIT ( 64'h0C1D041508190011 ))
  \_n0107<8>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(N58),
    .ADR4(\SrcA[31]_SrcB[31]_sub_5_OUT<8> ),
    .ADR5(\SrcA[31]_SrcB[31]_add_3_OUT<8> ),
    .O(NlwRenamedSig_OI_ALURes[8])
  );
  X_LUT3 #(
    .INIT ( 8'h17 ))
  \_n0107<9>_SW0  (
    .ADR0(SrcA[9]),
    .ADR1(SrcB[9]),
    .ADR2(ALUCtr[0]),
    .O(N60)
  );
  X_LUT6 #(
    .INIT ( 64'h0C1D041508190011 ))
  \_n0107<9>  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(N60),
    .ADR4(\SrcA[31]_SrcB[31]_sub_5_OUT<9> ),
    .ADR5(\SrcA[31]_SrcB[31]_add_3_OUT<9> ),
    .O(NlwRenamedSig_OI_ALURes[9])
  );
  X_LUT5 #(
    .INIT ( 32'h76625440 ))
  \_n0109<0>1  (
    .ADR0(ALUCtr[1]),
    .ADR1(ALUCtr[0]),
    .ADR2(SrcB[0]),
    .ADR3(SrcA[0]),
    .ADR4(\SrcA[31]_SrcB[31]_add_3_OUT<0> ),
    .O(_n0109[0])
  );
  X_LUT6 #(
    .INIT ( 64'h5DDD55D508880080 ))
  \_n0109<0>2  (
    .ADR0(ALUCtr[2]),
    .ADR1(ALUCtr[1]),
    .ADR2(ALUCtr[0]),
    .ADR3(\Mcompar_SrcA[31]_SrcB[31]_LessThan_6_o_cy<15>_535 ),
    .ADR4(\SrcA[31]_SrcB[31]_sub_5_OUT<0> ),
    .ADR5(_n0109[0]),
    .O(NlwRenamedSig_OI_ALURes[0])
  );
  X_LUT6 #(
    .INIT ( 64'hFFFFFFFFFFFFFFFE ))
  \Zero<31>2_SW0  (
    .ADR0(NlwRenamedSig_OI_ALURes[23]),
    .ADR1(NlwRenamedSig_OI_ALURes[16]),
    .ADR2(NlwRenamedSig_OI_ALURes[15]),
    .ADR3(NlwRenamedSig_OI_ALURes[14]),
    .ADR4(NlwRenamedSig_OI_ALURes[13]),
    .ADR5(NlwRenamedSig_OI_ALURes[12]),
    .O(N62)
  );
  X_LUT6 #(
    .INIT ( 64'h0080000000000000 ))
  \Zero<31>7  (
    .ADR0(\Zero<31>3_664 ),
    .ADR1(\Zero<31>4_665 ),
    .ADR2(\Zero<31>2 ),
    .ADR3(N62),
    .ADR4(\Zero<31>5_666 ),
    .ADR5(Zero_0[31]),
    .O(Zero)
  );
endmodule

module Data_memory (
  Clk, DmemWrite, DmemAddr, DmemWrData, DmemRdData
);
  input Clk;
  input DmemWrite;
  input [31 : 0] DmemAddr;
  input [31 : 0] DmemWrData;
  output [31 : 0] DmemRdData;
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem2 (
    .CLK(Clk),
    .I(DmemWrData[1]),
    .WE(DmemWrite),
    .O(DmemRdData[1]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000003 ))
  Mram_DataMem1 (
    .CLK(Clk),
    .I(DmemWrData[0]),
    .WE(DmemWrite),
    .O(DmemRdData[0]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000002 ))
  Mram_DataMem3 (
    .CLK(Clk),
    .I(DmemWrData[2]),
    .WE(DmemWrite),
    .O(DmemRdData[2]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000004 ))
  Mram_DataMem4 (
    .CLK(Clk),
    .I(DmemWrData[3]),
    .WE(DmemWrite),
    .O(DmemRdData[3]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem5 (
    .CLK(Clk),
    .I(DmemWrData[4]),
    .WE(DmemWrite),
    .O(DmemRdData[4]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem6 (
    .CLK(Clk),
    .I(DmemWrData[5]),
    .WE(DmemWrite),
    .O(DmemRdData[5]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem7 (
    .CLK(Clk),
    .I(DmemWrData[6]),
    .WE(DmemWrite),
    .O(DmemRdData[6]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem8 (
    .CLK(Clk),
    .I(DmemWrData[7]),
    .WE(DmemWrite),
    .O(DmemRdData[7]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem9 (
    .CLK(Clk),
    .I(DmemWrData[8]),
    .WE(DmemWrite),
    .O(DmemRdData[8]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem10 (
    .CLK(Clk),
    .I(DmemWrData[9]),
    .WE(DmemWrite),
    .O(DmemRdData[9]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem11 (
    .CLK(Clk),
    .I(DmemWrData[10]),
    .WE(DmemWrite),
    .O(DmemRdData[10]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem12 (
    .CLK(Clk),
    .I(DmemWrData[11]),
    .WE(DmemWrite),
    .O(DmemRdData[11]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem13 (
    .CLK(Clk),
    .I(DmemWrData[12]),
    .WE(DmemWrite),
    .O(DmemRdData[12]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem14 (
    .CLK(Clk),
    .I(DmemWrData[13]),
    .WE(DmemWrite),
    .O(DmemRdData[13]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem15 (
    .CLK(Clk),
    .I(DmemWrData[14]),
    .WE(DmemWrite),
    .O(DmemRdData[14]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem16 (
    .CLK(Clk),
    .I(DmemWrData[15]),
    .WE(DmemWrite),
    .O(DmemRdData[15]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem17 (
    .CLK(Clk),
    .I(DmemWrData[16]),
    .WE(DmemWrite),
    .O(DmemRdData[16]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem18 (
    .CLK(Clk),
    .I(DmemWrData[17]),
    .WE(DmemWrite),
    .O(DmemRdData[17]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem19 (
    .CLK(Clk),
    .I(DmemWrData[18]),
    .WE(DmemWrite),
    .O(DmemRdData[18]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem20 (
    .CLK(Clk),
    .I(DmemWrData[19]),
    .WE(DmemWrite),
    .O(DmemRdData[19]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem21 (
    .CLK(Clk),
    .I(DmemWrData[20]),
    .WE(DmemWrite),
    .O(DmemRdData[20]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem22 (
    .CLK(Clk),
    .I(DmemWrData[21]),
    .WE(DmemWrite),
    .O(DmemRdData[21]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem23 (
    .CLK(Clk),
    .I(DmemWrData[22]),
    .WE(DmemWrite),
    .O(DmemRdData[22]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem24 (
    .CLK(Clk),
    .I(DmemWrData[23]),
    .WE(DmemWrite),
    .O(DmemRdData[23]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem25 (
    .CLK(Clk),
    .I(DmemWrData[24]),
    .WE(DmemWrite),
    .O(DmemRdData[24]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem26 (
    .CLK(Clk),
    .I(DmemWrData[25]),
    .WE(DmemWrite),
    .O(DmemRdData[25]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem27 (
    .CLK(Clk),
    .I(DmemWrData[26]),
    .WE(DmemWrite),
    .O(DmemRdData[26]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem28 (
    .CLK(Clk),
    .I(DmemWrData[27]),
    .WE(DmemWrite),
    .O(DmemRdData[27]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem29 (
    .CLK(Clk),
    .I(DmemWrData[28]),
    .WE(DmemWrite),
    .O(DmemRdData[28]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem30 (
    .CLK(Clk),
    .I(DmemWrData[29]),
    .WE(DmemWrite),
    .O(DmemRdData[29]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem31 (
    .CLK(Clk),
    .I(DmemWrData[30]),
    .WE(DmemWrite),
    .O(DmemRdData[30]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
  X_RAMS256 #(
    .INIT ( 256'h0000000000000000000000000000000000000000000000000000000000000000 ))
  Mram_DataMem32 (
    .CLK(Clk),
    .I(DmemWrData[31]),
    .WE(DmemWrite),
    .O(DmemRdData[31]),
    .ADR7(DmemAddr[7]),
    .ADR6(DmemAddr[6]),
    .ADR5(DmemAddr[5]),
    .ADR4(DmemAddr[4]),
    .ADR3(DmemAddr[3]),
    .ADR2(DmemAddr[2]),
    .ADR1(DmemAddr[1]),
    .ADR0(DmemAddr[0])
  );
endmodule

module register_register (
  Clk, RegWrite, RegARdAddr, RegBRdAddr, RegWrAddr, RegWrData, RegARdData, RegBRdData
);
  input Clk;
  input RegWrite;
  input [4 : 0] RegARdAddr;
  input [4 : 0] RegBRdAddr;
  input [4 : 0] RegWrAddr;
  input [31 : 0] RegWrData;
  output [31 : 0] RegARdData;
  output [31 : 0] RegBRdData;
  wire \RegARdAddr[4]_read_port_4_OUT<31> ;
  wire \RegARdAddr[4]_read_port_4_OUT<30> ;
  wire \RegARdAddr[4]_read_port_4_OUT<29> ;
  wire \RegARdAddr[4]_read_port_4_OUT<28> ;
  wire \RegARdAddr[4]_read_port_4_OUT<27> ;
  wire \RegARdAddr[4]_read_port_4_OUT<26> ;
  wire \RegARdAddr[4]_read_port_4_OUT<25> ;
  wire \RegARdAddr[4]_read_port_4_OUT<24> ;
  wire \RegARdAddr[4]_read_port_4_OUT<23> ;
  wire \RegARdAddr[4]_read_port_4_OUT<22> ;
  wire \RegARdAddr[4]_read_port_4_OUT<21> ;
  wire \RegARdAddr[4]_read_port_4_OUT<20> ;
  wire \RegARdAddr[4]_read_port_4_OUT<19> ;
  wire \RegARdAddr[4]_read_port_4_OUT<18> ;
  wire \RegARdAddr[4]_read_port_4_OUT<17> ;
  wire \RegARdAddr[4]_read_port_4_OUT<16> ;
  wire \RegARdAddr[4]_read_port_4_OUT<15> ;
  wire \RegARdAddr[4]_read_port_4_OUT<14> ;
  wire \RegARdAddr[4]_read_port_4_OUT<13> ;
  wire \RegARdAddr[4]_read_port_4_OUT<12> ;
  wire \RegARdAddr[4]_read_port_4_OUT<11> ;
  wire \RegARdAddr[4]_read_port_4_OUT<10> ;
  wire \RegARdAddr[4]_read_port_4_OUT<9> ;
  wire \RegARdAddr[4]_read_port_4_OUT<8> ;
  wire \RegARdAddr[4]_read_port_4_OUT<7> ;
  wire \RegARdAddr[4]_read_port_4_OUT<6> ;
  wire \RegARdAddr[4]_read_port_4_OUT<5> ;
  wire \RegARdAddr[4]_read_port_4_OUT<4> ;
  wire \RegARdAddr[4]_read_port_4_OUT<3> ;
  wire \RegARdAddr[4]_read_port_4_OUT<2> ;
  wire \RegARdAddr[4]_read_port_4_OUT<1> ;
  wire \RegARdAddr[4]_read_port_4_OUT<0> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<31> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<30> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<29> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<28> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<27> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<26> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<25> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<24> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<23> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<22> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<21> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<20> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<19> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<18> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<17> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<16> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<15> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<14> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<13> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<12> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<11> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<10> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<9> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<8> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<7> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<6> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<5> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<4> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<3> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<2> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<1> ;
  wire \RegBRdAddr[4]_read_port_7_OUT<0> ;
  wire N1;
  wire Clk_inv;
  wire \Mram_regFile71/SPO ;
  wire \Mram_regFile162/SPO ;
  wire \Mram_regFile72/SPO ;
  wire \Mram_regFile161/SPO ;
  wire \NLW_Mram_regFile2_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile2_DOD[0]_UNCONNECTED ;
  wire \NLW_Mram_regFile3_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile3_DOD[0]_UNCONNECTED ;
  wire \NLW_Mram_regFile6_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile6_DOD[0]_UNCONNECTED ;
  wire \NLW_Mram_regFile4_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile4_DOD[0]_UNCONNECTED ;
  wire \NLW_Mram_regFile5_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile5_DOD[0]_UNCONNECTED ;
  wire \NLW_Mram_regFile11_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile11_DOD[0]_UNCONNECTED ;
  wire \NLW_Mram_regFile12_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile12_DOD[0]_UNCONNECTED ;
  wire \NLW_Mram_regFile13_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile13_DOD[0]_UNCONNECTED ;
  wire \NLW_Mram_regFile14_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile14_DOD[0]_UNCONNECTED ;
  wire \NLW_Mram_regFile15_DOD[1]_UNCONNECTED ;
  wire \NLW_Mram_regFile15_DOD[0]_UNCONNECTED ;
  X_ZERO   XST_GND (
    .O(N1)
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile2 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[1], RegWrData[0]}),
    .DIB({RegWrData[3], RegWrData[2]}),
    .DIC({RegWrData[5], RegWrData[4]}),
    .DID({N1, N1}),
    .ADDRA({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRB({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRC({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegARdAddr[4]_read_port_4_OUT<1> , \RegARdAddr[4]_read_port_4_OUT<0> }),
    .DOB({\RegARdAddr[4]_read_port_4_OUT<3> , \RegARdAddr[4]_read_port_4_OUT<2> }),
    .DOC({\RegARdAddr[4]_read_port_4_OUT<5> , \RegARdAddr[4]_read_port_4_OUT<4> }),
    .DOD({\NLW_Mram_regFile2_DOD[1]_UNCONNECTED , \NLW_Mram_regFile2_DOD[0]_UNCONNECTED })
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile3 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[7], RegWrData[6]}),
    .DIB({RegWrData[9], RegWrData[8]}),
    .DIC({RegWrData[11], RegWrData[10]}),
    .DID({N1, N1}),
    .ADDRA({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRB({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRC({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegARdAddr[4]_read_port_4_OUT<7> , \RegARdAddr[4]_read_port_4_OUT<6> }),
    .DOB({\RegARdAddr[4]_read_port_4_OUT<9> , \RegARdAddr[4]_read_port_4_OUT<8> }),
    .DOC({\RegARdAddr[4]_read_port_4_OUT<11> , \RegARdAddr[4]_read_port_4_OUT<10> }),
    .DOD({\NLW_Mram_regFile3_DOD[1]_UNCONNECTED , \NLW_Mram_regFile3_DOD[0]_UNCONNECTED })
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile6 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[25], RegWrData[24]}),
    .DIB({RegWrData[27], RegWrData[26]}),
    .DIC({RegWrData[29], RegWrData[28]}),
    .DID({N1, N1}),
    .ADDRA({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRB({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRC({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegARdAddr[4]_read_port_4_OUT<25> , \RegARdAddr[4]_read_port_4_OUT<24> }),
    .DOB({\RegARdAddr[4]_read_port_4_OUT<27> , \RegARdAddr[4]_read_port_4_OUT<26> }),
    .DOC({\RegARdAddr[4]_read_port_4_OUT<29> , \RegARdAddr[4]_read_port_4_OUT<28> }),
    .DOD({\NLW_Mram_regFile6_DOD[1]_UNCONNECTED , \NLW_Mram_regFile6_DOD[0]_UNCONNECTED })
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile4 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[13], RegWrData[12]}),
    .DIB({RegWrData[15], RegWrData[14]}),
    .DIC({RegWrData[17], RegWrData[16]}),
    .DID({N1, N1}),
    .ADDRA({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRB({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRC({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegARdAddr[4]_read_port_4_OUT<13> , \RegARdAddr[4]_read_port_4_OUT<12> }),
    .DOB({\RegARdAddr[4]_read_port_4_OUT<15> , \RegARdAddr[4]_read_port_4_OUT<14> }),
    .DOC({\RegARdAddr[4]_read_port_4_OUT<17> , \RegARdAddr[4]_read_port_4_OUT<16> }),
    .DOD({\NLW_Mram_regFile4_DOD[1]_UNCONNECTED , \NLW_Mram_regFile4_DOD[0]_UNCONNECTED })
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile5 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[19], RegWrData[18]}),
    .DIB({RegWrData[21], RegWrData[20]}),
    .DIC({RegWrData[23], RegWrData[22]}),
    .DID({N1, N1}),
    .ADDRA({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRB({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRC({RegARdAddr[4], RegARdAddr[3], RegARdAddr[2], RegARdAddr[1], RegARdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegARdAddr[4]_read_port_4_OUT<19> , \RegARdAddr[4]_read_port_4_OUT<18> }),
    .DOB({\RegARdAddr[4]_read_port_4_OUT<21> , \RegARdAddr[4]_read_port_4_OUT<20> }),
    .DOC({\RegARdAddr[4]_read_port_4_OUT<23> , \RegARdAddr[4]_read_port_4_OUT<22> }),
    .DOD({\NLW_Mram_regFile5_DOD[1]_UNCONNECTED , \NLW_Mram_regFile5_DOD[0]_UNCONNECTED })
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile11 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[1], RegWrData[0]}),
    .DIB({RegWrData[3], RegWrData[2]}),
    .DIC({RegWrData[5], RegWrData[4]}),
    .DID({N1, N1}),
    .ADDRA({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRB({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRC({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegBRdAddr[4]_read_port_7_OUT<1> , \RegBRdAddr[4]_read_port_7_OUT<0> }),
    .DOB({\RegBRdAddr[4]_read_port_7_OUT<3> , \RegBRdAddr[4]_read_port_7_OUT<2> }),
    .DOC({\RegBRdAddr[4]_read_port_7_OUT<5> , \RegBRdAddr[4]_read_port_7_OUT<4> }),
    .DOD({\NLW_Mram_regFile11_DOD[1]_UNCONNECTED , \NLW_Mram_regFile11_DOD[0]_UNCONNECTED })
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile12 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[7], RegWrData[6]}),
    .DIB({RegWrData[9], RegWrData[8]}),
    .DIC({RegWrData[11], RegWrData[10]}),
    .DID({N1, N1}),
    .ADDRA({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRB({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRC({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegBRdAddr[4]_read_port_7_OUT<7> , \RegBRdAddr[4]_read_port_7_OUT<6> }),
    .DOB({\RegBRdAddr[4]_read_port_7_OUT<9> , \RegBRdAddr[4]_read_port_7_OUT<8> }),
    .DOC({\RegBRdAddr[4]_read_port_7_OUT<11> , \RegBRdAddr[4]_read_port_7_OUT<10> }),
    .DOD({\NLW_Mram_regFile12_DOD[1]_UNCONNECTED , \NLW_Mram_regFile12_DOD[0]_UNCONNECTED })
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile13 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[13], RegWrData[12]}),
    .DIB({RegWrData[15], RegWrData[14]}),
    .DIC({RegWrData[17], RegWrData[16]}),
    .DID({N1, N1}),
    .ADDRA({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRB({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRC({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegBRdAddr[4]_read_port_7_OUT<13> , \RegBRdAddr[4]_read_port_7_OUT<12> }),
    .DOB({\RegBRdAddr[4]_read_port_7_OUT<15> , \RegBRdAddr[4]_read_port_7_OUT<14> }),
    .DOC({\RegBRdAddr[4]_read_port_7_OUT<17> , \RegBRdAddr[4]_read_port_7_OUT<16> }),
    .DOD({\NLW_Mram_regFile13_DOD[1]_UNCONNECTED , \NLW_Mram_regFile13_DOD[0]_UNCONNECTED })
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile14 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[19], RegWrData[18]}),
    .DIB({RegWrData[21], RegWrData[20]}),
    .DIC({RegWrData[23], RegWrData[22]}),
    .DID({N1, N1}),
    .ADDRA({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRB({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRC({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegBRdAddr[4]_read_port_7_OUT<19> , \RegBRdAddr[4]_read_port_7_OUT<18> }),
    .DOB({\RegBRdAddr[4]_read_port_7_OUT<21> , \RegBRdAddr[4]_read_port_7_OUT<20> }),
    .DOC({\RegBRdAddr[4]_read_port_7_OUT<23> , \RegBRdAddr[4]_read_port_7_OUT<22> }),
    .DOD({\NLW_Mram_regFile14_DOD[1]_UNCONNECTED , \NLW_Mram_regFile14_DOD[0]_UNCONNECTED })
  );
  X_RAM32M #(
    .INIT_A ( 64'h000000000000000C ),
    .INIT_B ( 64'h000000000000000C ),
    .INIT_C ( 64'h000000000000000C ),
    .INIT_D ( 64'h0000000000000000 ))
  Mram_regFile15 (
    .WCLK(Clk_inv),
    .WE(RegWrite),
    .DIA({RegWrData[25], RegWrData[24]}),
    .DIB({RegWrData[27], RegWrData[26]}),
    .DIC({RegWrData[29], RegWrData[28]}),
    .DID({N1, N1}),
    .ADDRA({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRB({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRC({RegBRdAddr[4], RegBRdAddr[3], RegBRdAddr[2], RegBRdAddr[1], RegBRdAddr[0]}),
    .ADDRD({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .DOA({\RegBRdAddr[4]_read_port_7_OUT<25> , \RegBRdAddr[4]_read_port_7_OUT<24> }),
    .DOB({\RegBRdAddr[4]_read_port_7_OUT<27> , \RegBRdAddr[4]_read_port_7_OUT<26> }),
    .DOC({\RegBRdAddr[4]_read_port_7_OUT<29> , \RegBRdAddr[4]_read_port_7_OUT<28> }),
    .DOD({\NLW_Mram_regFile15_DOD[1]_UNCONNECTED , \NLW_Mram_regFile15_DOD[0]_UNCONNECTED })
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData11 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<0> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[0])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData121 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<1> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[1])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData231 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<2> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[2])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData261 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<3> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[3])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData271 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<4> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[4])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData281 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<5> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[5])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData291 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<6> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[6])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData301 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<7> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[7])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData311 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<8> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[8])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData321 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<9> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[9])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData321 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<9> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[9])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData11 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<0> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[0])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData121 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<1> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[1])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData231 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<2> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[2])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData261 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<3> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[3])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData271 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<4> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[4])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData281 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<5> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[5])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData291 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<6> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[6])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData301 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<7> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[7])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData311 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<8> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[8])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData31 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<11> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[11])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData21 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<10> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[10])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData51 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<13> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[13])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData41 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<12> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[12])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData71 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<15> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[15])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData61 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<14> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[14])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData91 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<17> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[17])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData81 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<16> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[16])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData111 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<19> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[19])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData101 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<18> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[18])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData141 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<21> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[21])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData131 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<20> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[20])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData161 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<23> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[23])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData151 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<22> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[22])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData181 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<25> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[25])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData171 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<24> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[24])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData201 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<27> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[27])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData191 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<26> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[26])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData221 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<29> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[29])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData211 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<28> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[28])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData31 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<11> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[11])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData21 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<10> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[10])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData51 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<13> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[13])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData41 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<12> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[12])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData71 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<15> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[15])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData61 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<14> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[14])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData91 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<17> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[17])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData81 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<16> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[16])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData111 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<19> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[19])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData101 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<18> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[18])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData141 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<21> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[21])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData131 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<20> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[20])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData161 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<23> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[23])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData151 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<22> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[22])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData181 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<25> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[25])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData171 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<24> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[24])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData201 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<27> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[27])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData191 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<26> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[26])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData221 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<29> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[29])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData211 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<28> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[28])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData251 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<31> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[31])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegBRdData241 (
    .ADR0(\RegBRdAddr[4]_read_port_7_OUT<30> ),
    .ADR1(RegBRdAddr[0]),
    .ADR2(RegBRdAddr[3]),
    .ADR3(RegBRdAddr[2]),
    .ADR4(RegBRdAddr[1]),
    .O(RegBRdData[30])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData251 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<31> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[31])
  );
  X_LUT5 #(
    .INIT ( 32'hAAAAAAA8 ))
  Mmux_RegARdData241 (
    .ADR0(\RegARdAddr[4]_read_port_4_OUT<30> ),
    .ADR1(RegARdAddr[0]),
    .ADR2(RegARdAddr[3]),
    .ADR3(RegARdAddr[2]),
    .ADR4(RegARdAddr[1]),
    .O(RegARdData[30])
  );
  X_INV   Clk_inv_INV_0 (
    .I(Clk),
    .O(Clk_inv)
  );
  X_RAMD32 #(
    .INIT ( 32'h00000002 ))
  \Mram_regFile71/X_RAMD32  (
    .RADR0(RegARdAddr[0]),
    .RADR1(RegARdAddr[1]),
    .RADR2(RegARdAddr[2]),
    .RADR3(RegARdAddr[3]),
    .RADR4(RegARdAddr[4]),
    .WADR0(RegWrAddr[0]),
    .WADR1(RegWrAddr[1]),
    .WADR2(RegWrAddr[2]),
    .WADR3(RegWrAddr[3]),
    .WADR4(RegWrAddr[4]),
    .I(RegWrData[30]),
    .CLK(Clk_inv),
    .WE(RegWrite),
    .O(\RegARdAddr[4]_read_port_4_OUT<30> )
  );
  X_RAMS32 #(
    .INIT ( 32'h00000002 ))
  \Mram_regFile71/X_RAMS32  (
    .ADR0(RegWrAddr[0]),
    .ADR1(RegWrAddr[1]),
    .ADR2(RegWrAddr[2]),
    .ADR3(RegWrAddr[3]),
    .ADR4(RegWrAddr[4]),
    .I(RegWrData[30]),
    .CLK(Clk_inv),
    .WE(RegWrite),
    .O(\Mram_regFile71/SPO )
  );
  X_RAMD32 #(
    .INIT ( 32'h00000002 ))
  \Mram_regFile162/X_RAMD32  (
    .RADR0(RegBRdAddr[0]),
    .RADR1(RegBRdAddr[1]),
    .RADR2(RegBRdAddr[2]),
    .RADR3(RegBRdAddr[3]),
    .RADR4(RegBRdAddr[4]),
    .WADR0(RegWrAddr[0]),
    .WADR1(RegWrAddr[1]),
    .WADR2(RegWrAddr[2]),
    .WADR3(RegWrAddr[3]),
    .WADR4(RegWrAddr[4]),
    .I(RegWrData[31]),
    .CLK(Clk_inv),
    .WE(RegWrite),
    .O(\RegBRdAddr[4]_read_port_7_OUT<31> )
  );
  X_RAMS32 #(
    .INIT ( 32'h00000002 ))
  \Mram_regFile162/X_RAMS32  (
    .ADR0(RegWrAddr[0]),
    .ADR1(RegWrAddr[1]),
    .ADR2(RegWrAddr[2]),
    .ADR3(RegWrAddr[3]),
    .ADR4(RegWrAddr[4]),
    .I(RegWrData[31]),
    .CLK(Clk_inv),
    .WE(RegWrite),
    .O(\Mram_regFile162/SPO )
  );
  X_RAMD32 #(
    .INIT ( 32'h00000002 ))
  \Mram_regFile72/X_RAMD32  (
    .RADR0(RegARdAddr[0]),
    .RADR1(RegARdAddr[1]),
    .RADR2(RegARdAddr[2]),
    .RADR3(RegARdAddr[3]),
    .RADR4(RegARdAddr[4]),
    .WADR0(RegWrAddr[0]),
    .WADR1(RegWrAddr[1]),
    .WADR2(RegWrAddr[2]),
    .WADR3(RegWrAddr[3]),
    .WADR4(RegWrAddr[4]),
    .I(RegWrData[31]),
    .CLK(Clk_inv),
    .WE(RegWrite),
    .O(\RegARdAddr[4]_read_port_4_OUT<31> )
  );
  X_RAMS32 #(
    .INIT ( 32'h00000002 ))
  \Mram_regFile72/X_RAMS32  (
    .ADR0(RegWrAddr[0]),
    .ADR1(RegWrAddr[1]),
    .ADR2(RegWrAddr[2]),
    .ADR3(RegWrAddr[3]),
    .ADR4(RegWrAddr[4]),
    .I(RegWrData[31]),
    .CLK(Clk_inv),
    .WE(RegWrite),
    .O(\Mram_regFile72/SPO )
  );
  X_RAMD32 #(
    .INIT ( 32'h00000002 ))
  \Mram_regFile161/X_RAMD32  (
    .RADR0(RegBRdAddr[0]),
    .RADR1(RegBRdAddr[1]),
    .RADR2(RegBRdAddr[2]),
    .RADR3(RegBRdAddr[3]),
    .RADR4(RegBRdAddr[4]),
    .WADR0(RegWrAddr[0]),
    .WADR1(RegWrAddr[1]),
    .WADR2(RegWrAddr[2]),
    .WADR3(RegWrAddr[3]),
    .WADR4(RegWrAddr[4]),
    .I(RegWrData[30]),
    .CLK(Clk_inv),
    .WE(RegWrite),
    .O(\RegBRdAddr[4]_read_port_7_OUT<30> )
  );
  X_RAMS32 #(
    .INIT ( 32'h00000002 ))
  \Mram_regFile161/X_RAMS32  (
    .ADR0(RegWrAddr[0]),
    .ADR1(RegWrAddr[1]),
    .ADR2(RegWrAddr[2]),
    .ADR3(RegWrAddr[3]),
    .ADR4(RegWrAddr[4]),
    .I(RegWrData[30]),
    .CLK(Clk_inv),
    .WE(RegWrite),
    .O(\Mram_regFile161/SPO )
  );
endmodule

module Clk_gen (
  CLK_IN1, RESET, CLK_OUT1, LOCKED
);
  input CLK_IN1;
  input RESET;
  output CLK_OUT1;
  output LOCKED;
  wire clkin1;
  wire clk0;
  wire clkfx;
  wire clkfb;
  wire N1;
  wire NLW_dcm_sp_inst_CLK2X180_UNCONNECTED;
  wire NLW_dcm_sp_inst_CLK2X_UNCONNECTED;
  wire NLW_dcm_sp_inst_CLK180_UNCONNECTED;
  wire NLW_dcm_sp_inst_CLK270_UNCONNECTED;
  wire NLW_dcm_sp_inst_CLKFX180_UNCONNECTED;
  wire NLW_dcm_sp_inst_CLKDV_UNCONNECTED;
  wire NLW_dcm_sp_inst_PSDONE_UNCONNECTED;
  wire NLW_dcm_sp_inst_CLK90_UNCONNECTED;
  wire \NLW_dcm_sp_inst_STATUS[7]_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS[6]_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS[5]_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS[4]_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS[3]_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS[2]_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS[1]_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS[0]_UNCONNECTED ;
  X_ZERO   XST_GND (
    .O(N1)
  );
  X_CKBUF   clkin1_buf (
    .I(CLK_IN1),
    .O(clkin1)
  );
  X_DCM_SP #(
    .CLKIN_DIVIDE_BY_2 ( "FALSE" ),
    .CLKOUT_PHASE_SHIFT ( "NONE" ),
    .CLK_FEEDBACK ( "1X" ),
    .DESKEW_ADJUST ( "SYSTEM_SYNCHRONOUS" ),
    .DFS_FREQUENCY_MODE ( "LOW" ),
    .DLL_FREQUENCY_MODE ( "LOW" ),
    .DSS_MODE ( "NONE" ),
    .DUTY_CYCLE_CORRECTION ( "TRUE" ),
    .FACTORY_JF ( 16'h0000 ),
    .STARTUP_WAIT ( "FALSE" ),
    .CLKFX_DIVIDE ( 25 ),
    .CLKFX_MULTIPLY ( 8 ),
    .PHASE_SHIFT ( 0 ),
    .CLKDV_DIVIDE ( 2.000000 ),
    .CLKIN_PERIOD ( 10.000000 ))
  dcm_sp_inst (
    .CLK2X180(NLW_dcm_sp_inst_CLK2X180_UNCONNECTED),
    .PSCLK(N1),
    .CLK2X(NLW_dcm_sp_inst_CLK2X_UNCONNECTED),
    .CLKFX(clkfx),
    .CLK180(NLW_dcm_sp_inst_CLK180_UNCONNECTED),
    .CLK270(NLW_dcm_sp_inst_CLK270_UNCONNECTED),
    .RST(RESET),
    .PSINCDEC(N1),
    .CLKIN(clkin1),
    .CLKFB(clkfb),
    .PSEN(N1),
    .CLK0(clk0),
    .CLKFX180(NLW_dcm_sp_inst_CLKFX180_UNCONNECTED),
    .CLKDV(NLW_dcm_sp_inst_CLKDV_UNCONNECTED),
    .PSDONE(NLW_dcm_sp_inst_PSDONE_UNCONNECTED),
    .CLK90(NLW_dcm_sp_inst_CLK90_UNCONNECTED),
    .LOCKED(LOCKED),
    .DSSEN(N1),
    .STATUS({\NLW_dcm_sp_inst_STATUS[7]_UNCONNECTED , \NLW_dcm_sp_inst_STATUS[6]_UNCONNECTED , \NLW_dcm_sp_inst_STATUS[5]_UNCONNECTED , 
\NLW_dcm_sp_inst_STATUS[4]_UNCONNECTED , \NLW_dcm_sp_inst_STATUS[3]_UNCONNECTED , \NLW_dcm_sp_inst_STATUS[2]_UNCONNECTED , 
\NLW_dcm_sp_inst_STATUS[1]_UNCONNECTED , \NLW_dcm_sp_inst_STATUS[0]_UNCONNECTED })
  );
  X_CKBUF   clkf_buf (
    .O(clkfb),
    .I(clk0)
  );
  X_CKBUF   clkout1_buf (
    .O(CLK_OUT1),
    .I(clkfx)
  );
  X_IPAD #(
    .LOC ( "V10" ))
  ClkIn (
    .PAD(CLK_IN1)
  );
endmodule

module Top (
  ClkIn, Rst, Switch, Led
);
  input ClkIn;
  input Rst;
  input [7 : 0] Switch;
  output [7 : 0] Led;
  wire Rst_IBUF_782;
  wire Clk;
  wire Zero;
  wire \PCRes[31]_PCJump[31]_mux_16_OUT<9> ;
  wire \PCRes[31]_PCJump[31]_mux_16_OUT<8> ;
  wire \PCRes[31]_PCJump[31]_mux_16_OUT<7> ;
  wire \PCRes[31]_PCJump[31]_mux_16_OUT<6> ;
  wire \PCRes[31]_PCJump[31]_mux_16_OUT<5> ;
  wire \PCRes[31]_PCJump[31]_mux_16_OUT<4> ;
  wire \PCRes[31]_PCJump[31]_mux_16_OUT<3> ;
  wire \PCRes[31]_PCJump[31]_mux_16_OUT<2> ;
  wire RegDst;
  wire ALUSrc;
  wire MemToReg;
  wire RegWrite;
  wire MemWrite;
  wire Branch;
  wire Jump;
  wire \InstSignExt[14] ;
  wire \InstSignExt[13] ;
  wire \InstSignExt[12] ;
  wire \InstSignExt[11] ;
  wire \InstSignExt[7] ;
  wire \InstSignExt[6] ;
  wire \InstSignExt[5] ;
  wire \InstSignExt[4] ;
  wire \InstSignExt[3] ;
  wire \InstSignExt[2] ;
  wire \InstSignExt[1] ;
  wire \InstSignExt[0] ;
  wire N0;
  wire \Madd_PCPlus4_cy<3>_rt_1102 ;
  wire \Madd_PCPlus4_cy<4>_rt_1103 ;
  wire \Madd_PCPlus4_cy<5>_rt_1104 ;
  wire \Madd_PCPlus4_cy<6>_rt_1105 ;
  wire \Madd_PCPlus4_cy<7>_rt_1106 ;
  wire \Madd_PCPlus4_cy<8>_rt_1107 ;
  wire \Madd_PCPlus4_xor<9>_rt_1108 ;
  wire \Switch<7>_IBUF_1117 ;
  wire \Switch<6>_IBUF_1118 ;
  wire \Switch<5>_IBUF_1119 ;
  wire \Switch<4>_IBUF_1120 ;
  wire \Switch<3>_IBUF_1121 ;
  wire \Switch<2>_IBUF_1122 ;
  wire \Switch<1>_IBUF_1123 ;
  wire \Switch<0>_IBUF_1124 ;
  wire \NLW_SignExtern_Data<31>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<30>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<29>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<28>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<27>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<26>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<25>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<24>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<23>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<22>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<21>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<20>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<19>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<18>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<17>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<16>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<15>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<10>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<9>_UNCONNECTED ;
  wire \NLW_SignExtern_Data<8>_UNCONNECTED ;
  wire NLW_Ctr_MemRead_UNCONNECTED;
  wire \NLW_IMemory_ImemRdAddr<29>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<28>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<27>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<26>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<25>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<24>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<23>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<22>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<21>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<20>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<19>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<18>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<17>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<16>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<15>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<14>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<13>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<12>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<11>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<10>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<9>_UNCONNECTED ;
  wire \NLW_IMemory_ImemRdAddr<8>_UNCONNECTED ;
  wire NLW_Clock_LOCKED_UNCONNECTED;
  wire \NlwInverterSignal_PC_2/C ;
  wire VCC;
  wire GND;
  wire \NlwInverterSignal_PC_3/C ;
  wire \NlwInverterSignal_PC_4/C ;
  wire \NlwInverterSignal_PC_5/C ;
  wire \NlwInverterSignal_PC_6/C ;
  wire \NlwInverterSignal_PC_7/C ;
  wire \NlwInverterSignal_PC_8/C ;
  wire \NlwInverterSignal_PC_9/C ;
  wire [9 : 2] PC;
  wire [31 : 0] RegARdData;
  wire [31 : 0] RegBRdData;
  wire [31 : 0] DmemRdData;
  wire [9 : 2] PCPlus4;
  wire [31 : 0] ALURes;
  wire [31 : 0] SrcB;
  wire [31 : 0] RegWrData;
  wire [9 : 2] PCBranch;
  wire [31 : 0] Instruction;
  wire [4 : 0] RegWrAddr;
  wire [3 : 0] ALUCtr;
  wire [2 : 2] Madd_PCPlus4_lut;
  wire [8 : 2] Madd_PCPlus4_cy;
  wire [9 : 2] Madd_PCBranch_lut;
  wire [8 : 2] Madd_PCBranch_cy;
  X_ONE   XST_VCC (
    .O(N0)
  );
  X_ZERO   XST_GND (
    .O(RegWrAddr[4])
  );
  X_FF #(
    .INIT ( 1'b0 ))
  PC_2 (
    .CLK(\NlwInverterSignal_PC_2/C ),
    .RST(Rst_IBUF_782),
    .I(\PCRes[31]_PCJump[31]_mux_16_OUT<2> ),
    .O(PC[2]),
    .CE(VCC),
    .SET(GND)
  );
  X_FF #(
    .INIT ( 1'b0 ))
  PC_3 (
    .CLK(\NlwInverterSignal_PC_3/C ),
    .RST(Rst_IBUF_782),
    .I(\PCRes[31]_PCJump[31]_mux_16_OUT<3> ),
    .O(PC[3]),
    .CE(VCC),
    .SET(GND)
  );
  X_FF #(
    .INIT ( 1'b0 ))
  PC_4 (
    .CLK(\NlwInverterSignal_PC_4/C ),
    .RST(Rst_IBUF_782),
    .I(\PCRes[31]_PCJump[31]_mux_16_OUT<4> ),
    .O(PC[4]),
    .CE(VCC),
    .SET(GND)
  );
  X_FF #(
    .INIT ( 1'b0 ))
  PC_5 (
    .CLK(\NlwInverterSignal_PC_5/C ),
    .RST(Rst_IBUF_782),
    .I(\PCRes[31]_PCJump[31]_mux_16_OUT<5> ),
    .O(PC[5]),
    .CE(VCC),
    .SET(GND)
  );
  X_FF #(
    .INIT ( 1'b0 ))
  PC_6 (
    .CLK(\NlwInverterSignal_PC_6/C ),
    .RST(Rst_IBUF_782),
    .I(\PCRes[31]_PCJump[31]_mux_16_OUT<6> ),
    .O(PC[6]),
    .CE(VCC),
    .SET(GND)
  );
  X_FF #(
    .INIT ( 1'b0 ))
  PC_7 (
    .CLK(\NlwInverterSignal_PC_7/C ),
    .RST(Rst_IBUF_782),
    .I(\PCRes[31]_PCJump[31]_mux_16_OUT<7> ),
    .O(PC[7]),
    .CE(VCC),
    .SET(GND)
  );
  X_FF #(
    .INIT ( 1'b0 ))
  PC_8 (
    .CLK(\NlwInverterSignal_PC_8/C ),
    .RST(Rst_IBUF_782),
    .I(\PCRes[31]_PCJump[31]_mux_16_OUT<8> ),
    .O(PC[8]),
    .CE(VCC),
    .SET(GND)
  );
  X_FF #(
    .INIT ( 1'b0 ))
  PC_9 (
    .CLK(\NlwInverterSignal_PC_9/C ),
    .RST(Rst_IBUF_782),
    .I(\PCRes[31]_PCJump[31]_mux_16_OUT<9> ),
    .O(PC[9]),
    .CE(VCC),
    .SET(GND)
  );
  X_MUX2   \Madd_PCPlus4_cy<2>  (
    .IB(RegWrAddr[4]),
    .IA(N0),
    .SEL(Madd_PCPlus4_lut[2]),
    .O(Madd_PCPlus4_cy[2])
  );
  X_XOR2   \Madd_PCPlus4_xor<2>  (
    .I0(RegWrAddr[4]),
    .I1(Madd_PCPlus4_lut[2]),
    .O(PCPlus4[2])
  );
  X_MUX2   \Madd_PCPlus4_cy<3>  (
    .IB(Madd_PCPlus4_cy[2]),
    .IA(RegWrAddr[4]),
    .SEL(\Madd_PCPlus4_cy<3>_rt_1102 ),
    .O(Madd_PCPlus4_cy[3])
  );
  X_XOR2   \Madd_PCPlus4_xor<3>  (
    .I0(Madd_PCPlus4_cy[2]),
    .I1(\Madd_PCPlus4_cy<3>_rt_1102 ),
    .O(PCPlus4[3])
  );
  X_MUX2   \Madd_PCPlus4_cy<4>  (
    .IB(Madd_PCPlus4_cy[3]),
    .IA(RegWrAddr[4]),
    .SEL(\Madd_PCPlus4_cy<4>_rt_1103 ),
    .O(Madd_PCPlus4_cy[4])
  );
  X_XOR2   \Madd_PCPlus4_xor<4>  (
    .I0(Madd_PCPlus4_cy[3]),
    .I1(\Madd_PCPlus4_cy<4>_rt_1103 ),
    .O(PCPlus4[4])
  );
  X_MUX2   \Madd_PCPlus4_cy<5>  (
    .IB(Madd_PCPlus4_cy[4]),
    .IA(RegWrAddr[4]),
    .SEL(\Madd_PCPlus4_cy<5>_rt_1104 ),
    .O(Madd_PCPlus4_cy[5])
  );
  X_XOR2   \Madd_PCPlus4_xor<5>  (
    .I0(Madd_PCPlus4_cy[4]),
    .I1(\Madd_PCPlus4_cy<5>_rt_1104 ),
    .O(PCPlus4[5])
  );
  X_MUX2   \Madd_PCPlus4_cy<6>  (
    .IB(Madd_PCPlus4_cy[5]),
    .IA(RegWrAddr[4]),
    .SEL(\Madd_PCPlus4_cy<6>_rt_1105 ),
    .O(Madd_PCPlus4_cy[6])
  );
  X_XOR2   \Madd_PCPlus4_xor<6>  (
    .I0(Madd_PCPlus4_cy[5]),
    .I1(\Madd_PCPlus4_cy<6>_rt_1105 ),
    .O(PCPlus4[6])
  );
  X_MUX2   \Madd_PCPlus4_cy<7>  (
    .IB(Madd_PCPlus4_cy[6]),
    .IA(RegWrAddr[4]),
    .SEL(\Madd_PCPlus4_cy<7>_rt_1106 ),
    .O(Madd_PCPlus4_cy[7])
  );
  X_XOR2   \Madd_PCPlus4_xor<7>  (
    .I0(Madd_PCPlus4_cy[6]),
    .I1(\Madd_PCPlus4_cy<7>_rt_1106 ),
    .O(PCPlus4[7])
  );
  X_MUX2   \Madd_PCPlus4_cy<8>  (
    .IB(Madd_PCPlus4_cy[7]),
    .IA(RegWrAddr[4]),
    .SEL(\Madd_PCPlus4_cy<8>_rt_1107 ),
    .O(Madd_PCPlus4_cy[8])
  );
  X_XOR2   \Madd_PCPlus4_xor<8>  (
    .I0(Madd_PCPlus4_cy[7]),
    .I1(\Madd_PCPlus4_cy<8>_rt_1107 ),
    .O(PCPlus4[8])
  );
  X_XOR2   \Madd_PCPlus4_xor<9>  (
    .I0(Madd_PCPlus4_cy[8]),
    .I1(\Madd_PCPlus4_xor<9>_rt_1108 ),
    .O(PCPlus4[9])
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_PCBranch_lut<2>  (
    .ADR0(\InstSignExt[0] ),
    .ADR1(PCPlus4[2]),
    .O(Madd_PCBranch_lut[2])
  );
  X_MUX2   \Madd_PCBranch_cy<2>  (
    .IB(RegWrAddr[4]),
    .IA(\InstSignExt[0] ),
    .SEL(Madd_PCBranch_lut[2]),
    .O(Madd_PCBranch_cy[2])
  );
  X_XOR2   \Madd_PCBranch_xor<2>  (
    .I0(RegWrAddr[4]),
    .I1(Madd_PCBranch_lut[2]),
    .O(PCBranch[2])
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_PCBranch_lut<3>  (
    .ADR0(\InstSignExt[1] ),
    .ADR1(PCPlus4[3]),
    .O(Madd_PCBranch_lut[3])
  );
  X_MUX2   \Madd_PCBranch_cy<3>  (
    .IB(Madd_PCBranch_cy[2]),
    .IA(\InstSignExt[1] ),
    .SEL(Madd_PCBranch_lut[3]),
    .O(Madd_PCBranch_cy[3])
  );
  X_XOR2   \Madd_PCBranch_xor<3>  (
    .I0(Madd_PCBranch_cy[2]),
    .I1(Madd_PCBranch_lut[3]),
    .O(PCBranch[3])
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_PCBranch_lut<4>  (
    .ADR0(\InstSignExt[2] ),
    .ADR1(PCPlus4[4]),
    .O(Madd_PCBranch_lut[4])
  );
  X_MUX2   \Madd_PCBranch_cy<4>  (
    .IB(Madd_PCBranch_cy[3]),
    .IA(\InstSignExt[2] ),
    .SEL(Madd_PCBranch_lut[4]),
    .O(Madd_PCBranch_cy[4])
  );
  X_XOR2   \Madd_PCBranch_xor<4>  (
    .I0(Madd_PCBranch_cy[3]),
    .I1(Madd_PCBranch_lut[4]),
    .O(PCBranch[4])
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_PCBranch_lut<5>  (
    .ADR0(\InstSignExt[3] ),
    .ADR1(PCPlus4[5]),
    .O(Madd_PCBranch_lut[5])
  );
  X_MUX2   \Madd_PCBranch_cy<5>  (
    .IB(Madd_PCBranch_cy[4]),
    .IA(\InstSignExt[3] ),
    .SEL(Madd_PCBranch_lut[5]),
    .O(Madd_PCBranch_cy[5])
  );
  X_XOR2   \Madd_PCBranch_xor<5>  (
    .I0(Madd_PCBranch_cy[4]),
    .I1(Madd_PCBranch_lut[5]),
    .O(PCBranch[5])
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_PCBranch_lut<6>  (
    .ADR0(\InstSignExt[4] ),
    .ADR1(PCPlus4[6]),
    .O(Madd_PCBranch_lut[6])
  );
  X_MUX2   \Madd_PCBranch_cy<6>  (
    .IB(Madd_PCBranch_cy[5]),
    .IA(\InstSignExt[4] ),
    .SEL(Madd_PCBranch_lut[6]),
    .O(Madd_PCBranch_cy[6])
  );
  X_XOR2   \Madd_PCBranch_xor<6>  (
    .I0(Madd_PCBranch_cy[5]),
    .I1(Madd_PCBranch_lut[6]),
    .O(PCBranch[6])
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_PCBranch_lut<7>  (
    .ADR0(\InstSignExt[5] ),
    .ADR1(PCPlus4[7]),
    .O(Madd_PCBranch_lut[7])
  );
  X_MUX2   \Madd_PCBranch_cy<7>  (
    .IB(Madd_PCBranch_cy[6]),
    .IA(\InstSignExt[5] ),
    .SEL(Madd_PCBranch_lut[7]),
    .O(Madd_PCBranch_cy[7])
  );
  X_XOR2   \Madd_PCBranch_xor<7>  (
    .I0(Madd_PCBranch_cy[6]),
    .I1(Madd_PCBranch_lut[7]),
    .O(PCBranch[7])
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_PCBranch_lut<8>  (
    .ADR0(\InstSignExt[6] ),
    .ADR1(PCPlus4[8]),
    .O(Madd_PCBranch_lut[8])
  );
  X_MUX2   \Madd_PCBranch_cy<8>  (
    .IB(Madd_PCBranch_cy[7]),
    .IA(\InstSignExt[6] ),
    .SEL(Madd_PCBranch_lut[8]),
    .O(Madd_PCBranch_cy[8])
  );
  X_XOR2   \Madd_PCBranch_xor<8>  (
    .I0(Madd_PCBranch_cy[7]),
    .I1(Madd_PCBranch_lut[8]),
    .O(PCBranch[8])
  );
  X_LUT2 #(
    .INIT ( 4'h6 ))
  \Madd_PCBranch_lut<9>  (
    .ADR0(\InstSignExt[7] ),
    .ADR1(PCPlus4[9]),
    .O(Madd_PCBranch_lut[9])
  );
  X_XOR2   \Madd_PCBranch_xor<9>  (
    .I0(Madd_PCBranch_cy[8]),
    .I1(Madd_PCBranch_lut[9]),
    .O(PCBranch[9])
  );
  Clk_gen   Clock (
    .CLK_IN1(ClkIn),
    .RESET(Rst_IBUF_782),
    .CLK_OUT1(Clk),
    .LOCKED(NLW_Clock_LOCKED_UNCONNECTED)
  );
  register_register   register (
    .Clk(Clk),
    .RegWrite(RegWrite),
    .RegARdAddr({Instruction[25], Instruction[24], Instruction[23], Instruction[22], Instruction[21]}),
    .RegBRdAddr({Instruction[20], Instruction[19], Instruction[18], Instruction[17], Instruction[16]}),
    .RegWrAddr({RegWrAddr[4], RegWrAddr[3], RegWrAddr[2], RegWrAddr[1], RegWrAddr[0]}),
    .RegWrData({RegWrData[31], RegWrData[30], RegWrData[29], RegWrData[28], RegWrData[27], RegWrData[26], RegWrData[25], RegWrData[24], RegWrData[23]
, RegWrData[22], RegWrData[21], RegWrData[20], RegWrData[19], RegWrData[18], RegWrData[17], RegWrData[16], RegWrData[15], RegWrData[14], RegWrData[13]
, RegWrData[12], RegWrData[11], RegWrData[10], RegWrData[9], RegWrData[8], RegWrData[7], RegWrData[6], RegWrData[5], RegWrData[4], RegWrData[3], 
RegWrData[2], RegWrData[1], RegWrData[0]}),
    .RegARdData({RegARdData[31], RegARdData[30], RegARdData[29], RegARdData[28], RegARdData[27], RegARdData[26], RegARdData[25], RegARdData[24], 
RegARdData[23], RegARdData[22], RegARdData[21], RegARdData[20], RegARdData[19], RegARdData[18], RegARdData[17], RegARdData[16], RegARdData[15], 
RegARdData[14], RegARdData[13], RegARdData[12], RegARdData[11], RegARdData[10], RegARdData[9], RegARdData[8], RegARdData[7], RegARdData[6], 
RegARdData[5], RegARdData[4], RegARdData[3], RegARdData[2], RegARdData[1], RegARdData[0]}),
    .RegBRdData({RegBRdData[31], RegBRdData[30], RegBRdData[29], RegBRdData[28], RegBRdData[27], RegBRdData[26], RegBRdData[25], RegBRdData[24], 
RegBRdData[23], RegBRdData[22], RegBRdData[21], RegBRdData[20], RegBRdData[19], RegBRdData[18], RegBRdData[17], RegBRdData[16], RegBRdData[15], 
RegBRdData[14], RegBRdData[13], RegBRdData[12], RegBRdData[11], RegBRdData[10], RegBRdData[9], RegBRdData[8], RegBRdData[7], RegBRdData[6], 
RegBRdData[5], RegBRdData[4], RegBRdData[3], RegBRdData[2], RegBRdData[1], RegBRdData[0]})
  );
  Data_memory   DMemory (
    .Clk(Clk),
    .DmemWrite(MemWrite),
    .DmemAddr({RegWrAddr[4], RegWrAddr[4], ALURes[31], ALURes[30], ALURes[29], ALURes[28], ALURes[27], ALURes[26], ALURes[25], ALURes[24], ALURes[23]
, ALURes[22], ALURes[21], ALURes[20], ALURes[19], ALURes[18], ALURes[17], ALURes[16], ALURes[15], ALURes[14], ALURes[13], ALURes[12], ALURes[11], 
ALURes[10], ALURes[9], ALURes[8], ALURes[7], ALURes[6], ALURes[5], ALURes[4], ALURes[3], ALURes[2]}),
    .DmemWrData({RegBRdData[31], RegBRdData[30], RegBRdData[29], RegBRdData[28], RegBRdData[27], RegBRdData[26], RegBRdData[25], RegBRdData[24], 
RegBRdData[23], RegBRdData[22], RegBRdData[21], RegBRdData[20], RegBRdData[19], RegBRdData[18], RegBRdData[17], RegBRdData[16], RegBRdData[15], 
RegBRdData[14], RegBRdData[13], RegBRdData[12], RegBRdData[11], RegBRdData[10], RegBRdData[9], RegBRdData[8], RegBRdData[7], RegBRdData[6], 
RegBRdData[5], RegBRdData[4], RegBRdData[3], RegBRdData[2], RegBRdData[1], RegBRdData[0]}),
    .DmemRdData({DmemRdData[31], DmemRdData[30], DmemRdData[29], DmemRdData[28], DmemRdData[27], DmemRdData[26], DmemRdData[25], DmemRdData[24], 
DmemRdData[23], DmemRdData[22], DmemRdData[21], DmemRdData[20], DmemRdData[19], DmemRdData[18], DmemRdData[17], DmemRdData[16], DmemRdData[15], 
DmemRdData[14], DmemRdData[13], DmemRdData[12], DmemRdData[11], DmemRdData[10], DmemRdData[9], DmemRdData[8], DmemRdData[7], DmemRdData[6], 
DmemRdData[5], DmemRdData[4], DmemRdData[3], DmemRdData[2], DmemRdData[1], DmemRdData[0]})
  );
  ALU_ALU   ALU (
    .Zero(Zero),
    .SrcA({RegARdData[31], RegARdData[30], RegARdData[29], RegARdData[28], RegARdData[27], RegARdData[26], RegARdData[25], RegARdData[24], 
RegARdData[23], RegARdData[22], RegARdData[21], RegARdData[20], RegARdData[19], RegARdData[18], RegARdData[17], RegARdData[16], RegARdData[15], 
RegARdData[14], RegARdData[13], RegARdData[12], RegARdData[11], RegARdData[10], RegARdData[9], RegARdData[8], RegARdData[7], RegARdData[6], 
RegARdData[5], RegARdData[4], RegARdData[3], RegARdData[2], RegARdData[1], RegARdData[0]}),
    .SrcB({SrcB[31], SrcB[30], SrcB[29], SrcB[28], SrcB[27], SrcB[26], SrcB[25], SrcB[24], SrcB[23], SrcB[22], SrcB[21], SrcB[20], SrcB[19], SrcB[18]
, SrcB[17], SrcB[16], SrcB[15], SrcB[14], SrcB[13], SrcB[12], SrcB[11], SrcB[10], SrcB[9], SrcB[8], SrcB[7], SrcB[6], SrcB[5], SrcB[4], SrcB[3], 
SrcB[2], SrcB[1], SrcB[0]}),
    .ALUCtr({ALUCtr[3], ALUCtr[2], ALUCtr[1], ALUCtr[0]}),
    .ALURes({ALURes[31], ALURes[30], ALURes[29], ALURes[28], ALURes[27], ALURes[26], ALURes[25], ALURes[24], ALURes[23], ALURes[22], ALURes[21], 
ALURes[20], ALURes[19], ALURes[18], ALURes[17], ALURes[16], ALURes[15], ALURes[14], ALURes[13], ALURes[12], ALURes[11], ALURes[10], ALURes[9], 
ALURes[8], ALURes[7], ALURes[6], ALURes[5], ALURes[4], ALURes[3], ALURes[2], ALURes[1], ALURes[0]})
  );
  Instruction_memory   IMemory (
    .ImemRdAddr({RegWrAddr[4], RegWrAddr[4], \NLW_IMemory_ImemRdAddr<29>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<28>_UNCONNECTED , 
\NLW_IMemory_ImemRdAddr<27>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<26>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<25>_UNCONNECTED , 
\NLW_IMemory_ImemRdAddr<24>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<23>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<22>_UNCONNECTED , 
\NLW_IMemory_ImemRdAddr<21>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<20>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<19>_UNCONNECTED , 
\NLW_IMemory_ImemRdAddr<18>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<17>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<16>_UNCONNECTED , 
\NLW_IMemory_ImemRdAddr<15>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<14>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<13>_UNCONNECTED , 
\NLW_IMemory_ImemRdAddr<12>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<11>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<10>_UNCONNECTED , 
\NLW_IMemory_ImemRdAddr<9>_UNCONNECTED , \NLW_IMemory_ImemRdAddr<8>_UNCONNECTED , PC[9], PC[8], PC[7], PC[6], PC[5], PC[4], PC[3], PC[2]}),
    .Instruction({Instruction[31], Instruction[30], Instruction[29], Instruction[28], Instruction[27], Instruction[26], Instruction[25], 
Instruction[24], Instruction[23], Instruction[22], Instruction[21], Instruction[20], Instruction[19], Instruction[18], Instruction[17], 
Instruction[16], Instruction[15], Instruction[14], Instruction[13], Instruction[12], Instruction[11], Instruction[10], Instruction[9], Instruction[8]
, Instruction[7], Instruction[6], Instruction[5], Instruction[4], Instruction[3], Instruction[2], Instruction[1], Instruction[0]})
  );
  Ctr_Ctr   Ctr (
    .RegDst(RegDst),
    .ALUSrc(ALUSrc),
    .MemToReg(MemToReg),
    .RegWrite(RegWrite),
    .MemWrite(MemWrite),
    .MemRead(NLW_Ctr_MemRead_UNCONNECTED),
    .Branch(Branch),
    .Jump(Jump),
    .OpCode({Instruction[31], Instruction[30], Instruction[29], Instruction[28], Instruction[27], Instruction[26]}),
    .Funct({Instruction[5], Instruction[4], Instruction[3], Instruction[2], Instruction[1], Instruction[0]}),
    .ALUControl({ALUCtr[3], ALUCtr[2], ALUCtr[1], ALUCtr[0]})
  );
  signext   SignExtern (
    .Inst({Instruction[15], Instruction[14], Instruction[13], Instruction[12], Instruction[11], Instruction[10], Instruction[9], Instruction[8], 
Instruction[7], Instruction[6], Instruction[5], Instruction[4], Instruction[3], Instruction[2], Instruction[1], Instruction[0]}),
    .Data({\NLW_SignExtern_Data<31>_UNCONNECTED , \NLW_SignExtern_Data<30>_UNCONNECTED , \NLW_SignExtern_Data<29>_UNCONNECTED , 
\NLW_SignExtern_Data<28>_UNCONNECTED , \NLW_SignExtern_Data<27>_UNCONNECTED , \NLW_SignExtern_Data<26>_UNCONNECTED , 
\NLW_SignExtern_Data<25>_UNCONNECTED , \NLW_SignExtern_Data<24>_UNCONNECTED , \NLW_SignExtern_Data<23>_UNCONNECTED , 
\NLW_SignExtern_Data<22>_UNCONNECTED , \NLW_SignExtern_Data<21>_UNCONNECTED , \NLW_SignExtern_Data<20>_UNCONNECTED , 
\NLW_SignExtern_Data<19>_UNCONNECTED , \NLW_SignExtern_Data<18>_UNCONNECTED , \NLW_SignExtern_Data<17>_UNCONNECTED , 
\NLW_SignExtern_Data<16>_UNCONNECTED , \NLW_SignExtern_Data<15>_UNCONNECTED , \InstSignExt[14] , \InstSignExt[13] , \InstSignExt[12] , 
\InstSignExt[11] , \NLW_SignExtern_Data<10>_UNCONNECTED , \NLW_SignExtern_Data<9>_UNCONNECTED , \NLW_SignExtern_Data<8>_UNCONNECTED , \InstSignExt[7] 
, \InstSignExt[6] , \InstSignExt[5] , \InstSignExt[4] , \InstSignExt[3] , \InstSignExt[2] , \InstSignExt[1] , \InstSignExt[0] })
  );
  X_LUT2 #(
    .INIT ( 4'h2 ))
  Mmux_SrcB321 (
    .ADR0(RegBRdData[9]),
    .ADR1(ALUSrc),
    .O(SrcB[9])
  );
  X_LUT2 #(
    .INIT ( 4'h2 ))
  Mmux_SrcB311 (
    .ADR0(RegBRdData[8]),
    .ADR1(ALUSrc),
    .O(SrcB[8])
  );
  X_LUT2 #(
    .INIT ( 4'h2 ))
  Mmux_SrcB301 (
    .ADR0(RegBRdData[7]),
    .ADR1(ALUSrc),
    .O(SrcB[7])
  );
  X_LUT2 #(
    .INIT ( 4'h2 ))
  Mmux_SrcB291 (
    .ADR0(RegBRdData[6]),
    .ADR1(ALUSrc),
    .O(SrcB[6])
  );
  X_LUT3 #(
    .INIT ( 8'hAC ))
  Mmux_SrcB281 (
    .ADR0(\InstSignExt[5] ),
    .ADR1(RegBRdData[5]),
    .ADR2(ALUSrc),
    .O(SrcB[5])
  );
  X_LUT2 #(
    .INIT ( 4'h2 ))
  Mmux_SrcB271 (
    .ADR0(RegBRdData[4]),
    .ADR1(ALUSrc),
    .O(SrcB[4])
  );
  X_LUT3 #(
    .INIT ( 8'hAC ))
  Mmux_SrcB261 (
    .ADR0(\InstSignExt[3] ),
    .ADR1(RegBRdData[3]),
    .ADR2(ALUSrc),
    .O(SrcB[3])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB251 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[31]),
    .O(SrcB[31])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB241 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[30]),
    .O(SrcB[30])
  );
  X_LUT3 #(
    .INIT ( 8'hAC ))
  Mmux_SrcB231 (
    .ADR0(\InstSignExt[2] ),
    .ADR1(RegBRdData[2]),
    .ADR2(ALUSrc),
    .O(SrcB[2])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB221 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[29]),
    .O(SrcB[29])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB211 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[28]),
    .O(SrcB[28])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB201 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[27]),
    .O(SrcB[27])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB191 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[26]),
    .O(SrcB[26])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB181 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[25]),
    .O(SrcB[25])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB171 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[24]),
    .O(SrcB[24])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB161 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[23]),
    .O(SrcB[23])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB151 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[22]),
    .O(SrcB[22])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB141 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[21]),
    .O(SrcB[21])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB131 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[20]),
    .O(SrcB[20])
  );
  X_LUT3 #(
    .INIT ( 8'hAC ))
  Mmux_SrcB121 (
    .ADR0(\InstSignExt[1] ),
    .ADR1(RegBRdData[1]),
    .ADR2(ALUSrc),
    .O(SrcB[1])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB111 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[19]),
    .O(SrcB[19])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB101 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[18]),
    .O(SrcB[18])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB91 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[17]),
    .O(SrcB[17])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB81 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[16]),
    .O(SrcB[16])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB71 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[15]),
    .O(SrcB[15])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_SrcB61 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[14]),
    .ADR2(\InstSignExt[14] ),
    .O(SrcB[14])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_SrcB51 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[13]),
    .ADR2(\InstSignExt[13] ),
    .O(SrcB[13])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_SrcB41 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[12]),
    .ADR2(\InstSignExt[12] ),
    .O(SrcB[12])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_SrcB31 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[11]),
    .ADR2(\InstSignExt[11] ),
    .O(SrcB[11])
  );
  X_LUT2 #(
    .INIT ( 4'h4 ))
  Mmux_SrcB21 (
    .ADR0(ALUSrc),
    .ADR1(RegBRdData[10]),
    .O(SrcB[10])
  );
  X_LUT3 #(
    .INIT ( 8'hAC ))
  Mmux_SrcB11 (
    .ADR0(\InstSignExt[0] ),
    .ADR1(RegBRdData[0]),
    .ADR2(ALUSrc),
    .O(SrcB[0])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrAddr41 (
    .ADR0(RegDst),
    .ADR1(Instruction[19]),
    .ADR2(Instruction[14]),
    .O(RegWrAddr[3])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrAddr31 (
    .ADR0(RegDst),
    .ADR1(Instruction[18]),
    .ADR2(Instruction[13]),
    .O(RegWrAddr[2])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrAddr21 (
    .ADR0(RegDst),
    .ADR1(Instruction[17]),
    .ADR2(Instruction[12]),
    .O(RegWrAddr[1])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrAddr11 (
    .ADR0(RegDst),
    .ADR1(Instruction[16]),
    .ADR2(Instruction[11]),
    .O(RegWrAddr[0])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData321 (
    .ADR0(MemToReg),
    .ADR1(ALURes[9]),
    .ADR2(DmemRdData[9]),
    .O(RegWrData[9])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData311 (
    .ADR0(MemToReg),
    .ADR1(ALURes[8]),
    .ADR2(DmemRdData[8]),
    .O(RegWrData[8])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData301 (
    .ADR0(MemToReg),
    .ADR1(ALURes[7]),
    .ADR2(DmemRdData[7]),
    .O(RegWrData[7])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData291 (
    .ADR0(MemToReg),
    .ADR1(ALURes[6]),
    .ADR2(DmemRdData[6]),
    .O(RegWrData[6])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData281 (
    .ADR0(MemToReg),
    .ADR1(ALURes[5]),
    .ADR2(DmemRdData[5]),
    .O(RegWrData[5])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData271 (
    .ADR0(MemToReg),
    .ADR1(ALURes[4]),
    .ADR2(DmemRdData[4]),
    .O(RegWrData[4])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData261 (
    .ADR0(MemToReg),
    .ADR1(ALURes[3]),
    .ADR2(DmemRdData[3]),
    .O(RegWrData[3])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData251 (
    .ADR0(MemToReg),
    .ADR1(ALURes[31]),
    .ADR2(DmemRdData[31]),
    .O(RegWrData[31])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData241 (
    .ADR0(MemToReg),
    .ADR1(ALURes[30]),
    .ADR2(DmemRdData[30]),
    .O(RegWrData[30])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData231 (
    .ADR0(MemToReg),
    .ADR1(ALURes[2]),
    .ADR2(DmemRdData[2]),
    .O(RegWrData[2])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData221 (
    .ADR0(MemToReg),
    .ADR1(ALURes[29]),
    .ADR2(DmemRdData[29]),
    .O(RegWrData[29])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData211 (
    .ADR0(MemToReg),
    .ADR1(ALURes[28]),
    .ADR2(DmemRdData[28]),
    .O(RegWrData[28])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData201 (
    .ADR0(MemToReg),
    .ADR1(ALURes[27]),
    .ADR2(DmemRdData[27]),
    .O(RegWrData[27])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData191 (
    .ADR0(MemToReg),
    .ADR1(ALURes[26]),
    .ADR2(DmemRdData[26]),
    .O(RegWrData[26])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData181 (
    .ADR0(MemToReg),
    .ADR1(ALURes[25]),
    .ADR2(DmemRdData[25]),
    .O(RegWrData[25])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData171 (
    .ADR0(MemToReg),
    .ADR1(ALURes[24]),
    .ADR2(DmemRdData[24]),
    .O(RegWrData[24])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData161 (
    .ADR0(MemToReg),
    .ADR1(ALURes[23]),
    .ADR2(DmemRdData[23]),
    .O(RegWrData[23])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData151 (
    .ADR0(MemToReg),
    .ADR1(ALURes[22]),
    .ADR2(DmemRdData[22]),
    .O(RegWrData[22])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData141 (
    .ADR0(MemToReg),
    .ADR1(ALURes[21]),
    .ADR2(DmemRdData[21]),
    .O(RegWrData[21])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData131 (
    .ADR0(MemToReg),
    .ADR1(ALURes[20]),
    .ADR2(DmemRdData[20]),
    .O(RegWrData[20])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData121 (
    .ADR0(MemToReg),
    .ADR1(ALURes[1]),
    .ADR2(DmemRdData[1]),
    .O(RegWrData[1])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData111 (
    .ADR0(MemToReg),
    .ADR1(ALURes[19]),
    .ADR2(DmemRdData[19]),
    .O(RegWrData[19])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData101 (
    .ADR0(MemToReg),
    .ADR1(ALURes[18]),
    .ADR2(DmemRdData[18]),
    .O(RegWrData[18])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData91 (
    .ADR0(MemToReg),
    .ADR1(ALURes[17]),
    .ADR2(DmemRdData[17]),
    .O(RegWrData[17])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData81 (
    .ADR0(MemToReg),
    .ADR1(ALURes[16]),
    .ADR2(DmemRdData[16]),
    .O(RegWrData[16])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData71 (
    .ADR0(MemToReg),
    .ADR1(ALURes[15]),
    .ADR2(DmemRdData[15]),
    .O(RegWrData[15])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData61 (
    .ADR0(MemToReg),
    .ADR1(ALURes[14]),
    .ADR2(DmemRdData[14]),
    .O(RegWrData[14])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData51 (
    .ADR0(MemToReg),
    .ADR1(ALURes[13]),
    .ADR2(DmemRdData[13]),
    .O(RegWrData[13])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData41 (
    .ADR0(MemToReg),
    .ADR1(ALURes[12]),
    .ADR2(DmemRdData[12]),
    .O(RegWrData[12])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData31 (
    .ADR0(MemToReg),
    .ADR1(ALURes[11]),
    .ADR2(DmemRdData[11]),
    .O(RegWrData[11])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData21 (
    .ADR0(MemToReg),
    .ADR1(ALURes[10]),
    .ADR2(DmemRdData[10]),
    .O(RegWrData[10])
  );
  X_LUT3 #(
    .INIT ( 8'hE4 ))
  Mmux_RegWrData11 (
    .ADR0(MemToReg),
    .ADR1(ALURes[0]),
    .ADR2(DmemRdData[0]),
    .O(RegWrData[0])
  );
  X_LUT6 #(
    .INIT ( 64'hFEEEAEEE54440444 ))
  \Mmux_PCRes[31]_PCJump[31]_mux_16_OUT231  (
    .ADR0(Jump),
    .ADR1(PCPlus4[2]),
    .ADR2(Branch),
    .ADR3(Zero),
    .ADR4(PCBranch[2]),
    .ADR5(Instruction[0]),
    .O(\PCRes[31]_PCJump[31]_mux_16_OUT<2> )
  );
  X_LUT6 #(
    .INIT ( 64'hFEEEAEEE54440444 ))
  \Mmux_PCRes[31]_PCJump[31]_mux_16_OUT261  (
    .ADR0(Jump),
    .ADR1(PCPlus4[3]),
    .ADR2(Branch),
    .ADR3(Zero),
    .ADR4(PCBranch[3]),
    .ADR5(Instruction[1]),
    .O(\PCRes[31]_PCJump[31]_mux_16_OUT<3> )
  );
  X_LUT6 #(
    .INIT ( 64'hFEEEAEEE54440444 ))
  \Mmux_PCRes[31]_PCJump[31]_mux_16_OUT271  (
    .ADR0(Jump),
    .ADR1(PCPlus4[4]),
    .ADR2(Branch),
    .ADR3(Zero),
    .ADR4(PCBranch[4]),
    .ADR5(Instruction[2]),
    .O(\PCRes[31]_PCJump[31]_mux_16_OUT<4> )
  );
  X_LUT6 #(
    .INIT ( 64'hFEEEAEEE54440444 ))
  \Mmux_PCRes[31]_PCJump[31]_mux_16_OUT281  (
    .ADR0(Jump),
    .ADR1(PCPlus4[5]),
    .ADR2(Branch),
    .ADR3(Zero),
    .ADR4(PCBranch[5]),
    .ADR5(Instruction[3]),
    .O(\PCRes[31]_PCJump[31]_mux_16_OUT<5> )
  );
  X_LUT5 #(
    .INIT ( 32'h54440444 ))
  \Mmux_PCRes[31]_PCJump[31]_mux_16_OUT291  (
    .ADR0(Jump),
    .ADR1(PCPlus4[6]),
    .ADR2(Branch),
    .ADR3(Zero),
    .ADR4(PCBranch[6]),
    .O(\PCRes[31]_PCJump[31]_mux_16_OUT<6> )
  );
  X_LUT6 #(
    .INIT ( 64'hFEEEAEEE54440444 ))
  \Mmux_PCRes[31]_PCJump[31]_mux_16_OUT301  (
    .ADR0(Jump),
    .ADR1(PCPlus4[7]),
    .ADR2(Branch),
    .ADR3(Zero),
    .ADR4(PCBranch[7]),
    .ADR5(Instruction[5]),
    .O(\PCRes[31]_PCJump[31]_mux_16_OUT<7> )
  );
  X_LUT5 #(
    .INIT ( 32'h54440444 ))
  \Mmux_PCRes[31]_PCJump[31]_mux_16_OUT311  (
    .ADR0(Jump),
    .ADR1(PCPlus4[8]),
    .ADR2(Branch),
    .ADR3(Zero),
    .ADR4(PCBranch[8]),
    .O(\PCRes[31]_PCJump[31]_mux_16_OUT<8> )
  );
  X_LUT5 #(
    .INIT ( 32'h54440444 ))
  \Mmux_PCRes[31]_PCJump[31]_mux_16_OUT321  (
    .ADR0(Jump),
    .ADR1(PCPlus4[9]),
    .ADR2(Branch),
    .ADR3(Zero),
    .ADR4(PCBranch[9]),
    .O(\PCRes[31]_PCJump[31]_mux_16_OUT<9> )
  );
  X_BUF   Rst_IBUF (
    .I(Rst),
    .O(Rst_IBUF_782)
  );
  X_LUT2 #(
    .INIT ( 4'hA ))
  \Madd_PCPlus4_cy<3>_rt  (
    .ADR0(PC[3]),
    .O(\Madd_PCPlus4_cy<3>_rt_1102 ),
    .ADR1(GND)
  );
  X_LUT2 #(
    .INIT ( 4'hA ))
  \Madd_PCPlus4_cy<4>_rt  (
    .ADR0(PC[4]),
    .O(\Madd_PCPlus4_cy<4>_rt_1103 ),
    .ADR1(GND)
  );
  X_LUT2 #(
    .INIT ( 4'hA ))
  \Madd_PCPlus4_cy<5>_rt  (
    .ADR0(PC[5]),
    .O(\Madd_PCPlus4_cy<5>_rt_1104 ),
    .ADR1(GND)
  );
  X_LUT2 #(
    .INIT ( 4'hA ))
  \Madd_PCPlus4_cy<6>_rt  (
    .ADR0(PC[6]),
    .O(\Madd_PCPlus4_cy<6>_rt_1105 ),
    .ADR1(GND)
  );
  X_LUT2 #(
    .INIT ( 4'hA ))
  \Madd_PCPlus4_cy<7>_rt  (
    .ADR0(PC[7]),
    .O(\Madd_PCPlus4_cy<7>_rt_1106 ),
    .ADR1(GND)
  );
  X_LUT2 #(
    .INIT ( 4'hA ))
  \Madd_PCPlus4_cy<8>_rt  (
    .ADR0(PC[8]),
    .O(\Madd_PCPlus4_cy<8>_rt_1107 ),
    .ADR1(GND)
  );
  X_LUT2 #(
    .INIT ( 4'hA ))
  \Madd_PCPlus4_xor<9>_rt  (
    .ADR0(PC[9]),
    .O(\Madd_PCPlus4_xor<9>_rt_1108 ),
    .ADR1(GND)
  );
  X_INV   \Madd_PCPlus4_lut<2>_INV_0  (
    .I(PC[2]),
    .O(Madd_PCPlus4_lut[2])
  );
  X_IPAD #(
    .LOC ( "B8" ))
  Rst_635 (
    .PAD(Rst)
  );
  X_OPAD #(
    .LOC ( "T11" ))
  \Led<7>  (
    .PAD(Led[7])
  );
  X_OPAD #(
    .LOC ( "R11" ))
  \Led<6>  (
    .PAD(Led[6])
  );
  X_OPAD #(
    .LOC ( "N11" ))
  \Led<5>  (
    .PAD(Led[5])
  );
  X_OPAD #(
    .LOC ( "M11" ))
  \Led<4>  (
    .PAD(Led[4])
  );
  X_OPAD #(
    .LOC ( "V15" ))
  \Led<3>  (
    .PAD(Led[3])
  );
  X_OPAD #(
    .LOC ( "U15" ))
  \Led<2>  (
    .PAD(Led[2])
  );
  X_OPAD #(
    .LOC ( "V16" ))
  \Led<1>  (
    .PAD(Led[1])
  );
  X_OPAD #(
    .LOC ( "U16" ))
  \Led<0>  (
    .PAD(Led[0])
  );
  X_IPAD #(
    .LOC ( "T5" ))
  \Switch<7>  (
    .PAD(Switch[7])
  );
  X_BUF   \Switch<7>_IBUF  (
    .I(Switch[7]),
    .O(\Switch<7>_IBUF_1117 )
  );
  X_IPAD #(
    .LOC ( "V8" ))
  \Switch<6>  (
    .PAD(Switch[6])
  );
  X_BUF   \Switch<6>_IBUF  (
    .I(Switch[6]),
    .O(\Switch<6>_IBUF_1118 )
  );
  X_IPAD #(
    .LOC ( "U8" ))
  \Switch<5>  (
    .PAD(Switch[5])
  );
  X_BUF   \Switch<5>_IBUF  (
    .I(Switch[5]),
    .O(\Switch<5>_IBUF_1119 )
  );
  X_IPAD #(
    .LOC ( "N8" ))
  \Switch<4>  (
    .PAD(Switch[4])
  );
  X_BUF   \Switch<4>_IBUF  (
    .I(Switch[4]),
    .O(\Switch<4>_IBUF_1120 )
  );
  X_IPAD #(
    .LOC ( "M8" ))
  \Switch<3>  (
    .PAD(Switch[3])
  );
  X_BUF   \Switch<3>_IBUF  (
    .I(Switch[3]),
    .O(\Switch<3>_IBUF_1121 )
  );
  X_IPAD #(
    .LOC ( "V9" ))
  \Switch<2>  (
    .PAD(Switch[2])
  );
  X_BUF   \Switch<2>_IBUF  (
    .I(Switch[2]),
    .O(\Switch<2>_IBUF_1122 )
  );
  X_IPAD #(
    .LOC ( "T9" ))
  \Switch<1>  (
    .PAD(Switch[1])
  );
  X_BUF   \Switch<1>_IBUF  (
    .I(Switch[1]),
    .O(\Switch<1>_IBUF_1123 )
  );
  X_IPAD #(
    .LOC ( "T10" ))
  \Switch<0>  (
    .PAD(Switch[0])
  );
  X_BUF   \Switch<0>_IBUF  (
    .I(Switch[0]),
    .O(\Switch<0>_IBUF_1124 )
  );
  X_PD   \Led<7>_PULLDOWN  (
    .O(Led[7])
  );
  X_PD   \Led<6>_PULLDOWN  (
    .O(Led[6])
  );
  X_PD   \Led<5>_PULLDOWN  (
    .O(Led[5])
  );
  X_PD   \Led<4>_PULLDOWN  (
    .O(Led[4])
  );
  X_PD   \Led<3>_PULLDOWN  (
    .O(Led[3])
  );
  X_PD   \Led<2>_PULLDOWN  (
    .O(Led[2])
  );
  X_PD   \Led<1>_PULLDOWN  (
    .O(Led[1])
  );
  X_PD   \Led<0>_PULLDOWN  (
    .O(Led[0])
  );
  X_OBUF   Led_7_OBUF (
    .I(PC[9]),
    .O(Led[7])
  );
  X_OBUF   Led_6_OBUF (
    .I(PC[8]),
    .O(Led[6])
  );
  X_OBUF   Led_5_OBUF (
    .I(PC[7]),
    .O(Led[5])
  );
  X_OBUF   Led_4_OBUF (
    .I(PC[6]),
    .O(Led[4])
  );
  X_OBUF   Led_3_OBUF (
    .I(PC[5]),
    .O(Led[3])
  );
  X_OBUF   Led_2_OBUF (
    .I(PC[4]),
    .O(Led[2])
  );
  X_OBUF   Led_1_OBUF (
    .I(PC[3]),
    .O(Led[1])
  );
  X_OBUF   Led_0_OBUF (
    .I(PC[2]),
    .O(Led[0])
  );
  X_INV   \NlwInverterBlock_PC_2/C  (
    .I(Clk),
    .O(\NlwInverterSignal_PC_2/C )
  );
  X_ONE   NlwBlock_Top_VCC (
    .O(VCC)
  );
  X_ZERO   NlwBlock_Top_GND (
    .O(GND)
  );
  X_INV   \NlwInverterBlock_PC_3/C  (
    .I(Clk),
    .O(\NlwInverterSignal_PC_3/C )
  );
  X_INV   \NlwInverterBlock_PC_4/C  (
    .I(Clk),
    .O(\NlwInverterSignal_PC_4/C )
  );
  X_INV   \NlwInverterBlock_PC_5/C  (
    .I(Clk),
    .O(\NlwInverterSignal_PC_5/C )
  );
  X_INV   \NlwInverterBlock_PC_6/C  (
    .I(Clk),
    .O(\NlwInverterSignal_PC_6/C )
  );
  X_INV   \NlwInverterBlock_PC_7/C  (
    .I(Clk),
    .O(\NlwInverterSignal_PC_7/C )
  );
  X_INV   \NlwInverterBlock_PC_8/C  (
    .I(Clk),
    .O(\NlwInverterSignal_PC_8/C )
  );
  X_INV   \NlwInverterBlock_PC_9/C  (
    .I(Clk),
    .O(\NlwInverterSignal_PC_9/C )
  );
endmodule


`ifndef GLBL
`define GLBL

`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;

    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule

`endif


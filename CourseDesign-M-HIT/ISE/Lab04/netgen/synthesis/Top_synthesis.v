////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: P.20131013
//  \   \         Application: netgen
//  /   /         Filename: Top_synthesis.v
// /___/   /\     Timestamp: Sat Jun 30 20:28:18 2018
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim Top.ngc Top_synthesis.v 
// Device	: xc6slx16-3-csg324
// Input file	: Top.ngc
// Output file	: F:\ISE\Lab04\netgen\synthesis\Top_synthesis.v
// # of Modules	: 2
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
  wire \NLW_dcm_sp_inst_STATUS<7>_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS<6>_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS<5>_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS<4>_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS<3>_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS<2>_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS<1>_UNCONNECTED ;
  wire \NLW_dcm_sp_inst_STATUS<0>_UNCONNECTED ;
  GND   XST_GND (
    .G(N1)
  );
  IBUFG #(
    .CAPACITANCE ( "DONT_CARE" ),
    .IBUF_DELAY_VALUE ( "0" ),
    .IBUF_LOW_PWR ( "TRUE" ),
    .IOSTANDARD ( "DEFAULT" ))
  clkin1_buf (
    .I(CLK_IN1),
    .O(clkin1)
  );
  DCM_SP #(
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
    .STATUS({\NLW_dcm_sp_inst_STATUS<7>_UNCONNECTED , \NLW_dcm_sp_inst_STATUS<6>_UNCONNECTED , \NLW_dcm_sp_inst_STATUS<5>_UNCONNECTED , 
\NLW_dcm_sp_inst_STATUS<4>_UNCONNECTED , \NLW_dcm_sp_inst_STATUS<3>_UNCONNECTED , \NLW_dcm_sp_inst_STATUS<2>_UNCONNECTED , 
\NLW_dcm_sp_inst_STATUS<1>_UNCONNECTED , \NLW_dcm_sp_inst_STATUS<0>_UNCONNECTED })
  );
  BUFG   clkf_buf (
    .O(clkfb),
    .I(clk0)
  );
  BUFG   clkout1_buf (
    .O(CLK_OUT1),
    .I(clkfx)
  );
endmodule

module Top (
  ClkIn, Rst, switch, led
);
  input ClkIn;
  input Rst;
  input [7 : 0] switch;
  output [7 : 0] led;
  wire Rst_IBUF_10;
  wire NLW_Clock_CLK_OUT1_UNCONNECTED;
  wire NLW_Clock_LOCKED_UNCONNECTED;
  Clk_gen   Clock (
    .CLK_IN1(ClkIn),
    .RESET(Rst_IBUF_10),
    .CLK_OUT1(NLW_Clock_CLK_OUT1_UNCONNECTED),
    .LOCKED(NLW_Clock_LOCKED_UNCONNECTED)
  );
  IBUF   Rst_IBUF (
    .I(Rst),
    .O(Rst_IBUF_10)
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


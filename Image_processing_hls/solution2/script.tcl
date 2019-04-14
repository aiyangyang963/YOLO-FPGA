############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Lab_10_Conv2d
set_top doImgProc
add_files Lab_10_Conv2d/core.cpp
add_files Lab_10_Conv2d/core.h
add_files -tb Lab_10_Conv2d/TestUtils.cpp -cflags "-Wno-unknown-pragmas"
add_files -tb Lab_10_Conv2d/TestUtils.h -cflags "-Wno-unknown-pragmas"
add_files -tb Lab_10_Conv2d/test_core.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution2"
set_part {xc7z020clg400-1} -tool vivado
create_clock -period 10 -name default
#source "./Lab_10_Conv2d/solution2/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -rtl verilog -format ip_catalog

# ==============================================================
# File generated on Thu Apr 11 00:03:36 EDT 2019
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../test_core.cpp -cflags { -Wno-unknown-pragmas}
add_files -tb ../TestUtils.h -cflags { -Wno-unknown-pragmas}
add_files -tb ../TestUtils.cpp -cflags { -Wno-unknown-pragmas}
add_files Lab_10_Conv2d/core.h
add_files Lab_10_Conv2d/core.cpp
set_part xc7z020clg400-1
create_clock -name default -period 10

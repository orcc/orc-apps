Digital predistortion filter

Authors: 
Jani Boutellier (jani.boutellier@ee.oulu.fi)
Department of Computer Science and Engineering
University of Oulu, Finland

Based on the C code implementation written
by Amanullah Ghazi. Related publications: "Mobile 
Transmitter Digital Predistortion:  Feasibility Analysis, 
Algorithms and Design Exploration", Asilomar 2013 and
"Joint Mitigation of Power Amplifier and I/Q Modulator 
Impairment in Broadband Direct Conversion Transmitters"
by Anttila, L.; Handel, P. and Valkama, M. IEEE Transactions 
on Microwave Theory and Techniques 58(4), 2010

Description:
This project contains RVC-CAL descriptions of a parallel
Hammerstein digital predistortion filter with 5 FIR filter
branches, each with 5 taps.
The 'lib'-folder contains native function bodies, which
are required when the filter is realized as C code and
compiled for a Linux workstation. Native functions are provided
in three files: linux.c, linuxbin.c and linuxmulti.c of which
the first reads and writes text files and the latter binary files.
The 'lib' folder has also an input sample sequence and
a reference output signal both in text and binary format.
The FIR filter and the local oscillator
leakage compensation coefficients are hardcoded into the
RVC-CAL sources in this implementation.
The package contains two descriptions of the same filter:
lowlevel_dpd is a hardware-friendly low-level implementation
whereas filter_dpd is a software-friendly version.

Compilation:
1. Generate Top_DPD.xdf with the Orcc C backend to a folder of
   preference that we will call <C_output_dir>
   * if you use small input files, such is the ones given in 'lib'
     remember to make the network FIFO size small (< 64) in order
     to see some output
   * if filter_dpd_multi is used, indicate the FIFO size used in
     the constants.cal file (default value 32). IMPORTANT: If you
     change this value remember to clean and rebuild the project
     before code generation!
2. Copy either linux.c or linuxbin.c to <C_output_dir>/src and add the
   file name to the filenames list in <C_output_dir>/src/CMakeLists.txt
3. If linuxbin.c is used, add the following entry to
   <C_output_dir>/CMakeLists.txt after "set(extra_libraries)":
   set(CMAKE_C_FLAGS "-O3 -DLENGTH=1000 -DFIFO_SIZE=32")
   where LENGTH gives the number of input samples in the binary input file and
   FIFO_SIZE indicates the FIFO size that was used in Orcc code generation
4. Compile:
   $ (in <C_output_dir>) cd build && cmake .. && make && cd ..
5. Copy either binary of textual input data files from
   orc-apps/Predistortion/lib/input_signals to <C_output_dir>
6. Run (in <C_output_dir>):
   bin/Top_DPD
   * Optionally the filter can be mapped to multiple cores with the -c or -m
   flags. See the detailed instructions by bin/Top_DPD -help

More information:
* In the folder orc-apps/Predistortion/lib/tools there are two software tools
  bindiff.c and fgen.c that can be used to generate random binary floating
  point data and compare two binary floating point files for differences

Changelog:
- initial version 16/12/2013
- new compilation instructions 14/07/2015
- multi-token design added 15/07/2015

Known issues:
- the lowlevel_dpd implementation has some structural illogicalities
  (ports of Polynomial network) due to limitations of the Orcc compiler
- lowlevel_dpd produces output that very slightly differs from the
  reference output. This is due to differences in rounding.

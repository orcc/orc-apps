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
compiled for a Linux workstation.
The same folder has also an input sample sequence and
a reference output signal.
The FIR filter and the local oscillator
leakage compensation coefficients are hardcoded into the
RVC-CAL sources in this implementation.
The package contains two descriptions of the same filter:
lowlevel_dpd is a hardware-friendly low-level implementation
whereas filter_dpd is a software-friendly version.

Compilation:
Standard GCC compilation with the following
- headers:      <output_folder>/libs/orcc/include
                <output_folder>/libs/roxml/include
- source files: <orc-apps-folder>/Predistortion/lib/native/linux.c
				<output_folder>/libs/orcc/src/util.c 
				<output_folder>/libs/orcc/src/serialize.c 
				<output_folder>/libs/orcc/src/dataflow.c 
				<output_folder>/libs/orcc/src/scheduler.c 
				<output_folder>/libs/roxml/src/roxml.c 
				<output_folder>/libs/roxml/src/roxml-parse-engine.c
				<output_folder>/libs/roxml/src/roxml-internal.c
				<output_folder>/libs/orcc/src/mapping.c
- libraries:    pthread

To compile and execute:

1. Generate the C Orcc backend for Top_DPD.xdf

2. Run:
$ cd <C_output_dir> && cd build && cmake .. && cd ..

3. Run:
$ gcc -o bin/dpd src/*.c libs/orcc-native/src/framerate.c libs/orcc-runtime/src/profiling.c \
libs/orcc-native/src/native.c libs/orcc-runtime/src/trace.c libs/orcc-runtime/src/options.c \
libs/orcc-runtime/src/util.c libs/orcc-runtime/src/serialize.c libs/orcc-runtime/src/dataflow.c \
-Ilibs/orcc/include -lpthread -I/usr/include/SDL libs/orcc-runtime/src/scheduler.c -Ibuild/libs/ \
-Ilibs/orcc-runtime/include/ -Ilibs/orcc-native/include/ -I libs/roxml/include/ libs/roxml/src/roxml.c \
libs/roxml/src/roxml-parse-engine.c libs/roxml/src/roxml-internal.c libs/orcc-runtime/src/mapping.c \
 ../lib/native/linux.c -O3

4. Run:
$ cd bin && cp <Predistortion_root>/lib/input_signals/in_*.txt .

5. Run:
./dpd


Changelog:
- initial version 16/12/2013

Known issues:
- the lowlevel_dpd implementation has some structural illogicalities
  (ports of Polynomial network) due to limitations of the Orcc compiler
- lowlevel_dpd produces output that very slightly differs from the
  reference output. This is due to differences in rounding.



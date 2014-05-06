IEEE 802.15.4 (ZigBee) Baseband

Authors: 
Jani Boutellier (jani.boutellier@ee.oulu.fi)
Department of Computer Science and Engineering
University of Oulu, Finland

Based on the C code implementation written
by Amanullah Ghazi. Described in SDR-WInnComm 2013 paper
"Low-complexity SDR Implementation of IEEE 802.15.4 (ZigBee)
Baseband Transceiver on Application Specific Processor"


Description:
This project contains RVC-CAL descriptions of the IEEE 802.15.4
(ZigBee) transmitter and receiver. At the moment, only
transmitter descriptions are included. Receiver description
is to be added.  
The 'lib'-folder contains native function bodies, which
are required when the transmitter is realized as C code and
compiled for a general purpose processor.
The same folder has also an input sample sequence and
a reference output signal. 
The implementation monotoken_tx also works well with Xronos
HDL generation. In this case the recommended FIFO size is 1.

Compilation:
Standard GCC compilation with the following
- headers:      <output_folder>/libs/orcc-runtime/include
                <output_folder>/libs/orcc-native/include
                <output_folder>/libs/roxml/include
                <folder_of_SDL_headers>
- source files: <orc-apps-trunk>/ZigBee/lib/native/linux.c 
                <output_folder>/src/*.c, 
                <output_folder>/libs/orcc-runtime/src/*.c,
                <output_folder>/libs/orcc-native/src/fps_print.c,
                <output_folder>/libs/orcc-native/src/native.c,
                <output_folder>/libs/roxml/src/roxml.c,
                <output_folder>/libs/roxml/src/roxml-parse-engine.c,
                <output_folder>/libs/roxml/src/roxml-internal.c
- libraries:    pthread
                SDL

e.g.
gcc -o bin/tx libs/orcc-runtime/src/*.c libs/orcc-native/src/fps_print.c
libs/orcc-native/src/native.c -I libs/orcc-native/include 
-I libs/orcc-runtime/include src/*.c -I libs/roxml/include/
libs/roxml/src/roxml.c libs/roxml/src/roxml-parse-engine.c
libs/roxml/src/roxml-internal.c -lpthread -I /usr/include/SDL
-lSDL /home/user/orc-apps/ZigBee/lib/native/linux.c -O3

Changelog:
- initial release 08/10/2012
- multitoken version of the transmitter 04/03/2013
- embedded version of the transmitter 26/03/2013
- several small improvements to embedded_tx 25/04/2014
- rewrote monotoken_tx 06/05/2014
- moved shared actors to common_tx 06/05/2014

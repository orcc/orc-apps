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
The embedded-version of the transmitter is targeted for the
TTA backend of Orcc, but is also fully functional on a general
purpose processor.

Compilation:
Standard GCC compilation with the following
- headers:      <output_folder>/libs/orcc/include
                <output_folder>/libs/roxml/include
- source files: <orc-apps-trunk>/ZigBee/lib/native/embedded.c 
                OR others.c
                <output_folder>/src/*.c, 
                <output_folder>/libs/orcc/src/orcc_util.c,
                <output_folder>/libs/orcc/src/scheduler.c,
                <output_folder>/libs/roxml/src/roxml.c,
                <output_folder>/libs/roxml/src/roxml-parse-engine.c,
                <output_folder>/libs/roxml/src/roxml-internal.c
- libraries:    pthread

e.g.
gcc -o bin/ZigBee src/*.c libs/orcc/src/orcc_util.c -Ilibs/orcc/include
libs/orcc/src/scheduler.c -Ilibs/roxml/include libs/roxml/src/roxml.c 
libs/roxml/src/roxml-parse-engine.c libs/roxml/src/roxml-internal.c
~/orc-apps/ZigBee/lib/native/others.c -lpthread 


Changelog:
- initial release 08/10/2012
- multitoken version of the transmitter 04/03/2013
- embedded version of the transmitter 26/03/2013

Known issues:
- The FIFO size must be at least 2

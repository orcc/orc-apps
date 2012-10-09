IEEE 802.15.4 (ZigBee) Baseband

Authors: 
Jani Boutellier (jani.boutellier@ee.oulu.fi)
Department of Computer Science and Engineering
University of Oulu, Finland

Based on the C code implementation written
by Amanullah Ghazi. Described in SDR-WInnComm 2012 paper
"Low-complexity SDR Implementation of IEEE 802.15.4 (ZigBee)
Baseband Transceiver on Application Specific Processor"


Description:
This project contains RVC-CAL descriptions of the IEEE 802.15.4
(ZigBee) transmitter and receiver. At the moment, only one
transmitter description is included. Receiver descriptions
and a multirate transmitter are to be added.  
The 'lib'-folder contains files necessary support files as
well as an input sample sequence and a reference output. 


Compilation:
Standard GCC compilation with the following
- headers:      <output_folder>/libs/orcc/include
                <output_folder>/libs/roxml/include
- source files: <orc-apps-trunk>/ZigBee/lib/native/support.c
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
~/orc-apps/trunk/ZigBee/lib/native/support.c -lpthread 


Changelog:
- initial release 08/10/2012


Known issues:
- The FIFO size must be at least 2

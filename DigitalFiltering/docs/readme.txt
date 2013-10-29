The DigitalFiltering project -- a gentle introduction to RVC-CAL


Authors: 
Jani Boutellier (jani.boutellier@ee.oulu.fi)
Department of Computer Science and Engineering
University of Oulu, Finland

Karol Desnos (karol.desnos@insa-rennes.fr)
IETR, INSA Rennes, France


Description:
This project contains descriptions of a 4-tap FIR filter, 
a 1-tap IIR filter and and adaptive LMS filter in the RVC-CAL
language. All filters exist as low-level and monolithic 
versions that illustrate different specification granularities
in RVC-CAL. The 'lib'-folder contains files necessary 
for trying out the filters. The assumed experimental 
platform should provide the 1.3 version of the Orcc compiler
and some relatively new version of GCC (4.6.3 was used in design).
The lib-folder contains also input sample sequences and
reference outputs. An example compilation command can
be found in the 'compile' script that needs some editing
though.


Changelog:
- initial version 08/03/2012 (jboutell)
- simplification of some actors 11/04/2012 (kdesnos)
- floating point FIR 08/05/2012 (jboutell)
- half-precision floating point FIR 15/05/2012 (jboutell)
- LMS filter and lots of updates 27/09/2013 (jboutell)


Known issues:
- The input file for FIR is a valid WAV file. However, the
  FIR implementations treat the WAV header and payload
  identically with the consequence of destroying the WAV
  header in the output
- The half-precision floating point filters are work-in-progress

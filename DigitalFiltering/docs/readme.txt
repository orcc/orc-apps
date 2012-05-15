The DigitalFiltering project -- a gentle introduction to RVC-CAL


Authors: 
Jani Boutellier (jani.boutellier@ee.oulu.fi)
Department of Computer Science and Engineering
University of Oulu, Finland

Karol Desnos (karol.desnos@insa-rennes.fr)
IETR, INSA Rennes, France


Description:
This project contains descriptions of a 4-tap FIR filter and
a 1-tap IIR filter in the RVC-CAL language. Both filters
exist as low-level and monolithic versions that illustrate
different implementation alternatives in RVC-CAL.
The 'lib'-folder contains files necessary for trying out
the filters. The assumed experimental platform should
provide the 1.0 version on the Orcc compiler and some
relatively new version of GCC (4.6.1 was used in design).
The lib-folder contains also input sample sequences and
reference outputs. An example compilation command can
be found in the 'compile' script that needs some editing
though.
As an update, a single-precision floating point version
of the FIR filter was added.


Changelog:
- initial version 08/03/2012 (jboutell)
- simplification of some actors 11/04/2012 (kdesnos)
- floating point FIR 08/05/2012 (jboutell)
- half-precision floating point FIR 15/05/2012 (jboutell)


Known issues:
- The low-level version of the IIR filter stops execution
  1 sample too early. That's why there are two reference
  outputs
- The input file for FIR is a valid WAV file. However, the
  FIR implementations treat the WAV header and payload
  identically with the consequence of destroying the WAV
  header in the output
- The low-level IIR filter contains the actor 'delayi' 
  to emulate the presence of an initial token in the
  feedback loop. A cleaner alternative would be to 
  allow initial tokens in the XDF
- The half-precision floating point FIR is work-in-progress

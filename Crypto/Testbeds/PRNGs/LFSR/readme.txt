RVC-CAL Implementation of Linear Forward Shift Register (LFSR)

**********************************************************

Junaid Jameel Ahmad, Shujun Li @ Uni-Konstanz

Last modified on 06 June, 2011
**********************************************************

This is testbed for LFSR and it has been tested under Orcc.

LFSR_testbed.XDF: the network
Source_LFSR.cal: sends initial parameters to LFSR and golden response stream to Validator. 
Validator_QWordStream.cal: validates the LFSR's output bit stream with the golden response bit stream.
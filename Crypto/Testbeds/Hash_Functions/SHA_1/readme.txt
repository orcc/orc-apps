RVC-CAL Implementation of Secure Hash Algorithm (SHA-1)

**********************************************************

Junaid Jameel Ahmad @ Uni-Konstanz

Last modified on 25.09.2011
**********************************************************
This folder contains the testbed files for SHA-1 and it has been verified using Orcc. Test vectors and their 
golden response are taken from http://csrc.nist.gov/groups/ST/toolkit/documents/Examples/SHA1.pdf.

SHA-160_testbed.XDF: the network 
Source_SHA_160.cal: sends initial parameters to SHA-160 and golden response stream to Validator.
Validator_DWordStream.cal: validates the SHA-1's hash message stream with the golden response stream.

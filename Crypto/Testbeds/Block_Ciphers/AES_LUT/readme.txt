Testbeds of RVC-CAL Implementation of AES (Rijndael) based on the Look Up Tables (LUTs) scheme described in [1].
[1] G. Bertoni, L. Breveglieri, P. Fragneto, M. Macchetti and S. Marchesin, "Efficient Software Implementation of AES on 32-Bit Platforms",
in the proceedings of the CRYPTOGRAPHIC HARDWARE AND EMBEDDED SYSTEMS - CHES 2002, Lecture Notes in Computer Science, Vol. 2523, pp. 129-142, 2003.

**********************************************************

Junaid Jameel Ahmad @ Uni-Konstanz

Last modified on 05.04.2012

**********************************************************

-- Source FUs --
Source_AES_Cipher.cal: Source FU with test vectors and golden responses for AES encipher
Source_AES_InvCipher.cal: Source FU with test vectors and golden responses for AES decipher

-- Validator FU --

Utilities.System.Validator_16B.cal: comparing the output of a FU against a golden response (used for validating the functionalities of blocks with 16 bytes).

---- Test vectors and golden response ----

AES_Cipher_testbed.xdf
AES_InvCipher_testbed.xdf
AES_CTR_Encipher_testbed.xdf


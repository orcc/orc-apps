RVC-CAL Implementation of Blowfish [1]

**********************************************************

Junaid Jameel Ahmad @ Uni-Konstanz

Last modified on 22 October, 2011

**********************************************************

This RVC-CAL implementation of Blowfish is composed of the following files.
The naming of cal files follow the terms used in the following paper:

[1] B. Schneier, "Description of a New Variable-Length Key, 64-Bit Block Cipher (Blowfish)", Fast Software Encryption, Cambridge Security Workshop Proceedings (December 1993), Springer-Verlag, 1994, pp. 191-204.

The test vectors and golden responses are taken from http://www.schneier.com/code/vectors.txt.

Since Blowfish is a Feistel cipher, this implementation of Blowfish has been designed to demonstrate the reusability of Feistel network used in our Blowfish implementation in the CTL. Therefore, this implementation should not be treated as an optimal implementation of Blowfish.

To support parallel processing of multiple blocks, the output of some FUs is expanded to include the round number. 

== Basic FUs ==

All basic FUs were written to be compliant with the subset of RVC-CAL supported by Orcc.

-- Common Kernel FUs for both Blowfish encipher and decipher --

Blowfish.Blowfish_F.cal
Blowfish.Blowfish_Final_XOR.cal
Feistel_Networks.Feistel.xdf
Feistel_Networks.Feistel_Manager.cal

-- Utility FUs used in both Blowfish encipher and decipher --

Utilities.Any2Bits.cal
Utilities.Bits2Any.cal
Utilities.Mux2.cal
Utilities.Mux8.cal
Utilities.Demux2.cal
Utilities.Demux8.cal
Utilities.XOR_1b.cal

== Blowfish encipher and decipher as FU networks ==

-- ECB mode --

Blowfish_Encipher.xdf
Blowfish_Decipher.xdf

-- CBC mode --

Blowfish_CBC_Encipher.xdf
Blowfish_CBC_Decipher.xdf

-- 8-bit CFB mode --

Blowfish_CFB8_Encipher.xdf
Blowfish_CFB8_Decipher.xdf

-- 64-bit CFB mode --

Blowfish_CFB64_Encipher.xdf
Blowfish_CFB64_Decipher.xdf

-- OFB mode --

Blowfish_OFB_Cipher.xdf (encipher/decipher)

-- CTR mode --

Blowfish_CTR_Cipher.xdf: Blowfish encipher/decipher

Note: CBC, CFB, OFB and CTR modes have external dependencies on the CAL files under package CTL.Block_Ciphers.Modes.

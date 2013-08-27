RVC-CAL Implementation of AES (Rijndael) based on the Look Up Tables (LUTs) scheme described in [1].
[1] G. Bertoni, L. Breveglieri, P. Fragneto, M. Macchetti and S. Marchesin, "Efficient Software Implementation of AES on 32-Bit Platforms",
in the proceedings of the CRYPTOGRAPHIC HARDWARE AND EMBEDDED SYSTEMS - CHES 2002, Lecture Notes in Computer Science, Vol. 2523, pp. 129-142, 2003.

**********************************************************

Junaid Jameel Ahmad @ Uni-Konstanz

Last modified on 05.04.2012

**********************************************************

This is the RVC-CAL implementation of AES (FIPS 197) based on the look up tables technique described in [1].
Unlike the byte-oriented standard implementation of AES (in the package Block_Ciphers.AES), this implementation does not have separate
CAL files for each AES operation. Both the encipher and the decipher of this implementation are implemented in a single CAL file each. 
These files are:

AES_Cipher.cal
AES_InvCihper.cal
Tables.cal

The test vectors and golden responses are taken from FIPS 197.

All the three editions of AES are implemented: AES-128, AES-192, and AES-256.
The FUs are written to automatically recognize the key size and work in the corresponding edition.

== AES encipher and decipher as FU networks ==

-- ECB mode --

AES_Cipher.cal
AES_InvCihper.cal

-- CBC mode --

AES_CBC_Encipher.xdf: AES encipher
AES_CBC_Decipher.xdf: AES decipher

-- CFB mode --

AES_CFB8_Encipher.xdf: 8-bit CFB AES encipher
AES_CFB8_Decipher.xdf: 8-bit CFB AES decipher

AES_CFB128_Encipher.xdf: 128-bit CFB AES encipher
AES_CFB128_Decipher.xdf: 128-bit CFB AES decipher

-- OFB mode --

AES_OFB_Cipher.xdf: AES encipher/decipher

-- CTR mode --

AES_CTR_Cipher.xdf: AES encipher/decipher

Note: CBC, CFB, OFB and CTR modes have external dependencies on the CAL files are located under package Block_Ciphers.Modes.
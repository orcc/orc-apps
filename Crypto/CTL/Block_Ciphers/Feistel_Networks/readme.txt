RVC-CAL Implementation of Feistel Network

**********************************************************

Junaid Jameel Ahmad @ Uni-Konstanz

Last modified on 22 October, 2011

**********************************************************

This RVC-CAL implementation of Feistel Network, which is used to in the implementation of Feistel ciphers (DES, Blowfish etc.). 
It consists of the following files.

Feistel_Networks.Feistel.xdf
Feistel_Networks.Feistel_Manager.cal

This current implementation of Feistel network has been implemented to support the bit-oriented tokens with cipher block size of 64-bits with both left and right sub-blocks of 32-bits.
An implementation handling byte-oriented tokens can be generated too.  

Feistel.xdf has one Network paramter 'SWAP_LR'. There are two possible values for this parameter.
For some block ciphers, if the round function 'f' has to be performed on the left sub-block (e.g., Blowfish) instead of the right sub-block, the true value for this parameter swaps the L and R sub-blocks within the network.

Feistel_Manager FU serves as the manager of this Feiestel nework. It controls the flow of blocks through the network, assigns and increments round number, swaps the L and R sub-blocks etc.
   
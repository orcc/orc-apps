RVC-CAL Implementation of SKID3 user authentication protocol.

**********************************************************

Junaid Jameel Ahmad @ Uni-Konstanz

Last modified: 05.04.2012

**********************************************************

The SKID3 user authentication protocol authenticates any two users (e.g., client T and server S) with the following steps:

Step 1: T -> S: (T, rT),
Step 2: S -> T: (rS, H1 = HMAC(KT, rS || rT || S)),
Step 3.1: T generates H1' = HMAC(KT, rS || rT || S) and evaluates if H1' and H1 are identical. 
If yes, then S is authenticated to T.
Step 3.2: T -> S: H2 = HMAC(KT, rT || rS || T)
Step 4: S generates H2' = HMAC(KT, rT || rS || T) and evaluates if H2' and H2 are identical. 
If yes, then T is also authenticated to S. 

where T and S are the user identifiers of client and server respectively, rT and rS are the randomly chosen numbers by T and S respectively, 
and KT is the key used for the HMAC operations

----------------------------------------------------------

Below is the list of files, which are part of the RVC-CAL's current implementation of SKID3. The description about the functionality of RVC-CAL FUs can be found in their header comments. 
All basic FUs were written to be compliant with the subset of RVC-CAL supported by Orcc.

Party 1 - Client:
=================
Client_Receiver.cal
Client_Sender.cal
Client_Source.cal
Client.xdf: the top network, which implements the Client's functionality.
Client_test.xdf: the testbed showing the usage of Client.xdf.

Party 2 - Server:
=================
Server_Receiver.cal
Server_Sender.cal
Server_Source.cal
Server.xdf: the top network, which implements the Server's functionality.
Server_test.xdf: the testbed showing the usage of Server.xdf.

SKID3 Protocol Simulation:
===================
Top_SKID3.xdf: implements the complete protocol by using both the Client.xdf and Server.xdf together.
SKID3_Source.cal
Channel.cal  


This implementation also uses the following items (packages and FUs) from the CTL:
===============================================================

1) The HMAC based on the SHA-256 hash function, which is available in CTL's package Hash_Functions.HMACs.
2) The ARC4 pseudo random number generator, which is available in CTL's package Stream_Ciphers.ARC4.
2) The Bigger2smaller.cal, available in the CTL's package Utilities.


 
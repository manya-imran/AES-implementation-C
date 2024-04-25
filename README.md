# AES-implementation-C
Implementation of AES from Scratch in C++

The Advanced Encryption Standard (AES) is a very important commercial block
cipher algorithm, designed to replace the earlier DES.
AES uses repeat cycles or ``rounds.'' There are 10, 12, or 14 rounds for keys of 128, 192, and 256 bits, respectively. The input text is represented as a 4 x 4 array of bytes. The key is represented as a 4 x 4 array of bytes, where n depends on the key size.
For AES 128 following flowchart is used for encryption and decryption.

Each round of the algorithm consists of four steps:

1. subBytes: for each byte in the array, use its value as an index into a fixed
256-element lookup table, and replace its value in the state by the byte value
stored at that location in the table. You can find the table and the inverse
table on the web.

2. shiftRows: Let Ri denote the ith row in state. Shift R0 in the state left 0
bytes (i.e., no change); shift R1 left 1 byte; shift R2 left 2 bytes; shift R3 left
3 bytes. These are circular shifts. They do not affect the individual byte
values themselves.

3. mixColumns: for each column of the state, replace the column by its value
multiplied by a fixed 4 x 4 matrix of integers (in a particular Galois Field).
This is the most complex step. Find details at any of several websites. Note
that the inverse operation multiplies by a different matrix.

4. addRoundkey: XOR the state with a 128-bit round key derived from the
original key K by a recursive process.

There is a tremendous amount of information on the web about the AES algorithm.
You can find it by searching for "Rijndael" or "Advanced Encryption Standard" on
the web. The AES standard is here:

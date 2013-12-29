Objective:
==========
  The program does not produce correct result. Why?

Logic:
======
  Number 8 is represented as 1000.
  ~8 is expected to be 0111. But the result is -9.
  ~8 will be represented as 11110111. The CPU while reading this, will interpret as negative number
    since the sign bit is 1. So it will take the two's complement and give the result. The number
    will become 00001001. This is -9.

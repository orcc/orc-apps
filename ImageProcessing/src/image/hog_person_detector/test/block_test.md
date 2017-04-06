There are two test files for the Blocks actor, a and b, which test it.

They consist of an input file and an output file. For the test to pass, the output file produced by running the test actor on the input file must match the output file exactly.

Input files are both 128x64 "image" files, although in reality they are just carefuly crafted binary data files.

## Test A ##
The input test file is numerically increasing bytes. That is, `00 01 02 03 04 05` and so on until it reaches `ff` after which it restarts at `00`.

The intent of this test is to ensure that the order of values inside inputted histograms is preserved when output. When grouping the output stream into sequences of 9 values, the first value should be `x` where `x mod 9` is `0`, and count up by one each item.

## Test B ##
The input test file is numerically increasing bytes, each repeated 9 times. That is, `00` repeated 9 times, `01` repeated nine times and so on.

This test is to ensure that the histograms are output in the correct order. Rows are 8 elements wide, so the first values should be `00 01 08 09`, the second should be `01 02 08 09` and so on. For the ease of visualising this, the following table is provided:

```
0 1 2 3 4 5 6 7
8 9 a b c d e f
```

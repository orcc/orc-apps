# DoubleCache Actor #
Writes to its output what was provided to its input, but has a large internal buffer.

## Inputs ##
* **uint(size=16) Gin**: The stream to read values from.

## Outputs ##
* **uint(size=16) Gout**: The stream to write those same values out to.

## Usage ##
This copies its input to its output without modification in the same order. However, it has an internal "buffer" which
is at least large enough to store one image (whose storage is defined by the constants in `image.constants.constants`,
however, the colour depth is considered 1 regardless of its actual value).

It will not block writes until this internal buffer is filled, meaning you can use it as a "large pipe".

This is equivalent to `image.utils.Cache`, with the following differences:

* It ignores the image's pixel depth.
* It uses 16 bit values instead of 8.

## Notes ##
None.

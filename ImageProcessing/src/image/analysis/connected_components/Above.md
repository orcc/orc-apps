# Above Actor #
Accepts a pixel value, and outputs the three pixels above it.

## Inputs ##
* **uint(size=16) Gin**: The stream to read image values from.

## Outputs ##
* **uint(size=16) Gout**: The upper left, upper middle and upper right value in that order.

## Usage ##
This class expects you to first write to Gin, and then read a triplet from Gout.

First write a value to Gin, assume this has the x coordinate `x`. You can then read the values from the PREVIOUS row
for `x - 1`, `x` and `x + 1` positions in that order from Gout.

Wrapping between rows happens automatically based on the constants in `image.constants`, that is, writing values after
a full row has been read will reset the `x` value to 0 to start a new row.

## Notes ##
* Writing or reading from Gout/Gin when not expected will block.
* Any pixels outside the current image (off the top, bottom, left or right) will be 0.
* A single pixel is 16 pixels, regardless of the colour depth of the image.

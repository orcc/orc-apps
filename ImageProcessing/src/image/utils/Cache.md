# Cache Actor #
Writes to its output what was provided to its input, but has a large internal buffer.

## Inputs ##
* **uint(size=8) Gin**: The stream to read values from.

## Outputs ##
* **uint(size=8) Gout**: The stream to write those same values out to.

## Usage ##
This copies its input to its output without modification in the same order. However, it has an internal "buffer" which
is at least large enough to store one image (whose storage is defined by the constants in `image.constants.constants`).

It will not block writes until this internal buffer is filled, meaning you can use it as a "large pipe".

## Notes ##
None.

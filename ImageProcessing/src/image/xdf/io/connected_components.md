# connected_components Actor #
Reads in an image and outputs the same image, but with colour values replace with connected classes

## Inputs ##
* **uint(size=8) In**: The stream to read image values from.

## Outputs ##
* **uint(size=16) Out**: The connected component classes.

## Usage ##
This actor reads in an image into its input port, and then outputs values for each pixel such that the following holds
for each value:

* All pixels with the same value will be connected.
* All pixels that are connected will have the same value.
* 0 is passed through untranslated.

Two pixels are "connected" they are touching ether horizontaly, vertically or diagonally.

In effect, this actor reads the image, works out which non-zero areas are touching, gives each a unique value and then
outputs that value for each pixel.

## Notes ##
* The output is 16 bits while the input is 8 bits.
* If piping more than one image through this, there is no guarantee that the connected areas will refer to the same
"object".

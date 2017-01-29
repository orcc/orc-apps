# image.arithmetic.logicalXOR
This operator takes two images as input, and outputs a third image whose pixel values are just those of the first image, XORed with the corresponding pixels from the second. 

## Inputs ##
* **uint(size=8) Gin1**: The first image stream.
* **uint(size=8) Gin2**: The second image stream.

## Outputs ##
* **uint(size=8) Gout**: The stream to write translated values out to.

## Usage ##
This actor reads `x` from `Gin1` and `y` from `Gin2`, and outputs the result of `~(x ^ y)` to the output.

## Notes ##
None.

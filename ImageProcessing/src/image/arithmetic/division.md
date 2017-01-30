# image.arithmetic.division
This image division operator takes as two identically sized images as input and produces a third image of the same size as the inputs whose pixel values are the pixel values of the first image divided by the corresponding pixel values of the second image.

## Inputs ##
* **uint(size=8) Gin1**: The first image stream.
* **uint(size=8) Gin2**: The second image stream.

## Outputs ##
* **uint(size=8) Gout**: The stream to write translated values out to.

## Usage ##
This actor reads `x` from `Gin1` and `y` from `Gin2`, and outputs the result of `x / y` to the output.

## Notes ##
Some divide by 0 error checking.

# Label Actor #
Takes in an image of 16 bit pixels, and outputs 8 bit pixels such that uniqueness is preserved

## Inputs ##
* **uint(size=18) Gin**: The stream to read image values from.

## Outputs ##
* **uint(size=16) Gout**: The stream to output values to.

## Usage ##
This takes an image, defined using the `IM_HEIGHT_OUT * IM_WIDTH_OUT` constants in `image.constants` and outputs an
8 bit image such that the following holds:

* 0 is output as 0.
* Non-zero values are output as a possibly different non-zero value.
* The same input values yield the same output values.

## Notes ##
* If there are more than 255 different classes, an error will be printed to the console, and 0 will be output for any
further class.

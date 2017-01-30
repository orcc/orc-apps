# ContrastStretch Actor #
Performs contrast stretching (aka normalization) of an image that passes through it.

## Inputs ##
* **uint(size=8) Gin**: The stream to read image values from.
* **uint(size=8) Max**: The maximum value in the stream.
* **uint(size=8) Min**: The minimum value in the stream.

## Outputs ##
* **uint(size=8) Gout**: The stream to write translated values out to.

## Usage ##
First of all, the maximum and minimum values found in the image must be written to the appropriate ports before the
algorithm will start processing the image. Once they are written. Image data should be fed into `Gin` and read from
`Gout`. Once a full image has been processed, as defined by the constants in `image.constants.constants`, any further
processing will block until a new `Max` and `Min` are read.

For each pixel `x`, the following is output: `(x - min) * (255 / (max - min))`.

## Notes ##
* Writing to `Max` or `Min` while processing the image will have no effect, and the values will not be consumed.

# MaxMin Actor #
Returns both the maximum and minimum octet values of an image fed to it.

## Inputs ##
* **uint(size=8) Gin**: The stream to read image values from.

## Outputs ##
* **uint(size=8) Max**: The maximum value in the stream.
* **uint(size=8) Min**: The minimum value in the stream.

## Usage ##
A full image must be written into `Gin`. The size of this image is given by the values in `image.constants.constants`.
Once a full image is written, the maximum and minimum value can be read from the appropriate ports. Once **both** have
been output, a new image can be written.

The maximum and minimum are based on octets.

## Notes ##
* The maximum and minimum values may only be read once per image.
* Trying to wirte an image when this actor is waiting for its output to be read will cause `Gin` to block.

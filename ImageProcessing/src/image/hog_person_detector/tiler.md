
# 8x8tiler Actor #

Outputs specified block sized sections of the image as a sequential stream.

## Inputs ##

* **uint(size=8) Gin**: The stream to read values from.
* **uint(size=8) windowDimension**: Height and Width of the sliding window.
* **uint(size=8) imageHeight**: Height of the input image.
* **uint(size=8) imageWidth**:  Width of the input image.

## Outputs ##

* **uint(size=8) Gout**: The block as a sequential stream of windowDimension * windowDimension.

## Usage ##

Outputs ((imageWidth / windowDimension) * 2) * ((imageHeight / windowDimension) *2)  windowDimension by windowDimension sections of the original image as a windowDimension * windowDimension stream.

## Notes ##

Image height and width must be a multiple of windowDimension.
Warning: Currently you can use even sized window blocks as the step distance is one half of the window dimension.

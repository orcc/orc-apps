# image.arithmetic.addition

This operator takes as input two identically sized images and produces as output a third image of the same size as the first two, in which each pixel value is the sum of the values of the corresponding pixel from each of the two input images.

## Function inputs

* ** uint(size=8) Gin1**: The original image stream.
* ** uint(size=8) Gin2**: An image stream or constant to add to Gin1.

## Function outputs

*  ** uint(size=8) Gout**: The image stream after addition. 

## Notes
For each value, if the addition would result in an overflow, `255` is output instead.

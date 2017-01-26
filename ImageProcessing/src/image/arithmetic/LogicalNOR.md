# image.arithmetic.LogicalNOR

This operator takes two images as input, and outputs a third image whose pixel values are just those of the first image, NORed with the corresponding pixels from the second. 

## Function inputs

* ** uint(size=8) Gin1**: The original image stream.
* ** uint(size=8) Gin2**: An image stream or constant to NOR operation.

## Function outputs

*  ** uint(size=8) Gout**: The image stream after LogicalNOR. 

## Notes


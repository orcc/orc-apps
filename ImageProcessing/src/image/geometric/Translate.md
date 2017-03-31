# image.geometric.translate

The translate operator performs a geometric transformation which maps the position of each picture element in an input image into a new position in an output image. The image element located at (x1,y1) in the original is shifted to a new position (x2,y2) in the corresponding output image by displacing it through a user-specified translation (Ox,Oy).

## Function inputs

* ** uint(size=8) Gin1**: The original image stream.

## Function outputs

*  ** uint(size=8) Gout**: The image stream after translation. 

## Notes
Specify the translation by changing the constants xOffset, yOffset. These values can be any integer.


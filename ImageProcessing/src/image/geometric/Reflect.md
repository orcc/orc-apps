# image.geometric.reflect

The reflection operator geometrically transforms an image such that image elements, i.e. pixel values, located at position (x1,y1) in an original image are reflected entirely horizontally or vertically depending on the chosen orientation. 

## Function inputs

* ** uint(size=8) Gin1**: The original image stream.

## Function outputs

*  ** uint(size=8) Gout**: The image stream after reflection. 

## Notes
The constant orientation determines the horizontal(0) or else vertical(1) reflect.


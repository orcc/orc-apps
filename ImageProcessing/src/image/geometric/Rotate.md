# image.geometric.rotate

The rotation operator performs a geometric transform which maps the position (x1,y1) of a picture element in an input image onto a position (x2,y2) in an output image by rotating it through a user-specified angle theta about an origin O. 

## Function inputs

* ** uint(size=8) Gin1**: The original image stream.

## Function outputs

*  ** uint(size=8) Gout**: The image stream after Rotation. 

## Notes
The rotation can only be in 90 degree multiples. i.e 90/180/270. It must be changed in the constant.


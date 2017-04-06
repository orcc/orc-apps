# Label Actor #
Takes in an image, and labels connected segments.

## Inputs ##
* **uint(size=16) Gin**: The stream to read image values from.
* **uint(size=16) Above**: The stream to read the above values from.

## Outputs ##
* **uint(size=16) Gout**: The outputted classes.
* **uint(size=16) Equiv**: Outputted equivalence classes.

## Usage ##
The main purpose of this class is to read an image from Gin and group it up into connected segments. A single output
value corresponds to a single pixel, using the following rules:

* If the input pixel is 0, the output will be 0.
* If the input value is non-zero, all pixels with this value will connected.
* However, a connected segment will NOT all have the same value.

A pixel is considered part of a connected segment if there is a pixel in a segment to its left, upper left, directly
above or its upper right. In order to read the "upper" values, an Above actor should be connected as follows:

* Label#Gin to Above#Gin
* Above#Gout to Above#Above

In the condition that a pixel is in two segments, one of them is chosen, and an `[x, y]` pair is written to Equiv after
the value. `x` and `y` are two segments which have the same value. `[0, 0]` is written to Equiv to signify the end of
all equivalence pairs.

This actor makes the guarantee that:

* All pixels with the same value will be in the same segment.
* Two values in an equivalence pair (written to Equiv) are the same segment.
* 0 is not part of any segment, it's value is passed through untranslated.

## Notes ##
None.

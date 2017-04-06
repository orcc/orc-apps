# Replace Actor #
Takes in an image and a list of equivalent classes, and outputs such that all equivalent classes have the same value

## Inputs ##
* **uint(size=16) Gin**: The stream to read image values from.
* **uint(size=16) Equiv**: Equivalence classes.

## Outputs ##
* **uint(size=16) Gout**: The stream to output values to.

## Usage ##
First, this class reads `[x, y]` pairs from Equiv, and stores them into "buckets" such that `x` and `y` are in the
same "bucket". This is repeated (using the same buckets) until we read `[0, 0]`, in which case we start reading from
the image.

It reads pixels from the image, checks which bucket it is in (putting it in a new bucket if it doesn't exist), and then
outputs that bucket's ID. Except 0, which always outputs 0.

The end result of this is that, if connected to a Label actor, it guarantees the following in the output:

* All pixels with the same value will be in the same segment.
* All pixels in the same segment will have the same value.
* 0 is not part of any segment, it's value is passed through untranslated.

## Notes ##
* The main intention for this actor is that Gin and Equiv are connected to the appropriate values of a Label actor.
* If there are more than 500 buckets, or 1000 entries in a single bucket, this will fail and print an error.

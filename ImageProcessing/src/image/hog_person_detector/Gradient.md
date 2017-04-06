# Gradient actor #
Takes in an 8 by 8 cell of values, then outputs the gradients (as both an angle and maginitude) for each pixel.

## Inputs ##
* **uint(size=8) Gin**: The stream to read the cells from.

## Outputs ##
* **uint(size=8) Angle**: The stream to output angles to.
* **uint(size=8) Magnitude**: The stream to output magnitudes to.

## Usage ##
First of all, reads values from Gin until it has an 8x8 cell. It expects the values to be written left to right, top to bottom. While it is doing this, it outputs nothing.

Once it has a full set of cells, it goes through each pixel calculating the gradient. That is, it first takes the difference between the pixels above and below it to calculate a `dy`, and the pixels to its left and right to calculate a `dx`. These values are calculated based on the intensity of the pixel.

It then uses these values to calculate a vector. If the point was on an "edge", this vector points perpendicular to that edge. The magnitude of this vector is how "sharp" that edge is.

For each pixel in the cell it outputs an angle and magnitude on the appropriate streams (left to right, top to bottom) as follows:

* `angle`: Half the angle of the vector in degrees. The initial value for this is `[0..360]`, but since it gets halved (so it fits in an 8 bit int), the range is `[0..180]`.
* `mag`: Half the magnitude of the vector, basically equal to `sqrt(dx^2 + dy^2) / 2`.

## Notes ##
* Pixels at the edge of the cell use their own value if they would otherwise read out of bounds.
* Because of this, pixel differences resting exactly on the edge of a cell will NOT be detected.
* A positive `dx` value is "left to right", a positive `dy` value is "top to bottom".
* Remember that both output values are halved, so when using them, you may have to double them.

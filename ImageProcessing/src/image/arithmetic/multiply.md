# multiply Actor #
For each octet in the data and factor stream, multiplies both values together.

## Inputs ##
* **uint(size=8) Gin**: The stream to read values from.
* **uint(size=8) Factor**: The stream to read values to multiply by from.

## Outputs ##
* **uint(size=8) Gout**: The stream to write translated values out to.

## Usage ##
This actor reads `x` from `Gin` and `y` from `Factor`, and outputs the result of `x * y` to the output.

For each value, if the multiplication would result in an overflow, `255` is output instead.

## Notes ##
None.

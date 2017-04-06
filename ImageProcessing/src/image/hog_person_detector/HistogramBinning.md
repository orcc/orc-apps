# Histogram Binning Actor #
Takes in a gradient angle and intensty and distributes the intensity in 9 histogram bins.

## Inputs ##
* **uint(size=8) angle**: The angle of a gradient. Values between 0 and 180
* **uint(size=8) intensity**: The intensity of a gradient

## Outputs ##
* **uint(size=16) Histogram**: The stream of 9 bins values 

## Usage ##
This actor takes in 64 angle and intensity inputs and bins them into 9 bins. The actor will distribute the intensity values between the closest bins to the angles.
The bins have the following values: 10, 30, 50, 70, 90, 110, 130, 150, 170.

An example binning would be: 

`if angle = 40 and intensity = 20 then bin30 += 10 and bin50 += 10.`
## Notes ##
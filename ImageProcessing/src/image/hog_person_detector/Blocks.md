# Blocks actor #
Takes some number of values from an image broken down into cells, and divides them into 2x2 "blocks".

## Inputs ##
* **uint(size=8) Gin**: The stream to read the histograms from.

## Outputs ##
* **uint(size=8) Grad**: The stream to output the blocks.

## Usage ##
This actor is designed to work in the hog image pipeline. For that reason, it accepts inputs in a specific format.

Basically, it expects an image (with dimensions specified in constants.cal), which has been divided into "cells" of size WINDOW_SIZE (a constant in this actor), and then turned into a HIST_SIZE (again, a constant in this actor) list of values. Basically, an image, divided down into WINDOW_SIZE x WINDOW_SIZE cells, each of which are transformed into an array of size HIST_SIZE.

It reads in these histograms, from left to right, top to bottom, and as soon as it is able, it outputs the same histograms, but in a diffent order.

A block is a square made up of histograms of cells in a 2x2. The 4 histograms that make up this block will be output in the order top right, top left, bottom right, bottom left.

The blocks themselves are written left to right, top to bottom. It's important to note that the blocks overlap. That is, the histogram from a cell can be in up to four blocks.

As an example, suppose the following image is input:

```
1 2 3 4
5 6 7 8
```

Where 1..8 are histograms for cells, this algorithm will output the following:

```
1 2
5 6

2 3
6 7

3 4
7 8
```

## Notes ##
* Behaviour is undefined when the image cannot be broken down excatly into WINDOW_SIZE x WINDOW_SIZE blocks.

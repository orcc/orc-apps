/*
* how to use cal description of Stereo Matching
* author: Jinglin Zhang
* version: v1
* date: 2013/03/10
*/

In stereo matching applications, we need two image source left and right, we must modify the genetated souce file a little.

For example:
Generated C

1. in the function of init_orcc()
...
case 'm':
			//mapping_file = strdup(optarg);
			input_file1 = strdup(optarg);
			break; 
...
we comment this line //mapping_file = strdup(optarg);
and add input_file1 = strdup(optarg);

2.in the mean time 
add 
extern char *input_file1;
into "orcc_util.h"

3. add 
void source_init1() {
	stop = 0;
	nb = 0;

	if (input_file1 == NULL) {
		print_usage();
		fprintf(stderr, "No input file given!\n");
		wait_for_key();
		exit(1);
	}

	file = fopen(input_file, "rb");
	if (file == NULL) {
		if (input_file1 == NULL) {
			input_file1 = "<null>";
		}

		fprintf(stderr, "could not open file \"%s\"\n", input_file1);
		wait_for_key();
		exit(1);
	}
	if(PRINT_SPEED) {
		atexit(printSpeed);
	}
	startTime = clock();
	loopsCount = nbLoops;
}

into source.c

4. Add -i ../data/imL.PPM -m ../data/imR.PPM into Commands Arguments

5. In the function of initialize_instances()
For two images left and right
there are two functions of loadimage.
In the two functions, it should use source_init() and source_init1() for left and right images respectively as defined in step 4.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	FILE *i1, *i2;
	int cnt = 0, j, done = 0;
	int differences = 0;
	double tol;

	if (argc != 4)
	{
		printf("parameters: file1, file2, tolerance\n");
		return 0;
	}

	i1 = fopen(argv[1], "rb");
	i2 = fopen(argv[2], "rb");
	tol = atof(argv[3]);

	while (!done) {
		int retval1, retval2;
		float data1, data2, diff;
		retval1 = fread(&data1, sizeof(float), 1, i1);
		retval2 = fread(&data2, sizeof(float), 1, i2);
		if (retval1 != 1 || retval2 != 1) {
			done = 1;
			break;
		}
		diff = data1 - data2;
		if (fabs(diff) > tol) {
			printf("%i: %f vs %f\n", cnt, data1, data2);
			differences ++;
		}
		cnt ++;
	}
	printf("%i samples compared in total, with %i differences.\n", cnt, differences);
	if(feof(i1) && feof(i2)) {
		printf("Files are of equal length.\n");
	} else if (feof(i1)) {
		printf("Stopped at end of file 1.\n");
	} else if (feof(i2)) {
		printf("Stopped at end of file 2.\n");
	} else {
		printf("Unknown cause of stopping.\n");
	}

	fclose(i1);
	fclose(i2);

	return 0;
}

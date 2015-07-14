#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

unsigned int seed()
{
	struct timezone tz;
	struct timeval tvs;

	gettimeofday(&tvs, &tz);
	return tvs.tv_usec;
}

int main(int argc, char **argv)
{
	FILE *o;
	int cnt, j;

	if(argc != 3)
	{
		printf("parameters: outfile, sample count\n");
		return 0;
	}

	srand(seed());
	o = fopen(argv[1], "wb");
	cnt = atoi(argv[2]);

	for(j = 0; j < cnt; j++)
	{
		int val = rand();
		int div = 1 << 30;
		float fdiv = (float) div;
		float data = (float) val;
		data = data / fdiv;
		data = data - 1.0;
		fwrite(&data, sizeof(float), 1, o);
	}

	fclose(o);
}

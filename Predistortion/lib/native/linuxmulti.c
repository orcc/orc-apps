// Native functions to be used with digital predistortion filter
// This implementation is for multi-token processing

#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>

typedef struct {
	FILE *i;
	FILE *q;
	struct timeval tvs;			// start time
	unsigned long long cal;		// time calibration value
} t_io_iq;

t_io_iq *src;
int src_count;
t_io_iq *snk;
int snk_count;

void source_init()
{
	char source_file_name[256];
	t_io_iq *ios;

	ios = (t_io_iq*) malloc(sizeof(t_io_iq));

	sprintf(source_file_name, "in_i.bin");
	ios->i = fopen(source_file_name, "rb");
	if(ios->i == NULL)
	{
		printf("error opening %s\n", source_file_name);
	}
	else if(feof(ios->i))
	{
		printf("source file %s empty\n", source_file_name);
	}

	sprintf(source_file_name, "in_q.bin");
	ios->q = fopen(source_file_name, "rb");
	if(ios->q == NULL)
	{
		printf("error opening %s\n", source_file_name);
	}
	else if(feof(ios->q))
	{
		printf("source file %s empty\n", source_file_name);
	}

	src = ios;
	src_count = 0;
}

void source_read_i(float *buffer, int offset, int len)
{
	t_io_iq *ios = (t_io_iq*) src;

	if (ios->i != NULL) {
		int retval = fread(&buffer[offset], sizeof(float), len, ios->i);
		if(feof(ios->i) || retval != len)
		{
			printf("Closing source i\n");
			fclose(ios->i);
			ios->i = NULL;
		}
	}
}

float source_read_q(float *buffer, int offset, int len)
{
	t_io_iq *ios = (t_io_iq*) src;

	if (ios->q != NULL) {
		int retval = fread(&buffer[offset], sizeof(float), len, ios->q);
		if(feof(ios->q) || retval != len)
		{
			printf("Closing source q\n");
			fclose(ios->q);
			ios->q = NULL;
		}
	}
}

void sink_consume_i(float *buffer, int len)
{
	t_io_iq *ios = (t_io_iq*) snk;
	fwrite(buffer, sizeof(float), len, ios->i);
}

void sink_consume_q(float *buffer, int len)
{
	t_io_iq *ios = (t_io_iq*) snk;
	fwrite(buffer, sizeof(float), len, ios->q);
	if(snk_count >= LENGTH)
	{
		unsigned long long uss;	
		unsigned long long use;
		struct timeval tve;
		struct timezone tz;

		// stop profiling
		gettimeofday(&tve,&tz);
		uss = ios->tvs.tv_sec * 1000000L + ios->tvs.tv_usec;
		use = tve.tv_sec * 1000000L + tve.tv_usec;

		printf("%i samples processed; closing sink\n", LENGTH);
		printf("Running time: %u\n", (unsigned int) (use - uss - ios->cal));
		fflush(stdout);
		fflush(ios->i);
		fclose(ios->i);
		ios->i = NULL;
		fflush(ios->q);
		fclose(ios->q);
		ios->q = NULL;

		exit(0);
	}

	snk_count += len;
}

void sink_init()
{
	struct timezone tz;		// dummy time zone
	struct timeval tve;		// end time
	char buffer[256];
	t_io_iq *ios;
	ios = (t_io_iq*) malloc(sizeof(t_io_iq));

	// find out how long two repeated gettimeofdays take
	gettimeofday(&ios->tvs, &tz);
	gettimeofday(&tve, &tz);
	ios->cal = (tve.tv_sec * 1000000L + tve.tv_usec) - (ios->tvs.tv_sec * 1000000L + ios->tvs.tv_usec);

	// start actual profiling
	gettimeofday(&ios->tvs, &tz);

	sprintf(buffer, "out_i.bin");

	ios->i = fopen(buffer, "w");
	if(ios->i == NULL)
	{
		printf("error opening %s\n", buffer);
	}

	sprintf(buffer, "out_q.bin");

	ios->q = fopen(buffer, "w");
	if(ios->q == NULL)
	{
		printf("error opening %s\n", buffer);
	}

	snk = ios; 
	snk_count = 0;
}


#include <stdio.h>
#include <stdlib.h>

FILE *sink_file;

char sink_file_name[] = "sink.out";
int num_sources_open = 0;

void native_sink_init()
{
	sink_file = fopen(sink_file_name, "w");
	if(!sink_file)
	{
		printf("error opening %s\n", sink_file_name);
		exit(0);
	}
}

void sink_close()
{
	fclose(sink_file);
	sink_file = NULL;
}

void native_sink_consume(short data)
{
	fprintf(sink_file, "%i\n", data);
	if(num_sources_open == 0)
	{
		sink_close();
		exit(0);
	}
}

void native_sink_consume_sf(float data)
{
	fprintf(sink_file, "%.0f\n", data);
	if(num_sources_open == 0)
	{
		sink_close();
		exit(0);
	}
}

void native_sink_consume_hf(unsigned short data)
{
	fprintf(sink_file, "%u\n", data);
	if(num_sources_open == 0)
	{
		sink_close();
		exit(0);
	}
}


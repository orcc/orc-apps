#include <stdio.h>
#include <stdlib.h>

FILE *sink_file;

char sink_file_name[] = "sink.out";

void native_sink_init()
{
	sink_file = fopen(sink_file_name, "w");
	if(!sink_file)
	{
		printf("error opening %s\n", sink_file_name);
		exit(0);
	}
}

void native_sink_close()
{
	fclose(sink_file);
	sink_file = NULL;
}

void native_sink_consume(short data)
{
	fputc(data, sink_file);
}

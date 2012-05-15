#include <stdio.h>
#include <stdlib.h>

FILE *source_file;

char source_file_name[] = "source.in";

extern int end_program;

int native_source_init()
{
	fpos_t start;
	int len;

	source_file = fopen(source_file_name, "r");
	if(!source_file)
	{
		printf("error opening %s\n", source_file_name);
		exit(0);
	}
	if(feof(source_file))
	{
		printf("source file %s empty\n", source_file_name);
		exit(0);
	}

	fgetpos(source_file, &start);
	fseek(source_file, 0, SEEK_END);
	len = ftell(source_file);
	fsetpos(source_file, &start);
	
	return len;
}

int native_source_produce()
{
	int data;

	data = fgetc(source_file);

	if(feof(source_file))
	{
		fclose(source_file);
		end_program = 1;
	}

	return data;
}

float native_source_produce_sf()
{
	float data;

	data = fgetc(source_file);

	if(feof(source_file))
	{
		fclose(source_file);
		end_program = 1;
	}

	return (float) data;
}

float native_source_produce_hf()
{
	float data;

	data = fgetc(source_file);

	if(feof(source_file))
	{
		fclose(source_file);
		end_program = 1;
	}

	return (float) data;
}


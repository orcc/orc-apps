#include <stdio.h>
#include <stdlib.h>

#define MAX_SRC 16
#define STR_MAX 256

FILE *source_file[MAX_SRC];
extern int num_sources_open;

int native_source_init(int index)
{
	char source_file_name[STR_MAX];
	fpos_t start;
	int len;

	sprintf(source_file_name, "input_%i.in", index);

	source_file[index] = fopen(source_file_name, "r");
	if(!source_file[index])
	{
		printf("error opening %s\n", source_file_name);
		exit(0);
	}
	if(feof(source_file[index]))
	{
		printf("source file %s empty\n", source_file_name);
		exit(0);
	}

	fgetpos(source_file[index], &start);
	fseek(source_file[index], 0, SEEK_END);
	len = ftell(source_file[index]);
	fsetpos(source_file[index], &start);

	num_sources_open ++;	

	return len;
}

void source_close(int index)
{
	fclose(source_file[index]);
	source_file[index] = NULL;
}

int native_source_produce(int index)
{
	int data = 0;

	if(source_file[index] != NULL)
	{
		fscanf(source_file[index],"%i\n", &data);

		if(feof(source_file[index]))
		{
			source_close(index);
			num_sources_open--;
		}
	}

	return data;
}

float native_source_produce_sf(int index)
{
	float data = 0.0;

	if(source_file[index] != NULL)
	{
		fscanf(source_file[index],"%f\n", &data);

		if(feof(source_file[index]))
		{
			source_close(index);
			num_sources_open--;
		}
	}

	return (float) data;
}

unsigned short native_source_produce_hf(int index)
{
	unsigned short data = 0;

	if(source_file[index] != NULL)
	{
		fscanf(source_file[index],"%hu\n", &data);

		if(feof(source_file[index]))
		{
			source_close(index);
			num_sources_open--;
		}
	}

	return (unsigned short) data;
}


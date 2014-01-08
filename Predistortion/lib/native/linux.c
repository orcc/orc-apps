// Native functions to be used with digital predistortion filter

#include <stdio.h>
#include <stdlib.h>

FILE *input_i = NULL;
FILE *input_q = NULL;
FILE *output_i = NULL;
FILE *output_q = NULL;
int count;

void close_file(FILE **file)
{
	if(file[0] != NULL)
	{
		fclose(file[0]);
		file[0] = NULL;
	}
}

void close_all()
{
	printf("Processed %i complex samples.\nClosing files.\n", count);
	close_file(&input_i);
	close_file(&input_q);
	close_file(&output_i);
	close_file(&output_q);
}

void try_file_open(FILE **file, const char *name, const char *rw)
{
	if(file[0] == NULL)
	{
		file[0] = fopen(name, rw);

		if(file[0] == NULL)
		{
			printf("Unable to open file %s\nExit\n", name);
			close_all();
			exit(0);
		}
		else
			printf("Opened file %s\n", name);
	}
}

void source_init()
{
	count = 0;
	try_file_open(&input_i, "in_i.txt", "r");
	try_file_open(&input_q, "in_q.txt", "r");
}

float source_read(FILE *file)
{
	int ret_val;
	float sample = 0.0;

	if(file != NULL)
	{
		ret_val = fscanf(file, "%f\n", &sample);

		if(ret_val != 1)
		{
			close_all();
			exit(0);
		}
	}
	return sample;
}

float source_read_i()
{
	return source_read(input_i);
}

float source_read_q()
{
	return source_read(input_q);
}

void file_write(FILE *file, float value)
{
	fprintf(file, "%f\n", value);		
}

void consume_i(float value)
{
	file_write(output_i, value);
	count ++;
}

void consume_q(float value)
{
	file_write(output_q, value);
}

void sink_init()
{
	try_file_open(&output_i, "out_i.txt", "w");
	try_file_open(&output_q, "out_q.txt", "w");
}


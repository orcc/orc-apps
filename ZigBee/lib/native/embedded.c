// Native functions to be used with the embedded_tx applications

#include <stdio.h>
#include <stdlib.h>

extern char *input_file;
FILE *input = NULL;

char *output_fn = "tx_stream.out";
FILE *output = NULL;

void close_input()
{
	if(input != NULL)
	{
		fclose(input);
		input = NULL;
	}
}

void close_output()
{
	if(output != NULL)
	{
		fclose(output);
		output = NULL;
	}	
}

void close_all()
{
	close_input();
	close_output();
}

void source_init()
{
	input = fopen(input_file, "r");

	if(input == NULL)
	{
		printf("Unable to open file %s\nExit\n", input_file);
		close_all();
		exit(0);
	}
}

#define BUF_SZ 12

int source_sizeOfFile()
{
	int len = 0;
	int ret_val = -1;

	if(input != NULL)
	{
		while(!feof(input))
		{
			char array[BUF_SZ];
			fgets(array, BUF_SZ, input);
			len++;
		}

		fseek(input, 0, SEEK_SET);	
	}

 	return len;
}

unsigned char source_readByte()
{
	int ret_val;
	int sample;

	ret_val = fscanf(input, "%i\n", &sample);

	if(ret_val != 1)
	{
		printf("Unable to read a sample from the input\nExit\n");
		close_all();
		exit(0);
	}

	return (unsigned char) sample;
}


void throw_away(int value)
{
	if(output == NULL)
		output = fopen(output_fn, "w");
	
	fprintf(output, "%i\n", value);		
}


void print_cyclecount()
{
	close_all();
	exit(0);
}


void display_checksum(int sum)
{
	close_all();
	exit(0);
}


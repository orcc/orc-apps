// Native functions to be used with the embedded_tx applications

#include <stdio.h>
#include <stdlib.h>

int source_packets = 0;
extern char *input_file;
FILE *input = NULL;

int sink_packets = 0;
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
	int ret_val;
	int sample;

	ret_val = fscanf(input, "%i\n", &sample);

	if(ret_val != 1)
	{
		// a not-so-nice way to finish execution
		// when the packet has been read and no 
		// new packet is available anymore,
		// 1 is returned. 1 is an invalid
		// packet size that leaves headerAdd
		// in an undefined state
		return 1;
	}

	source_packets ++;

	return sample;
}

unsigned char source_readByte()
{
	int ret_val;
	int sample;

	ret_val = fscanf(input, "%i\n", &sample);

	if(ret_val != 1)
	{
		close_all();
		exit(0);
		return 0;
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
	sink_packets ++;

	if(sink_packets == source_packets)
	{
		close_all();
		exit(0);
	}
}


void display_checksum(int sum)
{
	close_all();
	exit(0);
}


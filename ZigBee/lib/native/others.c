#include <stdio.h>
#include <stdlib.h>

// the stream length must be known by both the source and sink
int len = -1;

unsigned char native_source_init();
unsigned char native_source_produce();
void native_source_close();

void native_sink_init();
void native_sink_consume(int sample);
void sink_close();

/* 
  Support functions for the ZigBee tx source actor
*/

char input_fn[] = "tx_stream.in";
FILE *input = NULL;

// source actor initialization
unsigned char native_source_init()
{
	input = fopen(input_fn, "r");

	if(input)
	{
		int ret_val;

		ret_val = fscanf(input, "%i\n", &len);

		if(ret_val != 1)
		{
			printf("Unable to read stream length\nExit\n");
			exit(0);
		}

		printf("Payload length is %i octets\n", len);
		if((len < 5) || (len > 127))
			printf("WARNING: According to specification, payload must have between 5 and 127 octets\n");

		// go back to start-of-file
		fseek(input, 0, SEEK_SET);	
	}
	else
	{

		printf("Unable to open file %s\nExit\n", input_fn);
		exit(0);
	}

	return len;
}

// delivers a sample for the source actor
unsigned char native_source_produce()
{
	int ret_val;
	int sample;

	ret_val = fscanf(input, "%i\n", &sample);

	if(ret_val != 1)
	{
		printf("Unable to read a sample from the input\nExit\n");
		native_source_close();
		exit(0);
	}

	return (unsigned char) sample;
}

// cleans up the source actor
void native_source_close()
{
	if(!input);
	{
		fclose(input);
		input = NULL;
	}
}


/* 
  Support functions for the ZigBee tx sink actor
*/

char *output_fn = "tx_stream.out";
FILE *output = NULL;
int sink_cons = 0;

// sink actor initialization
void native_sink_init()
{
	output = fopen(output_fn, "w");

	if(output)
	{
		printf("Writing output to file %s\n", output_fn);
	}
	else
	{
		printf("Unable to open output file %s\nExit\n", output_fn);
		native_source_close();
		exit(0);		
	}
}

// delivers a sample for the sink actor
void native_sink_consume(int sample)
{
	fprintf(output, "%i\n", sample);

	sink_cons ++;

	if(sink_cons == (((len+6)*512+8)))
	{
		printf("Sink consumed %i samples\nEnd\n", sink_cons);
		native_source_close();
		sink_close();
		exit(0);
	}

}

// cleans up the sink actor
void sink_close()
{
	if(!output);
	{
		fclose(output);
		output = NULL;
	}
}



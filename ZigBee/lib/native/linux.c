// Native functions to be used with the Zigbee transmitter

#include <stdio.h>
#include <stdlib.h>
#include "options.h"

// opt is defined in util.c
extern options_t *opt;

FILE *input = NULL;
FILE *output = NULL;

int source_packets = 0;
int sink_packets = 0;

void close_input() {
	if(input != NULL) {
		fclose(input);
		input = NULL;
	}
}

void close_output() {
	if(output != NULL) {
		fclose(output);
		output = NULL;
	}	
}

void close_all() {
	close_input();
	close_output();
}

void source_init() {
	if(input == NULL) {
		input = fopen(opt->input_file, "r");

		if(input == NULL) {
			printf("Unable to open file %s\nExit\n", opt->input_file);
			close_all();
			exit(0);
		}
	}
}

int source_sizeOfFile() {
	int ret_val;
	int sample;

	ret_val = fscanf(input, "%i\n", &sample);

	if(ret_val != 1) {
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

unsigned char source_readByte() {
	int ret_val;
	int sample;

	ret_val = fscanf(input, "%i\n", &sample);

	if(ret_val != 1) {
		printf("Packet payload ended unexpectedly\nExit\n", opt->input_file);
		close_all();
		exit(0);
	}

	return (unsigned char) sample;
}

void throw_away(int value) {
	if(output == NULL)
		output = fopen(opt->write_file, "w");
	
	fprintf(output, "%i\n", value);		
}

void print_cyclecount() {
	sink_packets ++;

	if(feof(input) && (sink_packets == source_packets)) {
		close_all();
		exit(0);
	}
}


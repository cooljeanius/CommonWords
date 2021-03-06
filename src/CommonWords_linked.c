/*
 *  CommonWords_linked.c
 *  CommonWords
 *
 *  Created by Eric Gallager on 8/6/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 */

#include "libword.h"

/*
 * Main function
 */
int main (int argc, const char * argv[]) { // generated by template
	FILE *infilep;
	infilep = fopen("input.dat", "r");
	if (infilep == NULL) { // check for existence of input file
		printf("\n Cannot open input.dat for input, make sure this file exists. \n");
		exit(1); // error
	} else {
		printf("\n input.dat is good to go. \n");
	}
	FILE *outfilep;
	outfilep = fopen("output.dat", "w");
	word_t words[MAX_NUMBER_OF_WORDS]; // array for putting words in
	int i = 0; // initialize loop-counter
    printf("\n Message for security and/or debugging: \n This program's path is %s and it is running with %i argument(s). \n", argv[0], argc); // Statement for debugging
	printf("\n The contents of your file are: \n \f \n");
	for (i = 1; i < MAX_NUMBER_OF_WORDS; i++) { // goes through array for holding words in
		if (words[i].number_of_letters != EOF) {
			words[i] = scan_word(infilep);
			print_word(words[i], outfilep);
		}
	}
	i--;
	int j = 0;
	int k = 0; // we're going to need some more loop-counters
	int results[i][i]; // output array
	for (j = 1; j < i; j++) { // i is what the previous loop got up to
		for (k = 1; k < i; k++) {
			results[j][k] = 0; // initialize each array element
		}
	}
	for (j = 1; j < i; j++) { // do a separate loop so the results array won't get over-written
		words[j].number_of_matches = 1; // initialize
		for (k = 1; k < i; k++) {
			if (j != k) { // we don't want to be comparing things to themselves
				results[j][k] = results[j][k] + compare_words(words[j], words[k]);
				results[k][j]++; // increment the other one to handle the associative property
				if (results[j][k] == 0) {
					words[j].number_of_matches++; // only need to increment one of them because they're the same thing
					printf("\n %s appears %i times. \n", words[j].word, words[j].number_of_matches);
					fprintf((FILE*)outfilep, "\n %s appears %i times. \n", words[j].word, words[j].number_of_matches); // put results into file
					results[k][j]++; // increment the other one to handle the associative property
				}
			}
		}
	}
	fclose(infilep); // finish up cleanly
	fclose(outfilep); // finish up cleanly
    return 0;
}

// newline \n


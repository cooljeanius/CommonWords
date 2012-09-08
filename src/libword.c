/*
 *  libword.c
 *  CommonWords
 *
 *  Created by Eric Gallager on 8/6/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 */

#include "libword.h"

/*
 * Displays a word
 */
void print_word(word_t word, FILE*outfilep); // prototype
void 
print_word(word_t word, FILE*outfilep) {
	if ((word.number_of_letters != 0) && (word.number_of_letters != EOF)) {
		fprintf((FILE*)outfilep, "%i %s \n", word.number_of_letters, word.word);
		printf("%i %s \n", word.number_of_letters, word.word); // Statement for debugging, so output.dat doesn't have to be opened each time
	} else {
		fprintf((FILE*)outfilep, "%i \n", word.number_of_letters);
		printf("%i \n", word.number_of_letters); // Statement for debugging, so output.dat doesn't have to be opened each time
	}
}

/*
 * Gets a word from a file
 */
word_t scan_word(FILE*infilep); // prototype
word_t 
scan_word(FILE*infilep) {
	word_t word;
	fscanf((FILE*)infilep, "%i", &word.number_of_letters);
	if ((word.number_of_letters != EOF) && (word.number_of_letters != 0)) {
		fscanf((FILE*)infilep, "%s", word.word);
	}
	/*
	 * The following loop doesn't actually do anything, but it doesn't hurt to keep it in, so why not
	 */
	if (word.word == NULL) {
		word.word[0] = ' ';
		fopen("input.dat", "w");
		fprintf((FILE*)infilep, "_"); // so it stops repeating scanning that one line
		fclose(infilep);
	}
	return (word);
}

/* 
 * Tests for same words
 * Return Values:
 *	0 => equal
 *	anything else => not equal
 *	1 => default return value (falls under the "not equal" set)
 */
int compare_words(word_t word1, word_t word2); // prototype
int
compare_words(word_t word1, word_t word2) {
	int ret_value = 1; // initialize to something other than 0 because 0 is what it returns on equality, and the null hypothesis is that of inequality
	if (word1.number_of_letters == word2.number_of_letters) { // only compare words with the same number of letters
		ret_value = strcmp(word1.word, word2.word); // returns 0 if equal
	}
	return(ret_value);
}

// newline \n


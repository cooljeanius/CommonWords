/*
 *  libword.h
 *  CommonWords
 *
 *  Created by Eric Gallager on 8/6/12.
 *  Copyright 2012 George Washington University. All rights reserved.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strcmp() function 

#define STRING_MAX_LENGTH 100
#define MAX_NUMBER_OF_WORDS 11 // this is hard-coded because I can't get EOF detection working properly

typedef struct {
	int number_of_letters;
	char word[STRING_MAX_LENGTH];
	int number_of_matches;
} word_t;

/*
 * Displays a word
 */
extern void print_word(word_t word, FILE*outfilep); // prototype

/*
 * Gets a word from a file
 */
extern word_t scan_word(FILE*infilep); // prototype

/* 
 * Tests for same words
 * Return Values:
 *	0 => equal
 *	anything else => not equal
 *	1 => default return value (falls under the "not equal" set)
 */
extern int compare_words(word_t word1, word_t word2); // prototype

// newline \n


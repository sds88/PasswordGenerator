#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include "defines.h"

char* GeneratePassword(char* username, char* serviceName) {
	char* firstWord;
	char* secondWord; 
	char* thirdWord; 
	char* finalPassword;
	int firstLine = 0;
	int secondLine = 0;
	int thirdLine = 0;
	int i;

	for(i = 0; username[i] != '\n'; i++) {
		double factor = username[i] << CONSTANT_FACTOR;
		factor = (int) fmod(INT_MAX, factor);
		factor = factor - (i * CONSTANT_FACTOR);
		factor = (int) fmod(INT_MAX, factor);
		firstLine += (int) abs(factor);
	}
	firstLine = globals.numLines % firstLine;
	firstWord = GetLineFromFile(globals.dictionary, firstLine);

	for(i = 0; serviceName[i] != '\n'; i++) {
		double factor = serviceName[i] << CONSTANT_FACTOR;
		factor = (int) fmod(INT_MAX, factor);
		factor = factor + (i * CONSTANT_FACTOR);
		factor = (int) fmod(INT_MAX, factor);
		secondLine += (int) abs(factor);
	}
	secondLine = globals.numLines % secondLine;
	secondWord = GetLineFromFile(globals.dictionary, secondLine);

	for(i = 0; CONSTANT_WORD[i] != '\0'; i++) {
		double factor = CONSTANT_WORD[i] << CONSTANT_FACTOR;
		factor = (int) fmod(INT_MAX, factor);
		factor = factor - (i * firstLine);
		factor = (int) fmod(INT_MAX, factor);
		factor = factor + (i * secondLine);
		factor = (int) fmod(INT_MAX, factor);
		thirdLine += (int) abs(factor);
	}
	thirdLine = globals.numLines % secondLine;
	thirdWord = GetLineFromFile(globals.dictionary, thirdLine);

	size_t len1 = strlen(firstWord);
	size_t len2 = strlen(secondWord);
	size_t len3 = strlen(thirdWord);
	
	finalPassword = malloc(len1 + len2 + len3 + 3);
	snprintf(finalPassword, len1 + len2 + len3 + 3, "%s %s %s", firstWord, secondWord, thirdWord);
	
	free(firstWord);
	free(secondWord);
	free(thirdWord);

	return finalPassword;
}


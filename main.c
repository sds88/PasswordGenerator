#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "defines.h"
#include <limits.h>

Globals globals;

int main(int argc, char **argv) {
	globals.dictionary = fopen(DICTIONARY_PATH, "r");
	if(globals.dictionary == NULL) {
		printf("Cannot find the dictionary.");
		return 1;
	}
	globals.numLines = GetNumLines(globals.dictionary);
	while(1) {
		printf("Enter a username or quit:\t");
		char* username = ReadFromStdIn();
		if(strncmp(username, QUIT_STATEMENT, 3) == 0) {
			free(username);
			break;
		}
		printf("\nEnter the service name:\t\t");
		char* serviceName = ReadFromStdIn();
	
		char* password = GeneratePassword(username, serviceName);
		printf("Password = \"%s\"\n", password);
		free(username);
		free(serviceName);
		free(password);
	}
	fclose(globals.dictionary);
	return 0;
}



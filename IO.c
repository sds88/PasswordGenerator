#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "defines.h"

char* ReadFromStdIn() {
	char* buffer = malloc(MAX_BUFFER_SIZE);
	if(fgets(buffer, MAX_BUFFER_SIZE, stdin) != NULL) {
		int bufferLen = strlen(buffer);
		if(bufferLen > 0 && buffer[bufferLen - 1] == '\n')
			buffer[bufferLen - 1] == '\0';
		return buffer;
	} else {
		free(buffer);
		return NULL;
	}
}

char* GetLineFromFile(FILE *file, int lineNum) {
	if(file == NULL)
		return NULL;
	if(lineNum > globals.numLines)
		lineNum = globals.numLines % lineNum;
	char* buffer = malloc(MAX_BUFFER_SIZE);
	int i = 0;
	for(i; i < lineNum; i++) {
		fgets(buffer, MAX_BUFFER_SIZE, file);
	}
	rewind(file);
	Strip(buffer);
	return buffer;
}

int GetNumLines(FILE *file) {
	if(file == NULL)
		return -1;
	int lines = 0;
	while (EOF != (fscanf(file, "%*[^\n]"), fscanf(file, "%*c")))
		++lines;
	rewind(file);
	return lines;
}

void Strip(char *buffer) {
	char *buffer2 = buffer;
	while(*buffer != '\0') {
		if(*buffer != '\n') {
			*buffer2++ = *buffer++;
		} else {
			++buffer;
		}
	}
	*buffer2 = '\0';
}

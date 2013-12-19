#ifndef DEFINES
#define DEFINES

#define QUIT_STATEMENT "quit"
#define DICTIONARY_PATH "dictionary"
#define CONSTANT_WORD	"dunno yet"
#define CONSTANT_FACTOR 6
#define MAX_BUFFER_SIZE 1024
/* wrapper struct for global variables */
typedef struct {
	FILE *dictionary;
	int numLines;
} Globals;
/* extern declaration for global variables */
extern Globals globals;
/* extern declarations for generator.c */
extern char*	GeneratePassword(char* username, char* serviceName);
/* extern declarations for IO.c */
extern char*	GetLineFromFile(FILE *file, int lineNum);
extern int	GetNumLines(FILE *file);
extern char*	ReadFromStdIn();
extern void	Strip(char *buffer);
#endif

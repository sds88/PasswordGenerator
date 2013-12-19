CC = gcc
MEM = valgrind
MFLAGS = --leak-check=full --show-reachable=yes -v
CFLAGS = -g -lm
CLASSES = main.c \
	generator.c \
	IO.c \
	globals.c \

PROGRAM = program

all: main.c
	$(CC) -o $(PROGRAM) $(CLASSES) $(CFLAGS)

memcheck: all
	$(MEM) $(MFLAGS) ./$(PROGRAM)

run: all
	./program

default: all

clean:
	rm "program"

CC=gcc
CFLAGS=-Wall -Wextra
SOURCE=bf_interpreter.c
TARGET=bf_interpreter

all:
	$(CC) -o $(TARGET) $(CFLAGS) $(SOURCE) 

debug:
	$(CC) -o $(TARGET) $(CFLAGS) -g $(SOURCE) 

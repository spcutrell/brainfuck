CC=gcc
CFLAGS=-Wall -Wextra
SOURCE=cbrain.c
TARGET=cbrain

all:
	$(CC) -o $(TARGET) $(CFLAGS) $(SOURCE) 

debug:
	$(CC) -o $(TARGET) $(CFLAGS) -g $(SOURCE) 

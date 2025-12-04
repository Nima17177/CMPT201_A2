CC = gcc
CFLAGS = -Wall -g -std=c11
LDFLAGS = -lm -lc -lncurses -ltinfo

HDRmod = map.h
SRCmod = map.c
OBJmod = map.o

SRCmain = main.c
OBJmain = main.o map.o
APP = a.out

$(APP): $(OBJmain) $(OBJmod) $(HDRmod)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
run: 
	./a.out

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<


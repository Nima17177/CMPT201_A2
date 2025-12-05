CC = gcc
CFLAGS = -Wall -g -std=c11
LDFLAGS = -lm -lc -lncurses -ltinfo

HDRmod = levels.h sprite.h map.h
SRCmod = levels.c sprite.c map.c
OBJmod = levels.o sprite.o map.o

SRCmain = main.c
OBJmain = main.o levels.o sprite.o map.o
APP = a.out

$(APP): $(OBJmain) $(OBJmod) $(HDRmod)
        $(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
run:
        ./a.out

%.o: %.c %.h
        $(CC) $(CFLAGS) -c $<

clean:
    rm *.o a.out
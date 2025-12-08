CC = gcc
CFLAGS = -Wall -g -std=c11
LDFLAGS = -lm -lc -lncurses -ltinfo

HDRmod = $(wildcard *.h)
SRCmod = $(HDRmod:.h=.c)
OBJmod = $(HDRmod:.h=.o)

SRCmain = main.c
OBJmain = $(SRCmain:.c=.o) $(OBJmod)

APP = MacPan.out


$(APP): $(OBJmain) $(OBJmod) $(HDRmod)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<


PHONY: run clean

run: $(APP)
	./$(APP)

clean:
	rm *.o $(APP)


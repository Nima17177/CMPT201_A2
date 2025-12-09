CC = gcc
CFLAGS = -Wall -g -std=c11
LDFLAGS = -lm -lc -lncurses -ltinfo

HDRmod = $(wildcard *.h)
SRCmod = $(HDRmod:.h=.c)
OBJmod = $(HDRmod:.h=.o)

SRCmain = main.c
OBJmain = $(SRCmain:.c=.o) $(OBJmod)
APP = MacPan.out

DOXY = DOCUMENTATION/doxyfile


$(APP): $(OBJmain) $(OBJmod) $(HDRmod)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

Doc: 
	doxygen $(DOXY)


PHONY: run clean Mem_valgrind debug

run: $(APP)
	./$(APP)

clean:
	rm *.o $(APP)

Mem_valgrind: $(APP)
	valgrind ./$(APP)

debug: $(APP)
	gdb $(APP)


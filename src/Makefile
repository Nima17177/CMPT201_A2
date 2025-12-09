CC = gcc
CFLAGS = -Wall -g -std=c11
LDFLAGS = -lm -lc -lncurses -ltinfo

HDR = $(wildcard *.h)
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

APP = ../bin/appGame

DOXY = ../doc/doxyfile


$(APP): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

Doc: 
	doxygen $(DOXY)


PHONY: run clean Mem_valgrind debug

run: 
	./$(APP)

clean:
	rm $(OBJ)

delapp:
	rm $(APP)

deldox:
	rm -r ../doc/html
	rm -r ../doc/latex

Mem_valgrind: $(APP)
	valgrind ./$(APP)

debug: $(APP)
	gdb $(APP)


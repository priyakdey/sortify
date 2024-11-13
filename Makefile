CC=gcc
CCFLAGS=-Wall -Wextra -Wswitch-enum -Wpedantic -ggdb -I./raylib/
LFLAGS=-L./raylib/ -lraylib -lm

.PHONY:=run
run: sortify
	./sortify

sortify: sortify.c
	$(CC) $(CCFLAGS)  -o sortify sortify.c $(LFLAGS)

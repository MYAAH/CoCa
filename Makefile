CC = gcc -ggdb -std=c99
CFLAGS = -I.
PROGRAM = reduction

all: reduction.c reduction.h 3tree.c 3tree.h
	$(CC) -o $(PROGRAM) reduction.c 3tree.c $(CFLAGS)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm $(PROGRAM)
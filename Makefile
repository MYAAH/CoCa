CC = gcc -ggdb -std=c99
CFLAGS = -I.
PROGRAM = 3tree petersen

all: $(PROGRAM)
#all: reduction.c reduction.h 3tree.c 3tree.h
#	$(CC) -o $(PROGRAM) reduction.c 3tree.c $(CFLAGS)

%: reduction.c reduction.h %.c %.h
	$(CC) -o $@ reduction.c $@.c $(CFLAGS)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm $(PROGRAM)

CC = gcc -ggdb -std=c99
CFLAGS = -I.
PROGRAM = 3tree petersen 10K2 C10 sierp3
TREES = $(PROGRAM:%=get_tree_%)

all: $(PROGRAM) $(TREES)
#all: reduction.c reduction.h 3tree.c 3tree.h
#	$(CC) -o $(PROGRAM) reduction.c 3tree.c $(CFLAGS)

%: reduction.c reduction.h %.c all.h
	$(CC) -o $@ $< $(word 3,$^) $(CFLAGS)

get_tree_%: get_tree.c get_tree.h %.c all.h
	$(CC) -o $@ $< $(word 3,$^) $(CFLAGS)

run: $(PROGRAM)
	./$(PROGRAM)

clean:
	rm $(PROGRAM) $(TREES)

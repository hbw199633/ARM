.PHONY:clean
all:seq
seq:seqlist.c main.c
	gcc $^ -o $@ -Wall -g
	valgrind --tool=memcheck ./seq
clean:
	rm seq *.o -f

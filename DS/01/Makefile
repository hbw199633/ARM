OBJS = seqlist.o

FLAGS = -Wall -g -c

CC = gcc

seqlist:$(OBJS)
	$(CC)  $^ -o $@

%.o:%.c
	$(CC) $(FLAGS) $^ -o $@

.PHONY:

clean:
	rm -rf *.o seqlist

#seqlist:seqlist.c
#	gcc -Wall $^ -o $@
#	gcc -Wall seqlist.c -o seqlist

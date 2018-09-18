OBJS = main.o seqlist.o
cc = gcc
FLAGS = -Wall -g -c

seqlist:$(OBJS)
	$(cc) $(OBJS) -o $@

%.o:%.c
	$(cc) $(FLAGS) $^ -o $@

.PHONY:

clean:
	rm -rf *.o seqlist

OBJS = main.o
OBJS += seqlist.o

FLAGS = -Wall -c -g

cc = gcc

seqlist:$(OBJS)
	$(cc) $^ -o $@
	valgrind --tool=memcheck ./seqlist

%.o:%.c
	$(cc) $(FLAGS) $^ -o $@

.PHONY:

clean:
	rm -rf $(OBJS) seqlist

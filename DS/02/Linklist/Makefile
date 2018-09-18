OBJS = main.o Linklist.o
cc = gcc
FLAGS = -Wall -g -c

Linklist:$(OBJS)
	$(cc) $(OBJS) -o $@

%.o:%.c
	$(cc) $(FLAGS) $^ -o $@

.PHONY:

clean:
	rm -rf *.o Linklist

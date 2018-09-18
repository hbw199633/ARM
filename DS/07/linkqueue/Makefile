OBJS = main.o Linkqueue.o
cc = gcc
FLAGS = -Wall -g -c

Linkqueue:$(OBJS)
	$(cc) $(OBJS) -o $@

%.o:%.c
	$(cc) $(FLAGS) $^ -o $@

.PHONY:

clean:
	rm -rf *.o Linkqueue

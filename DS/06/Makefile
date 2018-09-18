OBJS = main.o sequeue.o
cc = gcc
FLAGS = -Wall -g -c

sequeue:$(OBJS)
	$(cc) $(OBJS) -o $@

%.o:%.c
	$(cc) $(FLAGS) $^ -o $@

.PHONY:

clean:
	rm -rf *.o sequeue

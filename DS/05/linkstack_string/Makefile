OBJS = main.o linkstack.o
cc = gcc
FLAGS = -Wall -g -c

linkstack:$(OBJS)
	$(cc) $(OBJS) -o $@

%.o:%.c
	$(cc) $(FLAGS) $^ -o $@

.PHONY:

clean:
	rm -rf *.o linkstack

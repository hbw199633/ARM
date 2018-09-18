OBJS = main.o bitree.o
OBJS += Linkqueue.o
cc = gcc
FLAGS = -Wall -g -c

bitree:$(OBJS)
	$(cc) $(OBJS) -o $@

%.o:%.c
	$(cc) $(FLAGS) $^ -o $@

.PHONY:

clean:
	rm -rf *.o bitree

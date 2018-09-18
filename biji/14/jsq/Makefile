.PHONY: clean install uninstall

OBJS  = main.o 
OBJS += add.o sub.o 
OBJS += mul.o div.o
CC = gcc
FLAGS = -Wall -g -c
jsq:$(OBJS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf jsq *.o

install:
	cp ./jsq /usr/bin

uninstall:
	rm -rf /usr/bin/jsq

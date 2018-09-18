.PHONY: clean
OBJS=main.o add.o sub.o div.o mul.o
FLAGS=-Wall -g -c
CC=gcc

jsq:$(OBJS)
	$(CC) $^  -o $@

%.o:%.c
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf jsq
install:
	cp ./jsq  /usr/local/sbin


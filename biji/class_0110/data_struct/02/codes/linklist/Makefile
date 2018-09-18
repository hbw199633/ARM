.PHONY:clean
all:link
link:main.c linklist.c
	gcc $^ -o $@ -Wall -g
	valgrind --tool=memcheck ./link
clean:
	rm *.o link -f

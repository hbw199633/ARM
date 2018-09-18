TARGET			:= clink
OBJS			:= main.o clinklist.o
FLAGS			:= -Wall -g
$(TARGET):$(OBJS)
	gcc $^ -o $@  $(FLAGS)
#%.o:%.c
#	gcc -c $< -o $@
.PHONY:
clean:
	rm *.o clink -f
test:
	make 
	valgrind --tool=memcheck ./$(TARGET)

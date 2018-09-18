TARGET			:= stack
OBJS			:= main.c seqstack.c
FLAGS			:= -Wall -g
$(TARGET):$(OBJS)
	gcc $^ -o $@  $(FLAGS)
.PHONY:
clean:
	rm $(TARGET) -f
test:
	make clean;make
	valgrind --tool=memcheck ./$(TARGET)

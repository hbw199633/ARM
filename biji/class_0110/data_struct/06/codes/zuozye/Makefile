TARGET			:= queue
OBJS			:= main.c linkqueue.c
FLAGS			:= -g -Wall
$(TARGET):$(OBJS)
	gcc $^ -o $@ $(FLAGS)
.PHONY:
clean:
	rm $(TARGET) -f
test:
	make clean;make
	valgrind --tool=memcheck ./$(TARGET)

TARGET			:= queue
OBJS			:= main.c sequeue.c
CFLAGS			:= -Wall -g
$(TARGET):$(OBJS)
	gcc $^ -o $@ $(CFLAGS)
.PHONY:
clean:
	rm $(TARGET) -f
test:
	make clean;make
	valgrind --tool=memcheck ./$(TARGET)

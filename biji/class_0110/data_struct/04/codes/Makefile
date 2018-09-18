TARGET			:= dlink
OBJS			:= main.c dlinklist.c
FLAGS			:= -Wall -g
$(TARGET):$(OBJS)
	gcc $^ -o $@  $(FLAGS)
.PHONY:
clean:
	rm *.o $(TARGET) -f
test:
	make clean;make
	valgrind --tool=memcheck ./$(TARGET)


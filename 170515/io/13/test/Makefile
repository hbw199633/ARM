all: a.out  b.out

a.out: a.c  fun.c
	gcc $^ -o $@
b.out: b.c  fun.c
	gcc $^ -o $@

clean:
	rm -rf a.out b.out

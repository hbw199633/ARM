all: a.out  b.out

a.out: a.c
	gcc $< -o $@ -g 
b.out: b.c
	gcc $< -o $@ -g
clean:
	rm -rf a.out b.out

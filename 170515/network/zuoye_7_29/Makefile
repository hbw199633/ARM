all: client  servier

client :client.c  
	gcc $^ -l pthread -o $@ 
servier :servier.c
	gcc $^ -l pthread -o $@ 

clean:
	rm -rf client servier

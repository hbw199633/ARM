all: server  client

server: server.c
	gcc $< -o $@  -g

client:client.c
	gcc $< -o $@ -g

clean:
	rm -rf server client

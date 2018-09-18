#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef int datatype;

typedef struct node {
	datatype		data;
	struct 	node *  next;
}linknode;

typedef struct {
	linknode	*	tail;
	linknode	*	head;
	int				count;
}linkqueue;


extern linknode * create_linknode(datatype value);
extern linkqueue * create_linkqueue(void);
extern int isfull_linkqueue(linkqueue * q);
extern int entry_linkqueue(linkqueue * q, datatype value);
extern int isempty_linkqueue(linkqueue * q);
extern int exit_linkqueue(linkqueue * q, datatype * data);
extern int free_linkqueue(linkqueue * q);
extern int show_linkqueue(linkqueue * q);

#endif

#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitree.h"

#define MAX 1000

typedef bitree * datatype1;

typedef struct _node_ {
	datatype1		data;
	struct 	_node_ *  next;
}linknode;

typedef struct {
	linknode	*	tail;
	linknode	*	head;
	int				count;
}linkqueue;


extern linknode * create_linknode(datatype1 value);
extern linkqueue * create_linkqueue(void);
extern int isfull_linkqueue(linkqueue * q);
extern int entry_linkqueue(linkqueue * q, datatype1 value);
extern int isempty_linkqueue(linkqueue * q);
extern int exit_linkqueue(linkqueue * q, datatype1 * data);
extern int free_linkqueue(linkqueue * q);
extern int show_linkqueue(linkqueue * q);

#endif

#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef int datatype;

typedef struct node {
	datatype		data;
	struct node *	next;
}linknode;

typedef struct {
	linknode *	head;
	int 		n;
}linkstack;

extern datatype pop_linkstack(linkstack * s);
extern int isempty_linkstack(linkstack * s);
extern int push_linkstack(linkstack * s, datatype value);
extern int isfull_linkstack(linkstack * s);
extern linkstack * create_linkstack(void);
extern linknode * create_linknode(datatype value);
extern int pop_linkstack1(linkstack * s, datatype * data);
extern int free_linkstack(linkstack * s);
extern int get_top_value_linkstack(linkstack * s, datatype * data);
extern int get_top_value_linkstack1(linkstack * s);

#endif

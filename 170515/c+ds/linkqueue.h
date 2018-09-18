#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitree.h"

#define M	20 

typedef bitree*  datatype;

typedef struct node
{
	datatype		data;
	struct node *	next;
}linknode;

typedef struct queue
{
	linknode *		head;
	linknode *		tail;
	int 			count;
}linkqueue;

extern linkqueue * create_linkqueue();
extern int enter_linkqueue(linkqueue * lq, datatype va);
extern int exit_linkqueue(linkqueue * lq, datatype * va);
extern int full_linkqueue(linkqueue * lq);
extern int empty_linkqueue(linkqueue * lq);
extern int get_head_linkqueue(linkqueue * lq, datatype * va);
extern int get_tail_linkqueue(linkqueue * lq, datatype * va);
extern int modify_head_linkqueue(linkqueue * lq, datatype va);
extern int modify_tail_linkqueue(linkqueue * lq, datatype va);
extern int free_linkqueue(linkqueue *lq);

extern int comp_linkqueue(linkqueue *lq_src,linkqueue *lq_dst);






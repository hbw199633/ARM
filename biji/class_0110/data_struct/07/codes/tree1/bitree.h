#ifndef __BITREE_H__
#define __BITREE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef INT
#define INT

typedef unsigned int datatype;

#endif

typedef struct node {
	struct node *	lchild;
	datatype		data;
	struct node * 	rchild;
}bitree;

extern bitree * create_node(datatype value);
extern bitree * create_bitree(int size, datatype value);
extern int pro_order(bitree * root);
extern int mid_order(bitree * root);
extern int no_order(bitree * root);

#endif

#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node {
	datatype 		data;
	struct node *	left;
	struct node *	right;
}dlinknode;

extern dlinknode * create_dlinknode(datatype value);
extern dlinknode * create_dlinklist(void);
extern int show_right_dlinklist(dlinknode * L);
extern int show_left_dlinklist(dlinknode * L);
extern int free_dlinklist(dlinknode * L);
extern int add_tail_dlinklist(dlinknode * L, datatype value);
extern int modify_value_dlinklist(dlinknode * L, datatype oldvalue, datatype newvalue);
extern int add_head_dlinklist(dlinknode * L, datatype value);
extern int delete_value_dlinklist(dlinknode * L, datatype value);
extern int delete_pos_dlinklist(dlinknode * L, int pos);
extern int find_value_dlinklist(dlinknode * L, datatype value);
extern int insert_value_dlinklist(dlinknode * L, datatype destvalue, datatype value);
extern int insert_pos_dlinklist(dlinknode * L, int pos, datatype value);

#endif

#ifndef __CLINKLIST_H__
#define __CLINKLIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node {
	datatype 		data;
	struct node *	next;
}linknode;

extern int free_clinlist(linknode * L);
extern int show_clinklist(linknode * L);
extern linknode * create_clinklist(void);
extern linknode * create_linknode(datatype value);
extern int add_tail_clinklist(linknode * L, datatype value);
extern int add_head_clinklist(linknode * L, datatype value);
extern int modify_value_clinklist(linknode * L, datatype oldvalue, datatype newvalue);
extern int find_value_clinklist(linknode * L, datatype value);
extern int getvalue_pos_clinklist(linknode * L, int pos, datatype * value);
extern int delete_pos_clinklist(linknode * L, int pos);
extern int delete_value_clinklist(linknode * L, datatype value);
extern int insert_pos_valuel_clinklist(linknode * L, int pos, datatype value);
extern int insert_value_clinklist(linknode * L, datatype destvalue, datatype value);

#endif


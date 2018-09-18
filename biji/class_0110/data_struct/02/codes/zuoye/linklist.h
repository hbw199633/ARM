#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int datatype;

typedef struct node {
	datatype 	  data;
	struct node * next;
}linknode;

extern linknode * create_linklist(void);
extern int show_linklist(linknode * L);
extern int free_linklist(linknode * L);
extern int add_tail_linklist(linknode * L, datatype value);
extern linknode * create_linknode(datatype value);
extern int add_head_linklist(linknode * L, datatype value);
extern int modify_value_linklist(linknode * L, datatype oldvalue, datatype newvalue);
extern int delete_value_linklist(linknode * L, datatype value);
extern int find_value_linklist(linknode * L, datatype value);
extern int insert_pos_linklist(linknode * L, int pos, datatype value);
extern int insert_value_linklist(linknode * L, datatype destvalue, datatype value);
extern int reverse_linklist(linknode * L);
extern int reverse_linklist1(linknode * L);


/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: Linklist.h
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月20日 星期二 15时00分23秒
***************************************************/

#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef int datatype;
typedef struct _node_
{
	datatype		data;
	struct _node_	*next;
}linknode;
typedef struct
{
	linknode	*head;
	int			count;
}linklist;

extern linklist * create_linklist();
extern linknode * create_linknode(datatype va);
extern int add_linklist(linklist *ls,datatype va);
extern int find_pos_linklist(linklist *ls,int pos);
extern int find_va_linklist(linklist *ls,datatype va);
extern int inr_va_linklist(linklist *ls,datatype old_va,datatype va);
extern int inr_pos_linklist(linklist *ls,int pos,datatype va);
extern int del_va_linklist(linklist *ls,datatype va);
extern int del_pos_linklist(linklist *ls,int pos);
extern int chg_va_linklist(linklist *ls,datatype,datatype);
extern int chg_pos_linklist(linklist *ls,int,datatype);

int show_linklist(linklist *ls);
int empty_linklist(linklist *ls);
int free_linklist(linklist *ls);

#endif

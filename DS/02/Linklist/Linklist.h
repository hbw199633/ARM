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

linklist * create_linklist();
linknode * create_linknode(datatype va);
int add_linklist(linklist *ls,datatype va);

int show_linklist(linklist *ls);
#endif

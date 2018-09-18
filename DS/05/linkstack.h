/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: linkstack.h
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月23日 星期五 10时34分41秒
***************************************************/

#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef int datatype;
typedef struct _node_
{
	datatype		data;  //栈的数据域
	struct _node_	*next; //栈的指针域
}linknode;
typedef struct
{
	linknode *head; //永远指向栈顶的地址
	int		 count; //栈的容量
}linkstack;

extern linkstack *create_linkstack();
extern linknode *create_linknode(datatype va);
extern int push_linkstack(linkstack *ls,datatype va);
extern int pop_linkstack(linkstack *ls,datatype *va);
extern int empty_linkstack(linkstack *ls);
#endif

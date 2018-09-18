/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: linkqueue.h
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月27日 星期二 09时55分25秒
***************************************************/

#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include "head.h"
typedef struct _node_
{
	datatype		data;
	struct _node_	*next;
}linknode;
typedef struct
{
	linknode *head;
	linknode *tail;
	int		 count;
}linkqueue;

extern linkqueue *create_linkqueue();
extern linknode *create_linknode(datatype va);
extern int enter_linkqueue(linkqueue *lq,datatype va);
extern int exit_linkqueue(linkqueue *lq,datatype *va);
extern int find_linkqueue(linkqueue *lq,datatype *va,int flag);
extern int chg_linkqueue(linkqueue *lq,datatype va,int flag);
extern int empty_linkqueue(linkqueue *lq);
extern int free_linkqueue(linkqueue *lq);



#endif

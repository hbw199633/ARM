/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: linkstack.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月23日 星期五 10时37分58秒
***************************************************/

#include "linkstack.h"

linkstack *create_linkstack()
{
	linkstack *ls =(linkstack *)malloc(sizeof(linkstack));
	if(NULL == ls)	return NULL;
	bzero(ls,sizeof(linkstack));
	return ls;
}

linknode *create_linknode(datatype va)
{
	linknode* n =(linknode *)malloc(sizeof(linknode));
	if(NULL == n)	return NULL;
	bzero(n,sizeof(linknode));
	memcpy(&n->data,&va,sizeof(datatype));
	n->next = NULL;
	return n;
}

int push_linkstack(linkstack *ls,datatype va)
{
	if(NULL == ls)		return -1;
	linknode *n = create_linknode(va);
	if(NULL == n)		return -1;
	n->next = ls->head;
	ls->head = n;
	ls->count++;
	return 0;
}

int pop_linkstack(linkstack *ls,datatype *va)
{
	if((NULL == ls)||(NULL == va)) return -1;
	linknode * n = ls->head;
	ls->head = n->next;
	memcpy(va,&n->data,sizeof(datatype));
	free(n);
	ls->count--;
	return 0;
}

int find_linkstack(linkstack *ls,datatype *va)
{
	if((NULL == ls)||(NULL == va)) return -1;
	if(empty_linkstack(ls))	return -2;
	memcpy(&va,&ls->head->data,sizeof(datatype));
	return 0;
}

int chg_linkstack(linkstack *ls,datatype va)
{
	if(NULL == ls)	return -1;
	if(empty_linkstack(ls))	return -2;
	memcpy(&ls->head->data,&va,sizeof(datatype));
	return 0;
}

int empty_linkstack(linkstack *ls)
{
	if(ls == NULL)	return -1;
	if(ls->count <= 0)	return -2;
	return 0;
}

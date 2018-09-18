/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: linkqueue.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月27日 星期二 09时55分18秒
***************************************************/

#include "Linkqueue.h"

linkqueue *create_linkqueue()
{
	linkqueue * lq = (linkqueue *)malloc(sizeof(linkqueue));
	if(NULL == lq)	return NULL;
	bzero(lq,sizeof(linkqueue));
	return lq;
}

linknode *create_linknode(datatype va)
{
	linknode * n = (linknode *)malloc(sizeof(linknode));
	if(NULL == n)	return NULL;
	bzero(n,sizeof(linknode));
	n->data = va;
	return n;
}

int enter_linkqueue(linkqueue *lq,datatype va)
{
	if(NULL == lq)	return -1;
	linknode *n = create_linknode(va);
	if(NULL == n)	return -1;
	if(lq->count == 0)
	{
		lq->head = n;
		lq->tail = n;
		lq->count++;
	}
	else
	{
		lq->tail->next = n;
		lq->tail = n;
		lq->count++;
	}
	return 0;
}

int exit_linkqueue(linkqueue *lq,datatype *va)
{
	if((NULL == lq)||(NULL == va)) return -1;
	if(empty_linkqueue(lq)==-2)	return -2;
	linknode *tmp = lq->head;
	lq->head = tmp->next;
	lq->count--;
	*va =  tmp->data;
	free(tmp);
	tmp = NULL;
	return 0;
}

int find_linkqueue(linkqueue *lq,datatype *va,int flag)
{
	if(flag)
		*va = lq->head->data;
	else
		*va = lq->tail->data;
	return 0;
}

int chg_linkqueue(linkqueue *lq,datatype va,int flag)
{
	if(flag)
		lq->head->data = va;
	else
		lq->tail->data = va;
	return 0;
}

int empty_linkqueue(linkqueue *lq)
{
	if(lq == NULL)	return -1;
	if(lq->count <= 0)	return -2;
	return 0;
}

int free_linkqueue(linkqueue *lq)
{
	datatype va = 0;
	while(!empty_linkqueue(lq))
		exit_linkqueue(lq,&va);
	free(lq);
	return 0;
}

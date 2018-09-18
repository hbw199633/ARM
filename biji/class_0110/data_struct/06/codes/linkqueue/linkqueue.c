/* ************************************************************************
	> File Name: linkqueue.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 13时48分11秒
	> Version: v1.0
 ************************************************************************/

#include "linkqueue.h"

/**************** 创建节点 ****************/
linknode * create_linknode(datatype value)
{
	linknode * p = (linknode *)malloc(sizeof(linknode));
	if (NULL == p)		return NULL;
	p->data	= value;
	p->next = NULL;

	return p;
}

/**************** 创建链式队列 ****************/
linkqueue * create_linkqueue(void)
{
	linkqueue * q = (linkqueue *)malloc(sizeof(linkqueue));
	if (NULL == q)		return NULL;
	bzero(q, sizeof(linkqueue));

	return q;
}

/**************** 判断队列是否为满 ****************/
int isfull_linkqueue(linkqueue * q)
{
	if (NULL == q)			return -1;
	if (q->count >= MAX)	return 1;
	else 					return 0;
}

/**************** 入队函数 ****************/
int entry_linkqueue(linkqueue * q, datatype value)
{
	if (NULL == q)				return -1;
	if (isfull_linkqueue(q))	return -2;
	linknode * L = create_linknode(value);
	if (NULL == L)				return -1;
	if (0 == q->count)
	{
		q->tail = q->head = L;
		q->count++;
	}
	else
	{
		q->tail->next = L;
		q->tail = L;
		q->count++;
	}

	return 0;
}

/**************** 判断队列是否为空 ****************/
int isempty_linkqueue(linkqueue * q)
{
	if (NULL == q)			return -1;
	if (q->count <= 0)		return 1;
	else 					return 0;
}

/**************** 出队函数 ****************/
int exit_linkqueue(linkqueue * q, datatype * data)
{
	if ((NULL == q) || (NULL == data))	return -1;
	if (isempty_linkqueue(q))			return -2;

	linknode * tmp = q->head;
	*data = tmp->data;
	q->head = tmp->next;
	free(tmp);
	q->count--;

	return 0;
}

/**************** 释放队列 ****************/
int free_linkqueue(linkqueue * q)
{
	if (NULL == q)		return -1;
	datatype data = 0;
	while (!isempty_linkqueue(q))
	{
		exit_linkqueue(q, &data);
	}
	free(q);

	return 0;
}

/**************** 打印链式队列 ****************/
int show_linkqueue(linkqueue * q)
{
	if (NULL == q)		return -1;
	datatype data = 0;
	while (!isempty_linkqueue(q))
	{
		exit_linkqueue(q, &data);
		printf("%d ", data);
	}
	printf("\n");
	return 0;
}


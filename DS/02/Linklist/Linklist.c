/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: Linklist.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月20日 星期二 15时00分17秒
***************************************************/

#include "Linklist.h"

linklist * create_linklist()
{
	linklist *ls = (linklist *)malloc(sizeof(linklist));
	if(NULL == ls)		return NULL;
	bzero(ls,sizeof(linklist));
	return ls;
}

linknode * create_linknode(datatype va)
{
	linknode * ln = (linknode *)malloc(sizeof(linknode));
	if(NULL == ln)		return NULL;
	bzero(ln,sizeof(linknode));
	ln->data = va;
	ln->next = NULL;
	return ln;
}

int add_linklist(linklist *ls,datatype va)
{
	if(NULL == ls)	return -1;
	linknode *ln = create_linknode(va);
	if(NULL == ln)	return -1;
	if(ls->count == 0)
	{
		ls->head = ln;
		ls->count++;
	}
	else
	{
		linknode *tmp = ls->head;
		while(tmp->next !=  NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = ln;
		ls->count++;
	}
	return 0;
}

int show_linklist(linklist *ls)
{
	if(NULL == ls)		return -1;
	linknode *tmp = ls->head;
	while(tmp!= NULL)
	{
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	return 0;
}

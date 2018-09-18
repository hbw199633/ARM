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
int find_va_linklist(linklist *ls,datatype va)
{
	if(NULL == ls)		return -1;
	linknode *tmp = ls->head;
	while(tmp)
	{
		if(tmp->data == va) return 0;
		tmp=tmp->next;
	}
	return -2;
}
int find_pos_linklist(linklist *ls,int pos)
{
	int i = 0;
	if(NULL == ls)	return -1;
	if((pos > ls->count)||(pos < 1)) return -2;
	linknode *tmp = ls->head;
	while(tmp)
	{
		if(i == pos-1)
		{
			printf("find the value %d\n",tmp->data);
			break;
		}
		tmp = tmp->next;
		i++;
	}
/*
	while(--pos)
	{
		tmp = tmp->next;
	}
	printf("find the value %d\n",tmp->data);
*/	return 0;
}

int inr_va_linklist(linklist *ls,datatype old_va,datatype va)
{
	if(NULL == ls)		return -1;
	if(find_va_linklist(ls,old_va)==-2)	return -2;
	linknode *ln = create_linknode(va);
	linknode *tmp = ls->head;
	while(tmp)
	{
		if(tmp->data == old_va)
		{
			ln->next = tmp->next;
			tmp->next = ln;
			ls->count++;
			break;
		}
		tmp = tmp->next;
	}
	return 0;
}

int inr_pos_linklist(linklist *ls,int pos,datatype va)
{
	int  i = 2;
	if(NULL == ls)	return -1;
	if((pos>ls->count)||(pos<=0)) return -2;
	linknode *ln = create_linknode(va);
	linknode *tmp = ls->head;
	if(pos == 1)
	{
		ln->next = tmp->next;
		ls->head = ln;
		ls->count++;
	}
	while(tmp)
	{
		if(pos == i)
		{
			ln->next = tmp->next;
			tmp->next = ln;
			ls->count++;
			break;
		}
		tmp = tmp->next;
		i++;
	}
	return 0;
}

int del_va_linklist(linklist *ls,datatype va)
{
	if(NULL == ls)		return -1;
	if(empty_linklist(ls)==-2)	return -2;
	linknode *tmp = ls->head;
	linknode *a = tmp->next;
	while(tmp->data == va)
	{
		ls->head = a;
		free(tmp);
		ls->count--;
		tmp = ls->head;
		a = tmp->next;
	}
	while(a)
	{
		if(a->data == va)
		{
			tmp->next = a->next;
			free(a);
			ls->count--;
			a = tmp->next;
		}
		else
		{
			a = a->next;
			tmp = tmp->next;
		}	
	}
	return 0;
}

int del_pos_linklist(linklist *ls,int pos)
{
	if(NULL == ls)		return -1;
	if(empty_linklist(ls)==-2) return -2;
	if((pos>ls->count)||(pos<0)) return -3;
	linknode *tmp = ls->head;
	linknode *a   = tmp->next;
	if(pos == 1)
	{
		ls->head = a;
	    free(tmp);
		ls->count--;
		return 0;		
	}
	else
	{
		while(--pos>1)
		{
			tmp = tmp->next;
			a = a->next;
		}
		tmp->next = a->next;
		free(a);
		ls->count--;
	}
	return 0;
}

int chg_va_linklist(linklist *ls,datatype old_va ,datatype va)
{
	if(NULL ==ls)	return -1;
	linknode *tmp = ls->head;
	while(tmp)
	{
		if(tmp->data == old_va)
		{
			tmp->data = va;
			return 0;
		}
		tmp = tmp->next;

	}
	return -2;
}

int chg_pos_linklist(linklist *ls,int pos,datatype va)
{
	int c = 1;
	if(NULL == ls)	return -1;
	if((pos>ls->count)||(pos<=0))	return -2;
	linknode *tmp = ls->head;
	while(tmp)
	{
		if(c == pos)
		{
			tmp->data = va;
			break;
		}
		tmp = tmp->next;
		c++;
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

int empty_linklist(linklist *ls)
{
	if(NULL == ls)		return -1;
	if(ls->count<=0)	return -2;
	return 0;
}

int free_linklist(linklist *ls)
{
	if(NULL == ls)		return -1;
	while(!empty_linklist(ls))
		del_pos_linklist(ls,1);
	free(ls);
	return 0;
}

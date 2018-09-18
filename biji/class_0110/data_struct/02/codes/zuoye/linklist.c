/* ************************************************************************
	> File Name: linklist.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月14日 星期二 10时27分25秒
	> Version: v1.0
 ************************************************************************/

#include "linklist.h"

/***************** 创建链表 *****************/
linknode * create_linklist(void)
{
	linknode * L = (linknode *)malloc(sizeof(linknode));
	if (NULL == L)		return NULL;
	bzero(L, sizeof(linknode));
	/*
	L->data = 0;
	L->next = NULL;
	*/

	return L;
}


/***************** 遍历单链表 *****************/
int show_linklist(linknode * L)
{
	if (NULL == L)		return -1;
	linknode * p = L;
	while (p != NULL)
//	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");

	return 0;
}


/***************** 释放单链表 *****************/
int free_linklist(linknode * L)
{
	if (NULL == L)		return -1;
	linknode * tmp = L;
	while (tmp != NULL)
	{
		L = tmp->next;
		free(tmp);
		tmp = L;
	}

	return 0;
}

/***************** 创建节点 *****************/
linknode * create_linknode(datatype value)
{
	linknode * p = (linknode *)malloc(sizeof(linknode));
	if (NULL == p)		return NULL;
	p->data = value;
	p->next = NULL;

	return p;
}


/***************** 尾部增加函数 *****************/
int add_tail_linklist(linknode * L, datatype value)
{
	if (NULL == L)		return -1;
	linknode * p = create_linknode(value);
	if (NULL == p)		return -1;
	linknode * tmp = L;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = p;
	L->data++;
	return 0;
}


/***************** 头部增加函数 *****************/
int add_head_linklist(linknode * L, datatype value)
{
	if (NULL == L)		return -1;
	linknode * p = create_linknode(value);
	if (NULL == p)		return -1;
	p->next = L->next;
	L->next = p;
	L->data++;
	return 0;
}

/***************** 修改增加函数 *****************/
int modify_value_linklist(linknode * L, datatype oldvalue, datatype newvalue)
{
	if (NULL == L)		return -1;
	linknode * p = L->next;
	while (p != NULL)
	{
		if (oldvalue == p->data)
		{
			p->data = newvalue;
		}
		p = p->next;
	}
	return 0;
}


/***************** 删除函数 *****************/
int delete_value_linklist(linknode * L, datatype value)
{
	if (NULL == L)		return -1;
	linknode * p = L, * tmp = L->next;
	while (tmp != NULL)
	{
		if (value == tmp->data)
		{
			p->next = tmp->next;
			free(tmp);
			tmp = p->next;
			L->data--;
		}
		else
		{
			p = p->next;
			tmp = tmp->next;
		}
	}
	return 0;
}


/***************** 查找函数 *****************/
int find_value_linklist(linknode * L, datatype value)
{
	if (NULL == L)		return -1;
	linknode * tmp = L->next;
	while (tmp != NULL)
	{
		if (value == tmp->data)
			return 1;
		else 
			tmp = tmp->next;
	}
	return 0;
}


/***************** 按位置进行插入函数 *****************/
int insert_pos_linklist(linknode * L, int pos, datatype value)
{
	if (NULL == L)		return -1;
	if ((pos < 1) || (pos > L->data))		return -1;
	pos -= 1;
	linknode * p = L, * tmp = L->next;
	while (pos--)
	{
		p = p->next;
		tmp = tmp->next;
	}
	linknode * p1 = create_linknode(value);
	if (NULL == p1)		return -1;
	p->next = p1;
	p1->next = tmp;
	L->data++;

	return 0;
}

/***************** 在目标值前面进行插入函数 *****************/
int insert_value_linklist(linknode * L, datatype destvalue, datatype value)
{
	if (NULL == L)		return -1;
	linknode * p = L, * tmp = L->next;
	while (tmp != NULL)
	{
		if (destvalue == tmp->data)
		{
			linknode * p1 = create_linknode(value);
			if (NULL == p1)		return -1;
			p->next = p1;
			p1->next = tmp;
			p = p->next;
		}
			tmp = tmp->next;
			p = p->next;
	}
	return 0;
}


/***************** 反转函数 *****************/
int reverse_linklist(linknode * L)
{
	if (NULL == L)		return -1;
	linknode * tmp = L->next, * p = tmp->next;
	while (p)
	{
		tmp->next = p->next;
		p->next = L->next;
		L->next = p;
		p = tmp->next;
	}
	return 0;
}


/***************** 反转函数 *****************/
int reverse_linklist1(linknode * L)
{
	if (NULL == L)		return -1;
	linknode * p = create_linklist();
	if (NULL == p)		return -1;
	linknode * tmp = L->next, *p1 = L;
	linknode * p2 = p;

	while (L->next != NULL)
	{
		p1 = L;
		tmp = L->next;
		while (tmp->next != NULL)
		{
			p1 = p1->next;
			tmp = tmp->next;
		}
		p1->next = NULL;

		while (p2->next != NULL)
		{
			p2 = p2->next;
		}
		p2->next = tmp;
		p->data++;
	}
	L->next = p->next;
	free(p);

	return 0;
}



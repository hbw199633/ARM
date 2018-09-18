/* ************************************************************************
	> File Name: clinklist.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月15日 星期三 09时49分14秒
	> Version: v1.0
 ************************************************************************/

#include "clinklist.h"

/**************** 创建节点 ****************/
linknode * create_linknode(datatype value)
{
	linknode * p = (linknode *)malloc(sizeof(linknode));
	if (NULL == p)		return NULL;
	p->data = value;
	p->next = p;

	return p;
}

/**************** 创建单项循环链表 ****************/
linknode * create_clinklist(void)
{
	return create_linknode(0);
}

/**************** 打印函数 ****************/
int show_clinklist(linknode * L)
{
	if (NULL == L)		return -1;
	linknode * tmp = L;
	while (tmp->next != L)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->data);
	return 0;
}


/**************** 释放函数 ****************/
int free_clinlist(linknode * L)
{
	if (NULL == L)		return -1;
	linknode * tmp = L, *p = L;
	while (L->next != p)
	{
		L = tmp->next;
		free(tmp);
		tmp = L;
	}
	free(L);
	return 0;
}

/**************** 尾部增加函数 ****************/
int add_tail_clinklist(linknode * L, datatype value)
{
	if (NULL == L)			return -1;
	linknode * tmp = L;
	while (tmp->next != L)
	{
		tmp = tmp->next;
	}
	linknode * p = create_linknode(value);
	if (NULL == p)			return -1;

	tmp->next = p;
	p->next = L;
	L->data++;

	return 0;
}

/**************** 头部增加函数 ****************/
int add_head_clinklist(linknode * L, datatype value)
{
	if (NULL == L)		return -1;
	linknode * p = create_linknode(value);
	if (NULL == p)		return -1;

	p->next = L->next;
	L->next = p;
	L->data++;

	return 0;
}

/**************** 修改函数 ****************/
int modify_value_clinklist(linknode * L, datatype oldvalue, datatype newvalue)
{
	if (NULL == L)		return -1;
	linknode * tmp = L->next;
	while (tmp != L)
	{
		if (oldvalue == tmp->data)
		{
			tmp->data = newvalue;
		}
		tmp = tmp->next;
	}
	return 0;
}


/**************** 查找函数 ****************/
int find_value_clinklist(linknode * L, datatype value)
{
	if (NULL == L)		return -1;
	linknode * tmp = L->next;
	while (tmp != L)
	{
		if (value == tmp->data)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

/**************** 指定位置返回函数 ****************/
int getvalue_pos_clinklist(linknode * L, int pos, datatype * value)
{
	if ((NULL == L) || (NULL == value))		return -1;
	if ((pos < 1) || (pos > L->data))	return -1;
	pos -= 1;
	linknode * tmp = L->next;
	while (pos--)
	{
		tmp = tmp->next;
	}
	*value = tmp->data;

	return 0;
}

/**************** 按位置删除函数 ****************/
int delete_pos_clinklist(linknode * L, int pos)
{
	if (NULL == L)		return -1;
	if ((pos < 1) || (pos > L->data))	return -1;
	linknode * tmp = L, * p = L->next;
	pos -= 1;
	/* int i = 0;
	 * for (i = 0; i < pos; i++)
	 * {
	 * 		tmp = tmp->next;
	 * 		p = p->nex;t
	 * }
	 * */
	while (pos--)
	{
		tmp = tmp->next;
		p = p->next;
	}
	tmp->next = p->next;
	free(p);
	L->data--;

	return 0;
}


/**************** 按值进行删除函数 ****************/
int delete_value_clinklist(linknode * L, datatype value)
{
	if (NULL == L)			return -1;
	linknode * tmp = L, * p = L->next;
	while (p != L)
	{
		if (value == p->data)
		{
			tmp->next = p->next;
			free(p);
			p = tmp->next;
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

/**************** 指定位置进行插入函数 ****************/
int insert_pos_valuel_clinklist(linknode * L, int pos, datatype value)
{
	if (NULL == L)						return -1;
	if ((pos < 1) || (pos > L->data))	return -1;
	pos -= 1;
	linknode * tmp = L;
	while (pos--)	
	{
		tmp = tmp->next;
	}
	linknode * p = create_linknode(value);
	if (NULL == p)			return -1;
	p->next = tmp->next;
	tmp->next = p;
	L->data++;

	return 0;
}


/**************** 指定值后面进行插入函数 ****************/
int insert_value_clinklist(linknode * L, datatype destvalue, datatype value)
{
	if (NULL == L)			return -1;
	linknode * tmp = L->next;
	while (tmp != L)
	{
		if (destvalue == tmp->data)
		{
			linknode * p = create_linknode(value);
			if (NULL == p)		return -1;
			p->next = tmp->next;
			tmp->next = p;
			L->data++;
			tmp = p->next;
		}
		else
		{
			tmp = tmp->next;
		}
	}
	return 0;
}


/**************** 约瑟夫环游戏 ****************/
int yuesefu_fun(linknode * L, int pos)
{
	if (NULL == L)			return -1;
	linknode * p = L->next;
	int num = 2;
	pos -= 1;
	while (pos--)
	{
		p = p->next;
		L = L->next;
	}

	while (L != p)
	{
		num = 2;
		while (num--)
		{
			p = p->next;
			L = L->next;
		}
		L->next = p->next;
		free(p);
		p = L->next;
	}
	printf("data:%d\n", L->data);
	free(L);
	L = NULL;
	return 0;
}



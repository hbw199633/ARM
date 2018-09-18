/* ************************************************************************
	> File Name: dlinklist.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月16日 星期四 10时05分22秒
	> Version: v1.0
 ************************************************************************/

#include "dlinklist.h"

/*************** 创建节点 ***************/
dlinknode * create_dlinknode(datatype value)
{
	dlinknode * p = (dlinknode *)malloc(sizeof(dlinknode));
	if (NULL == p)			return NULL;
	p->data = value;
	p->left = p->right = p;

	return p;
}

/*************** 创建双向循环链表 ***************/
dlinknode * create_dlinklist(void)
{
	return create_dlinknode(0);
}

/*************** 打印双向循环链表 ***************/
int show_right_dlinklist(dlinknode * L)
{
	if (NULL == L)			return -1;
	dlinknode * tmp = L;
	printf("%s:\n", __func__);
	while (tmp->right != L)
	{
		printf("%d ", tmp->data);
		tmp = tmp->right;
	}
	printf("%d\n", tmp->data);
	return 0;
}

int show_left_dlinklist(dlinknode * L)
{
	if (NULL == L)		return -1;
	dlinknode * tmp = L->right;
	printf("%s:\n", __func__);
	while (tmp = tmp->left, tmp->left != L)
	{
		printf("%d ", tmp->data);
	}
	printf("%d\n", tmp->data);
	return 0;
}

/*************** 释放双向循环链表 ***************/
int free_dlinklist(dlinknode * L)
{
	if (NULL == L)			return -1;
	dlinknode * tmp = L, * p = NULL;
	while (tmp->right != L)
	{
		p = tmp->right;
		free(tmp);
		tmp = p;
	}
	free(tmp);

	return 0;
}


/*************** 增加节点 ***************/
int add_tail_dlinklist(dlinknode * L, datatype value)
{
	if (NULL == L)		return -1;
	dlinknode * tmp = L->left;
	dlinknode * p = create_dlinknode(value);
	if (NULL == p)		return -1;

	tmp->right = p;
	p->left = tmp;
	p->right = L;
	L->left = p;

	L->data++;
	return 0;
}


/*************** 修改函数 ***************/
int modify_value_dlinklist(dlinknode * L, datatype oldvalue, datatype newvalue)
{
	if (NULL == L)			return -1;
	dlinknode * tmp = L->right;
	while (tmp != L)
	{
		if (oldvalue == tmp->data)
		{
			tmp->data = newvalue;
		}
		tmp = tmp->right;
	}
	return 0;
}

/*************** 增加节点 ***************/
int add_head_dlinklist(dlinknode * L, datatype value)
{
	if (NULL == L)		return -1;
	dlinknode * p = create_dlinknode(value);
	if (NULL == p)		return -1;

	p->right = L->right;
	L->right->left = p;
	L->right = p;
	p->left = L;
	L->data++;

	return 0;
}


/*************** 删除函数 ***************/
int delete_value_dlinklist(dlinknode * L, datatype value)
{
	if (NULL == L)			return -1;
	dlinknode * tmp = L, * p = L->right;
	while (p != L)
	{
		if (value == p->data)
		{
			p->right->left = tmp;
			tmp->right = p->right;
			free(p);
			p = tmp->right;
			L->data--;
		}
		else
		{
			p = p->right;
			tmp = tmp->right;
		}
	}
	return 0;
}


int delete_pos_dlinklist(dlinknode * L, int pos)
{
	if (NULL == L)						return -1;
	if ((pos < 1) || (pos > L->data))	return -1;
	pos -= 1;
	dlinknode * tmp = L->right;
	while (pos--)
	{
		tmp = tmp->right;
	}
	tmp->right->left = tmp->left;
	tmp->left->right = tmp->right;
	free(tmp);
	L->data--;

	return 0;
}


/*************** 查找函数 ***************/
int find_value_dlinklist(dlinknode * L, datatype value)
{
	if (NULL == L)			return -1;
	dlinknode * tmp = L->left;
	while (tmp != L)
	{
		if (value == tmp->data)
			return 1;
		else
			tmp = tmp->left;
	}
	return 0;
}

/*************** 插入函数 ***************/
/* 在指定值的后面插入一个新的节点 */
int insert_value_dlinklist(dlinknode * L, datatype destvalue, datatype value)
{
	if (NULL == L)			return -1;
	dlinknode * tmp = L->right;
	while (tmp != L)
	{
		if (destvalue == tmp->data)
		{
			dlinknode * p = create_dlinknode(value);
			if (NULL == p)		return -1;
			p->right = tmp->right;
			tmp->right->left = p;
			tmp->right = p;
			p->left = tmp;
			L->data++;
			tmp = p->right;
		}
		else
		{
			tmp = tmp->right;
		}
	}
	return 0;
}

int insert_pos_dlinklist(dlinknode * L, int pos, datatype value)
{
	if (NULL == L)						return -1;
	if ((pos < 1) || (pos > L->data))	return -1;
	dlinknode * tmp = L->right;
	pos -= 1;
	while (pos--)
	{
		tmp = tmp->right;
	}
	dlinknode * p = create_dlinknode(value);
	if (NULL == p)			return -1;

	tmp->left->right = p;
	p->left = tmp->left;
	p->right = tmp;
	tmp->left = p;

	L->data++;

	return 0;
}





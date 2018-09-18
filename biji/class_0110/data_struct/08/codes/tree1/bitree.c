/* ************************************************************************
	> File Name: bitree.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月21日 星期二 11时33分11秒
	> Version: v1.0
 ************************************************************************/

#include "bitree.h"
#include "linkqueue.h"

/**************** 创建节点 ****************/
bitree * create_node(datatype value)
{
	bitree * t = (bitree *)malloc(sizeof(bitree));
	if (NULL == t)		return NULL;
	t->data	= value;
	t->lchild = t->rchild = NULL;

	return t;
}

/**************** 创建二叉树 ****************/
bitree * create_bitree(char s[], int size, datatype value)
{
	if (NULL == s)			return NULL;
	if (s[value] == '#')	return NULL;
	bitree * root = (bitree *)malloc(sizeof(bitree));
	if (NULL == root)		return NULL;
	root->data = s[value];
	root->lchild = root->rchild = NULL;

	if (2*value <= size)
	{
		root->lchild = create_bitree(s, size, 2*value);
	}
	if (2*value + 1 <= size)
	{
		root->rchild = create_bitree(s, size, 2*value+1);
	}
	return root;
}


/**************** 先序遍历二叉树 ****************/
int pro_order(bitree * root)
{
	if (NULL == root)		return -1;
	printf("%c ", root->data);
	if (root->lchild)
	{
		pro_order(root->lchild);
	}
	if (root->rchild)
	{
		pro_order(root->rchild);
	}
	return 0;
}

int mid_order(bitree * root)
{
	if (NULL == root)		return -1;
	if (root->lchild)
	{
		mid_order(root->lchild);
	}
	printf("%c ", root->data);
	if (root->rchild)
	{
		mid_order(root->rchild);
	}
	return 0;
}


int no_order(bitree * root)
{
	if (NULL == root)		return -1;
	linkqueue * q = create_linkqueue();
	if (NULL == q)			return -1;
	entry_linkqueue(q, (datatype)root);
	bitree * t = NULL;
	while (!isempty_linkqueue(q))
	{
		exit_linkqueue(q, (datatype *)&t);
		printf("%c ", t->data);
		if (t->lchild)
		{
			entry_linkqueue(q, (datatype)t->lchild);
		}
		if (t->rchild)
		{
			entry_linkqueue(q, (datatype)t->rchild);
		}
	}
	free_linkqueue(q);
	printf("\n");
	return 0;
}

/**************** 释放二叉树 ****************/
int free_bitree(bitree * root)
{
	if (NULL == root)		return -1;
	if (root->lchild)
	{
		free_bitree(root->lchild);
	}
	if (root->rchild)
	{
		free_bitree(root->rchild);
	}
	free(root);
	return 0;
}



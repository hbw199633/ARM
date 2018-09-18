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
bitree * create_bitree(int size, datatype value)
{
	bitree * root = create_node(value);
//	printf("value:%d ", value);
	if (NULL == root)		return NULL;
	if (2*value <= size)
	{
		root->lchild = create_bitree(size, 2*value);
		/*value = 1,value = 2						*/
	}
	if (2*value + 1 <= size)
	{
		root->rchild = create_bitree(size, 2*value+1);
		/* value = 2 */
	}
	return root;
}


/**************** 先序遍历二叉树 ****************/
int pro_order(bitree * root)
{
	if (NULL == root)		return -1;
	printf("%d ", root->data);
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
	printf("%d ", root->data);
	if (root->rchild)
	{
		mid_order(root->rchild);
	}
	return 0;
}


#if 1
int no_order(bitree * root)
{
	if (NULL == root)		return -1;
	linkqueue * q = create_linkqueue();
	if (NULL == q)			return -1;
	entry_linkqueue(q, root);
	bitree * t = NULL;
	while (!isempty_linkqueue(q))
	{
		exit_linkqueue(q, &t);
		printf("%d ", t->data);
		if (t->lchild)
		{
			entry_linkqueue(q, t->lchild);
		}
		if (t->rchild)
		{
			entry_linkqueue(q, t->rchild);
		}
	}
	free_linkqueue(q);
	printf("\n");
	return 0;
}
#endif




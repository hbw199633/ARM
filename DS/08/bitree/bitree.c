/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: bitree.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月28日 星期三 11时08分09秒
***************************************************/

#include "bitree.h"
#include "Linkqueue.h"

bitree *create_bnode(datatype va)
{
	bitree *n  =(bitree *)malloc(sizeof(bitree));
	if(NULL == n)	return NULL;
	bzero(n,sizeof(bitree));
	n->data = va;
	return n;
}

bitree *create_bitree(int va,int size)
{
	bitree * n = create_bnode(va);
	if(NULL == n)	return NULL;
	if(2*va<= size)
		n->lchild = create_bitree(2*va,size);
	if(2*va+1<= size)
		n->rchild = create_bitree(2*va+1,size);
	return n;
}

int pro_order(bitree *n)
{
	printf(" %d ",n->data); //根
	if(n->lchild)
		pro_order(n->lchild); //左
	if(n->rchild)
		pro_order(n->rchild); //右
	return 0;
}

int mid_order(bitree *n)
{
	if(n->lchild)
		mid_order(n->lchild); //左
	printf(" %d ",n->data); //根
	if(n->rchild)
		mid_order(n->rchild); //右
	return 0;
}

int aft_order(bitree *n)
{
	if(n->lchild)
		aft_order(n->lchild); //左
	if(n->rchild)
		aft_order(n->rchild); //右
	printf(" %d ",n->data); //根
	return 0;
}

int ceng_order(bitree *n)
{
	if(NULL == n)	return -1;
	datatype va = 0;
	linkqueue *q = create_linkqueue();
	enter_linkqueue(q,(datatype)n);
	while(!empty_linkqueue(q))
	{
		exit_linkqueue(q,&va);
		bitree *t = (bitree *)va;
		printf(" %d ",t->data);
		if(t->lchild)
			enter_linkqueue(q,(datatype)t->lchild);
		if(t->rchild)
			enter_linkqueue(q,(datatype)t->rchild);
	}
	printf("\n");
	free_linkqueue(q);
}

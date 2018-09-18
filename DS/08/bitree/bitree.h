/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: bitree.h
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月28日 星期三 11时08分15秒
***************************************************/

#ifndef _BITREE_H_
#define _BITREE_H_

#include "head.h"
typedef struct _bnode_
{
	struct _bnode_	*lchild;
	datatype		data;
	struct _bnode_	*rchild;
}bitree;

extern bitree *create_bnode(int va);
extern bitree *create_bitree(int va,int size);
extern int pro_order(bitree *n);
extern int mid_order(bitree *n);
extern int aft_order(bitree *n);
extern int ceng_order(bitree *n);

#endif

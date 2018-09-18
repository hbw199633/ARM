/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: main.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月28日 星期三 11时08分01秒
***************************************************/
#include "head.h"
#include "bitree.h"

int main(int argc,const char* argv[])
{
	int i = 1,szie = 7;
	bitree *root = create_bitree(i,szie);
/*	pro_order(root);
	printf("\n");
	mid_order(root);
	printf("\n");
	aft_order(root);
	printf("\n");
  */
	ceng_order(root); 
	return 0;
}

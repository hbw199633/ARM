/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fopen.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月07日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 100;
	int *pa = &a;
	printf(" pa = %x *pa = %x \n",pa,*pa);

	FILE * fp = fopen("./b.txt","r");
	if(NULL == fp)
	{
		perror("xxxx");
		return -1;
	}

	printf("fopen open file ok !!! fp = %x *fp = %x \n",fp,*fp);

	FILE * fp2  = fopen("./b.txt","r");
	printf("fopen open file ok !!! fp2 = %x *fp2 = %x \n",fp2,*fp2);


    return 0;
}

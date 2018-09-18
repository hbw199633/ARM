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

	FILE * fp = fopen("./b.txt","r+");
	if(NULL == fp)
	{
		perror("xxxx");
		return -1;
	}

	printf("fopen open file ok !!! \n");

	int c = fputc('G',fp);
	if(-1 == c)
	{
		perror("fputc");
		return -1;
	}

	printf("fputc ok ~!!! \n");


    return 0;
}

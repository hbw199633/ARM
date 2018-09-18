/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：hello.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月19日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i  = 0;
	for(i=0;i<argc;i++)
	{
		printf("i = %d argv= %s \n",i,argv[i]);
	}
    return 0;
}

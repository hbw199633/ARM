/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：main.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月26日
*   描    述：
================================================================*/

#include <stdio.h>
#include "fun.h"

int main(int argc, char *argv[])
{

	printf_hello();

	int x = 5,y = 6;

	printf("input num: ");
	scanf("%d %d",&x ,&y);

	int z = add(x,y);
	if(z == -1)
	{
		printf("输入错误\n");
		return -1;
	}
	else if(z == -2)
	{
		printf("就算异常\n");
		return -1;
	}
	else
		printf("%d + %d  = %d \n",x,y,z);



    return 0;
}

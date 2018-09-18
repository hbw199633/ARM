/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fun.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月26日
*   描    述：
================================================================*/
#include <stdio.h>

void printf_hello()
{
	printf("hello world \n");
}


int add(int a,int b)
{
	if((a  > 100 ) && ( b > 100))  return -2;
	if((a < -100) && (b < -100))   return -1;

	int c = a + b;
	return  c;
}

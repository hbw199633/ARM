/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：gets.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月11日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	char buff[10]= {0};
	gets(buff);
	printf("buff = %s \n",buff);

    return 0;
}

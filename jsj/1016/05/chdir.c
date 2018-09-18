/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：chdir.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月25日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	
	printf("main.... \n");

	getchar();

	system("touch b");

	getchar();

	chdir("./test");

	getchar();
	system("touch b");


    return 0;
}

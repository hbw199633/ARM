/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：a.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月25日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	while(1)
	{
		printf("hello %d \n",getpid());
		sleep(1);
	}

    return 0;
}

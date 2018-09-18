/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：raise.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	printf("nihao \n");

	alarm(5);

	while(1)
	{
		printf("test  ... \n");
		sleep(1);
	}

    return 0;
}

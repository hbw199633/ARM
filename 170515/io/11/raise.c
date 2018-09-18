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
	while(1)
	{
		sleep(1);
		printf("nihao \n");
		raise(19);
		sleep(3);
		raise(18);
		printf("wohao \n");
	}


    return 0;
}

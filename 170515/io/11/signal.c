/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：signal.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void  fun(int sig)
{
	if(sig == 4)
		printf("fun  ,...  \n");
	else if(sig == 5)
		printf("hello world \n");
	else
		exit(0);
}

int main(int argc, char *argv[])
{
	signal(1,SIG_IGN);
	signal(2,SIG_IGN);
	signal(3,SIG_IGN);
	signal(4,fun);
	signal(5,fun);
	signal(6,fun);
	while(1)
	{
		sleep(1);
		printf("nihao mypid = %d\n",getpid());
	}

    return 0;
}

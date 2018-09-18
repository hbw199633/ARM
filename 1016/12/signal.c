/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：signal.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月04日
*   描    述：
================================================================*/

#include <stdio.h>
#include <signal.h>

void test(int sig)
{
	printf("test... \n");
	return ;
}
int main(int argc, char *argv[])
{
	signal(1,SIG_IGN);
	signal(2,SIG_IGN);
	signal(3,SIG_DFL);
	signal(4,test);

	while(1)
	{
		printf("my pid = %d \n",getpid());
		sleep(1);
	}

    return 0;
}

/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：alarm.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月04日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>


void test(int sig)
{
	printf("test alarm... \n");
	return ;
}
int main(int argc, char *argv[])
{
	signal(SIGALRM,test);	
	alarm(5);

	int count = 0;
	while(1)
	{
		printf("count = %d \n",count++);
		sleep(1);
	}


    return 0;
}

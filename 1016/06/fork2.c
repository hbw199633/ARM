/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fork2.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月26日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("hello world \n");
	getchar();

	pid_t pid = fork();
	/*
	if(pid == 0)
	{
		while(1)
		{
			printf("child ... pid = %d\n",pid);
			sleep(1);
		}
	}
	*/

	while(1)
	{
		printf(" sleep   ...pid = %d \n",pid);
		sleep(2);
	}


    return 0;
}

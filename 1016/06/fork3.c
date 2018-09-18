/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fork3.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月26日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	printf("main pid = %d ppid = %d \n",getpid(),getppid());

	pid_t pid = fork();

	if(pid  == 0)
	{
		printf("child  pid = %d ppid = %d \n",getpid(),getppid());
	}
	if(pid > 0)
	{
		printf("father pid = %d ppid = %d  child pid = %d \n",getpid(),getppid(),pid);
		sleep(3);
	}
	

    return 0;
}

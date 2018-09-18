/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：fork.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月03日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

	pid_t pid = fork();
	if(pid == 0)
	{
		printf(" child .... pid = %d \n", getpid());
		printf(" child .... pid = %d \n", getpid());
		printf(" child .... pid = %d \n", getpid());
	
		sleep(5);

		exit(0);

	}
	
	if(pid > 0)
	{
		
		printf(" father .... pid = %d \n", getpid());
		printf(" father .... pid = %d \n", getpid());
		printf(" father .... pid = %d \n", getpid());

		wait(NULL);
	
	}



    return 0;
}

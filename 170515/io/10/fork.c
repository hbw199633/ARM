/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fork.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月24日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	printf("main ...  \n");
	printf("main ...  \n");
	printf("main ...  \n");

	char buff[128] ={0};
	pid_t pid = fork();
	if(pid == 0)
	{
		while(1)
		{
			sleep(1);
			sprintf(buff,"child run pid = %d \n",getpid());
		}
		exit(0);
	}
	if(pid > 0)
	{
		while(1)
		{
			sleep(2);
			sprintf(buff,"father run pid = %d \n",getpid());
		}
		wait(NULL);
		exit(0);
	}

	if(pid < 0)
	{
		perror("fork");
		return -1;
	}
    return 0;
}

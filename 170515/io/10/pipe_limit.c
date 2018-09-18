/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：pipe.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月24日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int fd[2] ={0};
	int i  =0 ;
	int ret = pipe(fd);
	if(ret < 0)
	{
		perror("pipe");
		return -1;
	}
	printf("ret = %d fd[0] =%d fd[1] = %d \n",ret,fd[0],fd[1]);

	pid_t pid = fork();
	if(pid == 0)
	{
		sleep(60);
		exit(0);
	}
	if(pid > 0)
	{
		char c = 'x';
		int count  = 0;
		while(1)
		{
			write(fd[1],&c,sizeof(char));
			printf("count   = %d \n",count++);
		}
		wait(NULL);
		exit(0);
	}

	if(pid < 0)
	{
		perror("fork");
	}

    return 0;
}

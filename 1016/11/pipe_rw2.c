/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：pipe.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月03日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	
	int fd[2];
	int ret = pipe(fd);
	if(ret < 0)
	{
		perror("create pipe error");
		return -1;
	}
	printf("ret = %d \n",ret);

	pid_t pid = fork();
	if(pid == 0)
	{
		int  a = 0;
		int *b = (int*)malloc(sizeof(int));
		read(fd[0],b,sizeof(int));   ////write pipe
		printf("read b = %d\n",*b);		
		free(b);
		exit(0);
	}
	if(pid > 0)
	{
		sleep(1);
		int a = 100;
		write(fd[1],&a,sizeof(int));
		wait(NULL);
	}


    return 0;
}

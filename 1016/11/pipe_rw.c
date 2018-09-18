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
		close(fd[0]);
		ret = write(fd[1],"hello world",11);   ////write pipe
		printf("write ret = %d \n",ret);
		exit(0);
	}
	if(pid > 0)
	{
		close(fd[1]);

		char buff[32] ={0};
		printf("read 1 buff = %s \n",buff);
		read(fd[0],buff,sizeof(buff));
		printf("read 2 buff = %s \n",buff);
		wait(NULL);
	}


    return 0;
}

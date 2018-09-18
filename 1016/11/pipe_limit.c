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

	pid_t pid = fork();
	if(pid == 0)
	{
		int ret = 0,count = 0;
		while(1)
		{
			ret = write(fd[1],"a",1);   ////write pipe
			if(ret == 1) 
			{ 
				count ++;
			    printf("count = %d \n",count);
			}
		}
		exit(0);
	}
	if(pid > 0)
	{
		//char buff[32] ={0};
		//printf("read 1 buff = %s \n",buff);
		//read(fd[0],buff,sizeof(buff));
		//printf("read 2 buff = %s \n",buff);
		wait(NULL);
	}


    return 0;
}

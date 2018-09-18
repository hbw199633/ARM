/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：main.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "myfifo.h"

int main(int argc, char *argv[])
{
	char buff[128] ={0};
	int ret = 0;
	pid_t pid = fork();
	if(pid == 0)
	{
		while(1)
		{
			bzero(buff,sizeof(buff));
			ret =fifo_read(NULL,buff,sizeof(buff));
			if(ret < 0)
			{
				printf("fifo read error ,arg error \n");
				break;
			}
			else if(ret > 0)
			{
				perror("fifo read"); break;
			}
			printf("fifo read buff = %s \n",(char *)buff);
		}
		exit(0);
		
	}
	if(pid > 0)
	{
		while(1)
		{
			bzero(buff,sizeof(buff));
			printf("输入任意字符串\n");
			scanf("%s",buff);
			ret =fifo_write("test",NULL,sizeof(buff));
			if(ret < 0)
			{
				printf("fifo write error ,arg error \n");
				break;
			}
			else if(ret > 0)
			{
				perror("fifo write"); break;
			}
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

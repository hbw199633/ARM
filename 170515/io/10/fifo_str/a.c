/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：a.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月24日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "head.h"



int main(int argc, char *argv[])
{
	int  x = 0;
	struct test x2 ={0};
	x2.e  = malloc(32);
	int fd_read = 0;
	int ret = mkfifo("./myfifo",0644);
	if(ret < 0)
	{
		if(errno != EEXIST)
		{
			perror("mkfifo");
			return -1;
		}
	}
	fd_read = open("./myfifo",O_RDONLY);
	if(fd_read < 0)
	{
		perror("open");
		return -1;
	}

	while(1)
	{
		sleep(1);
		ret = read(fd_read,x2.e,32);
		if(ret > 0)
		{
			printf("fifo read x2.a = %s \n",(char *)x2.e);
		}


	}

    return 0;
}

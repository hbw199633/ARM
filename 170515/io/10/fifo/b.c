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
	int  x = 0,ret =0;
	struct test xx ={100,"zhangsan",99.9,90000};
	int fd_write = 0;

	ret = mkfifo("./myfifo",0644);
	if(ret < 0)
	{
		if(errno != EEXIST)
		{
			perror("mkfifo");
			return -1;
		}
	}
	fd_write = open("./myfifo",O_WRONLY);
	if(fd_write < 0)
	{
		perror("open");
		return -1;
	}

	while(1)
	{
		sleep(1);  x++;
		ret = write(fd_write,&xx,sizeof(struct test));
		printf("fifo write ret = %d\n",ret);
	}

    return 0;
}

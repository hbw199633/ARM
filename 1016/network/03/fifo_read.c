/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：fifo_read.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月10日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	//int fd = open("./fifo",O_RDONLY);
	int fd = open("./fifo",O_RDONLY|O_NONBLOCK);
	if(fd < 0)
	{
		perror("open fifo");
		return -1;
	}
	char buff[128] ={0};
	int ret = read(fd,buff,sizeof(buff));
	if(ret > 0)
	{
		printf("read buff = %s \n",buff);
	}
	else
	{
		perror("read fifo");
	}

	close(fd);


    return 0;
}

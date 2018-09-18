/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fifo.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月02日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("./fifo",O_RDONLY|O_NONBLOCK);
	//int fd = open("./fifo",O_RDONLY);
	if(fd < 0)
	{
		perror("open read");
		return -1;
	}

	char buff[128] ={0};

	read(fd,buff,sizeof(buff));


	close(fd);

    return 0;
}

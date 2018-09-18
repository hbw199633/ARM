/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：open.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月13日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("./1.txt",O_RDONLY);
	if(-1 == fd)
	{
		printf("fopen error !\n");
		return -1;
	}

	printf("fd = %d \n",fd);


	close(fd);

    return 0;
}

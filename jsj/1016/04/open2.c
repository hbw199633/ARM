/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：open2.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月14日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_A    O_WRONLY|O_CREAT|O_APPEND
#define FILE_AP   O_RDWR|O_CREAT|O_APPEND

int main(int argc, char *argv[])
{

	//int fd = open("./2.txt",O_RDWR|O_CREAT,0644);
	//int fd = open("./2.txt",O_RDWR|O_CREAT|O_APPEND,0644);
	//int fd = open("./2.txt",FILE_A,0644);
	int fd = open("./3.txt",FILE_AP);
	if(-1 == fd)
	{
		printf("open file");
		return -1;
	}

	printf("file create ok! \n");

	write(fd,"x",1);

	close(fd);

    return 0;
}

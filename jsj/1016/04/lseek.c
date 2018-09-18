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
	int fd = open("./1.txt",O_RDWR);
	if(-1 == fd)
	{
		printf("fopen error !\n");
		return -1;
	}

	printf("fd = %d \n",fd);

	write(fd,"a",1);

	int ret = lseek(fd,10,SEEK_SET);
	printf("lseek1 ret = %d\n",ret);

	write(fd,"b",1);

	lseek(fd,-5,SEEK_CUR);

	write(fd,"c",1);

	lseek(fd,-1,SEEK_END);

	char x = 0;
	read(fd,&x,1);
	printf("read x = %c \n",x);

	close(fd);

    return 0;
}

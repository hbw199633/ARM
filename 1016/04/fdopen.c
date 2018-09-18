/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fdopen.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("./1.txt",O_RDWR);
	if(fd < 0)
	{
		printf("open file error");
		return -1;
	}
	
	FILE * fp = fdopen(fd,"r+");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}

	fputs("hello ",fp);
	
	fclose(fp);

	close(fd);

    return 0;
}

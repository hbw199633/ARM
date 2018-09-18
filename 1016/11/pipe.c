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

int main(int argc, char *argv[])
{
	
	int fd[2];
	int ret = pipe(fd);
	if(ret < 0)
	{
		perror("create pipe error");
		return -1;
	}
	printf("ret = %d \n",ret);


    return 0;
}

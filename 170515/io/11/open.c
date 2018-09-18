/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：open.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{

	int fd = open("./abc",O_RDONLY);
	if(fd < 0)
	{
		//perror("open");
		printf("errno  = %d errmsg = %s \n",
				errno,strerror(errno));
		return errno;
	}




    return 0;
}

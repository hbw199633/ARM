/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：mkfifo.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月03日
*   描    述：
================================================================*/

#include  "head.h"

int main(int argc, char *argv[])
{
	int ret = mkfifo("./def",0644);
	if(ret < 0)
	{
		if(errno != EEXIST)
		{
			perror("mkfifo");
			return -1;
		}
	}
	printf("mkfifo ok!!! \n");



	unlink("./def");

    return 0;
}

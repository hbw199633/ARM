/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fork.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月27日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	pid_t xxx = fork();

	if(xxx == 0)
	{
		printf("child ... ");
		sleep(1000);
		_exit(0);
	}
	else  if(xxx  > 0)
	{
		printf("father .... ");
		sleep(1000);
		_exit(0);
	}


	while(1)  sleep(1);

    return 0;
}

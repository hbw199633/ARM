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
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

	pid_t xxx = fork();

	if(xxx == 0)
	{
		printf("child ...  getpid = %d \n",getpid());
		sleep(5);
		exit(0);
	}
	else  if(xxx  > 0)
	{
		printf("father .... \n");
		
		//sleep(30);
		int ret = wait(NULL);
		printf("ret = %d \n",ret);
		sleep(15);
		exit(0);
	}



    return 0;
}

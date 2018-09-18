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
		printf("child ...15  getpid = %d \n",getpid());
		sleep(15);
		exit(0);
	}

	pid_t yyy = fork();
	if(yyy == 0)
	{
		printf("child ...10   getpid = %d \n",getpid());
		sleep(10);
		exit(0);	
	}

	pid_t zzz = fork();
	if(zzz == 0)
	{
		printf("child ... 5  getpid = %d \n",getpid());
		sleep(5);
		exit(0);	
	}


	int ret = wait(NULL);
	printf("father ret = %d \n",ret);

	int ret2 = wait(NULL);
	printf("father ret = %d \n",ret2);

	int ret3 = wait(NULL);
	printf("father ret = %d \n",ret3);

    return 0;
}

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
		printf("child ...3 getpid = %d \n",getpid());
		sleep(3);
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

	int count = 0;
	while(1)
	{
		int ret = waitpid(yyy,NULL,WNOHANG);
		if(ret > 0) 
		{
			printf("father ret = %d \n",ret);
			count ++;
		}

		int ret2 = waitpid(zzz,NULL,WNOHANG);
		if(ret2 > 0) 
		{
			count ++;
			printf("father ret = %d \n",ret2);
	 	}
		int ret3 = waitpid(xxx,NULL,WNOHANG);
		if(ret3 > 0) 
		{
			count ++;
			printf("father ret = %d \n",ret3);
        }

		if(count == 3) break;

		sleep(1);
	}
    return 0;
}

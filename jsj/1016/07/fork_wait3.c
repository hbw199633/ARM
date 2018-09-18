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
		sleep(3);
		exit(15);
	}
	else  if(xxx  > 0)
	{
		printf("father .... \n");
		
		int status =0;
		int ret = wait(&status);
		printf("ret = %d status = %d \n",ret,WEXITSTATUS(status));
		//sleep(15);
		exit(0);
	}



    return 0;
}

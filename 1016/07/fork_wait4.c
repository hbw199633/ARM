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
	int i = 0;
	for(i=0;i<3;i++)
	{
		pid_t pid= fork();
		if(pid == 0)
		{
			printf("child ...i= %d  getpid = %d \n",i,getpid());
			sleep(5);
			//pid[i] = getpid();
			//exit(0);
			goto eixt;
		}

	}
	
	///printf("请输入要停止的进程pid\n");
	///scanf("%d",&www);

eixt:
	if(i == 1)
	{
		
		exit(0);
	}
	else if((i == 0) || (i == 2))
	{
		while(1)  sleep(1);
	}


	printf("test.... \n");
	int ret = wait(NULL);
	printf("father ret = %d \n",ret);


    return 0;
}

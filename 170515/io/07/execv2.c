/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：execv.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月19日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	char *agv[] ={"top",NULL};
	pid_t pid = fork();
	if(pid == 0)
	{
	//	printf("child pid = %d \n",getpid());
		execv("/usr/bin/top",agv);
		exit(0);
	}

	sleep(5);


	char name[32] ={0};
	sprintf(name,"%d",pid);
	//printf("name = %s \n",name);
	char *agv2[] = {"kill",name,NULL};
	pid_t pid2 = fork();
	if(pid2 == 0)
	{
		execv("/bin/kill",agv2);
		exit(0);
	}

	if(pid > 0)  
	{
		wait(NULL);
		wait(NULL);
	}

	if(pid < 0)  perror("fork");

    return 0;
}

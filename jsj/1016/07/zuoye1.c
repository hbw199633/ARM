/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：zuoye1.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月28日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i = 0,sta = 0,ret =0;
	pid_t pid = fork();
	if(pid == 0)
	{
		char *arg[] ={"b.out",NULL};
		ret = execv("./b.out",arg);
		exit(ret);
	}
	
	for(i=0;i<10;i++)
	{
		ret = waitpid(pid,&sta,WNOHANG);
		if(ret > 0)
		{
			exit(0);
		}
		sleep(1);
	}

	char num[128] ={0};
	sprintf(num,"%d",pid);
	pid = fork();
	if(pid == 0)
	{
		char *arg[] ={"kill","-9",num,NULL};
		ret= execv("/bin/kill",arg);
		exit(ret);
	}
	wait(NULL);


    return 0;
}

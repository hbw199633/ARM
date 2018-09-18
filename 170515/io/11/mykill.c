/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：kill.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	int sig = -1,ret = 0;
	pid_t pid = 0;
	
	if( (argc == 1) || (argc > 3) )
	{
		printf("Usage %s [sig] [pid] \n",argv[0]);
		return -1;
	}

	if(argc == 2)  
	{ 
		sig = 15;	
		pid = atoi(argv[1]);
		if(pid <2)
		{
			printf("pid error\n");
			return -1;
		}
		if(!strcmp(argv[1],"-l"))
		{
			printf("暂不支持\n");
			return -1;
		}	
	}
	else
	{
		sig = atoi(argv[1]);
		if( (sig <= 0) || (sig > 64))
		{
			printf("sig error \n");
			return -1;
		}
		pid = atoi(argv[2]);
		if(pid <2)
		{
			printf("pid error\n");
			return -1;
		}
	}
		
	ret = kill(pid,sig);
	if(ret < 0)
	{
		perror("kill");
		return -1;
	}

return 0;
}

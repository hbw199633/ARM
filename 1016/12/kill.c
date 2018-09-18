/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：kill.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月04日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage %s [sig] [pid] \n",argv[0]);
		return -1;
	}

	//int sig = atoi(&argv[1][1]) ;
	int sig = atoi(argv[1]) ;
	sig = sig * -1;
	//printf("sig = %d \n",sig);
	int pid = atoi(argv[2]);

	int ret = kill(pid,sig);
	if(ret < 0)
	{
		perror("kill send");
		return -1;
	}
	printf("kill ok \n");

    return 0;
}

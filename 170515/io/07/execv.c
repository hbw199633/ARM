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

	char *agv[] ={"ls",
				  "-l","-a",NULL};

	pid_t pid = fork();
	if(pid == 0)
	{
		execv("/bin/ls",agv);
		exit(0);
	}
	if(pid > 0)  wait(NULL);
	if(pid < 0)  perror("fork");

    return 0;
}

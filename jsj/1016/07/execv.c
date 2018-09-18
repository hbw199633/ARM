/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：execv.c
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
	
	pid_t  pid=  fork();
	if(pid == 0)
	{
		char *arg[] = {"aaa","-l","-a","./",NULL};
		int ret = execv("/bin/ls",arg);
		exit(ret);
	}


	wait(NULL);


    return 0;
}

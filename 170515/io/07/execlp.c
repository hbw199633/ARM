/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：execl.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月19日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	
	pid_t pid = fork();
	if(pid == 0)
	{
		//int ret = execlp("ls","ls",NULL);
		//int ret = execlp("ls","ls","-l","-a",NULL);
		int ret = execlp("ls1","ls1","-l","-a",NULL);
		if(ret <0 ) perror("execl");
		exit(errno);
	}
	if(pid > 0)  
	{
		int sta = 0;
		wait(&sta);
		printf("father wait sta = %d \n",WEXITSTATUS(sta));
	}
	if(pid < 0)  perror("fork");

    return 0;
}

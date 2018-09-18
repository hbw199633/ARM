/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：execlp.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月28日
*   描    述：
================================================================*/

#include  "head.h"

int main(int argc, char *argv[])
{
	int ret = 0;
	pid_t  pid = fork();
	if(pid == 0)
	{
		//ret = execlp("ls","ls","-l","./",NULL);
		char *arg[]={"ls","-l","./",NULL};
		ret = execvp("ls",arg);
		exit(ret);
	}
	wait(NULL);


    return 0;
}

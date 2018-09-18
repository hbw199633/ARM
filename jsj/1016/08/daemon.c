/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：daemon.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月28日
*   描    述：
================================================================*/

#include  "head.h"

int main(int argc, char *argv[])
{

	pid_t  pid = fork();
	if(pid > 0 ) 
	{
//		sleep(10);
		exit(0);
	}
	setsid();
	chdir("/daemon");
	umask(0);
	//system("touch yyy");	
	int i = 0;
	for(i=0;i<getdtablesize();i++)
	{
		close(i);
	}

	//printf("hello world \n");
	//===========================================
	
	
	////模拟的守护进程的业务逻辑
	while(1)
	{
		sleep(1);
	}



    return 0;
}

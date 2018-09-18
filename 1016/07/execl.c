/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：execl.c
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

	pid_t pid = fork();
	if(pid == 0)
	{
		//int ret = execl("/bin/lsx","lsx","-l","-a","./",NULL);
		int ret = execl("./c.out","c.out",NULL);
		if(ret != 0 )
			exit(ret);
		else
			exit(0);
	}


	int sta =0;
	wait(&sta);
	printf("execl ret = %u \n",WEXITSTATUS(sta));


    return 0;
}

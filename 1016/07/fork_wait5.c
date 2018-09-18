/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fork.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月27日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{


	char * str[5] ={
				"nihao", "wohao","error","warning","unknown"
				};
	pid_t xxx = fork();
	if(xxx == 0)
	{
		printf("child ... \n");
		sleep(5);
		exit(1);
	}
	else  if(xxx  > 0)
	{
		printf("father .... ");
		
		int sta = 0;
		wait(&sta);
		printf("child ret str = %s \n",str[WEXITSTATUS(sta)-1]);
	}



    return 0;
}

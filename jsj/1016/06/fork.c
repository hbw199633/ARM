/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fork.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月26日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 99;
	pid_t pid = fork();
	printf("nihao \n");

	if(pid == 0)
	{
		i++;
		printf("child ... pid = %d i = %d \n",pid,i);
		

	}
	if(pid > 0)
	{
		i--;
		printf("father... pid = %d i = %d \n",pid,i);
	}
	if(pid < 0)
	{
		printf("fork error \n");
	}


	while(1)
	{
		sleep(1);
	}

	printf("\n");


    return 0;
}

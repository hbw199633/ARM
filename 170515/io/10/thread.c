/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：thread.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月24日
*   描    述：
================================================================*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *fun1(void *arg)
{
	while(1)
	{
		sleep(1);
	}
	pthread_exit(0);
}

void *fun2(void *arg)
{
	while(1)
	{
		sleep(2);
	}
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	
	pthread_t tid1 =0,tid2  =0;

	pthread_create(&tid1,NULL,fun1,NULL);
	pthread_create(&tid2,NULL,fun2,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


    return 0;
}

/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：pthread.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月28日
*   描    述：
================================================================*/

#include <stdio.h>
#include <pthread.h>


void * fun1(void *arg)
{
	int *px = (int *)arg;

	while(1)
	{
		printf("child %lu thread run.... static x = %d \n",pthread_self(), (*px)++ );
		sleep(1);
	}
	return NULL;
}

void * fun2(void *arg)
{
	int *py = (int *)arg;
	while(1)
	{
		printf("child %lu thread run.... static x = %d \n",pthread_self(),*py);
		sleep(1);
	}
	return NULL;
}


int main(int argc, char *argv[])
{
	pthread_t  tid =0;
	static int  x = 0;
	int i = 0;
		pthread_create(&tid,NULL,fun1,&x);
		pthread_create(&tid,NULL,fun2,&x);

	//sleep(20);  ////main  thread

    return 0;
}

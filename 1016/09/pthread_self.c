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


void * fun(void *arg)
{
	printf("child %lu thread run....  \n",pthread_self());
	sleep(15);
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t  tid =0;

	int i = 0;
	for(i=0;i<5;i++)
	{
		pthread_create(&tid,NULL,fun,NULL);
	}

	sleep(20);  ////main  thread

    return 0;
}

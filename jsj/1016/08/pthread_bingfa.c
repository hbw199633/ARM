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

int  x ;
void * fun1(void *arg)
{
	while(1)
	{
		printf(" nihao x = %d \n",x++);
		sleep(1);
	}
	return NULL;
}
void * fun2(void *arg)
{
	while(1)
	{
		printf("wohao x = %d\n",x);
		sleep(1);
	}
	return NULL;
}


int main(int argc, char *argv[])
{
	pthread_t  tid =0;

	pthread_create(&tid,NULL,fun1,NULL);
	pthread_create(&tid,NULL,fun2,NULL);


	sleep(20);  ////main  thread

    return 0;
}

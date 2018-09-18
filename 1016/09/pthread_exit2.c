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

	printf("child %lu thread run.... \n",pthread_self());
	
	sleep(15);
	
	pthread_exit(NULL);

	printf("pthread exit.... \n");

	return NULL;
}

void * fun2(void *arg)
{
	int *py = (int *)arg;
		printf("child %lu thread run.... static x = %d \n",pthread_self(),*py);
		sleep(10);
	return NULL;
}


int main(int argc, char *argv[])
{
	pthread_t  tid1 =0,tid2 = 0;
	static int  x = 0;
	int i = 0;
	
	pthread_create(&tid1,NULL,fun1,&x);
	pthread_create(&tid2,NULL,fun2,&x);


	pthread_exit(0);

	sleep(5);

    return 0;
}

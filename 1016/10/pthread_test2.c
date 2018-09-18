/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：pthread_test.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月02日
*   描    述：
================================================================*/

#include <stdio.h>
#include <pthread.h>


int  i;
pthread_mutex_t   mutex;

void *fun1(void *arg)
{
	pthread_mutex_lock(&mutex);
	while(1)
	{
		printf("fun1 tid = %lu i++ = %d \n",pthread_self(),i++);
		sleep(1);
		if(i == 10)
		{	
			i = 0;
			break;
		}
	}
	pthread_mutex_unlock(&mutex);

}

void *fun2(void *arg)
{
	pthread_mutex_lock(&mutex);
	while(1)
	{
		printf("fun2  i-- = %d \n",i--);
		sleep(1);
		if(i == -10 ) break;
	}
	pthread_mutex_unlock(&mutex);
}


int main(int argc, char *argv[])
{
	pthread_t  tid1 = 0,tid2 = 0;

	pthread_mutex_init(&mutex,NULL);
	
	pthread_create(&tid1,NULL,fun1,NULL);
	pthread_create(&tid2,NULL,fun1,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


    return 0;
}

/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：pthread_mutex_init.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月21日
*   描    述：
================================================================*/

#include <stdio.h>
#include <pthread.h>

//pthread_mutex_t   mutex;
int  x = 0;

int mutex = 0;
int pthread_mutex_mylock(int *mutex)
{
	while(1)
	{
		if(*mutex == 0)  
		{ 
		   *mutex = 1;
		   break;
		}
		else
		//	sleep(1);
	}
	return  0;
}

int pthread_mutex_unmylock(int *mutex)
{
	*mutex = 0;
}


void * fun1(void * arg)
{
	pthread_mutex_mylock(&mutex);
	while(1)
	{
		x++;
		printf("fun1  x++ = %d \n",x);
		sleep(1);
		if(x >=10) break;
	}
	pthread_mutex_unmylock(&mutex);

	pthread_exit(0);
}

void * fun2(void *arg)
{
	pthread_mutex_mylock(&mutex);
	while(1)
	{
		x--;
		printf("fun2  x-- = %d \n",x);
		sleep(1);
		if(x <= -10) break;
	}
	pthread_mutex_unmylock(&mutex);
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
//	int ret  = pthread_mutex_init(&mutex,NULL);
//	printf("ret = %d \n",ret);

	pthread_t tid1 = 0,tid2  = 0;
	pthread_create(&tid1,NULL,fun1,NULL);
	pthread_create(&tid2,NULL,fun2,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

    return 0;
}

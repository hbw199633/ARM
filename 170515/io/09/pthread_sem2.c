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
#include <semaphore.h>


int  x = 0;
sem_t  sem1 ,sem2 ;


void * fun2(void *arg)
{
	int i=0;
	for(i=0;i<10;i++)
	{
		sem_wait(&sem1);
		printf("sem wait i = %d \n",i);
	}

	while(1)
	{
		x--;
		printf("fun2  x-- = %d \n",x);
		sleep(1);
		if(x <= -10) break;
	}
	sem_post(&sem2);
	pthread_exit(0);
}

int main(int argc, char *argv[])
{

	pthread_t tid1 = 0,tid2  = 0;
	sem_init(&sem1,0,0);

	pthread_create(&tid1,NULL,fun2,NULL);

	sleep(3);

	int i = 0;
	for(i=0;i<10;i++)
	{
		sem_post(&sem1);
	}



	pthread_join(tid1,NULL);

    return 0;
}

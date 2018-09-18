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
#include <semaphore.h>


int  i;
sem_t   sem ,sem1;

void *fun1(void *arg)
{
	while(1)
	{
		printf("fun1  i++ = %d \n",i++);
		sleep(1);
		if(i == 5) 
		{ 
		   break;
		}
	}
	sem_post(&sem);
}

void *fun2(void *arg)
{
	sem_wait( &sem);
	while(1)
	{
		printf("fun2  i-- = %d \n",i--);
		sleep(1);
		if(i == -5) 
		{ 
		   break;
		}
	}
	sem_post(&sem1);
}

void *fun3(void *arg)
{
	sem_wait( &sem1);
	while(1)
	{
		printf("fun3  i+2 = %d \n",i = i+2);
		sleep(1);
		if(i == 5 ) 
		{ 
		   break;
		}
	}
}



int main(int argc, char *argv[])
{
	pthread_t  tid1 = 0,tid2 = 0, tid3 = 0;

	sem_init(&sem,0,0);
	sem_init(&sem1,0,0);

	pthread_create(&tid1,NULL,fun1,NULL);
	pthread_create(&tid2,NULL,fun2,NULL);
	pthread_create(&tid3,NULL,fun3,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);


    return 0;
}

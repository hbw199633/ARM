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
#include <string.h>

int  x = 0;
sem_t  sem  ;
char buff[128] ={0};

void * fun1(void * arg)
{
	while(1)
	{
		sem_wait(&sem);
		printf("输入的字符串长度是: %d \n",strlen(buff)-1);
		if(!strcmp(buff,"quit\n")) break;
	}	
	pthread_exit(0);
}
int main(int argc, char *argv[])
{

	pthread_t tid1 = 0,tid2  = 0;
	sem_init(&sem,0,0);
	
	pthread_create(&tid1,NULL,fun1,NULL);
	printf("请输入字符串\n");
	while(1)
	{
		fgets(buff,sizeof(buff),stdin);
		sem_post(&sem);
		if(!strcmp(buff,"quit\n")) break;
	}

	pthread_join(tid1,NULL);

    return 0;
}

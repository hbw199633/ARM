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
#include <stdlib.h>
#include <string.h>
void * fun(void *arg)
{
	/*
	int na = (int )arg;
	printf("child %lu thread run....  pa = %d\n",pthread_self(),na);
	*/
	 char *str = (char *)arg;
	 printf("str = %s \n",str);
//	 strcpy(str,"nihao");
//	 printf("str 2 = %s \n",str);
	sleep(5);
	//free(arg);
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t  tid =0;

	int i = 0, a = 100;
	char * s = "hello world";
	
	for(i =0;i<5;i++)
	{
	//	int *p = malloc(sizeof(int));
	//	*p = i;
		//pthread_create(&tid,NULL,fun,(void *)a);   /// 0x0000 0100
		pthread_create(&tid,NULL,fun,(void *)s);   /// 0x0000 0100
		//a++;
		//pthread_create(&tid,NULL,fun,(void *)p);
		//pthread_create(&tid,NULL,fun,(void *)&a);
		//a++;
		//sleep(1);
	}

	pthread_join(tid,NULL);


    return 0;
}

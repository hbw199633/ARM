/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：pthread_create.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月20日
*   描    述：
================================================================*/

#include <stdio.h>
#include <pthread.h>


void *  fun(void * arg)
{
   printf("fun ... \n");
   pthread_t ftid = pthread_self();
   printf("ftid = %lu \n",ftid);

   while(1)
   {
   	  printf("fun ... run... \n");
	  sleep(1);
   }


   return NULL;
}
int main(int argc, char *argv[])
{

	pthread_t tid = 0;
	pthread_t mtid = pthread_self();
	
	pthread_create(&tid,NULL,fun,NULL);
	pthread_create(&tid,NULL,fun,NULL);
	pthread_create(&tid,NULL,fun,NULL);
	printf("mtid = %lu tid = %lu \n",mtid,tid);

   while(1)
   {
   	  printf("main ... run... \n");
	  sleep(1);
   }


	sleep(1);

    return 0;
}

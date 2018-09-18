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
#include <stdlib.h>
#include <string.h>
int  x = 0;
int *px = NULL;
char *py = NULL;
void *  fun1(void * arg)
{
   printf("fun1 ... \n");
   int x2  = 0;
   px = &x2;
   while(1)
   {
   	  x++;
	  x2--;
	  sleep(1);
	  printf("py = %s",py);
   }


   return NULL;
}

void *  fun2(void * arg)
{
   printf("fun2 ... \n");
   sleep(1);
   py = malloc(128);
   while(1)
   {
   	  printf("fun2 x = %d \n",x);
	  printf("fun2 px = %d \n",*px);
	  sprintf(py,"nihao %d \n",x);
	  sleep(1);
   }


   return NULL;
}




int main(int argc, char *argv[])
{

	pthread_t tid1 = 0,tid2 = 0;
	
	pthread_create(&tid1,NULL,fun1,NULL);
	pthread_create(&tid2,NULL,fun2,NULL);

   while(1)
   {
	  sleep(1);
   }
   return 0;
}

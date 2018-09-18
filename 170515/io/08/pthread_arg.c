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
#include <string.h>

void *  fun(void * arg)
{
   printf("fun ... \n");

   int *p = (int *)arg;
   printf("fun *p = %d \n",*p);
   *p =100;
   printf("fun *p2 = %d \n",*p);

/*
   char *p  =  (char *)arg;

   printf("fun p = %s \n",p);

	strcpy(p,"def");

   printf("fun p = %s \n",p);
*/

   pthread_exit(0);
}
int main(int argc, char *argv[])
{

	pthread_t tid = 0;

	int x = 99;
	pthread_create(&tid,NULL,fun, &x);

	pthread_join(tid,NULL);


    return 0;
}

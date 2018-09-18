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


void *  fun1(void * arg)
{
	while(1)
	{
		printf("fun1... \n");
		sleep(1);
	}
	
   static int a = 200;
   return &a;
}
void *  fun2(void * arg)
{
	 printf("fun2... \n");

   return NULL;
}



int main(int argc, char *argv[])
{

	pthread_t tid1 = 0,tid2 = 0;
	
	pthread_create(&tid1,NULL,fun1,NULL);
	pthread_create(&tid2,NULL,fun2,NULL);
	
	sleep(1);

	pthread_cancel(tid1);
	pthread_cancel(tid2);

	void * va = NULL;
	int ret = pthread_join(tid1,&va);
	printf("ret = %d va = %d\n",ret,*((int*)va));
    return 0;

}

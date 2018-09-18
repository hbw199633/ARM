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

void *fun1(void *arg)
{
		sleep(5);
		printf("fun1  i++ = %d \n",i++);
		printf("fun1  i++ = %d \n",i++);
		printf("fun1  i++ = %d \n",i++);

}

void *fun2(void *arg)
{
	int num = 0;
	while(1)
	{
		num = num ++;
		sleep(1);
	}
		
}


int main(int argc, char *argv[])
{
	pthread_t  tid1 = 0,tid2 = 0;

	
	pthread_create(&tid1,NULL,fun1,NULL);
	pthread_create(&tid2,NULL,fun2,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


    return 0;
}

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


void * fun(void *arg)
{
	printf("child %lu thread run....  \n",pthread_self());
	sleep(5);
	static char str[] ={"hello world"};
	//pthread_exit((void*)100);
	pthread_exit((void*)str);
}

int main(int argc, char *argv[])
{
	pthread_t  tid =0;

	int i = 0, ret  = 0;
	pthread_create(&tid,NULL,fun,NULL);

	printf("pthread create ok!!! \n");
	void * retval = NULL;
	ret = pthread_join(tid,&retval);

	//printf("pthread join ret = %d  ret value = %d\n",ret,  (int)retval);
	printf("pthread join ret = %d  ret value = %s\n",ret,  (char *)retval);

	strcpy((char *)retval,"nihao");

	printf("retval  = %s \n", (char *)retval);


    return 0;
}

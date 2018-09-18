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

pthread_mutex_t   mutex;

int main(int argc, char *argv[])
{
	int ret  = pthread_mutex_init(&mutex,NULL);
	printf("ret = %d \n",ret);


    return 0;
}

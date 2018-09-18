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

struct student
{
	int		id;
	char	name[32];
	float   score;
};



void * fun(void *arg)
{
	printf("child %lu thread run....  \n",pthread_self());
	sleep(5);
	static char str[] ={"hello world"};
	//pthread_exit((void*)100);
	//pthread_exit((void*)str);
	static struct student  stu ={123,"zhangsan",99.8};
	pthread_exit((void*)&stu);
}

int main(int argc, char *argv[])
{
	pthread_t  tid =0;
	int i = 0, ret  = 0;
	pthread_create(&tid,NULL,fun,NULL);

	printf("pthread create ok!!! \n");
	void * retval = NULL;
	ret = pthread_join(tid,&retval);
	
	//struct student * pstu  = (struct student *)retval;
	//printf("id = %d name = %s score = %f \n",pstu->id,pstu->name,pstu->score);
	printf("id = %d name = %s score = %f \n",((struct student*)retval)->id,
											((struct student *)retval)->name,
											((struct student *)retval)->score);
	

    return 0;
}

/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：shmget.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月26日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include "head.h"


int main(int argc, char *argv[])
{
	key_t key = 0x123456;

	int shmid  = shmget(key,sizeof(struct test),IPC_CREAT|IPC_EXCL|0644);
	if(shmid < 0)
	{
		if(errno == EEXIST)
		{
			shmid = shmget(key,sizeof(struct test),0644);
		}
		else
		{
			perror("shmget");
			return -1;
		}
	}
	printf("key = %#x shmid = %d \n",key,shmid);

	void * p = shmat(shmid,NULL,0644);
	if(NULL == p)
	{
		perror("shmat");
		return -1;
	}
	printf("shmat p = %p \n",p);


	//strcpy(p,"hello world");  ///写共享内存
	/*
	struct test  var ={100,"sdasdf",99.9};
	
	memcpy(p,&var,sizeof(struct test));
	*/

	struct test *pt = (struct test *)p;
	printf("请输入id \n");
	scanf("%d",&pt->id);

	printf("请输入name\n");
	scanf("%s",pt->name);

	printf("请输入score\n");
	scanf("%f",&pt->score);



    return 0;
}

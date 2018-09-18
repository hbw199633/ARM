/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：shmget.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月05日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{

	key_t key = ftok("./abc",345);
	if(key < 0)
	{
		perror("ftok error");
		return -1;
	}
	printf("key = %x \n",key);

	int shmid = shmget(key,sizeof(int),IPC_CREAT|0644);
	if(shmid < 0)
	{
		perror("shmget error");
		return -1;
	}
	printf("shmid  = %d \n",shmid);

	int   a = 0;
	void *x =  malloc(4); 
	bzero(x,4);

	void *p =  shmat(shmid,x,SHM_RND|SHM_REMAP|0644);

	printf("&a = %p  p = %p \n",x,p);



    return 0;
}

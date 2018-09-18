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
#include <sys/sem.h>
#include <string.h>


int main(int argc, char *argv[])
{

	key_t key = ftok("./abc",333);
	if(key < 0)
	{
		perror("ftok error");
		return -1;
	}
	printf("key = %x \n",key);

	int shmid = shmget(key,128,IPC_CREAT|0644);
	if(shmid < 0)
	{
		perror("shmget error");
		return -1;
	}
	printf("shmid  = %d \n",shmid);


	char *p  = shmat(shmid,NULL,0644);
	if(NULL == p)
	{
		perror("shmat error");
		return -1;
	}

	printf("shmat addr = %p \n",p);


	key_t key1 = 0x123;
	int semid = semget(key1,2,IPC_CREAT|0644);
	int len  = 0;
	FILE * fp = fopen("./test","r");

	semctl(semid,0,SETVAL,0);
	semctl(semid,1,SETVAL,1);

	while(1)
	{
		my_sem_wait(semid,1);	
		len = fread(p,1,128,fp);
		if(len == 0) 
		{
			strcpy(p, "");
			my_sem_post(semid,0);
			break;
		}
		my_sem_post(semid,0);
	}



    return 0;
}

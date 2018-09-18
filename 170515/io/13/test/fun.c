/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fun.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月27日
*   描    述：
================================================================*/

#include  "head.h"


void* shm_init(key_t key,int size)
{
	int shmid  = shmget(key,size,IPC_CREAT|IPC_EXCL|0644);
	if(shmid < 0)
	{
		if(errno == EEXIST)
		{
			shmid = shmget(key,size,0644);
		}
		else
		{
			perror("shmget");
			return NULL;
		}
	}
	void * p = shmat(shmid,NULL,0644);
	if(NULL == p)
	{
		perror("shmat");
		return NULL;
	}
    return p;
}

int shm_exit(key_t key,int size)
{
	int shmid  = shmget(key,size,0644);
	void *p = shmat(shmid,NULL,0644);
	shmdt(p);
	return  0;
}

int  sem_init(key_t key,int n)
{
	int semid = semget(key,n,IPC_CREAT|IPC_EXCL|0644);
	if(semid < 0)
	{
		if(errno == EEXIST)
		{
			semid = semget(key,n,0644);
		}
		else
		{
			perror("semget");
			return -1;
		}
	}
	return semid;
}
int sem_exit(int semid)
{
	return  0;
}

int my_sem_wait(int semid, int sem)
{
	int ret = 0;
	struct sembuf sops = {0};
	sops.sem_num = sem;
	sops.sem_op = -1;
	sops.sem_flg = 0;
	
	ret = semop(semid, &sops, 1);
	if(ret < 0) {
		perror("semop");
		return -1;
	}
	return 0;
}

int my_sem_post(int semid, int sem)
{
	int ret = 0;
	struct sembuf sops = {0};
	sops.sem_num = sem;
	sops.sem_op = +1;
	sops.sem_flg = 0;
	
	ret = semop(semid, &sops, 1);
	if(ret < 0) {
		perror("semop");
		return -1;
	}
	return 0;
}




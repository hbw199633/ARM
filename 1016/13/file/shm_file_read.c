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
	int semid= semget(key1,2,0644);

	FILE *fp  = fopen("./test2","w+");
	while(1)
	{
		my_sem_wait(semid,0);	
			
		fwrite(p,1,strlen(p),fp);
		if(strlen(p) <= 0) 
		{
			my_sem_post(semid,1);
			break;
		}
		bzero(p,128);
		my_sem_post(semid,1);

	}

    return 0;
}

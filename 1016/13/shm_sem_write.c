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
	int semid = semget(key1,1,IPC_CREAT|0644);
	struct sembuf  sem;
	sem.sem_num = 0;
	sem.sem_op  = 1;
	sem.sem_flg = 0;


	while(1)
	{
		printf("请输入：");
		fgets(p,128,stdin);
		if(!strcmp(p,"quit\n")) 
		{
			semop(semid,&sem,1);
		 	break;
		}

		semop(semid,&sem,1);
	}



    return 0;
}

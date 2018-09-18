/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：semget.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月05日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(int argc, char *argv[])
{
	key_t  key  = 0x56789;

	int semid  = semget(key,2,IPC_CREAT|0644);
	if(semid < 0)
	{
		perror("sem get error");
		return -1;
	}
	printf("key = %x semid = %d \n",key,semid);


	struct sembuf  sem;
	sem.sem_num  = 0;
	sem.sem_op   = -1;
	sem.sem_flg  = 0;

	int ret = semop(semid,&sem,1);
	if(ret < 0)
	{
		perror("semop error");
		return -1;
	}

	printf("hello world\n");



    return 0;
}

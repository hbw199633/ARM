/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：sem.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月27日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	key_t key = 0x8888;
	int ret = 0;
	int semid = semget(key,2,IPC_CREAT|IPC_EXCL|0644);
	if(semid < 0)
	{
		if(errno == EEXIST)
		{
			semid = semget(key,2,0644);
		}
		else
		{
			perror("semget");
			return -1;
		}
	}
	printf("semget semid = %d \n",semid);


	my_sem_wait(semid,0);  
	my_sem_post(semid,0);

/*
	struct sembuf  sops ={0};
	sops.sem_num  = 0;   ///控制信号量集中0号信号量
	//sops.sem_op   = -1;  ///对0号信号量执行p操作
	sops.sem_op   = +1;  ///对0号信号量执行p操作
	sops.sem_flg = 0 ;  ///默认阻塞执行

	ret = semop(semid,&sops,1);
	if(ret < 0)
	{
		perror("semop");
		return -1;
	}
	printf("ret == %d \n",ret);
*/


    return 0;
}

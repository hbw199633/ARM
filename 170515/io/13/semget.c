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


    return 0;
}

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


	system("ipcs -s");


	semctl(semid,0,IPC_RMID);
	semctl(semid,1,IPC_RMID);

	system("ipcs -s");


    return 0;
}

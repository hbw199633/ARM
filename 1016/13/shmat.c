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

int main(int argc, char *argv[])
{

	key_t key = ftok("./abc",33);
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


	void *p  = shmat(shmid,NULL,0644);
	if(NULL == p)
	{
		perror("shmat error");
		return -1;
	}

	printf("shmat addr = %p \n",p);


	system("ipcs -m");

	getchar();

	int ret = shmdt(p);
	if(ret < 0)
	{
		perror("shmdt error");
		return -1;
	}
	p = NULL;

	system("ipcs -m");



    return 0;
}

/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：ftok.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月26日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

int main(int argc, char *argv[])
{

	key_t key = ftok("./abcd",'y');
	printf("key = %#x \n",key);

	int msgid = msgget(key,IPC_CREAT|IPC_EXCL|0644);
	if(msgid < 0)
	{
		if(errno == EEXIST)
		{
			msgid = msgget(key,0644);
		}
		else
		{
			perror("msgget");
			return -1;
		}
	}
	printf("msgid = %d\n",msgid);

	
	system("ipcs -q");


	msgctl(msgid,IPC_RMID,NULL);

	system("ipcs -q");


    return 0;
}

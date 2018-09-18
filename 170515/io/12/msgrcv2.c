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
#include <string.h>
struct msgbuf1
{
	long   mtype;
	char   mtext[128];
};


int main(int argc, char *argv[])
{
	int ret = 0,msgid = 0;
	if(argc != 2)
	{
		printf("Usage %s [msgtype] \n",argv[0]);
		return -1;
	}

	key_t key = ftok("./abcd",'y');
	printf("key = %#x \n",key);
	
	msgid = msgget(key,IPC_CREAT|IPC_EXCL|0644);
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
	
	struct msgbuf1  var ={0};
	ret  = msgrcv(msgid,&var,sizeof(var)-4,atoi(argv[1]),0);
	if(ret < 0)
	{
		perror("msgrcv");
		return -1;
	}
	printf("msgrcv var = %s \n",var.mtext);
	

	return 0;
}

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

struct msgbuf
{
	long   mtype;
	char   mtext[128];
};



int main(int argc, char *argv[])
{
	int ret = 0,msgid = 0;

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

	struct msgbuf  var ={0};
	var.mtype = 1;
	strcpy(var.mtext,"hello world");
	ret  = msgsnd(msgid,&var,sizeof(var)-4,0);
	if(ret < 0)
	{
		perror("msgsnd");
		return -1;
	}
	else
		printf("msgsnd ret = %d \n",ret);





    return 0;
}

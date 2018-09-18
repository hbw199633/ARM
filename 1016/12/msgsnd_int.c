/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：msgget.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月04日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


struct msgbuf
{
	long  mtype;
	char  mtext[128];
	//int   x;
};

int main(int argc, char *argv[])
{

	key_t   key  = 0x123456;

	int msgid = msgget(key,IPC_CREAT|0644);

	printf("msgid = %d \n",msgid);

	struct msgbuf var= {123,"hello world"};

	while(1)
	{
		printf("请输入字符串\n");
		fgets(var.mtext,sizeof(var.mtext),stdin);
		msgsnd(msgid,&var,sizeof(var.mtext),0 );
		if(!strcmp(var.mtext,"quit\n")) break;
	}


    return 0;
}

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
};

int main(int argc, char *argv[])
{

	key_t   key  = 0x123456;

	int msgid = msgget(key,IPC_CREAT|0644);

	printf("msgid = %d \n",msgid);

	struct msgbuf var= {0};

	while(1)
	{
		msgrcv(msgid,&var,sizeof(var.mtext),123,0 );
		if(!strcmp(var.mtext,"quit\n")) break;
		printf("var text = %s \n",var.mtext);
	}


    return 0;
}

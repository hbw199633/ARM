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

int main(int argc, char *argv[])
{

	key_t   key  = 0x123456;

	int msgid = msgget(key,IPC_CREAT|0644);

	printf("msgid = %d \n",msgid);


	system("ipcs -q");


	msgctl(msgid,IPC_RMID,NULL);

	system("ipcs -q");


    return 0;
}

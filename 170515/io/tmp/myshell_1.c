/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：myshell_1.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月22日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char buff[128] ={0};
	while(1)
	{
		printf("my con >>");
		fflush(NULL);
		bzero(buff,sizeof(buff));
		fgets(buff,sizeof(buff),stdin);
		if(!strcmp(buff,"quit\n")) break;
		if(!strcmp(buff,"?\n"))
		{
			printf("quit is exit \n");
			continue;
		}
		if(strlen(buff) >1)
		{
			pid_t pid = fork();
			if(pid == 0)
			{
				execl("/bin/bash","bash","-c",buff,NULL);
				exit(0);
			}
			if(pid > 0)
			{
				wait(NULL);
			}
		}
	}

    return 0;
}

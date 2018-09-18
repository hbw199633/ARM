/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：myshell_2.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月22日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int ret =0;
	char buff[128] ={0};
	char s1[32] ={0};
	char s2[32] ={0};
	char s3[32] ={0};
	char s4[32] ={0};


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
			return -1;
		}
		//printf("buff = %s\n",buff);
		if(strlen(buff)>1)
		{
			bzero(s1,sizeof(s1));
			bzero(s2,sizeof(s2));
			bzero(s3,sizeof(s3));
			ret = sscanf(buff,"%s %s %s %s",s1,s2,s3,s4);
			if(ret > 3)
			{
				printf("输入参数过多，无法解析执行\n");
				continue;
			}
			pid_t pid = fork();
			if(pid == 0)
			{
				if(strlen(s3)>1)
					ret= execlp(s1,s1,s2,s3,NULL);	
				else if(strlen(s2)>1)
					ret = execlp(s1,s1,s2,NULL);
				else
					ret = execlp(s1,s1,NULL);
				if(ret == -1)
				{
					printf("%s 未找到命令\n",s1);
				}
				exit(0);
			}
			wait(NULL);
		}
	}


    return 0;
}

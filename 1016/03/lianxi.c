/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：lianxi.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月12日
*   描    述：
================================================================*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage %s [file]\n",argv[0]);
		return -1;
	}

	FILE * fp = fopen(argv[1],"w+");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}

	char buff[128] ={0};
	char buff2[128] ={0};
	printf("请任意输入，'quit'退出\n");
	while(1)
	{
		bzero(buff,sizeof(buff));
		bzero(buff2,sizeof(buff2));
		fgets(buff,sizeof(buff),stdin);
		if(!strcmp(buff,"quit\n")) break;
		fputs(buff,fp);
		fflush(fp);
		fseek(fp,-strlen(buff),SEEK_CUR);
		fgets(buff2,sizeof(buff2),fp);
		printf("fseek fgets buff2  = %s \n",buff2);
	}

	fclose(fp);

    return 0;
}

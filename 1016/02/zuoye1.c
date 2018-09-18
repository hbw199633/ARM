/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：zuoye1.c
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
		printf("Usage %s [file] \n",argv[0]);
		return -1;
	}
	printf("请任意输入，单独输入 'quit' 程序退出\n");

	FILE * fp = fopen(argv[1],"w+");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}

	char s[128] ={0};
	int ret = 0;
	while(1)
	{
			bzero(s,sizeof(s));
			//ret = fread(s,sizeof(char),sizeof(s),stdin);
			fgets(s,sizeof(s),stdin);
			if(strlen(s) == 5)
			{
				if(!strcmp(s,"quit\n")) break;
			}
			else
				fwrite(s,sizeof(char),strlen(s),fp);
	}

	fclose(fp);

    return 0;
}

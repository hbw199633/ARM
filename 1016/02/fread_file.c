/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fread.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月11日
*   描    述：
================================================================*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf(" Usage %s [file] \n",argv[0]);
		return -1;
	}

	FILE * fp = fopen(argv[1],"r");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}

	char buff[128] ={0};
	int ret = 0;
	while(1)
	{
		bzero(buff,sizeof(buff));
		ret = fread(buff,sizeof(char),sizeof(buff),fp);
		if(ret == 0) break;
		printf("%s",buff);
	}


	fclose(fp);

    return 0;
}

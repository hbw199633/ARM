/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fgets.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月11日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{	
	if(argc != 2)
	{
		printf("Usage %s [file]\n",argv[0]);
		return -1;
	}

	FILE * fp  = fopen(argv[1],"r");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}
	char s[128] ={0};
	char *p =NULL ;
	while(1)
	{
		p = fgets(s,128,fp);
		if(NULL == p)
		{
			goto error;
		}
		printf("%s",s);
	}
	fclose(fp);
    return 0;
error:
	fclose(fp);
	return -1;
}

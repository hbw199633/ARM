/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fputs.c
*   创 建 者：cqb  2848319176@qq.com
	*   创建日期：2017年12月11日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE * fp  = fopen("./c.txt","r+");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}


	//int ret = fputs("hello world",fp);
	//int ret = fputs("hello world",stdout);
	int ret = fputs("hello world",stderr);
	if(ret < 0)
	{
		perror("fputs error");
		goto error;
	}
	
	sleep(10);

	fclose(fp);
    return 0;
error:
	fclose(fp);
	return -1;
}

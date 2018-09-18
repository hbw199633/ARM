/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fwrite_bin.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月11日
*   描    述：
================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE * fp = fopen("./a.out","r");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}
	FILE * fp2  = fopen("./b.out","w+");
	if(NULL == fp2)
	{
		perror("fopen file");
		fclose(fp);
		return -1;
	}

	
	void * ptr = malloc(128);
	int ret = 0;
	while(1)
	{
		bzero(ptr,128);
		ret = fread(ptr,1,128,fp);
		if(ret == 0) break;
		fwrite(ptr,1,ret,fp2);

	}

	free(ptr);
	fclose(fp2);
	fclose(fp);

    return 0;
}

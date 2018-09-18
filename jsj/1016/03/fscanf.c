/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fscanf.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月12日

*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE * fp = fopen("./a.txt","r");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}
	int a = 0;
	char b = 0;
	char c[32] ={0};

	fscanf(fp,"%d %c %s",&a,&b,c);

	printf("a = %d b = %c c = %s \n",a,b,c);

	
	fclose(fp);
	return 0;
}

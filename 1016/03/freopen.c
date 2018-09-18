/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：freopen.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月12日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
/*
	FILE * fp = fopen("./a.txt","r+");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}
	
	int c = fgetc(fp);
	printf("fgetc fp = %c \n",c);

	freopen("./b.txt","r+",fp);

	c = fgetc(fp);
	printf("fgetc fp2 = %c \n",c);

	fclose(fp);
*/

	printf("hello world \n");

	freopen("./c.log","w+",stdout);
	//freopen(/dev/null,"w+",stdout);

	printf("nihao wohao \n");

	
    return 0;
}

/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fseek.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月12日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{

	FILE * fp = fopen("./b.txt","r+");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}

	//int c = fgetc(fp);
	//printf("c = %c \n",c);

	//fseek(fp,25,SEEK_SET);
	//fseek(fp,5,SEEK_END);
	  fseek(fp,25,SEEK_CUR);

int	c = fputc('x',fp);
	fclose(fp);
    return 0;
}

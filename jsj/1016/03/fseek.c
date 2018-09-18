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

	int c = fgetc(fp);
	printf("c = %c \n",c);

	fseek(fp,5,SEEK_SET);

	c = fgetc(fp);
	printf("fseek c = %c \n",c);


	fseek(fp,-3,SEEK_CUR);
	c = fgetc(fp);
	printf("fseek2 c = %c \n",c);


	fseek(fp,0,SEEK_END);
	c = fgetc(fp);
	printf("fseek3 c = %c \n",c);
		
		


	fclose(fp);
    return 0;
}

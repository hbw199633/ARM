/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：ftell.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月12日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE * fp = fopen("./b.txt","r");

	fseek(fp,0,SEEK_END);

	long n = ftell(fp);

	printf("n = %ld \n",n);


	rewind(fp);

	n = ftell(fp);

	printf("n = %ld \n",n);


/*
	fseek(fp,-10,SEEK_END);

	n = ftell(fp);

	printf("n = %ld \n",n);
*/
	fclose(fp);
    return 0;
}

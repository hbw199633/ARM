/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fprintf.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月12日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE * fp = fopen("./b.txt","w+");

	int a = 99;
	float b = 3.14;
	char  c= 'k';
	char *p = "nihao";
	//fprintf(fp,"%d %f %c %s",a,b,c,p);
	//fprintf(stderr,"%d %f %c %s",a,b,c,p);
	fprintf(stdout,"%d %f %c %s\n",a,b,c,p);

	fclose(fp);
    return 0;
}

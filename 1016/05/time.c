/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：time.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{

	time_t  t;

	time(&t);

	printf("t = %ld \n", t);

	struct tm *ptm  = localtime(&t);	
	printf(" %2d月 %2d %2d:%2d:%2d ",
			  ptm->tm_mon + 1,
			  ptm->tm_mday,
			  ptm->tm_hour,
			  ptm->tm_min,
			  ptm->tm_sec);

	printf("\n");
	

    return 0;
}

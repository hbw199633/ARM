/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：no_buff.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月06日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	char buff[] ="hello world";
	//printf("nihao %s ",buff);
	fprintf(stderr,"nihao %s ", buff);


	while(1)  sleep(1);

    return 0;
}

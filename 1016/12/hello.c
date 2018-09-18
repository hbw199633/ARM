/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：hello.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月04日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	while(1)
	{
		sleep(1);
		printf("my pid  = %d \n",getpid());
	}
    return 0;
}

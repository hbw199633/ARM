/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：raise.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月04日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{

	printf("mypid = %d \n",getpid());

	raise(19);

	printf("hello world \n");

    return 0;
}

/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：kill.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{

	int ret = kill(22126,SIGHUP);
	printf("ret = %d\n",ret);

return 0;
}

/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：ftok.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月04日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(int argc, char *argv[])
{
 	key_t  key = ftok("./test",10);
	printf("key = %d \n",key);
 
 	return 0;
}

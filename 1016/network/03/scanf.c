/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：scanf.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月10日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{

//	close(STDIN_FILENO);
//	int fd = open("/dev/tty",O_RDWR);
//	int fd = open("/dev/tty",O_RDWR|O_NONBLOCK);

	int flag = fcntl(STDIN_FILENO,F_GETFL,0);
	flag = flag | O_NONBLOCK;
	fcntl(STDIN_FILENO,F_SETFL,flag);
	
	char buff[128] ={0};
	scanf("%s",buff);
	printf("buff = %s \n",buff);


    return 0;
}

/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：test1.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月02日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char *argv[])
{
	char buff[128] ={0};
	scanf("%s",buff);
	printf("scanf buff = %s \n",buff);

	int fd = STDIN_FILENO;
	int flag = fcntl(fd,F_GETFL,0);
	flag = flag | O_NONBLOCK;
	fcntl(fd,F_SETFL,flag);

	bzero(buff,sizeof(buff));
	scanf("%s",buff);
	printf("scanf2 buff = %s \n",buff);



    return 0;
}

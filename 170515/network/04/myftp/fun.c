/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fun.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月02日
*   描    述：
================================================================*/

#include  "head.h"


int sendfile(int sockfd, char * filename)
{
	int ret  = 0;
	int fd = open(filename,O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	char buff[1024] ={0};
	while(1)
	{
		bzero(buff,sizeof(buff));
		ret = read(fd,buff,sizeof(buff));
		if(ret == 0) break;
		ret = send(sockfd,buff,ret,0);
		if(ret > 0)
		{
			printf("send buff ret = %d buff = %s \n",ret,buff);
		}
		else
		{
			perror("send");
			break;
		}
	}
	close(fd);
	return 0;
}





/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：client.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月29日
*   描    述：
================================================================*/

#include  "head.h"

int main(int argc, char *argv[])
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	int i  = 0;
	char buff[128] ={0};
	struct sockaddr_in  seraddr ={0};
	seraddr.sin_family	= AF_INET;
	seraddr.sin_port	= htons(8888);
	seraddr.sin_addr.s_addr	= inet_addr("172.16.4.134");
	socklen_t len=  sizeof(seraddr);

	connect(sockfd,(struct sockaddr*)&seraddr,len);
	/*
	while(1)
	{
		send(sockfd,"hello world",11,0);
		printf("send %d \n",i++);
		sleep(1);

		int ret = recv(sockfd,buff,sizeof(buff),0);
		if(ret > 0)
			printf("client recv buff = %s \n",buff);
	}
	*/

	close(sockfd);

    return 0;
}

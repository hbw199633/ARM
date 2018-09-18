/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：socket.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月29日
*   描    述：
================================================================*/

#include "head.h"

int main(int argc, char *argv[])
{
	int ret  =0,connfd = 0;
	char buff[128] ={0};
	struct sockaddr_in  addr={0},cliaddr={0};
	socklen_t  len  = 0;
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	
	int on = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
	
	addr.sin_family	= AF_INET;
	addr.sin_port	= htons(8888);
	addr.sin_addr.s_addr = inet_addr("172.16.4.134");
	len = sizeof(addr);
	ret  = bind(sockfd,(struct sockaddr*)&addr,len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}
	printf("bind ok \n");


	listen(sockfd,5);
	
	while(1)
	{
		connfd = accept(sockfd,(struct sockaddr *)&cliaddr,&len);
		if(connfd < 0)
		{
			perror("accept");
			return -1;
		}
		printf("ip  = %s \n", inet_ntoa(cliaddr.sin_addr));
		/*
		   int fd = connfd;
		   int flag = fcntl(fd,F_GETFL,0);
		   flag = flag | O_NONBLOCK;
		   fcntl(fd,F_SETFL,flag);
		   */

		ret= recv(connfd,buff,sizeof(buff),0);
		if(ret < 0)
		{
			perror("recv ");
			return -1;
		}
		printf("recv buff = %s \n",buff);

		close(connfd);

	}

	close(sockfd);


    return 0;
}

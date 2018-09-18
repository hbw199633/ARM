/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：socket.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月29日
*   描    述：
================================================================*/

#include "head.h"


int socket_init(char *ip ,short port)
{
	int ret  =0;
	struct sockaddr_in  addr={0};
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
	addr.sin_port	= htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	len = sizeof(addr);
	ret  = bind(sockfd,(struct sockaddr*)&addr,len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}
	listen(sockfd,5);
	return sockfd;
}



int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage %s [local ip] \n",argv[0]);
		return -1;
	}
	int connfd = 0;
	int sockfd = socket_init(argv[1],8888);
	if(sockfd < 0)  return -1;

	struct sockaddr_in  cliaddr={0};
	socklen_t len= sizeof(cliaddr);
	char  ipaddr[100][32]={{0}};

	fd_set  readfds = {{0}}; ///有效描述符集
	fd_set  allfds = {{0}};  ///所有描述符集
	FD_SET(sockfd,&readfds);
	allfds = readfds;  ///保证集合相等
	int maxfd = sockfd ,i = 0,ret = 0; 
	char buff[128] ={0};

	while(1)
	{
		readfds = allfds;	
		select(maxfd+1,&readfds, NULL,NULL,0);
		for(i=sockfd;i<=maxfd+1;i++)
		{
			if( FD_ISSET(i,&readfds))
			{
				if( i == sockfd)
				{
					connfd = accept(sockfd,(struct sockaddr*)&cliaddr,&len);
					strcpy(ipaddr[connfd],inet_ntoa(cliaddr.sin_addr));
					if(connfd >maxfd)  maxfd = connfd;
					FD_SET(connfd,&allfds);
				}
				else
				{
					bzero(buff,sizeof(buff));
					ret = recv(i,buff,sizeof(buff),0);
					if(ret <=0){
						close(i);
						FD_CLR(i,&allfds);}
					else
						printf("ip = %s buff  = %s\n",ipaddr[i],buff);
				}
			}
		}
	}

	close(sockfd);

    return 0;
}

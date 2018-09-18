/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：socket.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月29日
*   描    述：
================================================================*/

#include "head.h"


pthread_t  tid[100] ;

int socket_init(char *ip ,short port)
{
	int ret  =0,connfd = 0;
	char buff[128] ={0};
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

void * fun(void * arg)
{
	int connfd = (int) arg;
	char buff[128] ={0};
	int ret = 0;
	while(1)
	{
		bzero(buff,sizeof(buff));
		ret = recv(connfd,buff,sizeof(buff)-2,0);
		buff[strlen(buff)-1] ='\0';
		buff[strlen(buff)-1] ='\0';
		printf("recv buff = %s ret = %d\n",buff,ret);
		if(!strncmp(buff,"quit",4))  break;
		if((ret <= 0) || (ret >sizeof(buff))) break;
		if(strlen(buff) <1) break;
		strcat(buff,"  shoudao \n");
		ret = send(connfd,buff,strlen(buff),0);
		printf("send buff = %s ret = %d\n",buff,ret);
	}
	close(connfd);
	pthread_exit(0);
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

	pthread_t tid1 =0;
	pthread_create(&tid1,NULL,fun1,NULL);

	while(1)
	{
		connfd = accept(sockfd,NULL,NULL);
		if(connfd < 0)
		{
			perror("accept");
			return -1;
		}
		//pthread_create(&tid[connfd],NULL,fun,(void *)connfd);
		pthread_create(&tid[connfd],NULL,fun,&connfd);
	}

	close(sockfd);

    return 0;
}

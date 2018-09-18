/***************************************************
  > Copyright (C) 2017 ==HEBOWEN== All rights reserved.
  > File Name: client.c
  > Author: hebowen
  > Mail:982034166@qq.com 
  > Created Time: 2017年07月29日 星期六 14时06分01秒
 ***************************************************/

#include "head.h"
#include <string.h>
#include <stdlib.h>
void *fun (void *arg);
int connfd; 
int sockfd;
int main(int argc,const char* argv[])
{
	if(argc != 3)
	{
		printf("请按格式输入:%s 端口号 ip地址\n",argv[0]);
		return -1;
	}
	char buff[128] = {0};
	socklen_t len = 0;
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = inet_addr(argv[2]);
	len = sizeof(addr);

	int ret = bind(sockfd,(struct sockaddr*)&addr,len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}

	listen(sockfd,5);
	connfd =  accept(sockfd,NULL,NULL);
	struct sockaddr_in cliaddr;
	pthread_t tid = 0;
	pthread_create(&tid,NULL,fun,NULL);
	while(1)
	{
		int ret = recv(connfd,buff,sizeof(buff),0);
		if(ret < 0)
			break;
		if(strncmp(buff,"quit",4) == 0)
		{
			close(connfd);
			close(sockfd);
			kill(pthread_cancel(tid),9);
			kill(pthread_self(),9);
		}
		printf("\t\t\t\033[42m接受客户\033[0m\n");
		printf("\t\t\t%s",buff);

	}


	close(connfd);
	close(sockfd);
	pthread_join(tid,NULL);
	return 0;
}

void *fun (void *arg)
{
	char buff1[128] = {0};
	while(1)
	{
		bzero(buff1,sizeof(buff1));
		printf("\033[41m服务输入\033[0m\n");
		fgets(buff1,sizeof(buff1),stdin);
		send(connfd,buff1,sizeof(buff1),0);
		if(strncmp(buff1,"quit",4) == 0)
			break;
	}
	close(connfd);
	close(sockfd);
	exit(0);
}

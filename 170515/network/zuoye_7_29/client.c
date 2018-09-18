/***************************************************
  > Copyright (C) 2017 ==HEBOWEN== All rights reserved.
  > File Name: client.c
  > Author: hebowen
  > Mail:982034166@qq.com 
  > Created Time: 2017年07月29日 星期六 14时06分01秒
 ***************************************************/

#include "head.h"
#include <string.h>

int sockfd;
void *fun (void *arg);
int main(int argc,const char* argv[])
{
	if(argc != 3)
	{
		printf("请按格式输入:%s 端口号 ip地址\n",argv[0]);
		return -1;
	}
	char buff[128] = {0};
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in seraddr = {0};
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(atoi(argv[1]));
	seraddr.sin_addr.s_addr = inet_addr(argv[2]);
	socklen_t len = sizeof(seraddr);

	int ret = connect(sockfd,(struct sockaddr*)&seraddr,len);	
	if(ret < 0)
	{
		perror("connect");
		return -1;
	}
	pthread_t tid = 0;
	pthread_create(&tid,NULL,fun,NULL);
	while(1)
	{
		bzero(buff,sizeof(buff));
		printf("\033[42m客户发送\033[0m\n");
		fgets(buff,sizeof(buff),stdin);
		send(sockfd,buff,sizeof(buff),0);
		if(strncmp(buff,"quit",4) == 0)
		{
			break;
		}

	}

	close(sockfd);
	pthread_join(tid,NULL);
	exit(0);
	return 0;
}

void *fun (void * arg)
{
	char buff1[128] = {0};
	while(1)
	{	int ret = recv(sockfd,buff1,sizeof(buff1),0);
		if(ret < 0)
			break;
		if(!strncmp(buff1,"quit",4))
			break;
		printf("\t\t\t\033[41m接受服务\033[0m\n");
		printf("\t\t\t%s",buff1);
	}
	close(sockfd);
	exit(0);

}

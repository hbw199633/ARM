/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：tcp_server.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月11日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void fun(int sig)
{
	wait(NULL);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage %s [server ip] \n",argv[0]);
		return -1;
	}

	signal(1,fun);

	int connfd = 0,pid = 0;
	int sockfd=  socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	struct sockaddr_in  myaddr,cliaddr;
	myaddr.sin_family		= AF_INET;
	myaddr.sin_port			= htons(6666);
	myaddr.sin_addr.s_addr  = inet_addr(argv[1]);
	socklen_t len = sizeof(myaddr);

	int on = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on ,sizeof(on));


	int ret  =bind(sockfd,(struct sockaddr*)&myaddr,len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}

	listen(sockfd,10);

	while(1)
	{
		connfd = accept(sockfd,(struct sockaddr*)&cliaddr,&len);
		if(connfd > 0)   pid = fork();
		if(pid == 0)
		{
			char buff[128] ={0};
			while(1)
			{
				bzero(buff,sizeof(buff));
				ret = recv(connfd,buff,sizeof(buff),0);
			    if(ret > 0)  printf("recv buff = %s \n",buff);
			    else   
				{ 
					printf("child exit... \n");
					break;
				}
			}
			kill(getppid(),1);
			exit(0);
		}
		printf("recv ip = %s \n",inet_ntoa(cliaddr.sin_addr));
	}

	close(connfd);
	close(sockfd);


    return 0;
}

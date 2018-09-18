/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：socket.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月08日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int sockfd  = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket error");
		return -1;
	}
	printf("sockfd  = %d \n",sockfd);

	struct sockaddr_in  myaddr;
	myaddr.sin_family		= AF_INET;
	myaddr.sin_port			= htons(2345);
	myaddr.sin_addr.s_addr  = inet_addr("172.16.6.134");
	socklen_t  len = sizeof(myaddr);
	int ret = bind(sockfd, (struct sockaddr*)&myaddr, len );
	if(ret < 0)
	{
		perror("bind error");
		return -1;
	}

	ret  = listen(sockfd,10);
	if(ret < 0)
	{
		perror("listen  error");
		return -1;
	}

	int connfd = accept(sockfd,NULL,NULL);
	if(connfd < 0)
	{
		perror("accept error");
		return -1;
	}

	printf("accept connfd = %d \n",connfd);
	
	char buff[128] ={0};

//while(1)
//{
	ret = recv(connfd,buff,sizeof(buff),0);
	if(ret <= 0)
	{
		perror("recv error");
		return -1;
	}
	printf("recv buff  = %s \n",buff);

//	send(connfd,"wohao",5,0);


//}



	close(connfd);
	close(sockfd);



    return 0;
}

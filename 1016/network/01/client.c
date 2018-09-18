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

	struct sockaddr_in  server_addr;
	server_addr.sin_family		= AF_INET;
	server_addr.sin_port			= htons(12345);
	server_addr.sin_addr.s_addr  = inet_addr("172.16.6.134");
	socklen_t  len = sizeof(server_addr);


	int ret = connect(sockfd,(struct sockaddr *)&server_addr,len);
	if(ret < 0)
	{
		perror("connect error");
		return -1;
	}
	printf("connect ok ret = %d \n",ret);


	
	char buff[128] ={"nihao "};

//while(1)
//{
	ret = send(sockfd,buff,sizeof(buff),0);
	if(ret < 0)
	{
		perror("send error");
		return -1;
	}
	printf("send buff  = %s \n",buff);
//	sleep(1);

//	recv(sockfd,buff,sizeof(buff),0);


//}

	close(sockfd);



    return 0;
}

/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：brocast.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月12日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}


	char buff[] ="hello world";

	struct sockaddr_in   broaddr;
	broaddr.sin_family		= AF_INET;
	broaddr.sin_port		= htons(5555);
	broaddr.sin_addr.s_addr = inet_addr("172.16.6.255");
	socklen_t  len = sizeof(broaddr);

	int on = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on));

	while(1)
	{
		sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&broaddr,len);
		sleep(1);
	}

	
	close(sockfd);

    return 0;
}

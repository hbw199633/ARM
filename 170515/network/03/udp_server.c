/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：udp_server.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月01日
*   描    述：
================================================================*/

#include  "head.h"


int main(int argc, char *argv[])
{
	char buff[128] ={0};
	struct sockaddr_in myaddr={0};
	socklen_t 	len = sizeof(myaddr);
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	
	myaddr.sin_family		= AF_INET;
	myaddr.sin_port			= htons(9999);
	myaddr.sin_addr.s_addr  = inet_addr("172.16.4.134");

	int ret = bind(sockfd,(struct sockaddr*)&myaddr,len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}


	ret = recvfrom(sockfd,buff,sizeof(buff),0,NULL,NULL);
	if(ret > 0)
		printf("recvfrom buff = %s \n",buff);
	else
		perror("recvfrom");


	close(sockfd);

    return 0;
}

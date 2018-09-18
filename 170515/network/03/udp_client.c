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
	int ret =0;
	char buff[128] ={0};
	struct sockaddr_in dest_addr={0},myaddr={0};
	socklen_t 	len = sizeof(dest_addr);
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	
	myaddr.sin_family		= AF_INET;
	myaddr.sin_port			= htons(1234);
	myaddr.sin_addr.s_addr  = inet_addr("172.16.4.134");
	ret= bind(sockfd,(struct sockaddr*)&myaddr,len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}
	
	dest_addr.sin_family		= AF_INET;
	dest_addr.sin_port			= htons(7777);
	dest_addr.sin_addr.s_addr  = inet_addr("172.16.4.15");
	strcpy(buff,"nihao");
	ret = sendto(sockfd,buff,strlen(buff),0,
			(struct sockaddr*)&dest_addr,len);
	if(ret > 0)
		printf("sendto buff = %s ret = %d\n",buff,ret);
	else
		perror("sendto");


	close(sockfd);

    return 0;
}

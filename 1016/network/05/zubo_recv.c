/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：zubo.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月12日
*   描    述：
================================================================*/

#include  "head.h"

int main(int argc, char *argv[])
{

	int sockfd  = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	char buff[128] ="nihao";
	struct sockaddr_in  seraddr;
	seraddr.sin_family		= AF_INET;
	seraddr.sin_port		= htons(6666);
	seraddr.sin_addr.s_addr = inet_addr("224.0.0.100");
	socklen_t  len  = sizeof(seraddr);

	int ret = bind(sockfd,(struct sockaddr *)&seraddr,len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}
	struct ip_mreq  mreq;  ///linux/in.h
	mreq.imr_multiaddr.s_addr  = inet_addr("224.0.0.100");
	mreq.imr_interface.s_addr  = inet_addr("172.16.6.134");
	setsockopt(sockfd,IPPROTO_IP,IP_ADD_MEMBERSHIP,&mreq,sizeof(mreq));


	while(1)
	{
		recvfrom(sockfd,buff,sizeof(buff),0,NULL,NULL);
		printf("recv buff = %s \n",buff);
		sleep(1);
	}

	close(sockfd);

    return 0;
}

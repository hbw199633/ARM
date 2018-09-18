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

	char buff[] ="nihao";
	struct sockaddr_in  seraddr;
	seraddr.sin_family		= AF_INET;
	seraddr.sin_port		= htons(6666);
	seraddr.sin_addr.s_addr = inet_addr("224.0.0.100");
	socklen_t  len  = sizeof(seraddr);

	while(1)
	{
		sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&seraddr,len);
		sleep(10);
	}

	close(sockfd);

    return 0;
}

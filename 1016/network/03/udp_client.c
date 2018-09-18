/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：udp_server.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月10日
*   描    述：
================================================================*/

#include  "head.h"


int main(int argc, char *argv[])
{
	int ret = 0;
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}

	struct sockaddr_in dest_addr;
	dest_addr.sin_family	= AF_INET;
	dest_addr.sin_port		= htons(8888);
	dest_addr.sin_addr.s_addr = inet_addr("172.16.6.134");
	socklen_t  len 	= sizeof(dest_addr);


	char buff[128] ={"hello world"};
	ret = sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&dest_addr,len);
	if(ret > 0)
	{
		printf("sendto buff  = %s \n",buff);
	}
	else
	{
		perror("sendto ");
	}
	
	close(sockfd);

    return 0;
}

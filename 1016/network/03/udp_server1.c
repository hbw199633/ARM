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

	struct sockaddr_in  myaddr,client_addr;
	myaddr.sin_family	= AF_INET;
	myaddr.sin_port		= htons(8888);
	myaddr.sin_addr.s_addr = inet_addr("172.16.6.134");
	socklen_t  len 	= sizeof(myaddr);

	ret = bind(sockfd,(struct sockaddr*)&myaddr,len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}




	char buff[128] ={0};
	ret = recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&client_addr,&len);
	if(ret > 0)
	{
		printf("recvfrom ip = %s port = %d buff  = %s \n",
				inet_ntoa(client_addr.sin_addr), 
				ntohs(client_addr.sin_port),
				buff);
	}
	else
	{
		perror("recvfrom");
	}

	strcpy(buff,"nihao");
	ret = sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&myaddr,len);
	if(ret > 0)
	{
		printf("sendto server buff = nihao \n");
	}
	else
	{
		perror("sendto");
	}


	close(sockfd);

    return 0;
}

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
#include <linux/un.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int sockfd  = socket(AF_LOCAL,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		perror("socket error");
		return -1;
	}


	struct sockaddr_un  server_addr;
	server_addr.sun_family		= AF_UNIX;
	strcpy(server_addr.sun_path,"./abc");
	socklen_t  len = sizeof(server_addr);


	
	char buff[128] ={"nihao "};

	int ret = sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&server_addr,len);
	if(ret < 0)
	{
		perror("send error");
		return -1;
	}
	printf("send buff  = %s \n",buff);


	close(sockfd);



    return 0;
}

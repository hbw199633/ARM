/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：client.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月29日
*   描    述：
================================================================*/

#include  "head.h"

int main(int argc, char *argv[])
{
	int sockfd = socket(AF_UNIX,SOCK_STREAM,0);

	int i  = 0;
	
	struct sockaddr_un  seraddr ={0};
	seraddr.sun_family	= AF_UNIX;
	strcpy(seraddr.sun_path,"./socket_file");
	socklen_t len=  sizeof(seraddr);
	connect(sockfd,(struct sockaddr*)&seraddr,len);

	while(1)
	{
		send(sockfd,"hello world",11,0);
		printf("send %d \n",i++);
		sleep(1);
	}
	close(sockfd);

    return 0;
}

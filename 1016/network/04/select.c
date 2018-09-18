/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：select.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月11日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int confd= 0;
	int sockfd = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in myaddr;
	myaddr.sin_family		= AF_INET;
	myaddr.sin_port			= htons(12345);
	myaddr.sin_addr.s_addr	= inet_addr("172.16.6.134");
	socklen_t  len  = sizeof(myaddr);

	bind(sockfd,(struct sockaddr*)&myaddr,len);

	listen(sockfd,10);

	fd_set  readfds = {0}; ///有效读描述符集
	fd_set  allfds = {0};  ///所有描述符集
	FD_SET(sockfd,&readfds);
	allfds = readfds;  ///保证集合相等
	int maxfd = sockfd,i  = 0;
	char buff[128] ={0};
	while(1)
	{
		readfds = allfds;
		select(maxfd+1,&readfds,NULL,NULL,0);
		for(i=sockfd;i<=maxfd+1;i++)
		{
			if( FD_ISSET(i,&readfds))
			{
				if( i == sockfd)
				{
					confd = accept(i,NULL,NULL);
					if(confd >maxfd)  maxfd = confd;
					FD_SET(confd,&allfds); break;
				}
				else
				{
					int ret = recv(i,buff,sizeof(buff),0);
					if(ret <=0)
					{
						close(i);
						FD_CLR(i,&allfds);
					}
					else
						printf(" recv buff = %s\n",buff);

					break;
				}
			}
		}
	}

	close(confd);
	close(sockfd);


	return 0;
}

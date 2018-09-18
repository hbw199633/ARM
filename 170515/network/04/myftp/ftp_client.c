/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：ftp_client.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月02日
*   描    述：
================================================================*/

#include  "head.h"

int  socket_init(char *ip,short port)
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}
	int ret  = 0;
	char buff[128] ={0};
	static  struct sockaddr_in  seraddr ={0};
	seraddr.sin_family	= AF_INET;
	seraddr.sin_port	= htons(port);
	seraddr.sin_addr.s_addr	= inet_addr(ip);
	socklen_t len=  sizeof(seraddr);
	ret = connect(sockfd,(struct sockaddr*)&seraddr,sizeof(struct sockaddr));
	if(ret < 0)
	{
		perror("connect");
		return -1;
	}

	return sockfd;
}



int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage %s [ftp server ip] \n",argv[0]);
		return -1;
	}

	printf("****************ftp client*************\n");
	printf("****支持命令： ls  \n"
		   "               put file \n"
		   "			   get file  \n"
		   "			   byi \n");
	printf("****************ftp client*************\n");
	int ret  =0;
	int sockfd= socket_init(argv[1],8888);
	char buff[128] ={0};
	char msg[1024] ={0};
	while(1)
	{
		printf("myftp>>");
		bzero(buff,sizeof(buff));
		fgets(buff,sizeof(buff),stdin);
		if(!strcmp(buff,"by\n"))  break;
		else if(!strcmp(buff,"ls\n"))
		{
			printf("ls in... \n");
			send(sockfd,buff,strlen(buff),0);
			recv(sockfd,msg,sizeof(msg),0);
			printf("%s\n",msg);
		}
		else if(!strncmp(buff,"put",3))
		{
			printf("put file ... \n");
			send(sockfd,buff,strlen(buff),0);
			buff[strlen(buff)-1] ='\0';	
			char name[128] ={0};
			strcpy(name,&buff[4]);
			sendfile(sockfd, name);
			close(sockfd);
			socket_init(argv[1],8888);
		}
		else if(!strncmp(buff,"get",3))
		{
			printf("get file ... \n");
			send(sockfd,buff,strlen(buff),0);
		}
		else
		{
			printf("命令不支持\n");
		}
	}


	close(sockfd);
    return 0;
}

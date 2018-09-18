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

int send_file(int sockfd, struct filemsg *file)
{
	int ret  = 0;
	int fd = open(file->filename,O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	while(1)
	{
		file->filesize = read(fd,file->filetext,sizeof(file->filetext));
		if(file->filesize <= 0) break;
		ret = send(sockfd,file,sizeof(struct filemsg),0);
		if(ret <0)
		{
			perror("send");
			break;
		}
	}
	close(fd);
	return 0;
}



int  recv_file(int sockfd,struct filemsg *file)
{
	int ret  =0;
	int fd = open(file->filename,O_WRONLY|O_TRUNC|O_APPEND|O_CREAT,0644);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	while(1)
	{
		ret = recv(sockfd,file,sizeof(struct filemsg),0);
		if(ret > 0)
		{
			write(fd,file->filetext,file->filesize);
		}
		if( (file->filesize == 0)  || (file->filesize > 1025))
		{
			printf("recv file end \n");
			break;
		}
		printf("recv file size = %d \n",file->filesize);
	}

	close(fd);
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
	struct filemsg var={0};
	char buff[128] ={0};
	char msg[1024] ={0};
	while(1)
	{
		printf("myftp>>");
		bzero(buff,sizeof(buff));
		fgets(buff,sizeof(buff),stdin);
		buff[strlen(buff)-1] ='\0';

		if(!strcmp(buff,"by"))  break;
		
		else if(!strcmp(buff,"ls"))
		{
			var.type = 1;
			strcpy(var.filename,"ls");
			send(sockfd,&var,sizeof(struct filemsg),0);
			recv(sockfd,&var,sizeof(struct filemsg),0);
			printf("%s\n",var.filetext);
		}
		else if(!strncmp(buff,"put",3))
		{
			var.type =2 ;
			strcpy(var.filename,buff+4);
			printf("put filename = %s\n",var.filename);
			send(sockfd,&var,sizeof(struct filemsg),0);
			send_file(sockfd, &var);
		}
		else if(!strncmp(buff,"get",3))
		{
			printf("get file ... \n");
			struct filemsg cmd ={0} ;
			cmd.type = 3;
			strcpy(cmd.filename,buff+4);
			send(sockfd,&cmd,sizeof(cmd),0); 
			recv_file(sockfd,&cmd);
		}
		else
		{
			printf("命令不支持\n");
		}

	}


	close(sockfd);
    return 0;
}

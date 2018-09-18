/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：ftp_server.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月02日
*   描    述：
================================================================*/

#include  "head.h"

int socket_init(char *ip, short port)
{
	int ret  =0,connfd = 0;
	char buff[128] ={0};
	struct sockaddr_in  addr={0};
	socklen_t  len  = 0;
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)
	{
		perror("socket");
		return -1;
	}	
	
	int on = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

	addr.sin_family	= AF_INET;
	addr.sin_port	= htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	len = sizeof(addr);
	ret  = bind(sockfd,(struct sockaddr*)&addr,len);
	if(ret < 0)
	{
		perror("bind");
		return -1;
	}
	printf("bind ok \n");
	listen(sockfd,5);
	return sockfd;
}


int socket_exit(int fd1,int fd2)
{
	close(fd1);
	close(fd2);
}


int get_dir_info(char *dirname,char *dirinfo)
{
	
   int ret = 0;
   DIR * dr = opendir(dirname);
   if(NULL == dr)
   {
		perror("opendir");
        return -1;
   }
   chdir(dirname);
   while(1)
   {
	   struct dirent * dt = readdir(dr);
	   if(NULL == dt) break;
	   if(dt->d_name[0] == '.') continue;
	  // printf("name = %s \n",dt->d_name);
	  	strcat(dirinfo,"	\n");
	    strcat(dirinfo, dt->d_name);
   }
   ret = closedir(dr);
   return ret;
}

int send_dir(int connfd,struct filemsg *msg)
{
	char buff[1024] ={0};
	get_dir_info("./",buff);
	msg->type =1;
	strcpy(msg->filename,"ls");
	strcpy(msg->filetext,buff);
	send(connfd,msg,sizeof(struct filemsg),0);
}

int send_file(int sockfd, struct filemsg * file)
{
	int fd = open(file->filename,O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	while(1)
	{
		 file->filesize  = read(fd,&file->filetext,sizeof(file->filetext));
		 if(file->filesize == 0) 
		 {
		 	printf("send file end \n");
			file->filesize = 0;
			send(sockfd,file,sizeof(struct filemsg),0);
		  break;
		 }
		 int ret = send(sockfd,file,sizeof(struct filemsg),0);
		 printf("send file ret = %d \n",ret);
	}
	close(fd);
	return 0;
}
int recv_file(int connfd, struct filemsg *file)
{
	int ret =0,i = 0;
	struct filemsg buff ={0};
	printf("recv file name = %s \n",file->filename);
	int fd = open(file->filename,O_CREAT|O_TRUNC|O_APPEND|O_WRONLY,0644);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	if(file->filesize >0)
	{
		write(fd,file->filetext,file->filesize);
	}

	while(1)
	{
		ret = recv(connfd,&buff,sizeof(struct filemsg),0);
		if( ( buff.filesize <=0)  || (buff.filesize >1025))
		{
			printf("recv file end \n");
			break;
		}
		write(fd,buff.filetext,buff.filesize);
	}
	close(fd);
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage %s [server ip] \n",argv[0]);
		return -1;
	}
	struct filemsg buff ={0};
	int connfd = 0,ret = 0;
	int sockfd = socket_init(argv[1],8888);
	if(sockfd < 0)  return -1;
	while(1)
	{
		connfd = accept(sockfd,NULL,NULL);
		while(1)
		{
			ret = recv(connfd,&buff,sizeof(buff),0);
			if(ret > 0)
			{
				if(buff.type == 1)
				{
					send_dir(connfd,&buff);
				}
				else if(buff.type == 2)
				{
					recv_file(connfd,&buff);
				}
				else if(buff.type == 3)
				{
					send_file(connfd,&buff);	
				}

			}
			else
			{
				printf("recv exit \n");
				close(connfd);
				break;
			}
		}
	}

	socket_exit(sockfd,connfd);

    return 0;
}

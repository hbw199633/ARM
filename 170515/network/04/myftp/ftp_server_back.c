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

int send_dir(int connfd)
{
	char buff[1024] ={0};
	get_dir_info("./",buff);
	//printf("get dir info buf f= %s \n",buff);
	send(connfd,buff,strlen(buff),0);
}

int send_file()
{

}
int recv_file(int connfd,char *filename,int len)
{
	int ret =0,i = 0;
	char name[128] ={0};
	char buff[1024] ={0};
	
	char *p  = filename;
	while(1)
	{
		if( *p == '\n') 
		{
			p++;
			break;
		}
		else
			name[i] = *p;	
		p++;
		i++;
	}

	
	int fd = open(name,O_CREAT|O_TRUNC|O_APPEND|O_WRONLY,0644);
	if(fd < 0)
	{
		perror("open");
		return -1;
	}
	ret = write(fd,p,len-strlen(name)-6);
	printf("p = %s \n",p);

	while(1)
	{
		bzero(buff,sizeof(buff));
		ret = recv(connfd,buff,sizeof(buff),0);
		printf("buff = %s ret = %d\n",buff,ret);
		if( ret <=0)
		{
			printf("recv file end \n");
			break;
		}
		write(fd,buff,ret);
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

	char buff[128] ={0};
	int connfd = 0,ret = 0;
	int sockfd = socket_init(argv[1],8888);
	if(sockfd < 0)  return -1;
	
	
	while(1)
	{
		connfd = accept(sockfd,NULL,NULL);
		while(1)
		{
			bzero(buff,sizeof(buff));
			ret = recv(connfd,buff,sizeof(buff),0);
			if(ret > 0)
			{
				buff[strlen(buff)-1] ='\0';
				printf("recv buff = %s \n",buff);
				if(!strncmp(buff,"ls",2)) 
					send_dir(connfd);
				else if(!strncmp(buff,"put",3))  
					recv_file(connfd,&buff[4],ret);
				else if(!strncmp(buff,"get",3))  
					send_file();
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

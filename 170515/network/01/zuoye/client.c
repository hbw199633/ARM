/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：client.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月29日
*   描    述：
================================================================*/

#include  "head.h"

char recv_buff[128];
char send_buff[128];
char show_buff[256];

void *fun1(void *arg)
{
	int connfd = (int)arg;
	int ret  =0;
	while(1)
	{
		ret= recv(connfd,recv_buff,sizeof(recv_buff),0);
		if(ret < 0)
		{
			perror("recv ");
			break;
		}
		sprintf(show_buff,"%s			%s \n",send_buff,recv_buff);
		printf("%s",show_buff);
		if(!strncmp(recv_buff,"quit",4)) 
		{
			break;
		}
	}
	pthread_exit(0);

}

void *fun2(void *arg)
{
	int connfd = (int)arg;
	int ret =0;
	while(1)
	{
		printf(">>");
		fgets(send_buff,sizeof(send_buff),stdin);
		ret= send(connfd,send_buff,sizeof(send_buff),0);
		if(ret < 0)
		{
			perror("recv ");
			break;
		}
		if(!strncmp(send_buff,"quit",4)) 
		{
			break;
		}
	}
	pthread_exit(0);
}




int main(int argc, char *argv[])
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	int i  = 0;
	char buff[128] ={0};
	struct sockaddr_in  seraddr ={0};
	seraddr.sin_family	= AF_INET;
	seraddr.sin_port	= htons(8888);
	seraddr.sin_addr.s_addr	= inet_addr("172.16.4.134");
	socklen_t len=  sizeof(seraddr);

	connect(sockfd,(struct sockaddr*)&seraddr,len);

	pthread_t tid1 =0,tid2  = 0;
	pthread_create(&tid1,NULL,fun1,(void*)sockfd);
	pthread_create(&tid2,NULL,fun2,(void*)sockfd);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);


/*
	while(1)
	{
		send(sockfd,"hello world",11,0);
		printf("send %d \n",i++);
		sleep(1);

		int ret = recv(sockfd,buff,sizeof(buff),0);
		if(ret > 0)
			printf("client recv buff = %s \n",buff);
	}

*/


close(sockfd);

    return 0;
}

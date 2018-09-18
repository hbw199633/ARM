#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <linux/un.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if(pid == 0)
	{
		int sockfd  = socket(AF_UNIX,SOCK_DGRAM,0);
		if(sockfd < 0)
		{
			perror("socket error");
			return -1;
		}
		//printf("sockfd  = %d \n",sockfd);
		unlink("./abc");

		struct sockaddr_un  myaddr;
		myaddr.sun_family		= AF_UNIX;
		strcpy(myaddr.sun_path, "./abc");
		socklen_t  len = sizeof(myaddr);
		int ret = bind(sockfd, (struct sockaddr*)&myaddr, len );
		if(ret < 0)
		{
			perror("bind error");
			return -1;
		}

		char buff[128] ={0};

		ret = recvfrom(sockfd,buff,sizeof(buff),0,NULL,NULL);
		if(ret <= 0)
		{
			perror("recv error");
			return -1;
		}
		printf("recv buff  = %s \n",buff);

		close(sockfd);

		exit(0);
	}
	if(pid > 0)
	{
		sleep(1);
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

		wait(NULL);


		return 0;

	}
}

/*====================================================
*   Copyright (C) 2016 ==CQB==  All rights reserved.
*
*   文件名称：server.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2016年11月01日
*   描    述：
*
================================================================*/
#include  "head.h"

int socket_init(char *ip,int port)
{
   int  sockfd =  socket(AF_INET,SOCK_STREAM,0);
   if(sockfd < 0)  return -1;

   struct sockaddr_in  myaddr;
   myaddr.sin_family        = AF_INET;
   myaddr.sin_port          = htons(port);
   myaddr.sin_addr.s_addr   = inet_addr(ip);
   socklen_t len  = sizeof(myaddr);

   int ret = bind(sockfd,(struct sockaddr*)&myaddr,len);
   if(ret< 0)   return -1;

   listen(sockfd,10);

   return sockfd;
}

int send_ls(int connfd)
{
    printf("send ls in .... \n");
    char *str ="abc \ndef  \nxxx \n";
    int ret = send(connfd,str,strlen(str),0);
    printf("send  ret = %d \n",ret);
    return  0;
}
int send_file(MSG *pmsg,int connfd)
{
    printf("send file in  cmd = %s file = %s \n",
            pmsg->cmd,pmsg->filename);

    char *str ="abcalskdfjaslkdfjasdf";
    int ret = send(connfd,str,strlen(str),0);
    printf("send  ret = %d \n",ret);
    send(connfd,"##END##",7,0);
    return 0;
}
int recv_file()
{

    printf("recv file in .... \n");
}


int command_deal(MSG *pmsg,int connfd)
{
    if(!strcmp(pmsg->cmd,"ls"))
    {
        send_ls(connfd);
    }
    else if(!strcmp(pmsg->cmd,"bye"))  
    {
        printf("client end .. \n");
        return 0;
    }
    else  if(!strcmp(pmsg->cmd,"get"))
    {
        send_file(pmsg,connfd);
    }
    else  if(!strcmp(pmsg->cmd,"put"))
    {
        recv_file();
    }
    else
        return -1;
}



int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage %s [local_ip] [local_port] \n",argv[0]);
        return -1;
    }

    int sockfd = socket_init(argv[1],atoi(argv[2]));
    if(sockfd == -1)
    {
        perror("socket init");
        return -1;
    }
    
    int connfd = 0,ret = 0;
    MSG msg = {0};
    while(1)
    {

        connfd = accept(sockfd,NULL,NULL);
        if(connfd < 0)
        {
            perror("accept");
            return -1;
        }
        while(1)
        {
            ret = recv(connfd,&msg,sizeof(msg),0);
            if(ret > 0)
            {
                command_deal(&msg,connfd);
            }
            if(!strcmp(msg.cmd,"bye")) break;
        }

        close(connfd);
    }    

    close(sockfd);



    return 0 ; 
}


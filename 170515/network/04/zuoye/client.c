/*====================================================
*   Copyright (C) 2016 ==CQB==  All rights reserved.
*
*   文件名称：client.c
*   创 建 者：cqb  2848319176@qq.com
2*   创建日期：2016年11月01日
*   描    述：
*
================================================================*/
#include  "head.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Usage %s [server_ip] [server_port] \n",argv[0]);
        return -1;
    }

    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    
    struct sockaddr_in seraddr;
    seraddr.sin_family      = AF_INET;
    seraddr.sin_port        = htons(atoi(argv[2]));
    seraddr.sin_addr.s_addr = inet_addr(argv[1]);
    socklen_t len = sizeof(seraddr);

    int ret = connect(sockfd,(struct sockaddr*)&seraddr,len);
    char buff[256]={0};
    char buff2[256]={0};
    MSG  msg = {0};
    while(1)
    {
        printf("mytfp>>");
        fgets(buff,sizeof(buff),stdin);
        if(strstr(buff,"ls"))
        {
            strcpy(msg.cmd ,"ls");       
            send(sockfd,&msg,sizeof(msg),0);
            ret = recv(sockfd,buff2,sizeof(buff2),0);
            if(ret > 0)
            {
                printf("%s",buff2);
            }
        }   
        else if(strstr(buff,"get"))
        {
            strcpy(msg.cmd,"get");
            buff[strlen(buff)-1]='\0';
            sscanf(buff,"%s %s",msg.cmd,msg.filename);
            send(sockfd,&msg,sizeof(msg),0);
            while(1)
            {
                bzero(buff2,sizeof(buff2));
                ret = recv(sockfd,buff2,sizeof(buff2),0);
               if(!strcmp(buff2,"##END##"))
                {
                    printf("\n recv file end .. \n");
                    break; 
                }
              
                if(ret >0)
                {
                    printf("%s",buff2); ////write file
                }
                
            }
        }
        else if(strstr(buff,"put"))
        {
            strcpy(msg.cmd,"put");
            send(sockfd,&msg,sizeof(msg),0);
        }
        else if(!strcmp(buff,"bye\n")) 
        {
            strcpy(msg.cmd,"bye");
            send(sockfd,&msg,sizeof(msg),0);
            break;
        }
        else
        {
            printf("输入命令有误！\n");
        }
    }


    close(sockfd);

    return 0 ; 
}


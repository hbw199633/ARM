#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
int send_char(char c,int pid)
{
    int i = 0, j = 1;
    for(i=0;i<8;i++)
    {
        usleep(1000);
        j = 1;
        j = j<<i;
        if( j & c)
        {
            printf("1");
            kill(pid,8-i);
        }
        else
            printf("0");
    }
    kill(pid,1);
    printf("\n");   
    return  0;
}


int main(int argc, const char *argv[])
{
     pid_t pid = 0;
     char buff[128] ={0};
     printf("请输入要发送目标的pid:\n");
     scanf("%d",&pid);
     while(1)
     {
         printf("请输入要发送的信息 q 退出:\n");
         fgets(buff,sizeof(buff),stdin);
         if(!strcmp(buff,"q\n")) 
         {
             kill(pid,9);
             exit(0);
         }
         int i = 0;
         while( buff[i] != '\0')
         {
             send_char(buff[i],pid);
             i++;
         }
     }

     return 0;
}

#include <stdio.h>
#include <signal.h>
#include <string.h>

char sig_char(int sig,char *c)
{
    int  x = *c;
    int  y =  1;
    switch(sig)
    {
      case 2:{ x = x | (y<<6); break;}   
      case 3:{ x = x | (y<<5); break;}   
      case 4:{ x = x | (y<<4); break;}   
      case 5:{ x = x | (y<<3); break;}   
      case 6:{ x = x | (y<<2);break;}   
      case 7:{x = x | (y<<1);break;}   
      case 8:{x = x | y;break;}   
    }
    *c = x;
    return  0;
}

void fun(int sig)
{
    static char c;
    sig_char(sig,&c);
   // printf("%c \n",c);
    if(sig == 1) 
    {
        printf("%c",c);
        fflush(stdout);
        c = 0;
    }
}

int main(int argc, const char *argv[])
{
    printf("mypid = %d \n",getpid());
    int i =0;
    for(i=1;i<9;i++)
    {
        signal(i,fun);
    }
    
    while(1)
    {
        sleep(1);
    }


     return 0;
}

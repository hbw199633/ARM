#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
   int i = 0;
   pid_t pid2 = 0;
   pid_t pid[11] ={0};

   for(i=0;i<10;i++)
   {
        pid[i] = fork();
	if(pid[i] == 0)
	{
	    printf("pid[%d] = %d \n",i,getpid());
	    if(i == 5) 
		sleep(5);
	    else
		sleep(10); 
	    
	    exit(0);
	}
   }
while(1)
{
   //pid2 = waitpid(pid[5],NULL,0);
   pid2 = waitpid(pid[5],NULL,WNOHANG);
   printf("waitpid pid2 = %d \n ",pid2);
   sleep(1);
   if(pid2 > 0) break;
}


   for(i=0;i<9;i++)
   {
     pid2 = wait(NULL);
     printf("wait pid2 = %d \n",pid2);
   }

   return  0;
}

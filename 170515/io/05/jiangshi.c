#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
   pid_t pid = fork();

   if(pid == 0)  exit(0);

   if(pid > 0)
   {
    while(1)  sleep(1);
   }


 return 0;
}

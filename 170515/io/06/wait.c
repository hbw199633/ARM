#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
/*
    pid_t pid = fork();
    printf("hello %d \n",getpid());
*/


/*
    pid_t pid = fork();
    if(pid == 0)  exit(0);
    if(pid > 0)   sleep(10);

*/


/*
    pid_t pid = fork();
    if(pid > 0)  exit(0);
    if(pid == 0) sleep(10);
*/


    //pid_t pid = fork();
   pid_t pid  = 100;
   if(pid == 0)
    {
	sleep(1);  exit(0);
    }
    if(pid > 0) 
    {
	sleep(2);
	int n = wait(NULL);
	printf(" n = %d \n",n);
	exit(0);
    }




    return  0;
}

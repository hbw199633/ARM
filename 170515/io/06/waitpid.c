#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
	printf("child pid = %d \n",getpid());
	sleep(5);
	// exit(9);
	//_exit(19);
	return 100;
    }
    if(pid > 0) 
    {
	int sta = 0;
	int n = waitpid(pid,&sta,0);
	printf(" n = %d sta = %d \n",n,WEXITSTATUS(sta));
	exit(0);
    }

    return  0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
	sleep(1);
	// exit(9);
	//_exit(19);
	return 100;
    }
    if(pid > 0) 
    {
	int sta = 0;
	int n = wait(&sta);
	printf(" n = %d sta = %d \n",n,WEXITSTATUS(sta));
	sleep(2);
	exit(0);
    }

    return  0;
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main()
{

//////////////////////////////////////////////////////////
      
	pid_t pid = fork();
	if(pid > 0)  exit(0);
	//if(pid == 0) printf("child pid = %d \n",getpid());

        pid = setsid();
	//printf("setsid ret = %d \n",pid);


	chdir("/daemon");

	umask(0);

	int i = 0;
	for(i=0;i<getdtablesize();i++)
	{
	    close(i);
	}

//////////////////////////////////////////////////////////


	///守护进程之后的业务逻辑
	while(1)
	{
	  sleep(1);
	}

	return  0;
}

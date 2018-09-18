#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	int i = 0;
/*	
	for(i=0;i<135;i++)
	{
		errno = i;
		printf("i = %d \n",i);
		perror("error info = ");
	}

*/
	for(i=0;i<135;i++)
	{
		printf("error i = %d str = %s \n",i,strerror(i));
	}
	return 0;
}

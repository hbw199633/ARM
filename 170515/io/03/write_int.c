#include "head.h"

int main()
{
	int a = 99;
	int ret = 0;
	int fd  = open("./abc",O_WRONLY);
	if(fd < 0)
	{
	  perror("open");
          return -1;
	}
	printf("fd = %d \n",fd);

	ret  = write(fd,&a,sizeof(int));
	if(ret < 0)
	{
	   perror("write");
	}
	else
		printf("write int ok \n");

	ret = close(fd);
	printf("close ret = %d \n",ret);
	return  0;
}

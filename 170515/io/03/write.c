#include "head.h"

int main()
{
	char buf[128] ={"wohao"};
	int ret = 0;
	//int fd  = open("./abc",O_RDONLY);
	int fd  = open("./abc",O_WRONLY);
	if(fd < 0)
	{
	  perror("open");
          return -1;
	}
	printf("fd = %d \n",fd);

	ret  = write(fd,buf,strlen(buf));
	if(ret < 0)
	{
	   perror("write");
	}
	else
		printf("write buff = %s ret = %d \n",buf,ret);

	ret = close(fd);
	printf("close ret = %d \n",ret);
	return  0;
}

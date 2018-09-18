#include "head.h"

int main()
{
	char buf[128] ={"wohao"};
	int ret = 0;
	int fd  = open("./abc",O_WRONLY);
	if(fd < 0)
	{
	  perror("open");
          return -1;
	}

	ret  = write(fd,buf,strlen(buf));
	if(ret < 0)
	{
	   perror("write");
	}
	else
		printf("write buff = %s ret = %d \n",buf,ret);

	lseek(fd,100,SEEK_SET);

	write(fd,"nihao",5);




	ret = close(fd);
	printf("close ret = %d \n",ret);
	return  0;
}

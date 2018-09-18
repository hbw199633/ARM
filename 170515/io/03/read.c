#include "head.h"

int main()
{
	char buf[128] ={0};
	int ret = 0;
	int fd  = open("./abc",O_RDONLY);
	if(fd < 0)
	{
	  perror("open");
          return -1;
	}
	printf("fd = %d \n",fd);

	while(1)
	{
		ret  = read(fd,buf,sizeof(buf));
		if(ret < 0)
		{
			printf("read  error \n"); break;
		}
		else if(ret == 0)
		{
			printf("read end \n"); break;
		}
		else
			printf("read buff = %s ret = %d \n",buf,ret);
	}

	ret = close(fd);
	printf("close ret = %d \n",ret);
	return  0;
}

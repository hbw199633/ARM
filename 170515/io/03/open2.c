#include "head.h"

int main()
{
	char buff[128] ={"nihao"};
	int ret = 0;
	//int fd  = open("./abc",O_RDONLY);
	int fd  = open("./abcd",O_RDWR|O_CREAT|O_APPEND, 0644);
	if(fd < 0)
	{
	  perror("open");
          return -1;
	}
	printf("fd = %d \n",fd);

	
	write(fd,buff,strlen(buff));



	ret = close(fd);
	printf("close ret = %d \n",ret);
	return  0;
}

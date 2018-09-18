#include "head.h"

int main()
{
	int ret = 0;
	int fd  = open("./abc",O_RDONLY);
	if(fd < 0)
	{
	  perror("open");
          return -1;
	}
	printf("fd = %d \n",fd);






	ret = close(fd);
	printf("close ret = %d \n",ret);
	return  0;
}

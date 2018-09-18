#include "head.h"

int main()
{
	char buff[128] ={"nihao"};
	int ret = 0;
	int fd  = open("./abcd",O_RDWR|O_CREAT|O_EXCL,0644);
	if(fd < 0)
	{
	  if(errno == EEXIST)
	  {	
	    fd = open("./abcd",O_RDWR);
          }	
          else
	  {
	  	perror("open");
          	return -1;
	  }
	}
	printf("fd = %d \n",fd);

	
	write(fd,buff,strlen(buff));



	ret = close(fd);
	printf("close ret = %d \n",ret);
	return  0;
}

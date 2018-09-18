#include "head.h"

int main()
{
	char buf[128] ={"wohao"};
	int ret = 0;
	//int fd  = open("./abc",O_WRONLY);
	int fd  = open("./abc",O_RDWR);
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
	
	FILE * fp  = fdopen(fd,"r");
	if(NULL == fp)
	{
	   perror("fdopen");
	   return -1;
	}

//	fputs("dajiahao",fp);
	fgets(buf,sizeof(buf),fp);
	printf("fgets buf = %s \n",buf);
//	fclose(fp);


	ret = close(fd);
	printf("close ret = %d \n",ret);
	return  0;
}

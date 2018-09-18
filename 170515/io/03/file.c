#include "head.h"

int main()
{
   char buff[128] ={0};
   FILE * fp = fopen("./abc","r+");
  if(NULL == fp)
  {
   perror("fopen");
   return -1;
  }

  printf("fp->fd = %d \n",fp->_fileno);


  read(fp->_fileno,buff,sizeof(buff));
  printf("read buff = %s \n",buff);

  write(fp->_fileno,"hello",5);


  fclose(fp);
	


  return 0;
}

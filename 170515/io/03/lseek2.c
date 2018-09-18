#include "head.h"

int main()
{
   char buff[128] ={0};
   FILE * fp = fopen("./abc","a+");
  if(NULL == fp)
  {
   perror("fopen");
   return -1;
  }

  printf("fp->fd = %d \n",fp->_fileno);



  write(fp->_fileno,"hello",5);

  int ret = lseek(fp->_fileno,100,SEEK_SET);
  printf("ret = %d \n",ret);

  write(fp->_fileno,"wrold",5);


  fclose(fp);
	


  return 0;
}

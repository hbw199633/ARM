#include "head.h"

int main()
{
  char buff[128] ={0};

  read(STDIN_FILENO,buff,sizeof(buff));

  printf("read buff = %s \n",buff);


  return 0;
}

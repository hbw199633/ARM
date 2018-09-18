#include "head.h"

int main()
{
   int ret = 0;
   char buff[128] ={0};
   DIR * dr = opendir("./test");
   if(NULL == dr)
   {
	perror("opendir");
        return -1;
   }
   printf("dr = %p\n",dr);


//   chdir("./test");

   getcwd(buff,sizeof(buff));
	
   printf("buff = %s \n",buff);
	

   ret = closedir(dr);
   printf("ret = %d \n",ret);
  return 0;
}

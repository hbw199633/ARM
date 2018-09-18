#include "head.h"

int main()
{
   int ret = 0;
   DIR * dr = opendir("./test");
   if(NULL == dr)
   {
	perror("opendir");
        return -1;
   }
   printf("dr = %p\n",dr);


   struct dirent * dt = readdir(dr);
   printf("name = %s \n",dt->d_name);
   if(dt->d_name[0] == '.') continue;
	
	

   ret = closedir(dr);
   printf("ret = %d \n",ret);
  return 0;
}

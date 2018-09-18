#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>

int main(int argc, char *argv[])
{
   int ret = 0;
   struct stat  buff ={0};

   ret = stat(argv[1], &buff); 
   if(ret < 0)
   {
     perror("stat");
     return -1;
   }
   printf("stat ret = %d \n",ret);


   if( S_ISREG(buff.st_mode))    printf("-");
   else if(S_ISDIR(buff.st_mode))  printf("d");


   if(S_IRUSR & buff.st_mode) printf("r"); else printf("-");
   if(S_IWUSR & buff.st_mode) printf("w"); else printf("-");
   if(S_IXUSR & buff.st_mode) printf("x"); else printf("-");


   struct  passwd * pwd = getpwuid(buff.st_uid);
   printf(" %s ",pwd->pw_name);



   struct tm *ptm = localtime(&buff.st_mtime);

   printf("%4d-%02d-%02d  %02d:%02d:%02d ",
	   ptm->tm_year+1900,
	   ptm->tm_mon +1,
	   ptm->tm_mday,
	   ptm->tm_hour,
	   ptm->tm_min,
	   ptm->tm_sec);


  printf("\n");
  return 0;
}

#include <stdio.h>
#include <unistd.h>

int main()
{
  pid_t pid = fork();

  if(pid > 0)
  {
    ///父亲逻辑空间
    while(1)
    {
     printf("fahter.... \n");
     sleep(1);
    }
  }
  if(pid ==0)
  {
   // 子进程逻辑空间
     while(1)
     {
      printf("child ... \n");
      sleep(2);
     }
  }
  if(pid < 0)
  {
    perror("fork");
    return -1;
  }



  while(1)
  {
   printf("pid = %d nihao \n",getpid());
   sleep(1);
  }

  return 0;
}

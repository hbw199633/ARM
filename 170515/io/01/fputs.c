#include <stdio.h>

int main()
{
	int ret = 0;
	FILE * fp  = fopen("./abc","r+");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}
	printf("fopen ok !\n");
	char *s = "dajiahao";
	ret = fputs(s,fp);
	if(ret == EOF)
	{
	  printf("fputs error \n");
	}
	else
	{
	  printf("fputs ret = %d \n",ret);
	}

	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

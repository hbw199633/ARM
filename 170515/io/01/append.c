#include <stdio.h>

int main()
{
	FILE * fp  = fopen("./abc","a+");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}
	printf("fopen ok !\n");

	int ret = fputc('q',fp);
	if(ret == EOF)
	{
	  printf("fputc error\n");
	}
	else
	{
	  printf("fputc ok \n");
	}


	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

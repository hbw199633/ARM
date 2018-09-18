#include <stdio.h>

int main()
{
	FILE * fp  = fopen("./abc","r+");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}
	printf("fopen ok !\n");
	
	int c = 'w';
	int ret = fputc(c,fp);
	if(ret != EOF)
	{
	  printf("fputc ok\n");
	}
	else
	{
	 printf("fputc error ret = %d \n",ret);
	}

	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

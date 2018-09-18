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

	int id = 1;
	char *name = "lisi";
	long  phone= 12345;

	ret = fprintf(fp,"id=%d name=%s phone=%ld \n",id,name,phone);
	if(ret == EOF)
	{
	  printf("fprintf error \n");
	}

	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

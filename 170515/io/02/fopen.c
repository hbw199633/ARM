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



	int ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
//	fclose(fp);
	return  0;

}

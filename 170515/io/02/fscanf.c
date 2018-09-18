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

	int id = 0;
	char name[32] = {0};
	long  phone= 0;
	while(1)
	{
		ret = fscanf(fp,"id=%d name=%s phone=%ld\n",&id,name,&phone);
		if(ret == EOF)
		{
			printf("fprintf error \n"); 
			break;
		}
		printf("fscanf id = %d name = %s ph = %ld \n",id,name,phone);
	}

	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

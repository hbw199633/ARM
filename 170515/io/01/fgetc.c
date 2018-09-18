#include <stdio.h>

int main()
{
	FILE * fp  = fopen("./abc","r");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}
	printf("fopen ok !\n");

	int c = fgetc(fp);
	if(c!= EOF)
		printf("c = %c \n",c);
	else
	{
		perror("fgetc");
		printf("fgetc ret c= %d \n",c);
	}

	int ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

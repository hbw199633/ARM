#include <stdio.h>

int main()
{
	int ret  =0;
	FILE * fp  = fopen("./abc","r+");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}

	fputc('a',fp);
	
	fseek(fp,3,SEEK_SET);

	fputc('b',fp);

	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

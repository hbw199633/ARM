#include <stdio.h>
#include <string.h>
int main()
{
	char buff[128] ={0};
	int ret = 0;
	char *p  = NULL;
	FILE * fp  = fopen("./abc","r+");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}
	printf("fopen ok !\n");

	p = fgets(buff,sizeof(buff),fp);
	if(NULL == p)
	{
	  printf("fgets error \n");
	}
	else
	{
	  printf("fgets buff = %s p = %p buff[0] = %p\n",
		buff,p,&buff[0]);
	}
	
	printf("strlen buff = %d \n",strlen(buff));


	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

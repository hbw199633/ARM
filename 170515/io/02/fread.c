#include <stdio.h>
#include <string.h>
int main()
{
	int ret = 0;
	FILE * fp  = fopen("./abc","r+");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}

	char buff[32] ={0};
while(1)
{
	bzero(buff,sizeof(buff));
	ret = fread(buff,sizeof(char),sizeof(buff),fp);
	if(ret == 0) break;
	printf("fread ret = %d buff = %s \n",ret,buff);
}

	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

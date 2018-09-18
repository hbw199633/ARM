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
	while(1)
	{
		bzero(buff,sizeof(buff));
		p = fgets(buff,sizeof(buff),fp);
		if(feof(fp))  break;
		printf("buff = %s",buff);
		//if(NULL == p) break;
	}	


	ret = fclose(fp);
	return  0;

}

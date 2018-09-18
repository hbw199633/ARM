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

	char buff[32] ={"nihao"};
	

	//ret = fwrite(buff,sizeof(char),sizeof(buff),fp);
	ret = fwrite(buff,sizeof(char),strlen(buff),fp);
	printf("fwrite ret = %d buff = %s \n",ret,buff);

	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

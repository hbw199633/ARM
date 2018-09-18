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
	char buff2[32] ={0};

	ret = fwrite(buff,sizeof(char),strlen(buff),fp);
	printf("fwrite ret = %d buff = %s \n",ret,buff);


//	fclose(fp);
//	fp  = fopen("./abc","r+");

	rewind(fp);

	ret = fread(buff2,sizeof(char),sizeof(buff2),fp);
	printf("fread ret = %d buff2 = %s \n",ret,buff2);

	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

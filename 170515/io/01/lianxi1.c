#include <stdio.h>
#include <string.h>
int main()
{
	char buff[128] ={0};
	FILE * fp  = fopen("./abc","r+");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}

	while(1)
	{
		bzero(buff,sizeof(buff));
		fputs("请任意输入信息\n",stdout);
		fgets(buff,sizeof(buff),stdin);
		if(!strcmp(buff,"quit\n")) break;
		fputs(buff,fp);
	}
	fclose(fp);
	

	fp  = fopen("./abc","r");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}

	while(1)
	{
	 if(NULL ==fgets(buff,sizeof(buff),fp)) break;
	 fputs(buff,stdout);
	}
	fclose(fp);
	
	return  0;

}

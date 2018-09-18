#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("Usage %s [file] \n",argv[0]);
		return -1;
	}
	char buff[128] ={0};
	int ret = 0;
	char *p  = NULL;
	FILE * fp  = fopen(argv[1],"r");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}

	while(1)
	{
		p = fgets(buff,sizeof(buff),fp);
		if(NULL == p)
		{
			break;
		}
		else
		{
			printf("%s",buff);
		}


	}
	ret = fclose(fp);
	return  0;

}

#include <stdio.h>
#include <string.h>

int main(int argc,char * argv[])
{

	if(argc != 3)
	{
	   printf("Usage %s [src file]  [dest file] \n",argv[0]);
	   return -1;
	}
	
	char buff[128] ={0};
	FILE * fp_src   = fopen(argv[1],"r");
	if(NULL == fp_src)
	{
	  perror("fopen src");
	  return -1;
	}

	FILE * fp_dst = fopen(argv[2],"w+");
	if(NULL == fp_dst)
	{
	  perror("fopen dest");
          return -1;
	}

	while(1)
	{
	    bzero(buff,sizeof(buff));
	    if(NULL == fgets(buff,sizeof(buff),fp_src)) break;
	    fputs(buff,fp_dst);
	    fflush(fp_dst);
	}

	fclose(fp_src);
	fclose(fp_dst);
	
	printf("cp file end \n");


	return  0;

}

#include <stdio.h>
#include <string.h>
#include "head.h"

int main()
{
	int ret = 0;
	FILE * fp  = fopen("./abcd","r");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}

	STU stu1 ={0};


	ret = fread(&stu1,sizeof(STU),1,fp);
	printf("stu1.id = %d name = %s score = %.2f \n",
		stu1.id,stu1.name,stu1.score);

	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}

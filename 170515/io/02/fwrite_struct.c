#include <stdio.h>
#include <string.h>

#include "head.h"

int main()
{
	int ret = 0;
	FILE * fp  = fopen("./abcd","w+");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}

	STU  stu1 ={1,"zhangsan",99.9};
	ret = fwrite(&stu1,sizeof(STU),1,fp);

	ret = fclose(fp);
	return  0;

}

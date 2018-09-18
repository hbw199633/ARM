#include <stdio.h>

int main(void)
{

	char buff[10] ={0};

	printf("请输入任意数据\n");

	char *p = gets(buff);

	printf("buff addr= %p uff = %s \n",&buff[0],buff);
	printf("p addr = %p p = %s \n",p,p);

	return 0;
}

#include <stdio.h>

int main()
{

	char buff[10] ={0};
//	gets(buff);
	fgets(buff,sizeof(buff),stdin);
	printf("buff = %s \n",buff);

	return  0;
}

#include <stdio.h>

int main()
{
	int a = 0;
	printf("请输入一个整数\n");
	fscanf(stdin,"%d",&a);
	fprintf(stdout,"a = %d \n",a);
	
	return 0;
}

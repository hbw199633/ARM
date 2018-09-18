#include <stdio.h>

extern int add(int ,int);
int main()
{
	int a = 3,b = 4;
	
	int c = add(a,b);
	printf("c = %d \n",c);	
	return  0;
}

#include <stdio.h>

int main()
{

	int i = 0;
	/*
	for(i=0;i<1024;i++)
	{
		printf("h");
	}
	printf("e");
	*/


	for(i=0;i<20;i++)
	{
		printf("%256d" ,i);
		sleep(1);
	}


	while(1)
	{
		sleep(1);
	}

	return  0;
}

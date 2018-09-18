#include <stdio.h>

int main()
{

	//fprintf(stderr,"nihao");   ///不缓存机制
	fprintf(stdout,"nihao");     //行缓存机制

	while(1)
	{
	  sleep(1);
	}

	return  0;
}

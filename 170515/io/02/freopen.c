#include <stdio.h>

int main()
{
	printf("nihao \n");

	//freopen("./def.log","w+", stdout);
	freopen("/dev/null","w+", stdout);

	printf("wohao \n");
		
	freopen("/dev/tty","w+",stdout);

	printf("dajiahao \n");


/*
	int i = 0;
	for(i=0;i<100;i++)
	{
		printf("wo shi %d \n",i);
		sleep(1);
		if(i >= 5)
		freopen("/dev/tty","w+",stdout);
	}

*/

	return  0;
}

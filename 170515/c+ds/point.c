#include <stdio.h>

int main(void)
{
	char a = 'x';
	printf("&a = %p \n",&a);

	char *pa = &a;
	printf("&pa = %p\n",&pa);

	*pa = 'y';

	printf("pa = %p *pa = %c &pa = %p \n",
			pa,*pa,&pa);

	printf("sizeof char = %d sizeof *pa = %d sizeof pa = %d \n",
			sizeof(char),sizeof(*pa),sizeof(pa));


	int b = 100;

	int *pb = &b;

	printf("pb = %p *pb = %d &pb = %p \n",
			pb,*pb,&pb);

	printf("sizeof int = %d sizeof *pb = %d sizeof pb = %d \n",
			sizeof(int),sizeof(*pb),sizeof(pb));





	return 0;
}

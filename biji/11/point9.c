/**************************************************
> File Name: point9.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 15时13分16秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char a[10]={0,1,2,3,4,5,6,7,8,9};
	char *p1 = &a[0];
	char *p2 = &a[9];
	char *p3 = NULL;
	if(p1==NULL)
	{
		printf("p1=NULL\n");
		return 0;
	}
	if(p1!=NULL)
		printf("p1!=NULL\n");
	p3 = p1;
	printf("%p\n",p1);
	if(p3=NULL)
	{
		p3++;
	}
	printf("%p\n",p3);
	if(NULL==p3)
	{
		p3++;
	}
	printf("%p\n",p3);

    return 0;
}

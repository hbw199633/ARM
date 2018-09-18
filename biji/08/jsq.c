/**************************************************
  > File Name: jsq.c
  > Author: Kingyi
  > Mail: joseph2009@163.com 
  > Created Time: 2017年01月17日 星期二 17时32分17秒
 **************************************************/

#include <stdio.h>

int add(int a,int b)
{
	printf("%d + %d = %d\n",a,b,(a+b));
}

int sub(int a,int b)
{
	printf("%d - %d = %d\n",a,b,(a-b));
}

int mul(int a,int b)
{
	printf("%d * %d = %d\n",a,b,(a*b));
}

int divl(int a,int b)
{
	if(b== 0)
	{
		printf("num2 can't be zero!\n");
		return 0;
	}
	printf("%d / %d = %d\n",a,b,(a/b));
}

int main(int argc,const char* argv[])
{
	int a ,b ,c ;
	a=b=c=0;
	printf("Please input num1 +/-/*// num2!\n");
	while(1)
	{
		scanf("%d %c %d",&a,&b,&c);
		switch(b)
		{
			case '+':add(a,c); break; 
			case '-':sub(a,c); break; 
			case '*':mul(a,c); break; 
			case '/':divl(a,c);break;  
			default:
					 printf("Input error! Please input again!\n");
		}
	}
	return 0;
}

/**************************************************
> File Name: printf.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月17日 星期二 16时36分44秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a =0;
	float b =0;
	int buf[128]={0};
	scanf("%d %f %s",&a,&b,buf);
	printf("d  %d\n",a);
	printf("c  %c\n",a);
	printf("x  %x\n",a);
	printf("o  %o\n",a);
	printf("X  %X\n",a);
	printf("f  %f\n",b);
	printf("lf %lf\n",b);
	printf("u  %u\n",a);
	printf("s  %s\n",buf);
	printf("#X %#X\n",a);
	printf("#o %#o\n",a);
	printf("0d %07d\n",a);
	printf("0d %07d\n",a);
	printf("7d %-7d\n",a);
	printf(".8f %.8f\n",b);
	printf(".8s %.8s\n",buf);
	printf("hd %hd\n",a);
	printf("ld %ld\n",a);
    return 0;
}

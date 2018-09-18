/**************************************************
> File Name: malloc.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月09日 星期四 10时16分02秒
**************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,const char* argv[])
{
	int a = 100;
	char b = 'a';
	float c =1.2;

	int *p1 =(int *)malloc(sizeof(int)*10);	
	*p1 =a;
	char *p2 =(char *)malloc(sizeof(char)*10);	
	float *p3 =(float *)malloc(sizeof(float)*10);	
	char *p4 =(char *)malloc(sizeof(char)*10);	
	*p2 =b;
	*p3 =c;
	char *p5;
	p5=p4;
    p4 ="nihao";	
	printf("%d %c %f %s\n",*p1,*p2,*p3,p4);
	
	free(p1);
	free(p2);
	free(p3);
	free(p5);
    return 0;
}

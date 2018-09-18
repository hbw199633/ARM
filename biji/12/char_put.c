/**************************************************
> File Name: char_put.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月07日 星期二 14时07分09秒
**************************************************/

#include <stdio.h>

void printf_out(int c);
int printf_out1(int c,int a);

void printf_out(int c)
{
	printf("%c de 8jinzhi=%#o 10jinzhi=%#d 16jinzhi=%#x\n",c,c,c,c);
}

int printf_out1(int c,int a)
{
	if(a==8)
		printf("%c 8jinzhi %#o\n",c,c);
	else if(a==10)
		printf("%c 10jinzhi %#d\n",c,c);
	else if(a==16)
		printf("%c 16jinzhi %#x\n",c,c);
	else
		printf("input error!\n");

}

int main(int argc,const char* argv[])
{
/*	char c=0;
	c = getchar();
	printf_out(c);
 */ 
	int c = 0, a = 0;
	printf("请输入一个字符和一个进制数字(8、10、16)\n");
	scanf("%c %d",&c,&a);
    printf_out1(c,a);
	return 0;
}

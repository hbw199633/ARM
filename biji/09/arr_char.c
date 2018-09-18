/**************************************************
> File Name: arr_char.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 16时07分18秒
**************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc,const char* argv[])
{
	char c[] ={'n','i','h','a','o'};
	char a[]="wohao";	
//	char b[128]={"dajiahao","wohao"};//wrong
	char b[]={"nihao"};
	char x[10];
//	x="nihao";//wrong
	x[0]='n';
	x[1]='h';
	printf("%c %c\n",x[0],x[1]);
	printf("%d %d\n",strlen(c),sizeof(c));	
	printf("%d %d\n",strlen(a),sizeof(a));	
	printf("%s %d %d\n",b,strlen(b),sizeof(b));
    return 0;
}

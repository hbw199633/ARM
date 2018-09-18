/**************************************************
  > File Name: puts_gets.c
  > Author: Kingyi
  > Mail: joseph2009@163.com 
  > Created Time: 2017年01月17日 星期二 14时12分09秒
 **************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int c =0;
	char buff[128]={0};
	while(1)
	{
		printf("Please in put some world\n");
		gets(buff);
		puts(buff);
		printf("Did you need exit! (y/n)\n");
/*		gets(buff);
 *		if(buff[0]=='y')
 *			break;
*/
		c =getchar();
		getchar();
		if(c =='y')
			break;
	}
	return 0;
}

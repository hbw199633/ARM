/**************************************************
  > File Name: goto1.c
  > Author: Kingyi
  > Mail: joseph2009@163.com 
  > Created Time: 2017年01月18日 星期三 16时22分16秒
 **************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0 ,j = 0;
loop:	i++;
		j=0;
flag:	j++;
		printf("%d*%d=%d\t",j,i,(j*i));
		if(j<i)
			goto flag;
		printf("\n");
		if(i<9)
			goto loop;
		return 0;
}

/**************************************************
> File Name: getchar_tui.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月17日 星期二 09时50分21秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int c =0;
	while(1)
	{
		printf("pls input one char,'#' exit\n");
		c =getchar();
//		getchar();
		if(c == '#')
			break;
		else
			printf("%d %c\n",c,c);
	}	
    return 0;
}

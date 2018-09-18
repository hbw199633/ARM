/**************************************************
> File Name: point15.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 17时29分15秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a[4][5]={{1,2,3,4,5},
				 {5,4,3,2,1},
				 {6,7,8,9,0},
				 {0,9,8,7,6}
				};
	int *p[5]={&a[0][0],&a[1][0],&a[2][0],
			   &a[3][0]};
	printf("%d \n",*(p[0]+0));
	printf("%d \n",*(p[1]+1));
	printf("%d \n",*(p[2]+2));
	printf("%d \n",*(p[3]+3));
	int **p1=p;
	printf("%d \n",*(*(p1+0)+0));
	printf("%d \n",*(*(p1+1)+1));
	printf("%d \n",*(*(p1+2)+2));
	printf("%d \n",*(*(p1+3)+3));
    return 0;
}

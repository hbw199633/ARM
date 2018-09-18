/**************************************************
> File Name: main.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月07日 星期二 16时35分49秒
**************************************************/

#include "head.h"

int main(int argc,const char* argv[])
{
	float sum = 0,src[5] = {0};
	fun_input(src,5);
	sum = fun_arv(src,5);
	fun_output(sum);

    return 0;
}

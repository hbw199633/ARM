/**************************************************
> File Name: test.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月09日 星期四 14时11分35秒
**************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc,const char* argv[])
{
	FILE *fp = fopen("/root/123","r");
	if(NULL==fp )
	{
		perror("open");
		return 0;
	}
    return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main()
{
    int fd = 0,ret = 0;
    struct stat buff ={0};

    fd = open("./test",O_RDONLY);
    if(fd < 0)
    {
	perror("open");
	return -1;
    }

    ret= fstat(fd,&buff);
    if(ret < 0)
    {
	perror("fstat");
	close(fd);
	return -1;
    }

    if(S_ISREG(buff.st_mode))    printf("-");
    else if(S_ISDIR(buff.st_mode))  printf("d");

    
    close(fd);
    printf("\n");

    return 0;
}



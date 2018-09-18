#ifndef _HEAD_H_

#define _HEAD_H_

#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

#include  <sys/types.h>
#include  <sys/socket.h>
#include  <arpa/inet.h>
#include  <netinet/in.h>

typedef struct
{
    char cmd[32] ;
    char filename[128];
}MSG;


#endif


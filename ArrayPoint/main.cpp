#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int sz[4][5][6];
    printf("address:%02X len:%d \n" ,sz,sizeof(sz));
    printf("address:%02X len:%d \n" ,sz[0],sizeof(sz[0]));
    printf("address:%02X len:%d \n" ,sz[0][0],sizeof(sz[0][0]));

    return 0;
}

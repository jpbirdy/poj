#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <string>
using namespace std;

#define SET(ADDRESS,BIT) ADDRESS|= (1 << (BIT))
#define CLR(ADDRESS,BIT) ADDRESS&=~(1 << (BIT))

int main()
{
    int x,y;
    int num;
    char stack[100];
    int top;

    while(scanf("%x,%d,%d",&num,&x,&y)==3)
    {
        CLR(num,x);
        SET(num,y);
        SET(num,y-1);
        CLR(num,y-2);

        printf("%x\n",num);
    }

    return 0;
}

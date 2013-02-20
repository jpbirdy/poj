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

int gcd(int m,int n)
{
    if(n > m) return gcd(n,m);
    if(m%n==0) return n;
    else return gcd(n,m%n);
}


int main()
{
    int a,b,c,d;
    char o;
    while(scanf("%d/%d%c%d/%d",&a,&b,&o,&c,&d)==5)
    {
        int x;
        if(o=='-')
            x = a*d - b*c;
        else
            x = a*d + b*c;
        int y = b*d;
        if(x==0) {printf("0\n");continue;}
        int gcd_x_y = gcd(abs(x),abs(y));
        x = x/gcd_x_y;
        y = y/gcd_x_y;
        if(y!=1)
            printf("%d/%d\n",x,y);
        else
            printf("%d\n",x);
    }
    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;


int main()
{
    int y,k,n;
    long long min;
    while(scanf("%d%d%d",&y,&k,&n)==3)
    {
        min = y/k+1;
        if(min*k > n)
            printf("-1\n");
        else
        {
            printf("%lld",min*k-y);

            for(min++;min*k<=n ; min++)
                printf(" %lld",min*k-y);
            printf("\n");
        }
    }
    return 0;
}

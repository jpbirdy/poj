#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t,cases=1;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        int flag = 1;
        for(int i=2 ; i<n ; i++)
            if(((n+i-1) / i)<2)
            {
                break;
            }

            else if(((n+i-1) % i) == 0)
            {
                flag = 0;
                printf("Case %d: %lld %d %d\n",cases++,n+i-1,i,1);
                break;
            }

        if(flag)
        {
            printf("Case %d: no solution\n",cases++);
        }
    }
    return 0;
}

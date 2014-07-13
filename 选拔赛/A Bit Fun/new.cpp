#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int d[100010][31],a[100010];

int n,m;

void init()
{
    memset(d,0,sizeof(n));
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<30; j++)
        {
            d[i][j]=d[i-1][j];
            if(a[i]&(1<<j))
                d[i][j]++;
        }
    }
}

int f(int j,int i)
{
    int num=0;
    for(int k=0; k<30; k++)
    {
        if(d[j][k]-d[i-1][k]>0)
            num|=(1<<k);
    }
    return num;
}

int main()
{
    int x;
    int t;
    int cases = 1;
    int i,j;
    int ans ;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d",&n,&m);
        for(i=1 ; i<=n ; i++)
            scanf("%d",a+i);

        init();
        ans = 0;
        i=j=1;

        for(; i<=n; i++)
        {
            while(j<=i && f(i,j)>=m)
                j++;
            ans+=i-j+1;
        }
        printf("Case #%d: %d\n",cases++,ans);
    }

}

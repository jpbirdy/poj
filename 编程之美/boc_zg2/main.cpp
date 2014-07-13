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

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int(i)=(n)-1;(i)>=0;(i)--)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())

void swap(int &a,int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

int main()
{
    int t;
    int n,m,k;
    int cases = 1;
    scanf("%d",&t);
    while(t--)
    {
        //保证N<M
        scanf("%d%d%d",&n,&m,&k);
        if(k==0)
        {
             printf("Case #%d: %ld\n",cases++,0);
             continue;
        }


        if(n>m) swap(n,m);
        int a,b,r;
        a = sqrt(k);
        //无法组成
        if(a>n) a = n;
        b = k/a;
        if(b>m) b=m;
        r = k-a*b;
        long long max = 0;
        for (;a>=2 && b<=m;--a,b=k/a)
        {
            long long res = 1;
            res = res*a*(a-1)*b*(b-1) / 4;
            r=k-a*b;
            if(b<m) res+=r*(r-1)/2*b;
            else res+=r*(r-1)/2*a;
            max=max>res?max:res;
        }



        printf("Case #%d: %lld\n",cases++,max);
    }

    return 0;
}

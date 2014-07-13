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

int n,a[100010];

int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n)==1 && n)
    {
        REP(i,n)
        scanf("%d",a+i);
        sort(a,a+n);

        //printf("%d\n",a[0]);
        double res = 0;
        REP(i,n)
            res+=a[i]*(n-i);
        res/=n;
        printf("%.3f\n",res);
    }

    return 0;
}

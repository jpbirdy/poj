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

int a[100010];

int mod[10010];
int n,m ;



int main()
{
    //freopen("input.txt","r",stdin);

    while(scanf("%d%d",&n,&m)==2)
    {
        REP(i,n)
        {
            scanf("%d",&a[i]);
            a[i]=a[i]%m;
            if(a[i]<0)a[i]+=m;
        }


        memset(mod,0xff,sizeof(mod));

        int sum = 0;
        REP(i,n)
        {
            sum = (sum + a[i]) % m;
            if(i>mod[sum]) mod[sum] = i;
        }
        int res = 0;
        int now = 0;
        REP(i,n)
        {
            if( (mod[now]-i+1)>res)
                res = mod[now] - i + 1;
            now = (now+a[i])%m;
        }
        printf("%d\n",res);
    }
    return 0;
}

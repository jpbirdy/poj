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

int n;
int q;
int u, l, r, delta;
int a[10010];
int d[10010];
int w[10010];
vector<int> al[10010];


const int MOD =1000000007; // 10^9 + 7
const int MAGIC= 12347;

long long gethash()
{
    long long ret = 0;
    for(int i=1 ; i<=n ; i++)
        ret = (ret * MAGIC +w[i]) % MOD;
    return ret;
}


void search_u(int u, int l, int r, int delta)
{
    if(d[al[u][0]] >=l  && d[al[u][0]]<=r)
            w[al[u][0]] = (w[al[u][0]] + delta) % MOD;
    for(int i=1 ; i<al[u].size() ; i++)
    {
        search_u(al[u][i] , l , r , delta);
    }
}

void get_u(int root,int dep)
{
    d[root] = dep;
    for(int i=1 ; i<al[root].size() ;i++)
        get_u(al[root][i],dep+1);
}

int main()
{

    //freopen("input.txt","r",stdin);
    int t;
    int cases = 1;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        memset(w,0,sizeof(w));
        scanf("%d",&n);
        REP(i,n+1)
        {
            al[i].clear();
            al[i].push_back(i);
        }



        for(int i=2 ; i<=n ; i++)
        {
            scanf("%d",&x);
            a[i] = x;
            al[x].push_back(i);
        }
        get_u(1,1);

        for(int i=1 ; i<=n ; i++)

        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d%d",&u, &l, &r, &delta);
            search_u(u,l,r,delta);
        }
        printf("Case %d: %lld\n",cases++,gethash());
    }

	return 0;

}

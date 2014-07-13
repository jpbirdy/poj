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

vector<int> edge_a[1000010];
vector<int> edge_b[1000010];

int n,m;

int check_width_b()
{
    int mm = 0;
    REP(i,m)
    {
        if(edge_b[i].size()>1) mm++;
        if(mm>1)return true;
    }
    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t,cases=1;
    int a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        REP(i,n)
            edge_a[i].clear();
        REP(i,n-1)
        {
            scanf("%d%d",&a,&b);
            edge_a[a].push_back(b);
            edge_a[b].push_back(a);
        }
        scanf("%d",&m);
        REP(i,m)
            edge_b[i].clear();
        REP(i,m-1)
        {
            scanf("%d%d",&a,&b);
            edge_b[a].push_back(b);
            edge_b[b].push_back(a);
        }

        if(m < 3)
        {
            printf("Case %d: NO\n",cases++);
        }
        else
        {
            if(check_width_b())
            {
                printf("Case %d: YES\n",cases++);
            }
            else
            {
                int bmax = 0;
                int amax = 0;
                REP(i,m)
                    if(edge_b[i].size()>bmax) bmax = edge_b[i].size();
                REP(i,n)
                    if(edge_a[i].size()>amax) amax = edge_a[i].size();

                if(bmax >= 3)
                    printf("Case %d: YES\n",cases++);
                else if(amax > bmax)
                    printf("Case %d: NO\n",cases++);
                else
                    printf("Case %d: YES\n",cases++);
            }
        }

    }


	return 0;
}

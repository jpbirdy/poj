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

int x[2010];
int y[2010];
int n;

bool g[2010];
int max_res;

void solve()
{
    double a,b;
    double x1,x2,y1,y2;
    for(int i=0 ; i<n-1 ; i++)
    {
        memset(g,0,sizeof(g));
        for(int j=i+1 ; j<n ; j++)
        {
            if(g[j]) continue;
            x1 = x[i];
            x2 = x[j];
            y1 = y[i];
            y2 = y[j];

            if(x[i] == x[j]) continue;

            a = (y2*x1-y1*x2) / (x2*x2*x1 - x1*x1*x2);
            b = (y1/x1-a*x1);
            int num = 2;
            for(int k=0 ; k<n ; k++)
                if(k==i || k==j) continue;
                else if(fabs(a*x[k]*x[k] + b*x[k] - y[k])<1e-4)
                {
                    num++;
                    g[k]=true;
                }

            if(num>max_res) max_res = num;
        }
    }

}


int main()
{
    int t;
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",x+i);
            scanf("%d",y+i);
        }
        max_res = 1;
        solve();
        printf("%d\n",max_res);
    }
    return 0;
}

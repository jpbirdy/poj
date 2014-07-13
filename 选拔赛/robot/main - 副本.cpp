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

int n,m,l,r;
int w[1000010];

float p[2][210];

int pl[200][110][2];

int il,ir,t;

int main()
{
    freopen("input.txt","r",stdin);
    while(scanf("%d%d%d%d",&n,&m,&l,&r)==4)
    {
        if(n==0 && m==0 && l==0 && r==0) break;
        l--;r--;


        n = 200;
        m = 1000000;
        for(int i=0 ; i<m ; i++)
            w[i] = rand()%100 + 1;



        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<=100 ; j++)
        {
            il = (i+n-j)%n;
            ir = (i+j)%n;
            pl[i][j][0] = il;
            pl[i][j][1] = ir;
        }

/*
        for(int i=m ; i>=1 ; i--)
            scanf("%d",&w[i]);
*/



        for(int i=0 ; i<n ; i++)
        {
            t = 0;
            il = (i+n-w[1])%n;
            ir = (i+w[1])%n;
            if(il>=l && il<=r) t++;
            if(ir>=l && ir<=r) t++;
            if(t==0) p[1][i] = 0;
            else if(t==1) p[1][i]=0.5;
            else if(t==2) p[1][i]=1;
        }


        for(int i=2 ; i<=m ; i++)
            for(int j=0 ; j<n ; j++)
        {
            il = pl[j][w[i]][0];
            ir = pl[j][w[i]][1];
            p[i%2][j] = p[(i-1)%2][il]*0.5+p[(i-1)%2][ir]*0.5;
        }
        printf("%.4f\n",p[m%2][0]);
    }
	return 0;
}

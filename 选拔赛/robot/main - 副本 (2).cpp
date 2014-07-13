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
float pt ;

int pl[200][110][2];

int il,ir,t;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d%d%d%d",&n,&m,&l,&r)==4)
    {
        if(n==0 && m==0 && l==0 && r==0) break;
        l--;r--;



        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<=100 ; j++)
        {
            il = (i+n-j)%n;
            ir = (i+j)%n;
            pl[i][j][0] = il;
            pl[i][j][1] = ir;
        }


        for(int i=0 ; i<m ; i++)
            scanf("%d",&w[i]);


        //memset(p,0,sizeof(p));
        p[0][0] = 1;

        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++) p[(i+1)%2][j] = 0;
            for(int j=0 ; j<n ; j++)
            {
                il = (j+n-w[i])%n;
                ir = (j+w[i])%n;
                pt = p[(i)%2][j]*0.5;
                p[(i+1)%2][il]+=pt;
                p[(i+1)%2][ir]+=pt;
            }
        }


        double sum = 0;
        for(int i=l ; i<=r ; i++)
            sum+=p[m%2][i];

        printf("%.4f\n",sum);
    }

	return 0;
}

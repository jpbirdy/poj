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


void rev_out(int n,int m,int mm)
{
    int i=n;
    REP(j,m-1)
        if(i>mm) printf("%d ",i--);
        else printf("%d ",(i--)-1);
    printf("%d\n",i-1);
}

int main()
{
    freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

    int t;
    int n,k;
    scanf("%d",&t);


    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0 ; i<n ; i++)
        {
            if(i==(n-1)) printf("%d\n",i+1);
            else
            {
                int remain = (n-i-1)*(n-i-2)/2;
                if(remain>=k)
                {
                    printf("%d ",i+1);
                }
                else
                {
                    int l = k-remain;
                    printf("%d ",i+l+1);
                    rev_out(n,n-i-1,i+l+1);
                    break;
                }
            }
        }
    }

    return 0;
}

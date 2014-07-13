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

int const N = 100010;

int a[N];

int cat(int aa,int bb)
{
    int x = aa;
    int y = bb;
    if(y==0) y=1;
    while(y)
    {
        x=x*10;y=y/10;
    }
    return x+bb;
}

int cmp(const void * aa,const void * bb)
{
    //return (*(int*)bb) - (*(int*)aa);
    int x = cat(*(int *)aa,*(int *)bb);
    int y = cat(*(int *)bb,*(int *)aa);
    return (y-x);
    //eturn (*(int*)aa) - (*(int*)bb);
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    int n;
    //memset(a,0,sizeof(a));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        REP(i,n)
            scanf("%d",a+i);
        qsort(a,n,sizeof(int),cmp);
        REP(i,n)
            printf("%d",a[i]);
        printf("\n");
    }

    return 0;
}

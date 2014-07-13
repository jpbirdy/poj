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

#define max(a,b) (((a)>(b))?(a):(b))

double f[410];

int main()
{
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for(int i=3; i<=400 ; i++)
    {
        double sum =0;
        for(int j=1 ; j<=i ; j++)
            sum+=max(f[j-1],f[i-j]);
        sum = sum /i + 1;
        f[i] = sum;
    }

    int n;
    int x;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d",&x);
        printf("%.5f\n",f[x]);
    }

    return 0;
}

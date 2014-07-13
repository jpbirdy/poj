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



int main()
{
    freopen("input.txt","w",stdout);
    int t = 10;
    REP(i,t)
    {
        int n,m,k;
        n = rand() * rand() % 100000;
        m = rand() * rand() % 100000;
        k = rand() * rand() % 100000 + 1;
        printf("%d %d %d\n",n,m,k);

        printf("%d",rand() * rand() % 100000);
        for(int j = 1 ; j<n ; j++)
            printf(" %d",rand() * rand() % 100000);
        printf("\n%d",rand() * rand() % 100000);
        for(int j = 1 ; j<m; j++)
            printf(" %d",rand() * rand() % 100000);
        printf("\n");

    }
    return 0;
}

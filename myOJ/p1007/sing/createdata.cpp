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
    int t = 100;
    REP(i,t)
    {
        int n = rand() % 100;
        printf("%d\n",n+1);
        printf("%d",rand()%70 + 130);
        REP(j,n)
            printf(" %d",rand()%70 + 130);
        printf("\n");
    }


    return 0;
}

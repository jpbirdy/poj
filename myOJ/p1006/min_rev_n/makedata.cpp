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

    int n = 10;
    printf("%d\n",n*3);
    REP(i,n)
    {
        int nn,kk;
        nn = rand()*rand()%100;
        kk = rand()*rand()%(nn*(nn-1)/2);
        printf("%d %d\n",nn,kk);
    }
    REP(i,n)
    {
        int nn,kk;
        nn = rand()*rand()%1000;
        kk = rand()*rand()%(nn*(nn-1)/2);
        printf("%d %d\n",nn,kk);
    }
    REP(i,n)
    {
        int nn,kk;
        nn = rand()*rand()%10000;
        kk = rand()*rand()%(nn*(nn-1)/2);
        printf("%d %d\n",nn,kk);
    }
    return 0;
}

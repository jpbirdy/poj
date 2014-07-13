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

#define LREP(i,n) for(long long(i)=0;(i)<(long long)(n);(i)++)
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int(i)=(n)-1;(i)>=0;(i)--)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())

int main()
{

    //freopen("input.txt","r",stdin);
    FILE *p = fopen("out.txt","w");
    long long n;
    scanf("%lld",&n);
    LREP(i,n)
    {
        int key = rand() * rand();
        fprintf(p,"%d\n",key);
    }
    fclose(p);
	return 0;

}

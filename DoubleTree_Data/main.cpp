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

#define LREP(i,n) for(long(i)=0;(i)<(long)(n);(i)++)
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int(i)=(n)-1;(i)>=0;(i)--)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())

char name[20];
long long v1,v2;


int main()
{
    FILE *p = fopen("out.txt","w");
    long long n;
    scanf("%lld",&n);
    LREP(i,n)
    {
        if(i%10000==1) printf("%d\n",i/10000);
        int len = rand()%5 + 5;
        REP(j,len)
        {
            name[j]=rand()%26+'a';
        }

        name[len]='\0';
        v1 = rand()*rand();
        v2 = rand()*rand();
        fprintf(p,"%d %s %lld %lld\n",i,name,v1,v2);
    }

	return 0;

}

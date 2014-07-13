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

const int MOD = 1000000007;


int main()
{
    int cases;
    long long n;
    long long t1,t2,t3;
    long long r1,r2,r3;
    long long k1,k2,k3;
    long long res ;
    scanf("%d",&cases);
    int t = 1;
    while(cases --)
    {
        scanf("%lld",&n);
        if(n%2==0)
        {
            t1 = ((n/2)% MOD * ((n+1) % MOD)) % MOD;
        }
        else
        {
            t1 = ((n)% MOD * ((n+1) / 2 % MOD)) % MOD;
        }

        r1 = t1 * t1 % MOD * t1 % MOD;
        r2 = (3 * t1) % MOD;

        k1 = n;
        k2 = n+1;
        k3 = n*2 + 1;
        if(k1%2 == 0) k1 = k1/2;
        else k2 = k2 / 2;
        if(k1%3 == 0) k1 = k1/3;
        else if(k2%3==0) k2 = k2/3;
        else k3 = k3/3;
        k1 = k1 % MOD;
        k2 = k2 % MOD;
        k3 = k3 % MOD;
        r2 = r2 * k1 % MOD * k2% MOD*k3% MOD;
        r3 = t1 * t1 % MOD * 3 % MOD;

        res = ((r1 + r3) % MOD - r2)%MOD;
        if(res < 0)
            res = res + MOD;
        printf("Case %d: %lld\n",t++,res);

    }

    //freopen("input.txt","r",stdin);
	return 0;

}

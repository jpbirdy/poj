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

typedef long long ll;

ll qpow(ll a, ll n, ll modulus)
{
    ll ret=1;
    while (n)
    {
        if (n&1) ret=ret*a%modulus;
        a=a*a%modulus;
        n>>=1;
    }
    return ret;
}

//MILLER ROBBIN≤‚ ‘
bool isPrime(ll n)
{
    if (n%2==0) return false;
    if (n<=1000)
    {
        for (int k=2; k*k<=n; k++)
            if (n%k==0) return false;
        return true;
    }
    ll b=101, d=n-1, j=0;
    while (d%2==0)
    {
        d/=2;
        j++;
    }
    ll i=0, y=qpow(b,d,n);
    while (i<j)
    {
        if ((i==0 && y==1) || (y==n-1)) return true;
        if (i>0 && y==1) break;
        y=y*y%n;
        i++;
    }
    return false;
}

int main()
{
    ll a,p;
    while (scanf("%lld%lld",&p,&a)!=EOF && a && p)
    {
        if (isPrime(p))
        {
            puts("no");
            continue;
        }
        if (qpow(a,p,p)==a) puts("yes");
        else puts("no");
    }
    return 0;
}

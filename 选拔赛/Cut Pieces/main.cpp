/**
方案数= a1*a2*a3*a4...*an+min（a1,a2)*a3*a4*a5...*an+
min(a2,a3)*a1*a4*..an+min(a3,a4)*a1*a2...*an+....
+min(an-1,an)*a1*a2*..*an-2

令S=a1*a2*a3*a4...*an
方案数= S+S-min（a1,a2)*a3*a4*a5...*an+
        S-min(a2,a3)*a1*a4*..an+
        S-min(a3,a4)*a1*a2...*an+....
        +S-min(an-1,an)*a1*a2*..*an-2

= S*n-1/max（a1,a2)*S-
1/max(a2,a3)*S-1/max(a3,a4)*S+....
+1/max(an-1,an)*S

1/max(a1,a2)+1/max(a2,a3)+...1/max(an-1,an)


*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long int64;

const int maxn=1000000+8;
const int64 mod=1000000000+7;
int64 a[maxn],b[maxn];
int n;


int64 exp(int64 p,int y)
{
    if(y==0)
        return 1;
    if(y==1)
        return p%mod;
    int64 x=exp(p,y/2);
    x=x*x%mod;
    if(y&1)
        return x*p%mod;
    return x%mod;

}

int64 exclu(int64 p)
{
    int64 s=b[n]*exp(p,mod-2)%mod;
    return s*(p-1)%mod;
}

int main()
{

    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        b[0]=1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",a+i);
            b[i]=b[i-1]*a[i]%mod;
            //    cout<<i<<" "<<b[i]<<endl;
        }
        sort(a+1,a+1+n);
        int64 ans=b[n];
        int tim=n-1;
        for(int i=n; i>=1; i--)
        {
            //cout<<i<<" "<<a[i]<<" "<<exclu(a[i])<<endl;
            if(tim<=0)
                break;
            tim--;
            int64 e=exclu(a[i]);
            ans=(ans+e)%mod;
            if(tim<=0)
                break;
            tim--;
            ans=(ans+e)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}

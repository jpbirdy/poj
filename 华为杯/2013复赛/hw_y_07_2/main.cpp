#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

#define maxn 100010

long long i,j,k,m,n;
long long s[maxn],f[maxn],p[maxn],rank[maxn];
long long x,y,z;

void swap(long long &x,long long &y)
{
    long long t;
    t = x;
    x = y ;
    y = t;
}

void sort(long long l,long long r)
{
    long long i=l,j=r;
    x = s[(l+r)/2];
    do
    {
        while(s[i]>x) i++;
        while(s[j]<x) j--;
        if(i<=j)
        {
            swap(s[i],s[j]);
            swap(rank[i],rank[j]);
            i++;j--;
        }
    }while(i<=j);
    if(i<r) sort(i,r);
    if(j>l) sort(l,j);
}

long long ask(long long x)
{
    long long ret = 0;
    long long i = 1;
    while(i<=x)
    {
        while(i+(i&(-i)) <=x) i=i+(i&(-i));
        ret+=f[i];
        i++;
    }
    return ret;
}


void ins(long long &x)
{
    while(x<=n)
    {
        f[x]++;
        x=x+(x&(-x));
    }
}


long long get(long long min)
{
    long long l,r,mid,i;
    l = 1;
    r = n;
    while((r-l)>3)
    {
        mid = (l+r)>>1;
        if(s[mid]>=min) l = mid;
        else r = mid;
    }
    for(i=l ; i<=r ; i++)
        if(s[i-1]>=min && s[i]<min)
            return (i-1);
    return n;
}

long long sum(long long max)
{
    long long i,j,k;
    long long ret = 0;
    memset(f,0,sizeof(f));
    for(i=1 ; i<=n ; i++)
    {
        j = p[i];
        k = get(s[j]-max);
        ret+=ask(k);
        ins(j);
    }
    return ret;
}

long long ans()
{
    long long l,r,mid;
    l = s[n]-s[1];
    r = s[1]-s[n];
    while(1)
    {
        mid = (l+r)/2;
        if(sum(mid)>=m)
            r = mid;
        else l = mid;
        if((r-l)<10)
        {
            for(i = l-1 ; i<=r ; i++)
            {
                k = sum(i);
                if(k>=m) return i;
            }
        }
    }
}


int main()
{
    //freopen("input.txt","r",stdin);
    //scanf("%lld%lld",&n,&m);

    n = 100000;
    m = n*(n+1)/2;
    m = n*(n+1)/2 - m + 1;
    s[0] = 0;
    for(i=1 ; i<=n ; i++)
    {
        //scanf("%lld",&x);
        x = rand()*rand()%10000;
        s[i] = s[i-1] + x;
        rank[i] = i+1;
    }
    n++;
    s[n] = 0;
    rank[n]=1;
    sort(1,n);
    s[0] = INT_MAX;
    for(i=1 ; i<=n ; i++)
        p[rank[i]] = i;
    printf("%lld\n",ans());
    return 0;
}

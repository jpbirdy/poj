#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAXBIT 40
#define NODE 4000010
#define N 100010

int n;
long long v[N];
long long sum_l[N],sum_r[N];
int node;
int next[NODE][2];
long long end[NODE];
void add(int cur,int k)
{
    memset(next[node],0,sizeof(next[node]));
    end[node]=0;
    next[cur][k]=node++;
}

void add_one(long long x)
{
    long long k,cur;
    cur=0;
    for(int j=MAXBIT;j>=0;j--)
    {
        k=(((long long)1<<j)&x)?1:0;
        if(next[cur][k]==0) add(cur,k);
        cur=next[cur][k];
    }
    end[cur]=x;
}

long long cal(long long x)
{
    long long i,k,cur=0;
    for(i=MAXBIT;i>=0;i--)
    {
        k=(((long long)1<<i)&x)?0:1;
        if(next[cur][k]) cur=next[cur][k];
        else cur=next[cur][1-k];
    }
    return (x^end[cur]);
}



int main()
{
    int i,j;
    long long x;
    long long ans;

    //freopen("input.txt","r",stdin);

    while(~scanf("%d",&n))
    {
        node=1;
        memset(next[0],0,sizeof(next[0]));
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            v[i]=x;
        }
        sum_l[0] = v[0];
        for(i=1 ; i<n ; i++)
            sum_l[i] = sum_l[i-1]^v[i];
        sum_r[n-1] = v[n-1];
        for(i=n-2 ; i>=0 ; i--)
            sum_r[i] = sum_r[i+1]^v[i];

        ans = 0;

        //计算一侧的值
        for(i=0 ; i<n-1 ; i++)
            ans=MAX(ans,sum_l[i]);
        for(i=n-1 ; i>0 ; i--)
            ans=MAX(ans,sum_r[i]);

        //计算两侧
        //枚举分割处的点
        for(i=n-2 ; i>0 ; i--)
        {
            add_one(sum_r[i+1]);
            ans=MAX(ans,cal(sum_l[i-1]));
        }

        printf("%lld\n",ans);
    }
    return 0;
}

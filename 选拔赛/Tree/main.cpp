#include <stdio.h>
#include <string.h>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MAXBIT 20
#define NODE 100010
#define N 500010

int n,m;
int node;
int next[NODE][2];
int end[NODE];

int a[N][2];

void add(int cur,int k)
{
    memset(next[node],0,sizeof(next[node]));
    end[node]=0;
    next[cur][k]=node++;
}

void add_one(int x)
{
    int k,cur;
    cur=0;
    for(int j=MAXBIT;j>=0;j--)
    {
        k=(((int)1<<j)&x)?1:0;
        if(next[cur][k]==0) add(cur,k);
        cur=next[cur][k];
    }
    end[cur]=x;
}

int cal(int x)
{
    int i,k,cur=0;
    for(i=MAXBIT;i>=0;i--)
    {
        k=(((int)1<<i)&x)?0:1;
        if(next[cur][k]) cur=next[cur][k];
        else cur=next[cur][1-k];
    }
    return (x^end[cur]);
}

int v1[N];
int top1;
int v2[N];
int top2;

void swap(int &a,int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

int main()
{
    int i,j;
    int u,v;
    int x,y,z;

    freopen("input.txt","r",stdin);

    while(~scanf("%d%d",&n,&m))
    {
        node=1;
        memset(a,0,sizeof(a));

        for(i=1 ; i<=n ; i++)
        {
            scanf("%d",&a[i][0]);
            a[i][1] = -1;
        }

        for(i=0 ; i<n-1 ; i++)
        {
            scanf("%d%d",&u,&v);
            if(u==v) break;
            if(u>v) swap(u,v);
            if(a[v][1]==-1)
                a[v][1] = u;
            else a[u][1] = v;
        }

        for(i=0 ; i<m ; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            memset(next[0],0,sizeof(next[0]));

            int t1 = y;
            int t2 = x;
            top1 = 0;
            v1[top1++] = a[t1][0];
            top2 = 0;
            v2[top2++] = a[t2][0];

            while(t1!=x && t1!=-1)
            {
                t1 = a[t1][1];
                if(t1!=-1)
                    v1[top1++] = a[t1][0];
            }

            while(t2!=y && t2!=-1)
            {
                t2 = a[t2][1];
                if(t2!=-1)
                    v2[top2++] = a[t2][0];
            }

            if(t1 == -1 && t2 == -1)
            {
                for(j=0 ; j<top1 ; j++)
                    add_one(v1[j]);
                for(j=0 ; j<top2 ; j++)
                    add_one(v2[j]);
            }
            else if(t2 == -1)
            {
                for(j=0 ; j<top1 ; j++)
                    add_one(v1[j]);
            }
            else
            {
                for(j=0 ; j<top2 ; j++)
                    add_one(v2[j]);
            }

            printf("%d\n",cal(z));
        }


    }
    return 0;
}

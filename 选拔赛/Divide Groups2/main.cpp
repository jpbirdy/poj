#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)



bool g[110][110];


int n;

bool check(int q[110],int len,int x)
{
    for(int i=0 ; i<len ; i++)
        if((!g[q[i]][x]) || (!g[x][q[i]])) return false;
    return true;
}

bool flag = false;
int a[110];
int b[110];
int sza,szb ;

void dfs(int d)
{

    if(d>n)
    {
        flag = true;
    }
    if(check(a,sza,d))
    {
        a[sza++] = d;
        dfs(d+1);
        sza--;
    }
    if(check(b,szb,d))
    {
        b[szb++] = d;
        dfs(d+1);
        szb--;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n)==1)
    {
        memset(g,0,sizeof(g));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        REP(i,n)
        {
            int x;
            scanf("%d",&x);
            while(x!=0)
            {
                g[i+1][x] = true;
                scanf("%d",&x);
            }
        }

        sza = szb = 0;
        flag = false;

        dfs(1);

        if(flag) printf("YES\n");
        else printf("NO\n");


    }
	return 0;

}

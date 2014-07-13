#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)



bool g[110][110];

int sza,szb ;
int n;

bool check(int q[110],int len,int x)
{
    for(int i=0 ; i<len ; i++)
        if((!g[q[i]][x]) || (!g[x][q[i]])) return false;
    return true;
}


int main()
{
    //freopen("input.txt","r",stdin);


    int a[110];
    int b[110];
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
        bool flag = true;

        bool ff;
        for(int i=1 ; (i<=n)&&flag ; i++)
        {
            ff = false;
            if(check(a,sza,i))
            {
                a[sza++] = i;
                ff = true;
            }
            if(check(b,szb,i))
            {
                b[szb++] = i;
                ff = true;
            }
            if(!ff) flag = false ;
        }

        if(flag) printf("YES\n");
        else printf("NO\n");


    }
	return 0;

}

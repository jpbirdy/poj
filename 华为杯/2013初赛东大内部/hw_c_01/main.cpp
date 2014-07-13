#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 50010;

struct ufind
{
	int p[MAXN],t;
	void init(){memset(p,0,sizeof(p));}
	void set_friend(int i,int j)
	{
	    i = find_father(i);
	    j = find_father(j);
	    if(i!=j)
            p[i] = j;
    }
	int is_friend(int i,int j)
	{
	    i = find_father(i);
	    j = find_father(j);
	    if(i!=j)
            return 0;
        else return 1;
    }
	int find_father(int x)
	{
        while(p[x]!=0)
            x = p[x];
        return x;
	}
};

bool b[MAXN];
int main()
{
    long long n,m;
    int x,y;
    ufind fset;
    int f,ret=0;
    //freopen("input.txt","r",stdin);
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        fset.init();
        for(long long i=0 ; i<m ; i++)
        {
            scanf("%d%d",&x,&y);
            fset.set_friend(x,y);
        }
        memset(b,0,sizeof(b));
        ret = 0;
        for(int i=1 ; i<=n ; i++)
        {
            f = fset.find_father(i);
            if(!b[f])
            {
                b[f]=true;
                ret++;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}

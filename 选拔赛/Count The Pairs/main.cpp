#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 10010;

struct node
{
    int a,b,c;
};

node a[500010];

int cmp(void const *a,void const *b)
{
    node *p1 = (node*) a;
    node *p2 = (node*) b;
    return p2->c - p1->c;
}


struct ufind
{
	int p[MAXN],t;
	int num[MAXN];
	void init()
	{
	    for(int i=0 ; i<MAXN ; i++)
        {
            p[i] = 0;
            num[i] = 1;
        }

    }
	void set_friend(int i,int j)
	{
	    i = find_father(i);
	    j = find_father(j);
	    if(i==j) return ;
	    if(num[i]>num[j])
        {
            p[j] = i;
            num[i]+=num[j];
        }
        else
        {
            p[i] = j;
            num[j]+=num[i];
        }
    }

    int find_num(int i)
    {
        return num[find_father(i)];
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


int main()
{
    freopen("input.txt","r",stdin);

    ufind fset;
    int n,m,p;
    map<int,int> res;
    map<int,int>::iterator iter;
    int t;
    while(scanf("%d%d",&n,&m)==2)
    {
        fset.init();
        for(int i=0 ; i<m ; i++)
        {
            scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
        }
        qsort(a,n,sizeof(node),cmp);

        //printf("%d %d %d\n",a[0].a,a[0].b,a[0].c);
        scanf("%d",&p);
        res.clear();
        int now = 0;
        int now_res = 0;
        while(p--)
        {
            scanf("%d",&t);
            while(a[now].c <=t)
            {
                int l,r;
                l = a[now].a;
                r = a[now].b;
                if(!fset.is_friend(l,r))
                {
                    now_res+=fset.find_num(l)*fset.find_num(r);
                    fset.set_friend(l,r);
                }

                res.insert(make_pair(a[now].c,now_res));
                now++;
                if(now>=n) break;
            }

            iter = res.lower_bound(t);
            printf("%d\n",iter->second * 2);


        }

    }






    return 0;
}

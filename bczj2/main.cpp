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

struct point
{
    int x,y;
    int v;
};

point a[11000];
int mx[110][110];
bool sr[110],sc[110];
int rmin[110],cmin[110];
int t;
int cases = 1;
int n,m;

int cmp( const point &a, const point &b )
{
    if( a.v >= b.v )
       return 0;
    else
       return 1;
}

//row被选中，col未选
bool check_colmin(int col,int value)
{
    REP(i,m)
    {
        //找出col列上，某行未被选中的元素
        if(!sr[i])
        {
            if(mx[i][col] < (value + rmin[i]))
                return false;
        }
    }
    return true;
}

//col被选中，row未选
bool check_rowmin(int row,int value)
{
    REP(i,n)
    {
        //找出col列上，某行未被选中的元素
        if(!sc[i])
        {
            if(mx[row][i] < (value + cmin[i]))
                return false;
        }
    }
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        REP(i,m)
        {
            rmin[i] = 9999999;
        }
        REP(i,n)
        {
            cmin[i] = 9999999;
        }


        REP(i,m)
            REP(j,n)
            {
                a[i*n+j].x = i;
                a[i*n+j].y = j;
                scanf("%d",&(mx[i][j]));
                a[i*n+j].v = mx[i][j];
                if(a[i*n+j].v < rmin[i]) rmin[i] = a[i*n+j].v;
                if(a[i*n+j].v < cmin[j]) cmin[j] = a[i*n+j].v;
            }
        sort(a,a+m*n,cmp);
        memset(sr,0,sizeof(sr));
        memset(sc,0,sizeof(sc));
        int res = 0;

        REP(i,m*n)
        {
            int row = a[i].x;
            int col = a[i].y;
            int value = a[i].v;
            if(!sr[row] && !sc[col])
            {
                res+=value;
                sr[row] = true;
                sc[col] = true;
            }
            else if(sr[row] && sc[col])
            {
                continue;
            }
            else if(sr[row] && !sc[col])
            {
                //该行已经有被选的，但列还为被选
                if(check_colmin(col,value))
                {
                    res += value;
                    sc[col] = true;
                }
            }
            else
            {
                if(check_rowmin(row,value))
                {
                    res += value;
                    sr[row] = true;
                }
            }
        }
        printf("Case %d: %d\n",cases++,res);
    }
	return 0;

}

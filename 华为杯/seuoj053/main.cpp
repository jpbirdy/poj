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

bool g[3][10];
int total_time;
int total_num;

bool g_t[3][10];
int single_num;

void flood(int l,int x)
{
    single_num++;
    g_t[l][x] = true;
    if(l>0 && !g_t[l-1][x] && g[l-1][x])
        flood(l-1,x);
    if(l<2 && !g_t[l+1][x] && g[l+1][x])
        flood(l+1,x);
    if(x<9 && !g_t[l][x+1] && g[l][x+1])
        flood(l,x+1);
    if(x>0 && !g_t[l][x-1] && g[l][x-1])
        flood(l,x-1);
}


void fill(int x)
{
    int l = 0;
    while(!g[l][x] && l<2 && !g[l+1][x])
        l++;
    g[l][x] = true;
    single_num = 0;
    memset(g_t , 0 , sizeof(g_t));
    flood(l,x);
    if(single_num>=3)
    {
        total_num+=single_num;
        total_time++;
        REP(i,3)
            REP(j,10)
            {
                if(g_t[i][j])
                    g[i][j]=false;
            }
    }
}


int main()
{
    int x;
    //freopen("input.txt","r",stdin);
    memset(g,0,sizeof(g));
    for(int i=0 ; i<20 ; i++)
    {
        scanf("%d",&x);
        fill(x);
    }
    printf("%d %d\n",total_time,total_num);
    return 0;
}

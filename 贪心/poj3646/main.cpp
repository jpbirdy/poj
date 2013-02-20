/**
勇者斗恶龙
有n个恶龙和m个勇者，每个勇者会有一个能力值x，并且可以砍生命不超过x的恶龙，需要支付x个金币

给出n个恶龙的生命和m个勇者的能力，如果有解，求出支付最少的金币数
否则输出无解

贪心算法：
对于某个恶龙，从当前未雇佣的勇者中找出一个可以砍死的能力值最小的一个
贪心算法正确。
该算法可以保证在有解的情况下，搜索的能力值最小

*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 20010;
int dragon[MAX_N],loowater[MAX_N];
bool b[MAX_N];


int main()
{
    int n,m;
    int i,j;
    int min_res = 0;
    while(scanf("%d%d",&n,&m)==2 && n && m)
    {
        for(i=0 ; i<n ; i++)
            scanf("%d",&dragon[i]);
        for(i=0 ; i<m ; i++)
            scanf("%d",&loowater[i]);
        if(n>m)
        {
            printf("Loowater is doomed!\n");
            continue;
        }
        memset(b,0,sizeof(b));
        min_res = 0;
        //sort(dragon,dragon+n);        //恶龙的生命可以不排序
        sort(loowater,loowater+m);
        for(i=0 ; i<n ; i++)
        {
            for(j=0 ; j<m ; j++)
                if(!b[j] && loowater[j]>=dragon[i])
                {
                    b[j] = true;
                    min_res+=loowater[j];
                    break;
                }
            if(j==m) break;
        }
        if(i==n)
            printf("%d\n",min_res);
        else
            printf("Loowater is doomed!\n");
    }
    return 0;
}

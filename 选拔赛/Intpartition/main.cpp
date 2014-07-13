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

const int MAX = 1000;
const int MOD = 1000000000+7;

int a[MAX+10];

int Func_d(int n,int max)            // 将n划分成若干不同整数之和的划分数。
{
    int counter=0;
    int i;

    if(max*(max-1)/2<n)
    {
        return 0;
    }
    else
    {
        if(max*(max-1)/2==n||n==0)
        {
            return 1;
        }
        else
        {
            for(i=1; i<max; i++)
            {
                counter+=Func_d(n-i,i);
            }
            return counter;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    printf("%d\n",Func_d(100,100));
    return 0;
}

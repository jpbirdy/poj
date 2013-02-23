/**
题目给定一个数，将其分解为不同的若干数的和，要求其乘积最大。
把一个数只要分解为比2大的两个数的和，乘积一定大于原数，
所以思想就是将原来的数从2开始，2、3、4...分配到不够了在从当前最大的+1一直到最小的，依次循环

如7 ，分成2+3+2，2不够分，3+1,2+1，得到最终为3+4
8，分成2+3+3,3不够分，3+1,2+1，还剩1，再从3开始+4，得到3,5

*/

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


int main()
{
    int n;
    int num = 0;
    int res[1000];
    while(scanf("%d",&n) == 1)
    {
        memset(res,0,sizeof(res));
        num = 0;
        int now = 0;
        for(int i=2 ; now+i <= n ; i++)
        {
            now +=i;
            res[num++] = i;
        }
        int remain = n - now;
        for(int i=num-1 ; remain>0 ; i--)
        {
            res[i]++;
            remain--;
            if(i==0) i = num;
        }
        for(int i=0 ; i<num-1 ; i++)
            printf("%d ",res[i]);
        printf("%d\n",res[num-1]);
    }

    return 0;
}

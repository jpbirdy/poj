/**
��Ŀ����һ����������ֽ�Ϊ��ͬ���������ĺͣ�Ҫ����˻����
��һ����ֻҪ�ֽ�Ϊ��2����������ĺͣ��˻�һ������ԭ����
����˼����ǽ�ԭ��������2��ʼ��2��3��4...���䵽�������ڴӵ�ǰ����+1һֱ����С�ģ�����ѭ��

��7 ���ֳ�2+3+2��2�����֣�3+1,2+1���õ�����Ϊ3+4
8���ֳ�2+3+3,3�����֣�3+1,2+1����ʣ1���ٴ�3��ʼ+4���õ�3,5

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

/**
BFS

有两个数N,K
每次可以最N做3种变换
1、N=N+1;
2、N=N-1;
3、N=N*2
求最少的变换次数使N变成K

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
#include <queue>
using namespace std;

bool hash[100010] ;
queue<int> q;
queue<int> step;

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        memset(hash,0,sizeof(hash));
        while(!q.empty()) {q.pop();step.pop();}
        hash[n] = true;
        q.push(n);
        step.push(0);
        while(!q.empty())
        {
            int t = q.front();
            int s = step.front();
            if(t==k) {printf("%d\n",s);break;}
            q.pop();
            step.pop();
            if(t>0 && !hash[t-1])
            {
                hash[t-1] = true;
                q.push(t-1);
                step.push(s+1);
            }
            if(t<100000 && !hash[t+1])
            {
                hash[t+1] = true;
                q.push(t+1);
                step.push(s+1);
            }
            if((t*2)<=100000 && !hash[t*2])
            {
                hash[t*2] = true;
                q.push(t*2);
                step.push(s+1);
            }
        }
    }
    return 0;
}

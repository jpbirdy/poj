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



priority_queue<int,vector<int> ,greater<int> > q;

int main()
{
    int n;
    scanf("%d",&n);
    q.push(1);
    int k;
    REP(i,n)
    {
        k = q.top();
        q.pop();
        q.push(k*2);
        q.push(k*3);
        q.push(k*5);
        q.push(k*7);
    }
    printf("%d\n",k);
    //freopen("input.txt","r",stdin);
	return 0;

}

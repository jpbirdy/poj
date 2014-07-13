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
#include <bits/stl_tree.h>


using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int(i)=(n)-1;(i)>=0;(i)--)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())




int main()
{
    set<int> s;
    REP(i,100)
        s.insert(rand());

    map<int ,int> m;
    m.insert(make_pair(1,1));

    pair<int ,int> p = make_pair(1,1);
    printf("%d\n",p.first);


    ITER(it,s)
        printf("%d\n",*it);


    s.insert(4000);
    set<int>::iterator iter = s.find(4000);
    set<int>::iterator iter1,iter2,iter3;
    iter1 = iter2 = iter3 = iter;
    printf("%d %d %d\n",*(--iter1),*iter2,*(++iter3));

    //freopen("input.txt","r",stdin);
	return 0;

}

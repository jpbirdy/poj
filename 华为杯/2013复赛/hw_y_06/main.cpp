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

int a[26];
char str[1010];


int main()
{
    //freopen("input.txt","r",stdin);

    while(~scanf("%s",str))
    {
        int len = strlen(str);
        memset(a,0,sizeof(a));
        for(int i=0 ; i<len ; i++)
            a[str[i]-'a']++;
        int x=0,y=0;
        for(int i=0 ; i<26 ; i++)
            if(a[i]%2==0) y++;
            else x++;
        if(x==0 || x%2==1) printf("First\n");
        else printf("Second\n");
    }
    return 0;
}

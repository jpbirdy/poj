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

char str[1000010];


bool check()
{
    int sum  = 0;
    int len = strlen(str);
    if(str[0]!='M') return false;
    if(len<=1) return false;
    for(int i=1 ; i<len ; i++)
        if(str[i]=='M') return false;
        else if(str[i]=='I') sum++;
        else if(str[i]=='U') sum+=3;
        else return false;
    if(sum%2 && sum!=1) return false;
    if(sum!=1) sum/=2;

    if((sum%3)!=0) return true;
    else return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int n ;
    scanf("%d\n",&n);

    while(n--)
    {
        gets(str);
        int sum = 0;
        int len = strlen(str);
        if(check()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

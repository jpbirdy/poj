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

string s1;
string s2;
int len1,len2;

int main()
{
    int t;
    int a[50010];
    int cases = 1;
    scanf("%d",&t);
    while(t--)
    {
        cin >> s1 >> s2;
        len1 = s1.size();
        len2 = s2.size();
        memset(a,0,sizeof(a));
        for(int j=0 ; j<len2 ; j++)
            for(int i=j ; i<len1+j-len2 +1; i++)
            {
                if(s1[i]==s2[j])
                    a[i-j]++;
            }
        int max = 0;
        for(int i=0 ; i<len1 ; i++)
        {
            if(a[i]>max) max = a[i];
            //printf("%d ",a[i]);
        }

        printf("Case #%d: %d\n",cases++,len2-max);
    }
    return 0;
}

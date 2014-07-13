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

const char mul[3][3] = {
                        {
                            'b','b','a'
                        },
                        {
                            'c','b','a'
                        },
                        {
                            'a','c','c'
                        }
                    };

int dp[20][20][3];


int calcu_num(char *str)
{
    int len = strlen(str);
    REP(i,len)
    {
        REP(j,len)
        {
            if(i==0) dp[j][j+i][str[j]-'a']=1;
            else
            {
                REP(k,i)
                {
                    //分割点为k,左侧为j,j+k，右侧为j+k+1，j+i
                    REP(l,3)
                        REP(m,3)
                        {
                            dp[j][j+i][mul[l][m]-'a']+=dp[j][j+k][l]*dp[j+k+1][j+i][m];
                        }
                }
            }
        }
    }


    return dp[0][len-1][0];

}


int main()
{
    //freopen("mult.in","r",stdin);
    //freopen("mult.out","w",stdout);
    char str[20];
    gets(str);

    memset(dp,0,sizeof(dp));

    printf("%d\n",calcu_num(str));


    return 0;
}

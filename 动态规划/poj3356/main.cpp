/**
�������ַ��������������ַ���֮�����С����
DP��

״̬dp[i][j] ��ʾstrA��ǰi���ַ���strBǰj���ַ������С����
��Ȼ
dp[0][j] = j;
dp[i][0] = i;
if(strA[i-1] == strB[j-1]) dp[i][j] = min(dp[i-1][j-1],dp[i][j-1]+1,dp[i-1][j]+1)
else dp[i][j] = min(dp[i-1][j-1] , dp[i-1][j] , dp[i][j-1]) + 1;

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
using namespace std;


char strA[1010],strB[1010];
int dp[1010][1010];

int min(int a,int b)
{
    return (a<b?a:b);
}

int min(int a,int b,int c)
{
    int min = a<b?a:b;
    min = min<c?min:c;
    return min;
}


int main()
{
    int lenA,lenB;
    //ע���������
    while(scanf("%d%s",&lenA,strA) >0 )
    {

        scanf("%d%s",&lenB,strB);
        int i,j;

        for(i=0 ; i<=lenA ; i++)
            for(j = 0 ; j<=lenB ; j++)
            {
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else
                {
                    int x = i-1;
                    int y = j-1;
                    if(strA[x] == strB[y])
                        dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]+1,dp[i][j-1]+1);
                    else
                    {
                        dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1;
                    }
                }
            }

        printf("%d\n",dp[lenA][lenB]);
    }
    return 0;
}

/*
简单dp，最小连续和
求第一组和，和对应下标
*/
#include <iostream>
#include <cstdio>
using namespace std;

int a[100010];
int dp[100010];

int main()
{
    //freopen("input.txt","r",stdin);
    int t,n;
    int cases = 1;
    scanf("%d",&t);
    while(t--)
    {
        if(cases==1)
            printf("Case %d:\n",cases++);
        else printf("\nCase %d:\n",cases++);
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++)
            scanf("%d",a+i);
        dp[0] = a[0];
        for(int i=1 ; i<n ; i++)
            if((dp[i-1]+a[i])<a[i])
                dp[i] = a[i];
            else dp[i] = dp[i-1]+a[i];
        int max_res = dp[0],max_i = 0;
        for(int i=1 ; i<n ; i++)
            if(dp[i]>max_res) max_res = dp[i],max_i = i;
        int max_l = max_i ;
        while(max_l>0 && dp[max_l]==dp[max_l-1]+a[max_l])
            max_l--;
        printf("%d %d %d\n",max_res,max_l+1,max_i+1);

    }
    return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;



int N = 10000;
const int mod = 1000000007;

long long dp[100010];

void solve()
{
    int i,j;
    dp[0] = 1;
        for (i = 1;i <= N;i++)
            for (j = i;j <= N;j++)
                dp[j] =(dp[j] + dp[j-i]) % mod;
}



int main()
{
    int n,k;

    /*
    solve();
    freopen("output.txt","w",stdout);
    printf("const long long arr[%d] = {",N);
    for(int i=1 ; i<=N ; i++)
        printf("%d,",dp[i]);
    printf("};\n");

    */
    solve();
    printf("%d\n",dp[1000]);
    /*
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",dp[n-1]);
    }
    */
    //printf("%d\n",arr[18]);


}

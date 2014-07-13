#include<stdio.h>
#include<string.h>

#define nmax 40010
#define kmax 110

#define MOD 1000000007

long long num[nmax][kmax]; //将i划分为j个数

void init()
{
    int i, j;
    for (i = 0; i < nmax; i++)
    {
        num[i][0] = 0, num[0][i] = 0;
    }
    for (i = 1; i < nmax; i++)
    {
        for (j = 1; j < kmax; j++)
        {
            if (i < j)
            {
                num[i][j] = 0;
            }
            else if (i == j)
            {
                num[i][j] = 1;
            }
            else
            {
                num[i][j] = (num[i - 1][j - 1] + num[i - j][j]) % MOD;
            }
        }
    }
}
int main()
{

    int n, k;
    init();
    while (~scanf("%d%d", &n, &k))
    {
        long long res = 0;
        for(int i=1 ; i<=k ; i++)
            res = (res+num[n][i]) % MOD;

        printf("%lld\n", res);
    }
    return 0;
}

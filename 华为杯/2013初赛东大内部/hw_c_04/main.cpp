#include <stdio.h>
#include <memory.h>
#include <cstring>
using namespace std;

#define MAX 100001
#define M  20010
long long dd[M], a[M], b[M] , C[M] , d[M];
long long c[MAX+10];
int n ;
long long ddt[M];

int lowbit(int i)
{
    return i & (-i);
}

void add(int i, int m)
{
    while (i <= MAX+1)
    {
        c[i] += m;
        i += lowbit(i);
    }
}

long long sum(int i)
{
    long long ret = 0;
    while (i > 0)
    {
        ret += c[i];
        i -= lowbit(i);
    }
    return ret;
}

int main()
{
    int i;
    long long ans;
    int t;
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        memset(c, 0, sizeof (c));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &dd[i]);
            ddt[i] = MAX-dd[i];
            a[i] = sum(dd[i]);
            add(dd[i] + 1, 1);
        }
        memset(c, 0, sizeof (c));
        for (i = n - 1; i >= 0; i--)
        {
            b[i] = sum(dd[i]);
            add(dd[i] + 1, 1);
        }

        memset(c, 0, sizeof (c));
        for (i = 0; i < n; i++)
        {
            C[i] = sum(ddt[i]);
            add(ddt[i] + 1, 1);
        }

        memset(c, 0, sizeof (c));
        for (i = n - 1; i >= 0; i--)
        {
            d[i] = sum(ddt[i]);
            add(ddt[i] + 1, 1);
        }

        ans = 0;
        for (i = 0; i < n; i++)
            ans += a[i] *  d[i] + b[i] * C[i];
        printf("%lld\n", ans);
    }
}

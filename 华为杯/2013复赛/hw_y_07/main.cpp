#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

typedef long long MAINTYPE;
typedef long long int64;

#define swap(a, b, t) ({t _ = (a); (a) = (b); (b) = _;})
#define MAX(a, b, t) ({t _ = (a), __ = (b); _ > __ ? _ : __;})
#define MIN(a, b, t) ({t _ = (a), __ = (b); _ < __ ? _ : __;})

#define max(a, b) MAX(a, b, MAINTYPE)
#define min(a, b) MIN(a, b, MAINTYPE)

#define maxn 100105
#define random (rand() * rand())
#define sum(i, j) (s[j] - s[(i) - 1])

int64 n, k;
int a[maxn];
long long s[maxn];
long long mini, maxi, ans, vetot;
struct node{node * c[2]; long long data, rank, size;} vess[maxn], * root;

void update(node * & p)
{
    if (! p) return;
    p->size = (p->c[0] ? p->c[0]->size : 0) + (p->c[1] ? p->c[1]->size : 0) + 1;
}

void rotate(node * & p, bool flag)
{
    node * q = p->c[! flag];
    p->c[! flag] = q->c[flag], q->c[flag] = p;
    update(p), update(q), p = q;
}

void insert(node * & p, long long data)
{
    if (! p)
    {
        p = vess + ++ vetot;
        p->data = data, p->rank = random, p->size = 1;
        p->c[0] = p->c[1] = 0;
    }
    else
    {
        bool flag = data > p->data;
        insert(p->c[flag], data), ++ p->size;
        if (p->c[flag]->rank < p->rank) rotate(p, ! flag);
    }
}

long long getrank(long long data)
{
    node * p = root;
    long long rank = 0;
    while (p)
    {
        rank += p->c[0] ? p->c[0]->size + 1: 1;
        if (data <= p->data)
        {
            rank -= p->c[0] ? p->c[0]->size + 1: 1;
            p = p->c[0];
        }
        else
            p = p->c[1];
    }
    return rank;
}

void work()
{
    if (k == 1) return (void) printf("%lld\n", mini);
    if (k == n * (n + 1) / 2) return (void) printf("%lld\n", maxi);
    for (long long l = mini, r = maxi; l < r; )
    {
        long long mid = (l + r) >> 1, rank = 0;
        vetot = 0, root = 0;
        for (long long i = n; i >= 1; -- i)
        {
            insert(root, s[i]);
            rank += getrank(mid + s[i - 1]);
        }
        rank < k ? (l = mid + 1) : (r = mid);
        ans = l - 1;
    }
    printf("%lld\n", ans);
}

void prepare()
{
    mini = INT_MAX, maxi = INT_MIN;
    for (int i = 1, s = 0, t = 0; i <= n; ++ i)
    {
        mini = min(mini, s += a[i]);
        maxi = max(maxi, t += a[i]);
        if (s > 0) s = 0;
        if (t < 0) t = 0;
    }
}

void init()
{
    scanf("%lld%lld", & n, & k);
    k = n * (n + 1) / 2 - k + 1;
    //printf("%I64d\n",k);
    s[0] = 0;
    for (long long i = 1; i <= n; ++ i)
    {
        scanf("%d", & a[i]);
        s[i] = s[i - 1] + a[i];
    }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("kth.out", "w", stdout);



    init();
    prepare();
    work();

    return 0;
}

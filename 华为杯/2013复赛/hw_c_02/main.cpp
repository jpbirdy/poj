#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;
typedef int T;
#define mem(a, b) memset(a, b, sizeof(a))
#define Sqr(x) ((x) * (x))

const int mn = 100010;
int ans;

struct EDGE
{
    int a, b;
    int next;
};

int a,b,m,n;

EDGE edge[mn];
bool bb[mn];

int edge_num;
int first[mn];
int cx[mn], cy[mn];// cx[i]表示xi对应的匹配，cy[i]表示yi对应的匹配.
int distx[mn], disty[mn]; // 层的概念，即在BFS中的第几层.
int que[mn];
int head, tail;

void init(void)
{
    fill(cx, cx + mn, -1);
    fill(cy, cy + mn, -1);
    fill(first, first + mn, -1);
    edge_num = 0;
    ans = 0;
}

void add_edge(int a, int b)
{
    edge[edge_num].a = a, edge[edge_num].b = b;
    edge[edge_num].next = first[a], first[a] = edge_num++;
}

bool BFS(void)
{
    int i, j, k;
    bool flag(0);
    int h, t;
    mem(distx, 0); mem(disty, 0);
    head = tail = 0;
    for (i = 1; i <= a; i++)
    {
        if (cx[i] == -1) que[tail++] = i;
    }
    while (head != tail)
    {
        for (h = head, t = tail; h != t; h = (h + 1) % mn)
        {
            i = que[h];
            for (k = first[i]; k != -1; k = edge[k].next)
            {
                j = edge[k].b;
                if (!disty[j])
                {
                    disty[j] = distx[i] + 1;
                    if (cy[j] == -1) flag = 1;
                    else
                    {
                        distx[cy[j]] = disty[j] + 1;
                        que[tail] = cy[j];
                        tail = (tail + 1) % mn;
                    }
                }
            }
        }
        head = t;
    }
    return flag;
}


bool DFS(int i)
{
    int j, k;
    for (k = first[i]; k != -1; k = edge[k].next)
    {
        j = edge[k].b;
        if (disty[j] == distx[i] + 1)
        { // 说明j是i的后继结点.
            disty[j] = 0; // j被用过了，不能再作为其他点的后继结点了.
            if (cy[j] == -1 || DFS(cy[j]))
            {
                cx[i] = j, cy[j] = i;
                return 1;
            }
        }
    }
    return 0;
}
void Hopcroft_Karp(void)
{
    int i;
    while (BFS())
    {
        for (i = 1; i <= a; i++)
        {
            if (cx[i] == -1 && DFS(i)) ans++;
        }
    }
}

int main()
{

    int x,y;
    int sum1 = 0;//喜欢小师妹个数

    freopen("input.txt","r",stdin);


    while(~scanf("%d%d%d%d",&a,&b,&m,&n))
    {
        ans = 0;
        sum1 = 0;

        init();
        mem(bb,0);

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d%d",&x,&y);


            if(y==1)
            {
                if(!bb[x])
                {
                    bb[x] = true;
                    sum1++;
                    first[x] = -1;
                }
                continue;
            }
            if(bb[x]) continue;
            add_edge(x,y);

        }

        for(int i=0 ; i<n ; i++)
        {
            scanf("%d%d",&y,&x);

            if(y==1)
            {
                if(!bb[x])
                {
                    bb[x] = true;
                    sum1++;
                    first[x] = -1;
                }
                continue;
            }
            if(bb[x]) continue;
            add_edge(x,y);

        }

        Hopcroft_Karp();


        printf("%d\n",a+b-sum1-ans+1);
    }


    return 0;
}

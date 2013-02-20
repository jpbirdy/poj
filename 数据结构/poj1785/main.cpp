/**
题意：
给出一些节点，每个节点有两个值，lable和priority，要求构成一个笛卡尔树，按lable是二叉排序树，按priority是大根堆（不一定完全二叉树）。输出括号表示。

思路1：
根据lable排序，结果一定是先序遍历结果，从先序遍历结果中找到权值最大的一定是根，此将树分为两颗子树，同理，可得到最终的树，展开求得结果
(TLE)

上面的思路因为每次要扩展两个方向，每个方向中没有可利用的结果

只从左向右扩展呢？
假设扩展到节点k时，从1~k-1个节点都满足堆的性质，找到第一个权值比当前节点大的（也就是它的权比k大，但是他的子节点的权都小于k,为了便于计算，假定0的权值为最大）
这样一定会找到一个节点（包含0）j，将j的右子树移动到i的左子树上，将i移动到j的右子树上（可以画图，这样保证先序遍历的顺序不变）
这种方式生成的树的结果与上面相同

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
#include <algorithm>
using namespace std;

#define maxn 100005

struct Node
{
    char c[100];
    int v;
    int l, r, fa;
} tree[maxn];

int n;

bool operator <(const Node &a, const Node &b)
{
    return strcmp(a.c, b.c) <0;
}

int input()
{
    int ret_max = 1;
    for (int i =1; i <= n; i++)
    {
        scanf("%*[ ]%[^/]/%d", tree[i].c, &tree[i].v);
        if(tree[i].v > tree[ret_max].v)
            ret_max = i;
    }
    return ret_max;
}


void ins(int i)
{
    int j = i -1;

    while (tree[j].v < tree[i].v)
        j = tree[j].fa;
    tree[i].l = tree[j].r;
    tree[tree[i].l].fa = i;
    tree[j].r = i;
    tree[i].fa = j;
}

void dfs(int i)
{
    if (!i)
        return;
    printf("(");
    dfs(tree[i].l);
    printf("%s/%d", tree[i].c, tree[i].v);
    dfs(tree[i].r);
    printf(")");
}

void expland(int l,int m,int r)
{
    int maxl = m-1;
    int maxr = m+1;
    if(m==l)
    {
        tree[m].l = 0;
    }
    else
    {
        for(int i=l ; i<maxl ; i++)
        if(tree[i].v > tree[maxl].v)
            maxl = i;
        tree[maxl].fa = m;
        tree[m].l = maxl;
        expland(l,maxl,m-1);
    }

    if(m==r)
    {
        tree[m].r = 0;
    }
    else
    {
        for(int i=maxr+1 ; i<=r ; i++)
        if(tree[i].v > tree[maxr].v)
            maxr = i;
        tree[maxr].fa = m;
        tree[m].r = maxr;
        expland(m+1,maxr,r);
    }


}

int main()
{
    int max_i;
    //freopen("in.txt", "r", stdin);
    while (scanf("%d", &n), n)
    {
        max_i = input();
        tree[0].l = tree[0].r = tree[0].fa =0;
        tree[0].v =0x3f3f3f3f;
        sort(tree +1, tree + n +1);


        for (int i =1; i <= n; i++)
        {
            tree[i].l = tree[i].r = tree[i].fa =0;
            ins(i);
        }


        //expland(1,max_i,n);
        //tree[0].r = max_i;
        dfs(tree[0].r);
        printf("\n");
    }
    return 0;
}

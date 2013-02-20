/**
���⣺
����һЩ�ڵ㣬ÿ���ڵ�������ֵ��lable��priority��Ҫ�󹹳�һ���ѿ���������lable�Ƕ�������������priority�Ǵ���ѣ���һ����ȫ����������������ű�ʾ��

˼·1��
����lable���򣬽��һ�������������������������������ҵ�Ȩֵ����һ���Ǹ����˽�����Ϊ����������ͬ���ɵõ����յ�����չ����ý��
(TLE)

�����˼·��Ϊÿ��Ҫ��չ��������ÿ��������û�п����õĽ��

ֻ����������չ�أ�
������չ���ڵ�kʱ����1~k-1���ڵ㶼����ѵ����ʣ��ҵ���һ��Ȩֵ�ȵ�ǰ�ڵ��ģ�Ҳ��������Ȩ��k�󣬵��������ӽڵ��Ȩ��С��k,Ϊ�˱��ڼ��㣬�ٶ�0��ȨֵΪ���
����һ�����ҵ�һ���ڵ㣨����0��j����j���������ƶ���i���������ϣ���i�ƶ���j���������ϣ����Ի�ͼ��������֤���������˳�򲻱䣩
���ַ�ʽ���ɵ����Ľ����������ͬ

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

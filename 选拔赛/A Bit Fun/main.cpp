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

struct Node
{
    int left,right;
    int data;           //通常是查询的值
    Node *left_child,*right_child;
};

void build(Node *cur , int l, int r)
{
    cur->left = l;
    cur->right = r;
    cur->data = 0;
    if(l+1 < r)
    {
        cur->left_child = new Node;
        cur->right_child = new Node;
        build(cur->left_child,l ,(l+r)/2);
        build(cur->right_child,(l+r)/2 , r);
    }
    else cur->left_child = cur->right_child = NULL;
}

int query(Node *cur , int l,int r)
{
    if(l<=cur->left && r>=cur->right) //当前节点在所查询区间中
        return cur->data;
    else
    {
        int ans = 0;                    //这里主要是针对查询为Sigma(...)，如果是乘法的，ans=1类似。
        if(l<(cur->left + cur->right)/2)
            ans|=query(cur->left_child,l,r);
        if(r>(cur->left + cur->right)/2)
            ans|=query(cur->right_child, l,r);
        return ans;
    }
}

void change(Node *cur,int x,int delta)
{
    if(cur->left+1 == cur->right)
        cur->data|=delta;
    else
    {
        if( x<(cur->left+cur->right) / 2)
            change(cur->left_child,x,delta);
        else
            change(cur->right_child,x,delta);
        cur->data = cur->left_child->data | cur->right_child->data;
    }
}

void delete_tree(Node *cur)
{
    if(cur->left_child!=NULL)
        delete_tree(cur->left_child);
    if(cur->right_child!=NULL)
        delete_tree(cur->right_child);
    delete cur;
}

int n;
Node * root;
int m;

int bsearch(int l)
{
    int i = l;
    int r = n;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        int q = query(root,i-1,mid);
        if(q<m)
            l = mid+1;
        else r = mid-1;
    }
    return l-i;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int x;
    int t;
    int cases = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        root = new Node;
        build(root,0,n);
        REP(i,n)
        {
            scanf("%d",&x);
            change(root,i,x);
        }


        long long sum = 0;
        /*
        for(int i=1 ; i<=n ; i++)
            sum+=bsearch(i);
        */

        int i,j;
        i=j=1;
        for(;i<=n;i++)
        {
            while(j<=i && query(root,j-1,i)>=m )
                j++;
            sum+=i-j+1;
        }
        printf("Case #%d: %lld\n",cases++,sum);
        delete_tree(root);
    }
    return 0;
}

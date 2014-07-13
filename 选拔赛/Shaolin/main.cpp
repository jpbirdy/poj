/**
伸展树经典
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 100010;

struct tree_node
{
    int k,g;            //data
    int left_id,right_id,father_id;
};

tree_node tree[MAXN];

int n,now ,root,prev,next,same;
int issame;

void init()
{
    //根
    root = 1;
    tree[1].k = 1;
    tree[1].g = 1000000000;
    tree[1].father_id = tree[1].left_id = tree[1].right_id = 0;
}

void left_rotate(int x)
{
    int y;
    y  = tree[x].father_id;
    tree[y].right_id = tree[x].left_id;
    if(tree[x].left_id != 0) tree[tree[x].left_id].father_id = y;
    tree[x].father_id = tree[y].father_id;
    if(tree[y].father_id !=0)
    {
        if(y==tree[tree[y].father_id].left_id) tree[tree[y].father_id].left_id = x;
        else tree[tree[y].father_id].right_id = x;
    }
    tree[y].father_id = x;
    tree[x].left_id = y;
}

void right_rotate(int x)
{
    int y;
    y = tree[x].father_id ;
    tree[y].left_id = tree[x].right_id ;
    if(tree[x].right_id !=0 ) tree[tree[x].right_id].father_id = y;
    tree[x].father_id = tree[y].father_id;
    if(tree[y].father_id != 0)
    {
        if(y==tree[tree[y].father_id].left_id) tree[tree[y].father_id].left_id = x;
        else tree[tree[y].father_id].right_id = x;
    }
    tree[y].father_id = x;
    tree[x].right_id = y;
}

void splay(int now)
{
    int t;
    while(tree[now].father_id!=0)
    {
        t = tree[now].father_id;
        if(tree[t].father_id==0)
        {
            if(now == tree[t].left_id) right_rotate(now);
            else left_rotate(now);
            break;
        }
        if(now == tree[t].left_id)
        {
            if(t==tree[tree[t].father_id].left_id)
            {
                right_rotate(t);
                right_rotate(now);
            }
            else
            {
                right_rotate(now);
                left_rotate(now);
            }
        }
        else
        {
            if(t==tree[tree[t].father_id].right_id)
            {
                left_rotate(t);
                left_rotate(now);
            }
            else
            {
                left_rotate(now);
                right_rotate(now);
            }
        }
    }
    root = now;
}

void insert_node()
{
    int t;
    t = root; same = now;
    while(true)
    {
        if(tree[t].g == tree[now].g)
        {
            issame = 0;same = t;return ;
        }
        if(tree[t].g > tree[now].g)
        {
            if(tree[t].left_id ==  0)
            {
                tree[now].father_id = t;
                tree[t].left_id = now;
                return ;
            }
            else t=tree[t].left_id;
        }
        else
        {
            if(tree[t].right_id ==  0)
            {
                tree[now].father_id = t;
                tree[t].right_id = now;
                return ;
            }
            else t=tree[t].right_id;
        }
    }
}

void find_prev()
{
    prev = tree[now].left_id;
    while(prev!=0)
    {
        if(tree[prev].right_id ==0) return ;
        else prev = tree[prev].right_id;
    }
}

void find_next()
{
    next = tree[now].right_id;
    while(next!=0)
    {
        if(tree[next].left_id ==0) return ;
        else next = tree[next].left_id;
    }
}

void work()
{
    scanf("%d%d",&tree[now].k,&tree[now].g);
    tree[now].father_id = tree[now].left_id = tree[now].right_id = 0;
    issame = 1;
    insert_node();
    splay(now);
    if(issame)
    {
        find_prev();
        find_next();
        //prev为比当前小的最大数，不一定存在
        //next为比当前大的最小数，一定存在
        if(prev == 0)
        {
            printf("%d %d\n",tree[now].k,tree[next].k);
        }
        else
        {
            int left_min = tree[now].g - tree[prev].g;
            int right_min = tree[next].g - tree[now].g;
            if(left_min<=right_min) printf("%d %d\n",tree[now].k,tree[prev].k);
            else printf("%d %d\n",tree[now].k,tree[next].k);
        }
    }

}


int main()
{
    int n;
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n)==1 && n!=0)
    {
        init();
        for(now = 2 ; now<=n+1 ; now++)
            work();
    }
    return 0;
}


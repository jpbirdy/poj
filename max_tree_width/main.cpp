/**
给定一颗树，每个节点有一个权值，将树种的节点的放入一个集合，要求，如果某个节点在集合中，则该节点的父节点和子节点都不在节点中。
求集合中最大的和

tree-dp

f(r) 表示以r为根的树中，包含根节点r的最大值
g(r) 表示不包含根的最大值

状态转移方程如下：
f(r) = r->width + sum(g(r->children[i]))
如果包含根节点r ，则一定不包含r的所有子节点。

g(r) = sum(   max( g(r->children[i]) , f(children[i]) )   )
如果不包含根节点r，则子节点可能包含，也可能不包含，选较大值

result = max(f(r) , g(r));

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
using namespace std;


inline int max(int a,int b)
{
    return (a>b?a:b);
}


struct tree_node
{
    int width;
    int dpf;
    int dpg;
    vector<tree_node*> children;
};

void read_width(tree_node *root,int k)
{
    int t;
    for(int i=0 ; i<k ; i++)
    {
        tree_node *temp = new tree_node;
        temp->width = 0 ;
        temp->dpf = -1;
        temp->dpg = -1;
        scanf("%d",&(temp->width));
        scanf("%d",&t);
        read_width(temp,t);
        root->children.push_back(temp);
    }
}

tree_node* init()
{
    tree_node *root = new tree_node;
    int k;
    root->children.clear();
    root->dpf = -1;
    root->dpg = -1;
    scanf("%d",&(root->width));
    scanf("%d",&k);
    read_width(root,k);
    return root;
}


void travel(tree_node *root)
{
    if(root == NULL) return ;
    else
    {
        printf("%d %d %d %d\n",root->width,root->children.size(),root->dpf,root->dpg);
        for(int i=0 ; i<root->children.size() ; i++)
            travel(root->children[i]);
    }
}

int f(tree_node *root);
int g(tree_node *root)
{
    if(root->dpg !=-1) return root->dpg;
    else
    {
        if(root->children.size()==0)
        {
            root->dpg = 0;
            return 0;
        }
        else
        {
            int sum = 0;
            for(int i=0 ; i<root->children.size() ; i++)
                sum+=max(f(root->children[i]),g(root->children[i]));
            root->dpg = sum;
            return root->dpg;
        }
    }
}

int f(tree_node *root)
{
    if(root->dpf!=-1) return root->dpf;
    else
    {
        if(root->children.size()==0)
        {
            root->dpf = root->width;
            return root->dpf;
        }
        else
        {
            int sumg = 0;
            for(int i=0 ; i<root->children.size() ; i++)
                sumg+= g(root->children[i]);
            root->dpf = root->width + sumg;
            return root->dpf;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    tree_node *root = init();
    printf("%d\n",max(f(root),g(root)));
    travel(root);
    return 0;
}

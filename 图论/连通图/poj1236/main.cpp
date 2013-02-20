/**
题目大意：
n个学校，每个学校会和其他一些学校有网络连接，这样这个学校的软件可以传到这些学校
给定每个学校的连接学校列表
现有某个软件
任务A：这个软件至少要给几个学校，可以保证每个学校都有一份
任务B：至少增加几个关系，可以保证随便将软件给某个学校，可以保证每个学校都有一份

解题思路：
一个图，他的一个强连通分量一定只需要一份，
而且这一份给此强连通分量里的任意一个都可以使整个连通分量中所有点都能有一份。
1、利用targan算法，求出该图的强连通分量
2、将每个连通分量缩成一个点。
这样就可以得到一个有向无环图
TASKA，就是求该有向无环图入度为0的点，然后所有入度为0的点都必须要有一份，这样所有的点都可以被COPY到
TASKB，如果新图中存在一个入度为0的点，如果软件被发到其他的点，一定不能达到这个入度为0的点；
       同时，如果存在出度为0，那么如果软件被发到了这个点，一定不能到达其他点。
       所以，在新加入的边中，一定要消除这些入度为0和出度为0的点。
       添加一个边，最多可以消除一个入度为0和出度为0的点，但是不能同时消除两个入度为0或者出度为0
       所以answer = MAX(in0,out0);

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

const int MAXN = 110;

int ans[MAXN][MAXN],indgr[MAXN],outdgr[MAXN],G[MAXN][MAXN];
int ins[MAXN],s[MAXN],top,num,N,dfn[MAXN],low[MAXN],time;

void tarjan(int u)
{
    int i,v;
    dfn[u]=low[u]=++time;
    s[top++]=u;
    ins[u]=1;
    for(v=0;v<N;v++)
        if(G[u][v])
        {
            if(!dfn[v])
            {
                tarjan(v);
                if(low[v]<low[u])
                    low[u]=low[v];
            }
            else if(ins[v]&&dfn[v]<low[u])
            low[u]=dfn[v];
        }
    if(dfn[u]==low[u])
    {
        s[top]=-1;
        for(i=0;s[top]!=u;i++)
        {
            ans[num][i]=s[--top];
            ins[ans[num][i]]=0;
        }
        num++;
    }
}

int main()
{
    int i,j,taskB,p,q,taskA,ok,u;
    while(scanf("%d",&N)==1)
    {
        for(i=0;i<N;i++)
            while(1)
            {
                scanf("%d",&j);
                if(j==0)
                    break;
                j--;
                G[i][j]=1;
            }
        memset(ans,-1,sizeof(ans));
        memset(ins,0,sizeof(ins));
        memset(dfn,0,sizeof(dfn));
        time=num=top=0;
        for(u=0;u<N;u++)
            if(!dfn[u])
                tarjan(u);

        if(num==1)
        {
            printf("1\n0\n");
            continue;
        }
        memset(indgr,0,sizeof(indgr));
        memset(outdgr,0,sizeof(outdgr));
        for(i=0;i<num;i++)
            for(j=0;j<num;j++)
            {
                if(i==j)
                    continue;
                ok=0;
                for(p=0;ans[i][p]!=-1;p++)
                {
                    for(q=0;ans[j][q]!=-1;q++)
                        if(G[ans[i][p]][ans[j][q]])
                        {
                            indgr[j]++;
                            outdgr[i]++;
                            ok=1;
                            break;
                        }
                    if(ok)
                        break;
                }
            }
        taskB=taskA=0;
        for(i=0;i<num;i++)
        {
            if(indgr[i]==0)
                taskA++;
            if(outdgr[i]==0)
                taskB++;
        }
        taskB=taskB>taskA?taskB:taskA;
        printf("%d\n%d\n",taskA,taskB);
    }
    return 0;
}

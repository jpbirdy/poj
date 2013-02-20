/**
��Ŀ���⣺
n��ѧУ��ÿ��ѧУ�������һЩѧУ���������ӣ��������ѧУ��������Դ�����ЩѧУ
����ÿ��ѧУ������ѧУ�б�
����ĳ�����
����A������������Ҫ������ѧУ�����Ա�֤ÿ��ѧУ����һ��
����B���������Ӽ�����ϵ�����Ա�֤��㽫�����ĳ��ѧУ�����Ա�֤ÿ��ѧУ����һ��

����˼·��
һ��ͼ������һ��ǿ��ͨ����һ��ֻ��Ҫһ�ݣ�
������һ�ݸ���ǿ��ͨ�����������һ��������ʹ������ͨ���������е㶼����һ�ݡ�
1������targan�㷨�������ͼ��ǿ��ͨ����
2����ÿ����ͨ��������һ���㡣
�����Ϳ��Եõ�һ�������޻�ͼ
TASKA��������������޻�ͼ���Ϊ0�ĵ㣬Ȼ���������Ϊ0�ĵ㶼����Ҫ��һ�ݣ��������еĵ㶼���Ա�COPY��
TASKB�������ͼ�д���һ�����Ϊ0�ĵ㣬�����������������ĵ㣬һ�����ܴﵽ������Ϊ0�ĵ㣻
       ͬʱ��������ڳ���Ϊ0����ô������������������㣬һ�����ܵ��������㡣
       ���ԣ����¼���ı��У�һ��Ҫ������Щ���Ϊ0�ͳ���Ϊ0�ĵ㡣
       ���һ���ߣ�����������һ�����Ϊ0�ͳ���Ϊ0�ĵ㣬���ǲ���ͬʱ�����������Ϊ0���߳���Ϊ0
       ����answer = MAX(in0,out0);

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

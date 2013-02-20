/**
倒酒问题，BFS
题目给定2个容器容积和一个需求的量
分别是A,B,C
要求在最少次数下通过FILL DROP POUR3种操作将A或B中某一个容器内的容量成为C
*/

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

struct state
{
    int a,b;
    int pre;
    int opt;
};

vector<state> q;
bool hash[110][110];
stack<int> s;

int main()
{
    int A,B,C;
    while(scanf("%d%d%d",&A,&B,&C) == 3)
    {
        state start;
        state temp;
        state now ;
        bool flag = false;
        memset(hash,0,sizeof(hash));


        start.a = start.b = 0;
        start.pre = -1;
        start.opt = 0;
        hash[0][0]=true;

        q.clear();
        q.push_back(start);

        int front,rear;
        front = rear = 0;


        while(front < q.size())
        {
            now = q[front];
            if(now.a == C || now.b == C)
            {
                flag = true;
                break;
            }

            //1fill a
            if(now.a != A)
            {
                temp = now;
                temp.a =A;
                temp.pre = front;
                temp.opt = 1;
                if(!hash[temp.a][temp.b])
                {
                    hash[temp.a][temp.b] = true;
                    q.push_back(temp);
                }
            }
            //2 fill B
            if(now.b != B)
            {
                temp = now;
                temp.b =B;
                temp.pre = front;
                temp.opt = 2;
                if(!hash[temp.a][temp.b])
                {
                    hash[temp.a][temp.b] = true;
                    q.push_back(temp);
                }
            }
            //3 dropA
            if(now.a != 0)
            {
                temp = now;
                temp.a =0;
                temp.pre = front;
                temp.opt = 3;
                if(!hash[temp.a][temp.b])
                {
                    hash[temp.a][temp.b] = true;
                    q.push_back(temp);
                }
            }

            //4 drop B
            if(now.b != 0)
            {
                temp = now;
                temp.b =0;
                temp.pre = front;
                temp.opt = 4;
                if(!hash[temp.a][temp.b])
                {
                    hash[temp.a][temp.b] = true;
                    q.push_back(temp);
                }
            }

            //5 pour a b
            if(now.a!=0 && now.b!=B)
            {
                //可以倒出水量
                int cano = now.a;
                //可以倒入水量
                int cani = B - now.b;
                //可倒出的比可倒入的多，将B填满
                //否则全部倒出
                if(cano>=cani)
                {
                    temp = now;
                    temp.a-=cani;
                    temp.b = B;
                }
                else
                {
                    temp = now;
                    temp.a = 0;
                    temp.b +=cano;
                }
                temp.pre = front;
                temp.opt = 5;
                if(!hash[temp.a][temp.b])
                {
                    hash[temp.a][temp.b] = true;
                    q.push_back(temp);
                }
            }

            //6 pour b a
            if(now.b!=0 && now.a!=A)
            {
                //可以倒出水量
                int cano = now.b;
                //可以倒入水量
                int cani = A - now.a;
                if(cano>=cani)
                {
                    temp = now;
                    temp.b-=cani;
                    temp.a = A;
                }
                else
                {
                    temp = now;
                    temp.b = 0;
                    temp.a +=cano;
                }
                temp.pre = front;
                temp.opt = 6;
                if(!hash[temp.a][temp.b])
                {
                    hash[temp.a][temp.b] = true;
                    q.push_back(temp);
                }
            }

            front++;
        }

        if(flag)
        {
            while(now.pre!=-1)
            {
                s.push(now.opt);
                now = q[now.pre];
            }
            printf("%d\n",s.size());
            while(!s.empty())
            {
                int opt = s.top();
                s.pop();
                switch(opt)
                {
                    case 1:
                        printf("FILL(1)\n");
                        break;
                    case 2:
                        printf("FILL(2)\n");
                        break;
                    case 3:
                        printf("DROP(1)\n");
                        break;
                    case 4:
                        printf("DROP(2)\n");
                        break;
                    case 5:
                        printf("POUR(1,2)\n");
                        break;
                    case 6:
                        printf("POUR(2,1)\n");
                        break;
                }
            }
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}

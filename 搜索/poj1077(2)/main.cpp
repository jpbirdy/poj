#include <cstdio>
#include <string.h>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;

const int mul[10]={1,1,2,6,24,120,720,5040,40320,362880};
int A[9],A1[9];
bool use[9],hash[362880];
//从数组得到特征值
int f(int *a)
{
    memset(use,0,sizeof(use));
    int ret=0;
    for(int i=8;i>=0;i--)
    {
        int cnt=0;
        for(int j=0;j<a[8-i];j++)
            if(!use[j])cnt++;
        ret+=cnt*mul[i];
        use[a[8-i]]=1;
    }
    return ret;
}

//倒推得到数组
void f1(int a1)
{
    int ret=a1,tmp;
    memset(use,0,sizeof(use));
    for(int i=8;i>=0;i--)
    {
        tmp=ret/mul[i];
        int a=0,p=-1;
        while(a<tmp)
        {
            p++;
            if(!use[p]) a++;
        }
        p++;
        while(use[p]) p++;
        A1[8-i]=p;
        use[p]=1;
        ret%=mul[i];
    }
}

queue<int> Q;
queue<queue<char> > Q1;
int path[362880],move[362880];
inline int m(int x,int y) {return x*3+y;}

void BFS()
{
    bool flag1=0;
    //queue<char> tmp1;
    //while(!tmp1.empty()) tmp1.pop();
    while(!Q.empty()) Q.pop();
    int tmp=f(A),tmp1;
    //printf("%d\n",tmp);
    Q.push(tmp);hash[tmp]=1;path[tmp]=-1;
    while(!Q.empty())
    {
        tmp=Q.front();Q.pop();tmp1=tmp;
        //tmp1=Q1.front();Q1.pop();
        f1(tmp);
        bool flag=1;
        //正解
        for(int i=0;i<8;i++)
            if(A1[i]!=i+1)
            {
                flag=0;break;
            }
        //输出结果
        if(flag)
        {
            stack<char> S;
            while(path[tmp]!=-1) {S.push(move[tmp]);tmp=path[tmp];}
            while(!S.empty())
            {
                printf("%c",S.top());
                S.pop();
            }
            puts("");flag1=1;
            break;
        }
        int x,y;
        //得到0所在位置
        for(x=0;x<3;x++)
        {
            for(y=0;y<3;y++)if(!A1[m(x,y)]) break;
            if(y<3) break;
        }
        //可以向上移动
        if(x>0)
        {
            swap(A1[m(x,y)],A1[m(x-1,y)]);
            tmp=f(A1);
            if(!hash[tmp]){hash[tmp]=1;Q.push(tmp);path[tmp]=tmp1;move[tmp]='u';}
            swap(A1[m(x,y)],A1[m(x-1,y)]);
        }
        //可以向下移动
        if(x<2)
        {
            swap(A1[m(x,y)],A1[m(x+1,y)]);
            tmp=f(A1);
            if(!hash[tmp]){hash[tmp]=1;Q.push(tmp);path[tmp]=tmp1;move[tmp]='d';}
            swap(A1[m(x,y)],A1[m(x+1,y)]);
        }
        //可以向左移动
        if(y>0)
        {
            swap(A1[m(x,y)],A1[m(x,y-1)]);
            tmp=f(A1);
            if(!hash[tmp]){hash[tmp]=1;Q.push(tmp);path[tmp]=tmp1;move[tmp]='l';}
            swap(A1[m(x,y)],A1[m(x,y-1)]);
        }
        //可以向右移动
        if(y<2)
        {
            swap(A1[m(x,y)],A1[m(x,y+1)]);
            tmp=f(A1);
            if(!hash[tmp]){hash[tmp]=1;Q.push(tmp);path[tmp]=tmp1;move[tmp]='r';}
            swap(A1[m(x,y)],A1[m(x,y+1)]);
        }
    }
    //全部空间搜索完毕，仍无解
    if(!flag1) puts("unsolvable");
}
int main()
{
    //Tester();
    char buf[2];
    int n;
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    while(n--)
    {
        for(int i=0;i<9;i++)
        {
            scanf("%s",buf);
            if(buf[0]=='x') A[i]=0;
            else A[i]=buf[0]-'0';
        }
        int c=clock();
        BFS();

        int t=clock()-c;
        printf("%d\n",t);
    }
    //getchar();getchar();getchar();getchar();
    return 0;
}

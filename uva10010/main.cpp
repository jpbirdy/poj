
/**
给一个字符串矩阵M*N
在给K个字符串
求这个字符串在矩阵中哪个位置可以找到

输出矩阵起点的字符的坐标

可以有8个方向，上下左右，上左、上右、下左、下右

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

char str_grid[60][60];
char str_found[30][100];

int m,n,k;

bool check_up(int kk,int i,int j)
{
    char buf[100];
    int len = strlen(str_found[kk]);
    buf[len] = '\0';
    if(i+1<len) return false;
    REP(k,len)
    {
        buf[k]=str_grid[i-k][j];
    }
    if(strcmp(buf,str_found[kk])==0) return true;
    else return false;
}

bool check_down(int kk,int i,int j)
{
    char buf[100];
    int len = strlen(str_found[kk]);
    buf[len] = '\0';
    if((m-i)<len) return false;
    REP(k,len)
    {
        buf[k]=str_grid[i+k][j];
    }
    if(strcmp(buf,str_found[kk])==0) return true;
    else return false;
}

bool check_left(int kk,int i,int j)
{
    char buf[100];
    int len = strlen(str_found[kk]);
    buf[len] = '\0';
    if((j+1)<len) return false;
    REP(k,len)
    {
        buf[k]=str_grid[i][j-k];
    }
    if(strcmp(buf,str_found[kk])==0) return true;
    else return false;
}


bool check_right(int kk,int i,int j)
{
    char buf[100];
    int len = strlen(str_found[kk]);
    buf[len] = '\0';
    if((n-j)<len) return false;
    REP(k,len)
    {
        buf[k]=str_grid[i][j+k];
    }
    if(strcmp(buf,str_found[kk])==0) return true;
    else return false;
}

bool check_up_left(int kk,int i,int j)
{
    char buf[100];
    int len = strlen(str_found[kk]);
    buf[len] = '\0';
    if((i+1)<len || (j+1)<len) return false;
    REP(k,len)
    {
        buf[k]=str_grid[i-k][j-k];
    }
    if(strcmp(buf,str_found[kk])==0) return true;
    else return false;
}

bool check_up_right(int kk,int i,int j)
{
    char buf[100];
    int len = strlen(str_found[kk]);
    buf[len] = '\0';
    if((i+1)<len || (n-j)<len) return false;
    REP(k,len)
    {
        buf[k]=str_grid[i-k][j+k];
    }
    if(strcmp(buf,str_found[kk])==0) return true;
    else return false;
}
bool check_down_left(int kk,int i,int j)
{
    char buf[100];
    int len = strlen(str_found[kk]);
    buf[len] = '\0';
    if((m-i)<len || (j+1)<len) return false;
    REP(k,len)
    {
        buf[k]=str_grid[i+k][j-k];
    }
    if(strcmp(buf,str_found[kk])==0) return true;
    else return false;
}

bool check_down_right(int kk,int i,int j)
{
    char buf[100];
    int len = strlen(str_found[kk]);
    buf[len] = '\0';
    if((m-i)<len || (n-j)<len) return false;
    REP(k,len)
    {
        buf[k]=str_grid[i+k][j+k];
    }
    if(strcmp(buf,str_found[kk])==0) return true;
    else return false;
}




void solve(int kk)
{
    for(int i=0 ; i<m ; i++)
        for(int j=0 ; j<n ; j++)
        {
            if(check_up(kk,i,j) || check_down(kk,i,j) || check_left(kk,i,j) || check_right(kk,i,j) ||
               check_up_left(kk,i,j) || check_up_right(kk,i,j) || check_down_left(kk,i,j) || check_down_right(kk,i,j)
               )
            {
                printf("%d% d\n",i+1,j+1);
                return ;
            }
        }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d\n",&m,&n);
        for(int i=0 ; i<m ; i++)
        {
            gets(str_grid[i]);
            for(int j=0 ; j<n ; j++)
                str_grid[i][j] = tolower(str_grid[i][j]);
        }

        scanf("%d\n",&k);
        for(int i=0 ; i<k ; i++)
        {
            gets(str_found[i]);
            for(int j=0 ; j<n ; j++)
                str_found[i][j] = tolower(str_found[i][j]);
        }

        for(int kk=0 ; kk<k ; kk++)
        {
            solve(kk);
        }

        if(t>0) printf("\n");


    }
    return 0;
}

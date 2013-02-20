/*
给一个日期，甲乙轮流做一个休息，甲先开始
甲乙都可以对给定的日期做两种变换1
1、对月份+1
2、变为该日期的下一天
如果不能月份+1就只能进行2变换。
谁先将日期变换到2001年11月4日就算胜利
如果甲必胜输出YES，否则输出NO

算法：
动态规划
令win[y][m][d]表示从y年m月d日开始甲报，甲是否必胜，若甲胜则win[y][m][d]=1，否则=0
则可以认为，ymd这一天是乙变换得来的，则ymd为目标是将，win=0，甲输
若ymd>目标时间，甲必胜。
若经过一次变换之后必输，则该状态甲必胜
因为一次变换之后是乙做变换，而该状态下是必输的，所以上一个状态必胜

*/


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int win[110][13][32] ;
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


int check(int y,int m,int d)
{
    int win_t = 0;
    if(y==101 && m==11 && d==4)
        win_t = 0;
        //return 1;
    else if(y>101 || (y==101 && (m>11 || (m==11 && d>4))))
        win_t = 1;
        //return 0;
    else if(win[y][m][d]==0)
        return 0;
    else if(win[y][m][d]==1)
        return 1;
    else
    {
        if(m==1)
        {
            //可以变成下个月
            if(d<=month[2] || (d==29 &&
                               ((y%4==0 && y%100!=0) || (y%400 ==0))
                               ))
                if(check(y,m+1,d)==0)
                    win_t = 1;
        }
        else if(m==12)
        {
            if(check(y+1,1,d)==0)
                win_t = 1;
        }
        else
        {
            if(d<=month[m+1])
                if(check(y,m+1,d)==0)
                    win_t = 1;
        }



        if(d<month[m])
        {
            if(check(y,m,d+1)==0) win_t = 1;
        }
        else
        {
            if(m<12)
                if(check(y,m+1,1)==0) win_t = 1;
            else
                if(check(y+1,1,1)==0) win_t = 1;
        }

    }

    win[y][m][d] = win_t;
    return win_t;

}

int main()
{

    memset(win,255,sizeof(win));
    int t;
    int y,m,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&y,&m,&d);
        if(check(y-1900,m,d))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

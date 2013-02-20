/**
DFS
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

char s[30][30];
int flag[30][30];
//上下左右
int dis[4][2]=
            {
                {1,0},{-1,0},{0,1},{0,-1}
            };
//对角线
int d_dis[4][2]=
            {
                {1,1},{1,-1},{-1,1},{-1,-1}
            };
int total;
int click_x,click_y;
int rows,cols;

void search(int x,int y)
{
    int x2,y2;
    int i;
    flag[x][y] = 1;
    //枚举上下左右
    for(i=0 ; i<4 ; i++)
    {
        x2 = x+dis[i][0];
        y2 = y+dis[i][1];
        if(s[x2][y2]=='X' && flag[x2][y2]==0)
            search(x2,y2);
        else if(s[x2][y2] == '.')
            total++;
    }

    for(i=0 ; i<4 ; i++)
    {
        x2 = x+d_dis[i][0];
        y2 = y+d_dis[i][1];
        if(s[x2][y2]=='X' && flag[x2][y2]==0)
            search(x2,y2);
    }
}

int main()
{
    while(scanf("%d%d%d%d",&rows,&cols,&click_x,&click_y)==4 && rows)
    {
        int i,j;
        memset(s,'.',sizeof(s));
        memset(flag,0,sizeof(flag));
        for(i=1 ; i<=rows ; i++)
        {
            char buf[40];
            scanf("%s",buf);
            for(j=1 ; j<=cols ; j++)
                s[i][j] = buf[j-1];
        }
        total = 0;
        search(click_x,click_y);
        printf("%d\n",total);
    }
    return 0;
}

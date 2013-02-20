/**
DFS������
��Ŀ����һ������0��1��ɣ�0��ʾ��λ�ÿ����ߣ�1��ʾ��������
һ����������������Ͻ����ϡ��¡��������ߡ�����������˵����߹���
�������˿��ܵ��������
���һ���Ŀ���������

��Ŀ�Ĺؼ����ڣ������������ӵ�������������
1�ǴӸ�λ�õ�����ߣ�һ���ж��ٸ��ϰ���left_f
2�ǴӸ�λ�õ������棬һ���ж��ٸ��ϰ���up_f

��������һ������k��һ�����������U����ǰλ���������������k������up_f[i][j] == up[i-k][j]�ͱ�ʾ��λ�õ�����k����û���ϰ�������
����������ͬ��

ö��ÿ���㣬�Դ�DFS�������ɵ����ս�

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

const int N = 110;
int field[N][N];
int left_f[N][N],up_f[N][N];

struct Step
{
    int s,e;
    char d;
};

vector<Step> vS;
int n,m;

void init()
{
    int i,j;
    for(i=0 ; i<n ; i++)
        for(j=0 ; j<m ; j++)
            scanf("%d",&field[i][j]);
    for(i=0 ; i<n ; i++)
        left_f[i][0] = field[i][0];
    for(i=0 ; i<n ; i++)
        for(j=1 ; j<m ; j++)
            left_f[i][j] = left_f[i][j-1] + field[i][j];
    for(i=0 ; i<n ; i++)
        up_f[0][i] = field[0][i];
    for(i=1 ; i<n ; i++)
        for(j=0 ; j<m ; j++)
            up_f[i][j] = up_f[i-1][j] + field[i][j];

    /*
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<m ; j++)
            printf("%d ",left_f[i][j]);
        printf("\n");
    }


    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<m ; j++)
            printf("%d ",up_f[i][j]);
        printf("\n");
    }
    */
}

int find_flag = 0;
int res_num = 0;

void check(int x,int i,int j)
{
    if(find_flag) return ;
    if(x == vS.size()) { find_flag = 1; res_num++ ; return ;}
    else
    {
        int k ;
        for(k = vS[x].s ; k<=vS[x].e ; k++)
            if(!find_flag)
            switch(vS[x].d)
            {
                case 'U':

                    if(i>=k && up_f[i][j] == up_f[i-k][j])
                        check(x+1,i-k,j);
                    break;
                case 'R':
                    if((j+k)<m && left_f[i][j] == left_f[i][j+k])
                        check(x+1,i,j+k);
                    break;
                case 'D':
                    if((i+k)<n && up_f[i][j] == up_f[i+k][j])
                        check(x+1,i+k,j);
                    break;
                case 'L':
                    if(j>=k && left_f[i][j] == left_f[i][j-k])
                        check(x+1,i,j-k);
                    break;
            }
    }
}

int main()
{
    int t;
    int s,e;
    int i,j;
    Step step ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();



        vS.clear();
        while(scanf("%d%d",&s,&e)==2 && s && e)
        {
            step.s = s;
            step.e = e;
            scanf(" %c",&step.d);
            vS.push_back(step);
        }

        res_num = 0;
        for(i=0 ; i<n ; i++)
            for(j=0 ; j<m ; j++)
                if(!field[i][j])
                {
                    find_flag = 0;
                    check(0,i,j);
                }

        printf("%d\n",res_num);
    }

    return 0;
}

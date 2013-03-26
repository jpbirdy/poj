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




int i,result,n,len;
int d[4];
int r[3][4];

bool flag ;
bool out_ans = true;

void swap(int &a, int &b)
{
    int t;t=a;a=b;b=t;
}

void print_ans()
{
    printf("%d %d %d %d Can point 24 in this way:",d[0],d[1],d[2],d[3]);
    REP(i,3)
    {
        REP(j,3)
        {
            if(j!=1)
                printf("%d",r[i][j]);
            else
                switch(r[i][j])
                {
                    case 0:
                        printf("+");
                        break;
                    case 1:
                        printf("-");
                        break;
                    case 2:
                        printf("*");
                        break;
                    case 3:
                        printf("/");
                        break;
                }
        }
        printf("=%d;",r[i][3]);
    }
    printf("\n");
}


void solve(int k,int dd[4])
{
    int a,b,i,j,l,t;
    int e[4];
    if(flag) return ;
    if(k==0)
    {
        if(dd[0] == 24)
        {
             if(out_ans) print_ans();
             flag = true;
        }

    }
    else
    {
        for(i=0 ; i<k ; i++)
            for(j=i+1 ; j<=k ; j++)
            {
                a=dd[i];
                b=dd[j];
                if(a<b) swap(a,b);
                t = 0;
                for(l=0 ; l<=k ; l++)
                {
                    if(l!=i && l!=j) e[t++]=dd[l];
                }
                r[3-k][0] = a;
                r[3-k][2] = b;
                r[3-k][3] = -1;
                for(l=0 ; l<4 ; l++)
                {
                    switch(l)
                    {
                        case 0:
                            r[3-k][3] = a+b;
                            break;
                        case 1:
                            r[3-k][3] = a-b;
                            break;
                        case 2:
                            r[3-k][3] = a*b;
                            break;
                        case 3:
                            if(b!=0 && a%b==0)
                                r[4-k][3] = a/b;
                            break;
                    }
                    r[3-k][1] = l;
                    if(r[3-k][3]!=-1)
                    {
                        e[t] = r[3-k][3];
                        solve(k-1,e);
                    }
                }

            }
    }
}



int main()
{
    freopen("out.txt","w",stdout);
    REP(k0,13)
        REP(k1,13)
            REP(k2,13)
                REP(k3,13)
                {
                    d[0] = k0+1;
                    d[1] = k1+1;
                    d[2] = k2+1;
                    d[3] = k3+1;
                    flag = false;
                    solve(3,d);
                    if(!flag)
                        printf("%d %d %d %d Can't point 24!\n",d[0],d[1],d[2],d[3]);
                }

    return 0;
}

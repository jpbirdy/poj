
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;



int xh[100010];

int a[110];
int b[110];

int main()
{
    int n,m;
    int mark;
    //freopen("input.txt","r",stdin);


    while(scanf("%d%d",&n,&m)==2)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&mark);
            xh[i] = mark;
            a[mark]++;
        }

        b[100] = 1;
        for(int i=99 ; i>=0 ; i--)
        {
            b[i] = b[i+1] + a[i+1];
        }

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d",&mark);
            printf("%d\n",b[xh[mark-1]]);
        }
        printf("\n");
    }


    return 0;
}

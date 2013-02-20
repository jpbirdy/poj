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

int g[70][70];


int main()
{
    int n,m,i,j;
    int x = 0;
    i = 0 ; j = 0;
    memset(g,255,sizeof(g));
    scanf("%d%d",&n,&m);

    while(x<n*m)
    {
        int i_len = n - i*2 - 1;
        int j_len = m - j*2 - 1;
        if(i_len == 0 && j_len == 0)
        {
            g[i][j] = (x++) % 26;
            break;
        }

        int k;
        for(k=0 ; k<j_len&&g[i][j]==-1 ; k++,j++)
            g[i][j] = (x++) % 26;
        for(k=0 ; k<i_len&&g[i][j]==-1 ; k++,i++)
            g[i][j] = (x++) % 26;
        for(k=0 ; k<j_len&&g[i][j]==-1 ; k++,j--)
            g[i][j] = (x++) % 26;
        for(k=0 ; k<i_len&&g[i][j]==-1 ; k++,i--)
            g[i][j] = (x++) % 26;
        j++;
        i++;
    }

    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<m ; j++)
            printf("%4c",g[i][j]+'A');
        printf("\n");
    }

    return 0;
}

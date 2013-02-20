#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;


int main()
{

    int d[16];
    int a[22][22];
    int b[22][22];

    char arr[4] = {'.','!','X','#'};
    int day;

    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d",&day);
    int i,j;
    for(i=0;i<16;i++)
        scanf("%d",&d[i]);
    for(i=1;i<=20;i++)
        for(j=1;j<=20;j++)
            scanf("%d",&a[i][j]);
    while(day--)
    {
        for(i=1;i<=20;i++)
            for(j=1;j<=20;j++)
            {
                int k=0;
                k = a[i][j]+a[i+1][j]+a[i-1][j]+a[i][j+1] + a[i][j-1];
                b[i][j] = a[i][j] + d[k];

                if(b[i][j]>3) b[i][j] = 3;
                if(b[i][j]<0) b[i][j] = 0;
            }
        memcpy(a,b,sizeof(a));
    }

    for(i=1;i<=20;i++)
    {
        for(j=1;j<=20;j++)
            printf("%c",arr[a[i][j]]);
        printf("\n");
    }



    return 0;
}

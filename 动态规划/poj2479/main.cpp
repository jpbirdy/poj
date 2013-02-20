/**

给定一个数组
求max{ SUM(A[I]~A[J]) + SUM(A[K]~A[L])}
其中 0<=I<=J<=K<=L<=(N-1)

动态规划
令数组max_f[i]表示从0~i的最大和
零数组max_l[i]表示从i~n-1的最大和
枚举k 求最大的max_f[k] + max_l[k+1];
一次正向求最大子数组和
一次反向求最大子数组和

同poj2593

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

const int N = 50010;

int a[N],max_f[N],max_l[N];

int main()
{
    int t;
    scanf("%d",&t);
    int n,i;
    int max ;
    memset(a,0,sizeof(a));
    memset(max_f,0,sizeof(max_f));
    memset(max_l,0,sizeof(max_l));
    while(t--)
    {
        scanf("%d",&n);
        for(i=0 ; i<n ; i++)
            scanf("%d",&a[i]);
        max_f[0] = a[0];
        for(i=1 ; i<n ; i++)
            if((max_f[i-1]+a[i])>a[i])
                max_f[i] = a[i] + max_f[i-1];
            else
                max_f[i] = a[i];


        for(i=1 ; i<n ; i++)
            if(max_f[i-1]>max_f[i])
                max_f[i] = max_f[i-1];

        max_l[n-1] = a[n-1];
        for(i=n-1 ; i>=0 ; i--)
            if((max_l[i+1] + a[i]) > a[i])
                max_l[i] = max_l[i+1] + a[i];
            else
                max_l[i] = a[i];
        for(i=n-2 ; i>=0 ; i--)
            if(max_l[i+1] > max_l[i])
                max_l[i] = max_l[i+1];

        max = -9999999;
        for(i=0 ; i<n-1 ; i++)
            if ((max_f[i] + max_l[i+1]) > max)
                max = max_f[i] + max_l[i+1];

        printf("%d\n",max);
        memset(a,0,sizeof(a));
        memset(max_f,0,sizeof(max_f));
        memset(max_l,0,sizeof(max_l));
    }


    return 0;
}

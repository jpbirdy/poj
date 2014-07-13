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


int main()
{
    /*
    int ans[11][11][11];
    for(int i=0 ; i<=10 ; i++)
        for(int j=1 ; j<=10 ; j++)
            for(int k=1 ; k<=10 ; k++)
            {
                switch(i)
                {
                    case 0:
                        a[i][j][k]=0;
                        break;
                    case 1:
                        if(j>=k) a[i][j][k] = 1;
                        else a[i][j][k] = -1;
                        break;
                    case 2:
                        if((j+1)*2<=k) a[i][j][k]=-1;
                        else if(j>=k*2) a[i][j][k]=1;
                        else a[i][j][k]=0;
                        break;
                    case 3:
                        if(j==1)
                        {
                            if(k==1) a[i][j][k]=0;
                            else a[i][j][k]=-1;
                        }
                        else if(k>=2*j) a[i][j][k]=-1;
                        else a[i][j][k]=1;
                        break;
                    case 4:
                        if(j==1)
                        {
                            if(k==1) a[i][j][k]=0;
                            else a[i][j][k]=-1;
                        }
                        else if(k>=j*3) a[i][j][k]=-1;
                        else if(k<(j-1)*2) a[i][j][k]=1;
                        else a[i][j][k]=0;
                        break;
                    case 5:

                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    case 8:
                        break;
                    case 9:
                        break;
                    case 10:
                        break;
                }
            }
            */
    int t,n,j,k;
    int ret;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&j,&k);
        if(n%2 ==0)

        {
            if(k>=j*(n/2+1)) ret = -1;
            else if(k<(j-n/2+1)*n/2) ret = 1;
            else ret = 0;
        }
    }
    return 0;
}


#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool hash[1010];

int main()
{
    int t;
    int a1,a2,a3,a4,a5,a6;
    int i,j,k,l,m,n;
    int res;
    int mo;
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
        memset(hash,0,sizeof(hash));
        hash[0] = true;
        res = 0;
        for(i=0 ; i<=a1 ; i++)
            for(j=0 ; j<=a2 ; j++)
                for(k=0 ; k<=a3 ; k++)
                    for(l=0 ; l<=a4 ; l++)
                        for(m=0 ; m<=a5 ; m++)
                            for(n=0 ; n<=a6 ; n++)
                            {
                                mo = i+j*2+k*3+l*5+m*10+n*20;
                                if(!hash[mo])
                                {
                                    hash[mo]=true;
                                    res++;
                                }
                            }
        printf("%d\n",res);
    }
    return 0;
}

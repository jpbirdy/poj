
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool hash[1010];
bool hash_t[1010];


//Ìí¼Ón¸övgµÄíÀÂë
void solve(int n,int v)
{
    memcpy(hash_t,hash,sizeof(hash));
    for(int i=0 ; i<=1000 ; i++)
        if(hash[i])
        {
            for(int j=1 ; j<=n ; j++)
                hash_t[i+j*v]= true;
        }
    memcpy(hash,hash_t,sizeof(hash));
}


int main()
{
    int t;
    int a[6];
    int b[6] = {1,2,3,5,10,20};
    int res;
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0 ; i<6 ; i++)
            scanf("%d",a+i);
        memset(hash,0,sizeof(hash));
        hash[0] = true;
        for(int i=0 ; i<6 ; i++)
            solve(a[i],b[i]);
        res = 0;
        for(int i=1 ; i<=1000 ; i++)
            if(hash[i])
                res++;
        printf("%d\n",res);
    }
    return 0;
}

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

int prime[80010];
int a[80010];
int b[80010];
int c[80010];
int total = 0;

int res[8000];

void create_prime()
{
    memset(prime,0,sizeof(prime));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i=2 ; i<80000 ; i++)
    {
        if(prime[i]==0)
        {
            res[total] = i;
            for(int j=2 ; i*j<80000 ; j++)
            {
                prime[i*j]=1;
                if(prime[j]==0) a[i*j] = 1;
                if(a[i]) b[i*j]=1;
            }

            total++;
        }
    }


    for(int i=0 ; i<total ; i++)
        for(int j=i ; j<total ; j++)
            c[res[i]+res[j]]++;


}



int main()
{
    create_prime();
    //printf("%d\n",total);
    int x;
    prime[0] = prime[1] = 0;

    while(scanf("%d",&x)==1)
    //RREP(x,80000)
    {
        int ret = 0;
        if(prime[x]==0) ret++;
        else if(a[x]) ret++;
        else if(b[x]) ret++;

        for(int i=0 ; (i<total) && (res[i]<x) ; i++)
            if(a[x-res[i]]) ret++;

        //for(int i=0 ; )

        for(int i=0 ; (i<total) && (res[i]<=x/3) ; i++)
            for(int j=i ; (j<total) && (res[j]<=(x-res[i])/2) ; j++)
            {
                int k = x-res[i]-res[j];
                if(prime[k]==0)
                    //ret++;
                    ret=(ret+1)%1000000007;
            }

        //ret+=c[x];
        ret= (ret+c[x])%1000000007;

        printf("%d\n",ret);

    }

    //freopen("input.txt","r",stdin);
	return 0;

}

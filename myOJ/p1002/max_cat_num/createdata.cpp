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
#include <ctime>

using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int(i)=(n)-1;(i)>=0;(i)--)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())

int a[10] = {10,100,1000,2000,4000,8000,10000,20000,50000,100000};

int main()
{
    srand(time(NULL));
    freopen("input.txt","w",stdout);
    printf("10\n");
    int n;
    int i,j;
    for(i=0 ; i<10 ;i++)
    {
        printf("%d\n",a[i]);
        for(j=0 ; j<a[i]-1;j++)
            printf("%d ",rand()*rand()%10000);
        printf("%d\n",rand()*rand()%10000);
    }



    return 0;
}

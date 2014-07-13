#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

const int N = 1000010;

bool b[1000010];

int main()
{
    memset(b,0,sizeof(b));
    b[0]=true;
    b[1]=true;
    for(int i=2 ; i<N ; i++)
        //b[i]==false;
        if(!b[i])
        {
            for(int j=2 ; i*j<N ; j++)
                b[i*j]=true;
        }
    int l,r;
    while(cin>>l>>r)
    {
        int res = 0;
        for(int i=l ; i<r ; i++)
            if(!b[i]) res++;
        printf("%d\n",res);
    }
    return 0;
}

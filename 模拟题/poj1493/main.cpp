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

int main()
{
    int i,j,n,m,t;
    char *p,str[128];

    while(scanf("%d ",&n)==1 && n)
    {
        t=26;
        m=0;
        for(i=0;i<n;i++)
        {
            gets(str);
            p=strchr(str,' ');
            if(p==NULL) j=0;
            else for(j=0;*p++==' ';j++);
            m+=j;
            if(j<t) t=j;
        }
        printf("%d\n",m-n*t);
    }
    return 0;
}

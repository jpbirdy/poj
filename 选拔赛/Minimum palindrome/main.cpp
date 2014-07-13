#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int n,m;
    int cases = 1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("Case #%d: ",cases++);
        if(n==1)
        {
            for(int i=0 ; i<m ; i++) printf("a");
            printf("\n");
        }
        else if(n==2)
        {
            int l , r;
            int rn = 0;
            l = (m+1)/2;
            while(l>=(rn*2+1))
                rn++,l--;
            rn--,l++;
            r = m-l-rn*2;
            for(int i=0 ; i<l ; i++) printf("a");
            for(int i=0 ; i<rn ; i++) printf("ba");
            for(int i=0 ; i<r ; i++) printf("b");
            printf("\n");
        }
        else
        {
            int k = 0;
            for(int i=0 ; i<m ; i++)
                printf("%c",(k++)%3+'a');
            printf("\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>
using namespace std;

int main()
{
    int i,k;
    bool b[9] = {0};
    srand((unsigned) time(NULL) * 123456); /*²¥ÖÖ×Ó*/

    int n;
    scanf("%d",&n);
    freopen("in10000.txt","w",stdout);
    printf("%d\n",n);
    for(i=0 ; i<n ; i++)
    {
        memset(b,0,sizeof(b));
        for(k = 1; k <= 9;)
        {
            int x = rand() % 9;
            if(b[x]) continue ;
            b[x] = true ;
            if(x==0) printf("x");
            else printf("%d",x);
            if(k<9) printf(" ");
            k++;
        }
        printf("\n");
    }



    return 0;
}

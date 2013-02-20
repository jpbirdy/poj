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

double x1 = (1+sqrt(5)) / 2;
double x2 = (1-sqrt(5)) / 2;

double x3 = x1 * x1;
double x4 = x2 * x2;


int main()
{
    int a1 = 1;
    int a2 = 1;
    int a3 ;
    int t;
    int n = 3;

    scanf("%d",&t);
    int c = 1;
    while(t--)
    {
        /*
        scanf("%d%d%d",&a1,&a2,&n);
        double y1 = a1/x1;
        double y2 = a2/x3;
        double c2 = (y2-y1)/(x4/x3-x2/x1);
        double c1 = (a1 - x2*c2) / x1;

        //printf("%f\n%f\n",c1,c2);
        printf("%.0f\n",c1*pow(x1,n)+c2*pow(x2,n));
        */
        scanf("%d%d%d",&a1,&a2,&n);
        if(n<=(log10(a1)+1))
        {
            int t=1;
            while(n<=log10(a1)){t*=10,n++;}
            printf("Case #%d: %d",c++,a1/t%10);
        }
        else
        {
            n--;
            a3 = a2;
            while(n>(log10(a3)+1))
            {
                n-= (int)log10(a3)+1;
                a3 = a1 + a2;
                if(a3>=10)
                {
                    a1 = a3/10;
                    a2 = a3%10;
                }
                else
                {
                    a1 = a2;a2 = a3;
                }
            }
            int t=1;
            if(a2>10) t=10;
            printf("Case #%d: %d\n",c++,a2/t);
        }

    }


    return 0;
}

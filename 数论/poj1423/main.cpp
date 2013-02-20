/**
给一个数n，求n!的位数
log(2nπ)/2+n*log(n/e)+log(1+1/12n+1/288n^2)/log10
n!≈(n/e)^n * sqrt(2*pi*n)
斯特林公式
位数= log10(N!) = (int)(n*log(n/e) + log(2πn)/2) + 1;
*/

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int solv(int n)
{
    if(n==1)
    {
        return 1;
    }
    //return (int)((log(2*acos((double)-1.0)*n)/2+n*log(n/exp((double)1.0))+log(1+1.0/(12*n)+1.0/(288*n*n)))/log(10.0))+1;
    return (int)((n*log(n/(exp(1.0))) + log(2*acos(-1.0)*n)/2)/log(10)) + 1;
}
int main()
{
    int cyle,n;
    scanf("%d",&cyle);
    while(cyle--)
	{
        scanf("%d",&n);
        printf("%d\n",solv(n));
    }
    return 0;
}

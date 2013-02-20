#include <cstdio>
#include <cmath>
using namespace std;

const double PI = 3.1415926;

int main ()
{
	int n,i;
	double a,b;
    scanf ("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf ("%lf%lf",&a,&b);
        int year;
        year = (int)ceil( PI*(a*a+b*b)/2 / 50);

        printf ("Property %d: This property will begin eroding in year %d.\n",i,year);
    }
    printf ("END OF OUTPUT.\n");
	return 0;
}

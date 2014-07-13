#include <iostream>
#include <ctime>

#include <cstdio>
using namespace std;

int a[1000010];

const int N = 100000000;

int main()
{
    int i;
    int t0 = clock();
    for(i=0 ; i<N ; i++)
        a[0] = 1;
    int t1 = clock();
    for(i=0 ; i<N ; i++)
        a[330000] = 1;
    int t2 = clock();
    for(i=0 ; i<N ; i++)
        a[660000] = 1;
    int t3 = clock();
    for(i=0 ; i<N ; i++)
        a[1000000] = 1;
    int t4 = clock();

    printf("t1:%d\nt2:%d\nt3:%d\nt4:%d\n",t1-t0,t2-t1,t3-t2,t4-t3);
}

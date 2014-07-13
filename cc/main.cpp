#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char str[500];
    int a[500];
    int i;
    char *pstr = str;
    cin >> str;
    char *c;
    int num = 0;
    int ret = 0;

    while(c=strstr(pstr,","))
    {
        //printf("%d\n",c);
        sscanf(pstr,"%d,",&a[num++]);
        pstr = c+1;
    }
    sscanf(pstr,"%d",&a[num++]);

    int maxa,mina ;
    maxa = mina = a[0];
    for(i=1 ; i<num ; i++)
        if(a[i]>maxa) maxa = a[i];
        else if(a[i]<mina) mina = a[i];
    for(i=0 ; i<num ; i++)
        if(a[i]!=maxa && a[i]!=mina) ret++;

    cout<< ret << endl;
    return 0;


}

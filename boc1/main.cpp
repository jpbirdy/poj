#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


char s1[100],s2[100],s3[100];

double getnum(char * s)
{
    int intarea;
    double floatarea;
    int t = 10;
    intarea = 0;
    floatarea = 0;
    int len = strlen(s);
    bool flag = true;
    int i;
    for( i=0 ; i<len ; i++)
    {
        if(flag)
        {
            if(s[i]>='0' && s[i]<='9')
                intarea = intarea*10+s[i]-'0';
            else if(s[i]=='.')
                flag = false;
        }
        else
        {
            if(s[i]>='0' && s[i]<='9')
            {
                floatarea = floatarea + (s[i]-'0')*1.0/t;
                t = t*10;
            }
            else break;
        }
    }

    double ret = intarea + floatarea;
    int elselen = strlen(s+i);
    if(elselen == 1)
        ret = ret * 1000000;
    else
    {
        switch(s[i])
        {
        case 'd':
            ret = ret * 100000;
            break;
        case 'c':
            ret = ret * 10000;
            break;
        case 'm':
            ret = ret * 1000;
            break;
        case 'u':
            break;
        case 'n':
            ret = ret / 1000;
            break;
        }
    }

    return ret;

}

double getnum2(char * s)
{
    int intarea;
    double floatarea;
    int t = 10;
    intarea = 0;
    floatarea = 0;
    int len = strlen(s);
    bool flag = true;
    int i;
    for( i=0 ; i<len ; i++)
    {
        if(flag)
        {
            if(s[i]>='0' && s[i]<='9')
                intarea = intarea*10+s[i]-'0';
            else if(s[i]=='.')
                flag = false;
        }
        else
        {
            if(s[i]>='0' && s[i]<='9')
            {
                floatarea = floatarea + (s[i]-'0')*1.0/t;
                t = t*10;
            }
            else break;
        }
    }

    double ret = intarea + floatarea;
    return ret;

}




int main()
{
    int t;
    int cases = 1;
    double a1,a2,a3;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s%s",s1,s2,s3);
        a1 = getnum(s1);
        a2 = getnum(s2);
        a3 = getnum2(s3);
        printf("Case %d: %.2lfpx\n",cases++,a1 * a3 / a2);
    }
    return 0;
}

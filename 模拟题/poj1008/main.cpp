/*
两种历法的计算
算出第一种是世界的第几天
再通过这个算出在第二种历法里的表示方法即可
水题
*/
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;


const char s1[22][22]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax",
                 "zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
const char s2[23][23]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk",
                 "ok","chuen","eb", "ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main()
{
    int n,m,i,q,w;
    scanf("%d",&m);
    printf("%d\n",m);
    while(m--)
    {
        char mon[44];
        int day,year;
        scanf("%d. %s %d",&day,mon,&year);
        n = year*365;
        for(i=0;i<19;i++)
        {
            if(strcmp(mon,s1[i])==0) break;
        }
        if(i!=19) n+=(i)*20+day;
        if(i==19) n+=(18*20)+day;
        q=n%20;//单词
        w=n%13;//数字
        printf("%d",w+1);
        printf(" %s ",s2[q]);
        printf("%d\n",n/260);//年

    }
    return 0;
}


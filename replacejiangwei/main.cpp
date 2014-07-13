#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int(i)=(n)-1;(i)>=0;(i)--)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())
int  mytrim(char s[])
{
   int  i=strlen(s)-1;
   for(;i>=0;i--)
          if(s[i]!='\t'&&s[i]!=' '&&s[i]!='\n')
                 break;
   s[i+1]='\0';
   return  i;
}

int main()
{
    freopen("test.txt","r",stdin);
    freopen("test.out","w",stdout);
    char line[1000];
    char varbuf[1000];
    int flag = 0;
    while(gets(line))
    {
        if(strlen(line) <= 1) continue;
        if(line[0] == '/' || line[0] == '*')
        {
            flag = 0;
            puts(line);
        }
        else
        {
            mytrim(line);
            if(flag == 0)
            {
                printf("#define kBDNMob%s_click @\"%s\"\n" ,line,line);
                strcpy(varbuf,line);
            }
            else
            {
                printf("#define kBDNMob%s_clickLabel @\"%s\"\n" ,varbuf,line);
            }
            flag = (flag+1)%2;
        }
    }
	return 0;

}



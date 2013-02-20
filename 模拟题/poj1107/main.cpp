/*
给定一串字符和k1,k2,k3
将这串字符分组a~i为1，j~r为2,s~z包括_为3
将原串分解为S1，S2，S3
将s1中的字符都改为其坐标向右移动k1个距离的字符，s2s3类似
得到的为加密的串
已知加密的串，求原串

如
the_quick_brown_fox

分组后
S1: i c b f h e
S2: o n o q k r
S3: _ u _ w _ x t
k1=2
右移2位得到的串为
S1: heicbf
S2: qkrono
S3: t_u_w_x
得到的加密串为
_icuo_bfnwhoq_kxert
反着做一遍即可
注意下标会越界

*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;


int main()
{
    int k1,k2,k3;
    int i;
    while(scanf("%d%d%d",&k1,&k2,&k3)==3)
    {
        if(k1==0 && k2==0 && k3==0)
            break;
        string str,s1,s2,s3;
        cin >>  str;
        s1 = s2 = s3 = "";
        for(i=0; i<str.size() ; i++)
        {
            if(str[i]>='a' && str[i]<='i')
            {
                s1+=str[i];
            }
            else if(str[i]>='j' && str[i]<='r')
            {
                s2+=str[i];
            }
            else
                s3+=str[i];
        }
        int i1,i2,i3;
        i1=i2=i3=0;
        string ret = "";
        int temp;
        for(i=0 ; i<str.size(); i++)
        {
            if(str[i]>='a' && str[i]<='i')
            {
                temp = i1 - k1;
                while(temp<0) temp+=s1.size();
                ret+=s1[temp];
                i1++;
            }
            else if(str[i]>='j' && str[i]<='r')
            {
                temp = i2 - k2;
                while(temp<0) temp+=s2.size();
                ret+=s2[temp];
                i2++;
            }
            else
            {
                temp = i3 - k3;
                while(temp<0) temp+=s3.size();
                ret+=s3[temp];
                i3++;
            }
        }
        cout << ret << endl;
    }
    return 0;
}

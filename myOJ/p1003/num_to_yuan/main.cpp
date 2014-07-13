/**
给定一个数字，表示钱数，转换为大写
可能有两位小数
*/
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

char dw[8][5] = {"仟","佰","拾","万","仟","佰","拾",""};
char num[9][5] = {"壹","贰","叁","肆","伍","陆","柒","仈","汣"};
//处理1亿以内
//保证str<=8
bool solve_yi(char *str ,bool flag)
{
    int len = strlen(str);
    int i = 8-len;
    int j;
    int last_0 = len-1;
    bool before = false;
    while(last_0>=0 && str[last_0] == '0') last_0--;
    //printf("%d\n",last_0);
    for(j=0 ; j<len ; j++,i++)
    {
        if(str[j] == '0')
        {
            if(i==3 && before) printf("万");
            if(flag == false && j<last_0)
            {
                printf("零");
                flag = true;
            }
        }
        else if(j==0 && str[j] == '1' && (i==2 || i==6))
        {
            before = true;
            flag = false;
            printf("%s%s",num[str[j]-'1'],dw[i]);
        }
        else
        {
            before = true;
            flag = false;
            printf("%s%s",num[str[j]-'1'],dw[i]);
        }
    }
    return flag;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    char str[100];
    char buff[10];
    char *temp = str;
    //int t;
    //scanf("%d\n",&t);
    while(gets(str))
    {
        temp = str;



        bool flag = true;

        char *dot = strstr(str,".");

        if(dot!=NULL)
        {
            *dot = '\0';
            dot++;
        }

        int len = strlen(str);
        int n = len/8;
        int i;
        if(len%8 !=0)
        {
            strncpy(buff,temp,len%8);
            buff[len%8] = '\0';
            flag = solve_yi(buff,flag);
            if(n > 0)
                printf("亿");
            else
                printf("元");
            temp = str+len%8;
        }
        buff[8]='\0';

        for(i=0 ; i<n ; i++)
        {
            strncpy(buff,temp,8);
            temp = temp+8;
            flag = solve_yi(buff,flag);
            if(i<(n-1))
                printf("亿");
            else printf("元");
        }

        if(dot!=NULL)
        {
            if((*dot) != '0')
                printf("%s角",num[(*dot) - '1']);
            dot++;
            if((*dot) != '0' && (*dot)!='\0')
                printf("%s分",num[(*dot) - '1']);
        }
        else printf("整");

        //solve_yi(buff,true);
        printf("\n");
    }

    return 0;
}

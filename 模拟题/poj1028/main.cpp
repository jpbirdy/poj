/**
模拟浏览器的前进后退功能，若无法后退或前进则Ignored，否则输出网址
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


const int arr=120;
string str[arr+10];

int main()
{
    string s="http://www.acm.org/";
    string s1,s2;
    int num,sum;
    num=0;
    while(cin>>s1)
    {
        if(s1=="QUIT")break;
        if(s1=="VISIT")
        {
            cin>>s2;
            num++;
            sum=num;
            str[num]=s2;
            cout<<s2<<endl;
        }
        if(s1=="BACK")
        {
            if(num==0){cout<<"Ignored"<<endl;continue;}
            else if(num==1){cout<<s<<endl;num--;}
            else {cout<<str[num-1]<<endl;num--;}
        }
        else if(s1=="FORWARD")
        {
            if(num+1>sum){cout<<"Ignored"<<endl;}
            else{cout<<str[num+1]<<endl;num++; }
        }
    }
    return 0;
}

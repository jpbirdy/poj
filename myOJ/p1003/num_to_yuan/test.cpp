#include<iostream>
#include<string>
#include<cstdlib>
#include <cstdio>
using namespace std;

const int INT_ONLY=1;
const int SMALL_ONLY=2;

string roundString(string s)
{
    double d=atof(s.c_str());
    int dec,sign;
    s=fcvt(d,2,&dec,&sign);
    return s;
}

string formatChinese(int flag,string s)
{
    int sLength=s.length();
    string bigLetter[]={"Áã","Ò¼","·¡","Èþ","ËÁ","Îé","Â½","Æâ","°Æ","¾Á"};
    string unit[]={"Ôª","Ê°","°Û","Çª","Íò","Ê°","°Û","Çª","ÒÚ","Ê°","°Û","Çª","Íò"};
    string small[]={"·Ö","½Ç"};
    string newS="";
    for(int i=0;i<sLength;i++)
    {
        if(flag==INT_ONLY)
            newS=newS+bigLetter[s.at(i)-48]+unit[sLength-i-1];
        else if(flag==SMALL_ONLY)
            newS=newS+bigLetter[s.at(i)-48]+small[sLength-i-1];
    }
    return newS;
}

string splitNum(string s)
{
    if(""==s)
        return "";
    string intOnly=s.substr(0,s.size()-2);
    string intPart=formatChinese(1,intOnly);
    string smallOnly=s.substr(s.size()-2,s.size());
    string smallPart=formatChinese(2,smallOnly);
    string newS=intPart+smallPart;
    return newS;
}

string replaceAll(string src,string regex,string replacement)
{
    int length=regex.length();
    while(src.find(regex)<src.length())
        src.replace(src.find(regex),length,replacement);
    return src;
}

string cleanZero(string s)
{
    if(""==s)
        return "";
    string regex1[]={"ÁãÇª","Áã°Û","ÁãÊ°"};
    string regex2[]={"ÁãÒÚ","ÁãÍò","ÁãÔª"};
    string regex3[]={"ÒÚ","Íò","Ôª"};
    string regex4[]={"Áã½Ç","Áã·Ö"};
    for(int i=0;i<3;i++)
        s=replaceAll(s,regex1[i],"Áã");
    for(int i=0;i<3;i++)
    {
        s=replaceAll(s,"ÁãÁãÁã","Áã");
        s=replaceAll(s,"ÁãÁã","Áã");
        s=replaceAll(s,regex2[i],regex3[i]);
    }
    for(int i=0;i<2;i++)
        s=replaceAll(s,regex4[i],"");
    s=replaceAll(s,"ÒÚÍò","ÒÚ");
    return s;
}

int main()
{
    string s;
    int i,j,l,flag;
    //freopen("input.txt","r",stdin);
    while(cin>>s)
    {
        if(s=="0"||s=="0.0"||s=="0.00")
        {
            cout<<"ÁãÔªÕû"<<endl;
            continue;
        }
        if(s=="10"||s=="10.0"||s=="10.00")
        {
            cout<<"Ê°ÔªÕû"<<endl;
            continue;
        }
        l=s.length();
        for(i=0;i<l;i++)
            if(s[i]=='.')
            {
                for(flag=1,j=i+1;s[j]!='\0';j++)
                    if(s[j]!='0')
                    {
                        flag=0;
                        break;
                    }
                if(!flag)
                    break;
            }
        s=roundString(s);
        s=splitNum(s);
        s=cleanZero(s);
        if(i<l)
            cout<<s<<endl;
        else
            cout<<s<<"Õû"<<endl;
    }
    return 0;
}

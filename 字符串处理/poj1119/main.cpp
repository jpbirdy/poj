/**
先给出若干字符串，这些字符串是需要被统计的，字符串可能重复，重复次数为Pi
然后给出一个文章，求文章中给定字符出现次数Ci
求出Sum(sqrt(Pi*Ci))

*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

map<string, int> match;
map<string, int>::iterator mPos;

map<string, int> doc;

int main()
{
    bool line = false;
    unsigned i;
    string a,b;
    while(cin >> a)
    {
        if(a=="----------")
            break;
        b= "" ;
        for(i=0 ; i<a.size() ; i++)
            if(isdigit(a[i]) || islower(a[i]))
                b+=a[i];
            else if(isupper(a[i]))
                b+=tolower(a[i]);
        if(b!="") match[b]++;
    }

    while(cin>>a)
    {
        if(line && a=="----------") break;
        else if(a=="----------")
        {
            line=true;
            double num = 0.0;
            for(mPos= match.begin() ; mPos!=match.end() ; mPos++)
            {
                double m1 = mPos->second;
                double m2 = doc[mPos->first];
                num+= sqrt(m1*m2);
            }
            printf("%.2f\n",num);
            doc.clear();
        }
        else
        {
            line = false;
            b = "";
            for(i=0 ; i<a.size() ; i++)
                if(isdigit(a[i]) || islower(a[i]))
                    b+=a[i];
                else if(isupper(a[i]))
                    b+=a[i]-'A'+'a';
                if(match[b]>0) doc[b]++;
        }
    }

    return 0;
}

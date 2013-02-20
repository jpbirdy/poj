#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct cs
{
    int k;
    int p;
};

class A
{
public :
    vector<cs> list;
    friend A operator * (const A& lhs,const A& rhs);
    friend A operator + (const A& lhs,const A& rhs);
    friend A operator * (const cs& lhs,const A& rhs);
    void list_sort();
    void output();
    void operator << (const A& a){output();}
};

int cmp( const cs &a, const cs &b )
{
    if( a.p < b.p )
       return 0;
    else
       return 1;
}

void A::list_sort()
{
    sort(list.begin(),list.end(),cmp);
}

void A::output()
{
    for(int i=0 ; i<list.size() ; i++)
        printf("+%dx^%d",list[i].k,list[i].p);
    printf("\n");
}

A operator + (const A& lhs,const A& rhs)
{
    int i,j;
    A res;
    res = lhs;
    for(i=0 ; i<rhs.list.size() ; i++)
    {
        for(j=0 ; j<res.list.size() ; j++)
            if(res.list[j].p == rhs.list[i].p)
                break;
        if(j<res.list.size()) res.list[j].k+=rhs.list[i].k;
        else
            res.list.push_back(rhs.list[i]);
    }
    res.list_sort();
    return res;
}

A multiply( A lhs, A rhs)
{
    A temp;
    if(lhs.list.size()>1)
    {
        for(int i=0 ; i<lhs.list.size() ; i++)
            temp = temp + (lhs.list[i] * rhs);
    }
    else
    {
        if(rhs.list.size()>1)
            for(int i=0 ; i<rhs.list.size() ; i++)
                temp = temp + (rhs.list[i] * lhs);
        else
        {
            cs temp_cs;
            cs a = lhs.list[0];
            cs b = rhs.list[0];
            temp_cs.k = a.k * b.k;
            temp_cs.p = a.p + b.p;
            temp.list.push_back(temp_cs);
        }
    }
    return temp;
}

A operator * (const A& lhs,const A& rhs)
{
    return multiply(lhs,rhs);
}

A operator * (const cs& lhs,const A& rhs)
{
    A temp;
    temp.list.push_back(lhs);
    return multiply(temp,rhs);
}

int main()
{
    A a,b,c;
    cs temp ;
    temp.k = 1;
    temp.p = 3;
    a.list.push_back(temp);

    temp.k = 2;
    temp.p = 1;
    a.list.push_back(temp);

    temp.k = 1;
    temp.p = 0;
    a.list.push_back(temp);

    temp.k = 1;
    temp.p = 2;
    b.list.push_back(temp);

    temp.k = 3;
    temp.p = 1;
    b.list.push_back(temp);

    temp.k = 2;
    temp.p = 0;
    b.list.push_back(temp);


    c = a * b;
    c.output();

    return 0;
}

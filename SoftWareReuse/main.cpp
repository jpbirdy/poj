#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdio>
using namespace std;

class Complex
{
public :
    double real;
    double imagin;
    friend Complex operator * (const Complex& lhs,const Complex& rhs);
    friend Complex operator + (const Complex& lhs,const Complex& rhs);
    friend ostream& operator << (ostream &o,const Complex&a)
    {
        return (o << a.real << "+ " << a.imagin << "i");
    }
    Complex(int a,int b){real = a;imagin = b;}
};

Complex operator + (const Complex& lhs,const Complex& rhs)
{
    Complex res(lhs.real+rhs.real,lhs.imagin+rhs.imagin);
    return res;
}

Complex operator * (const Complex& lhs,const Complex& rhs)
{
    Complex res(lhs.real*rhs.real-lhs.imagin*rhs.imagin,lhs.real*rhs.imagin+rhs.real*lhs.imagin);
    return res;
}


int main()
{
    Complex a(1,2),b(2,1),c(0,0);
    cout << a+b << endl;
    cout << a*b << endl;
    return 0;
}

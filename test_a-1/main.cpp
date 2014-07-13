#include <iostream>
#include <cstdio>

using namespace std;

class A
{
    public :
    A()
    {
        printf("C\n");
    }
    ~A()
    {
        printf("D\n");
    }
};

int main()
{
    A *a = new A[10];
    A *b = a+1;
    *(unsigned*)(a)=9;
    delete [] b;
    return 0;
}

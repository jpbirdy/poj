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

int rand7()
{
    return rand()%7+1;
}

int rand10()
{
    int x=0;
    do
    {
        x=(rand7()-1)*7+rand7();
    }
    while(x>40);
    return x%10+1;
}

int main()
{
    return 0;
}

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;



//逆序vi1.begin()
//如需改为倒序，修改0/1位置
//sort的排序cmp函数需要用const+具体类型的引用
//返回0或1
int cmp( const int &a, const int &b )
{
    if( a > b )
       return 0;
    else
       return 1;
}

int main()
{
    //定义
    vector<int> vi1;

    vi1.push_back(5);
    vi1.push_back(3);
    vi1.push_back(1);
    vi1.push_back(4);
    vi1.push_back(2);

    //vector排序
    sort(vi1.begin(),vi1.end(),cmp);

    for(vector<int>::iterator it=vi1.begin();it<vi1.end();it++)
        printf("%d ",*it);
    printf("\n");


    return 0;
}

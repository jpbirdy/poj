//题目大意是，给定一个M*N点的方阵，要求一条路径遍历所有点。
//解题思路很简单，不需要复杂的算法
//方阵的点和边很固定，所以当M和N同时为奇数时，每次都走边到最后的两个点不是邻边。所以长度是（M*N-1)+1.414
//否则，只走边一定能走完而且不重复
//每遍历 一个点需要走一条边，遍历所有点则需要M*N条，奇数情况则是前面M*N-1个点通过边走，最后一个需要走对角线

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    int tt = 1;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        printf("Scenario #%d:\n",tt++);
        if(m%2 && n%2) printf("%d.41\n\n",m*n);
        else printf("%d.00\n\n",m*n);
    }
    return 0;
}


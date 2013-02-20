/**
对二叉树进行编号，输入编号，输出二叉树
(左子树)X(右子树)的格式
编号从1开始

分析编号的规则，是左子树个数小的在前
首先通过catalan数，得到该编号对应二叉树节点个数 = n ，同时编号数N-节点个数<n的全部种数的和
就可以得到在节点数为n的情况下，对应的编号是X
开始遍历，从左子树l=0~n-1，依次对X-catalan[l]*catalan[n-l-1]，
若结果>0，则左子树为l，右子树为n-1-l的全部情况都没有达到X，继续减
知道某个L和n-L-1使得X不够减，则表示该树的左子树个数为L，右子树为n-L-1
因为二叉树编号是右子树有限的，而右子树的情况数为catalan[n-L-1] ，
也就是说，每一个情况的左子树都有catalan[n-L-1]个右子树对应
就可以推算出
(x/catalan[n-L-1])+1 为左子树在L个节点的对应编号
(x%catalan[n-L-1])+1 为右子树在n-L-1个的对应编号

递归即可

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

int catalan[20];
int sum[20];


//C(n,m)
long long combo(int n,int m)
{
    long long s=1;
    int a=n,b=1;
    int i;
    for(i=0;i<m;i++,a--,b++)
        s=s*a/b;
    return s;
}

void print_tree(int x,int n)
{
    if(n==0) return ;
    if(n==1){printf("X");return ;}
    int i;
    int temp;
    int L,R;
    for(i=0; i<n ; i++)
    {
        temp = catalan[i]*catalan[n-i-1];
        if(x>temp) x-=temp;
        else break;
    }
    L = i;
    R = n-L-1;
    //root
    x--;
    //存在左子树
    if(L>0)
    {
        printf("(");
        print_tree((x/catalan[R])+1,L);
        printf(")");
    }
    printf("X");
    if(R>0)
    {
        printf("(");
        print_tree((x % catalan[R]) +1 ,R);
        printf(")");
    }
}

int main()
{
    int i;
    catalan[0]=catalan[1]=1;

    //printf("%lld\n",combo(30,15));

    for(i=2 ; i<20 ; i++)
    {
        catalan[i] = combo(i*2,i) / (i+1);
        //printf("%d\n",catalan[i]);
    }


    sum[0] = 0;
    for(i=1 ; i<20 ; i++)
        sum[i] = sum[i-1]+catalan[i];

    int n;
    while((scanf("%d",&n)==1) && n)
    {
        for(i=1;i<20 ; i++)
            if(n<=sum[i]) break;
        print_tree(n-sum[i-1],i);
        printf("\n");
    }
    return 0;
}

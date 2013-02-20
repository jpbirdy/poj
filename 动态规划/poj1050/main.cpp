/**
给定一个数字N和N*N个数的矩阵，
求出一个子矩阵，使得该矩阵内数字和最大。

先将二维的问题转换为一维
给一个长度为N的数组，求一个最大和的子序列（EASY）
F[i]表示包含第i个元素的最最大和序列，F[i] = {F[i-1]+a[i]>a[i]? F[i-1]+a[i]:a[i]}
推广到二维的情况
1、枚举起点列，col_start,col_end，用S[col_s,col_e]计算从第col_s列到col_e列最大和子矩阵，
当列确定了，那么某行的元素要么全部取，要么全取，这就转换为一维的情况

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


int main()
{
    int col_start,col_end;
    int i,j;
    int a[110][110];
    //保存列选好之后的最大子序列
    int s[110];
    //保存列选好之后每一行的和
    int m[110];
    int result = 0;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0 ; j<n ; j++)
            scanf("%d",&a[i][j]);
    for(col_start=0 ; col_start<n ; col_start++)
        for(col_end=(col_start+1) ; col_end<n ; col_end++)
        {
            int k,l;
            for(k=0 ; k<n ; k++)
            {
                //计算第k行，从start到end的全部元素和
                m[k] = 0;
                for(l=col_start ; l<=col_end ; l++)
                    m[k]+=a[k][l];
            }
            s[0] = m[0];
            for(k=1 ; k<n ; k++)
            {
                if((s[k-1]+m[k])> m[k] ) s[k] = s[k-1] + m[k];
                else s[k] = m[k];
                if(result<s[k]) result = s[k];
            }
        }
    printf("%d\n",result);
    return 0;
}

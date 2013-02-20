/**
给定一个串，要求在串中添加一些字符，使其成为回文串
要求添加的字符数最少，求最少的个数

DP
用
f[i][j]表示从i出发到字符j，最少需要添加的字符个数

状态转移方程
f[i][j] =
        1、str[i] == str[j] ，i==j或i==j+1，f[i][j] = 0;f[i][j] = f[i+1][j-1];
        2、!=，i==j+1，f[i][j] = 1;f[i][j] = min{f[i+1][j] , f[i][j-1]} + 1;

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

#define min(a,b) (((a)<(b))?(a):(b))

char str[5010];
unsigned short int f[5010][5010];

int main()
{
	int n;
	scanf("%d%s",&n,str);
	int i,j;
	for(i=1;i<n;i++)
		for(j=0;j<n-1;j++)
		{
			if(str[j]==str[j+i])
				if (i==1) f[j][j+i]=0;
				else f[j][j+i]=f[j+1][j+i-1];
			else if (i==1)f[j][j+i]=1;
			     else f[j][j+i]=min(f[j+1][j+i],f[j][j+i-1])+1;
		}
    printf("%d\n",f[0][n-1]);
	return 0;
}

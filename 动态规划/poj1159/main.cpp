/**
����һ������Ҫ���ڴ������һЩ�ַ���ʹ���Ϊ���Ĵ�
Ҫ����ӵ��ַ������٣������ٵĸ���

DP
��
f[i][j]��ʾ��i�������ַ�j��������Ҫ��ӵ��ַ�����

״̬ת�Ʒ���
f[i][j] =
        1��str[i] == str[j] ��i==j��i==j+1��f[i][j] = 0;f[i][j] = f[i+1][j-1];
        2��!=��i==j+1��f[i][j] = 1;f[i][j] = min{f[i+1][j] , f[i][j-1]} + 1;

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
